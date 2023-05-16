import os

import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)


# Custom filter
app.jinja_env.filters["usd"] = usd

# Auto reload
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    # select the transactions of the current user logged in
    # returns [{'symbol': 'IDX', 'name': ......}, {.....}, {.....}]
    purchases = db.execute(
        "SELECT symbol, name, SUM(shares) AS total_shares, price FROM purchases WHERE user_id = ? GROUP BY symbol", user_id)

    # print(f"PURCHASES: {purchases}")

    # returns the data in this format: [{'id': 3, 'cash': 1111, ....}]
    user_current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]['cash']

    full_total = user_current_cash

    for purchase in purchases:
        # calculate the full total
        full_total += purchase["price"] * purchase["total_shares"]

    return render_template("index.html", purchases=purchases, user_current_cash=user_current_cash, full_total=full_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # stock symbol (like: NFLX)
        symbol = request.form.get("symbol")
        # check for empty input
        if not symbol:
            return apology("Missing symbol")

        # check for valid symbol
        stock = lookup(symbol)
        if not stock:
            return apology("invalid symbol")

        # shares must be a positive integer
        shares = request.form.get("shares")

        try:
            shares_to_int = int(shares)
            if shares_to_int <= 0:
                return apology("Shares must be a positive integer")
        except ValueError:
            return apology("Shares must be an integer")

        # select how much cash the user has
        user_current_cash = db.execute("SELECT cash FROM users where id = ?", session["user_id"])[0]['cash']

        # Get user's id
        user_id = session["user_id"]

        # stock infor
        stock_price = stock['price']
        stock_symbol = stock['symbol']
        stock_name = stock['name']

        total_user_will_spend = float(stock_price) * shares_to_int

        # cash the user will have after buying the stocks
        user_new_cash = user_current_cash - total_user_will_spend

        if user_new_cash < 0:
            return apology("Not enough cash, stranger")

        # time that the user bought the stock to insert into the database
        time_bought = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # update the cash in the users table
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?",
            user_new_cash,
            user_id
        )

        # insert info into the table
        db.execute(
            "INSERT INTO purchases (user_id, symbol, name, shares, price, time, type) VALUES (?, ?, ?, ?, ?, ?, ?)",
            user_id,
            stock_symbol,
            stock_name,
            shares_to_int,
            stock_price,
            time_bought,
            "Buy"
        )

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    historics = db.execute("SELECT symbol, shares, price, time, type FROM purchases WHERE user_id = ?", session["user_id"])

    if not historics:
        return apology("Nothing here", 403)

    else:
        return render_template("history.html", historics=historics)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        # get the symbol that the user typed (like NFLX)
        symbol = request.form.get("symbol")

        # check for empty input
        if not symbol:
            return apology("Missing symbol")

        # look function returns {'name': ..., 'price': ..., 'symbol': ...}
        stock = lookup(symbol)

        # check for valid stocks
        if not stock:
            return apology("Invalid symbol")

        # in the html we access those values with stock['name'], stock['price']....
        return render_template("quoted.html", stock=stock)

    # method GET, we just render the form
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        # getting username from the form
        username = request.form.get("username")

        # check if username is not empty
        if not username:
            return apology("username cannot be empty")

        # check if that username exists on the table, if true the username is already taken
        result = db.execute("SELECT username FROM users WHERE username = ?", username)
        if result:
            return apology("Username already taken")

        # getting password and confirmation from the form
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # check if password or confirmation are empty
        if not password or not confirmation:
            return apology("password cannot be empty")

        # check for equal passwords
        if password != confirmation:
            return apology("Passwords dont match")

        # check password length
        if len(password) < 8 or len(confirmation) < 8:
            return apology("Password must be more than 8 characters")

        # encrypt user's password
        hash = generate_password_hash(password)

        # insert the username and the encrypted password on the table
        db.execute("INSERT INTO users(username, hash) VALUES (?, ?)", username, hash)

        # row returns: [{'id': 9, 'username': .....}]
        row = db.execute("SELECT * FROM users WHERE username = ?", username)

        # log the user in
        session["user_id"] = row[0]["id"]

        # once we assign the user id to the session we redirect to the homepage
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        user_id = session["user_id"]
        symbol = request.form.get("symbol")

        # check if user actually selected a symbol
        if not symbol:
            return apology("Missing symbol")

        # check if it is a valid symbol
        user_owned_symbols = db.execute("SELECT symbol FROM purchases WHERE user_id = ? GROUP BY symbol", user_id)

        user_symbol = [d['symbol'] for d in user_owned_symbols]

        if symbol not in user_symbol:
            return apology("Invalid symbol")

        # check if share is an integer
        try:
            shares = int(request.form.get("shares"))
        except:
            return apology("Shares must be an integer")

        stock_name = lookup(symbol)['name']
        stock_price = lookup(symbol)['price']
        total_price = stock_price * shares

        # check if user owns that many shares of the stock
        user_info = db.execute(
            "SELECT symbol, SUM(shares) AS total_shares FROM purchases WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)

        user_shares = user_info[0]['total_shares']

        if user_shares < shares:
            return apology("Not enough shares, stranger")

        user_current_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]['cash']

        user_balance = user_current_cash + total_price

        time_sold = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        db.execute("UPDATE users SET cash = ? WHERE id = ?", user_balance, user_id)

        db.execute("INSERT INTO purchases (user_id, name, shares, symbol, time, type, price) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   user_id,
                   stock_name,
                   -shares,
                   symbol,
                   time_sold,
                   "Sold",
                   stock_price
                   )

        return redirect("/")

    else:
        user_id = session["user_id"]

        # returns [{'symbol': 'IDX'}, {'symbol': 'MSFT'}, {...}]
        symbols = db.execute("SELECT symbol FROM purchases WHERE user_id = ? GROUP BY symbol", user_id)

        return render_template("sell.html", symbols=symbols)

