# TODO
import cs50


def main():
    # get a number of cents
    cents = get_cents()

    # get the number of quarters and update the cents
    # rounding up to two decimal places
    quarters = calculate_quarters(cents)
    cents = round((cents - quarters * 0.25), 2)

    dimes = calculate_dimes(cents)
    cents = round((cents - dimes * 0.10), 2)

    nickles = calculate_nickles(cents)
    cents = round((cents - nickles * 0.05), 2)

    pennies = calculate_pennies(cents)
    cents = round((cents - pennies * 0.01), 2)

    total = quarters + nickles + dimes + pennies

    # print the number of coins to give
    print(total)


# function the returns the change inputted by the user
def get_cents():

    # loop the forces the user to type a positive number
    while True:
        try:
            change = cs50.get_float("Changed owed: ")

            if change > 0:
                return change

        except EOFError:
            break
        except:
            pass


# returns the quarters 25
def calculate_quarters(n):
    return int(n / 0.25)


# returns the dimes 10
def calculate_dimes(n):
    return int(n / 0.10)


# returns the nickles 5
def calculate_nickles(n):
    return int(n / 0.05)


# returns the pennies
def calculate_pennies(n):
    return int(n / 0.01)


if __name__ == "__main__":
    main()
