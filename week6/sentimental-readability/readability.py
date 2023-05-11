# TODO
import re
from cs50 import get_string


def main():

    text = get_string("Text: ")

    # print(f"NUMBER OF LETTERS: {count_letters(text)}")
    # print(f"NUMBER OF WORDS: {count_words(text)}")
    # print(f"NUMBER OF SENTENCES: {count_sentences(text)}")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = letters / float(words) * 100

    S = sentences / float(words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8

    if index < 1:
        print("Before Grade 1")

    elif index >= 16:
        print("Grade 16+")

    else:
        print(f"Grade {round(index)}")


# function that count the number of letters in a string
def count_letters(string):
    number_letters = 0

    for char in string:
        if char.isalpha():
            number_letters += 1

    return number_letters


# function that counts the number of words in a given text
def count_words(string):
    number_words = 1

    for char in string:
        if char == " ":
            number_words += 1

    return number_words


# functions that counts the number of sentences
def count_sentences(string):
    number_sentences = 0

    for char in string:
        if re.search(r"[.?!]", char):
            number_sentences += 1

    return number_sentences


if __name__ == "__main__":
    main()