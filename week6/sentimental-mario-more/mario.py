def main():

    h = get_int("Height: ")

    mario(h)


def mario(height):
    # loop for printing the new lines
    for i in range(1, height + 1):

        # loop for printing the set of spaces
        for j in range(height - i):
            print(" ", end="")

        # loop for printing the 1st pyramid
        for k in range(i):
            print("#", end="")

        # loop for printing the blank space between the pyramids
        for m in range(2):
            print(" ", end="")

        # loop for printing the 2nd pyramid
        for n in range(i):
            print("#", end="")

        print()


def get_int(prompt):
    while True:
        try:
            h = int(input(prompt))

            if h >= 1 and h <= 8:
                return h
        except EOFError:
            break
        except:
            pass


if __name__ == "__main__":
    main()