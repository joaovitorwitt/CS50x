def main():
    # prompts the user for a name
    name = input("What's your name? ")

    # calls the function with the name passed as input
    print(hello(name))


# returns the greeting with the users name
def hello(string):
    return f"hello, {string}"


if __name__ == "__main__":
    main()