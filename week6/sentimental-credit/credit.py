from cs50 import get_int, get_string
import re

# DETAILS

# American Express
# 15 digits
# starts with 34 or 37

# MasterCard
# 16 digits
# starts with 51, 52, 53, 54, 55

# Visa
# 13 or 16 digits
# starts with 4


def main():

    card = get_int("Number: ")

    # temporary variable
    temp = card

    # total
    total = 0

    # last digit
    last_digit = None

    while temp > 0:

        last_digit = temp % 10

        total = total + last_digit

        temp = temp // 100

    temp = card // 10

    while temp > 0:

        last_digit = temp % 10

        times_two = last_digit * 2

        total = total + (times_two % 10) + (times_two // 10)

        temp = temp // 100

    # credit card number of digits
    length = int(card_length(card))

    # get first digit
    first = int(first_digit(card))

    # get two first digits
    first_two = int(first_two_digits(card))

    if total % 10 == 0:
        if (length == 13 or length == 16) and first == 4:
            print("VISA")

        elif length == 16 and (first_two > 50 and first_two < 56):
            print("MASTERCARD")

        elif length == 15 and (first_two == 34 or first_two == 37):
            print("AMEX")

        else:
            print("INVALID")

    else:
        print("INVALID")


# get the credit cards length
def card_length(n):
    return len(str(n))


# get first digit of credit card
def first_digit(n):
    to_str = str(n)
    return to_str[0]


# get last digit of the credit card
def last_digit(n):
    to_str = str(n)
    return to_str[-1]


# get first two digits of the credit card number
def first_two_digits(n):
    to_str = str(n)
    return to_str[:2]


if __name__ == "__main__":
    main()