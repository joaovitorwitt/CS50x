# # TODO

# height = 4

# # loop for printing a new line
# for i in range(1, height+1):

#     # TODO loop for printing the spaces
#     for k in range(height - i):
#         print(" ", end="")

#     # loop for printing the hashes
#     for j in range(i):
#         print("#", end="")

#     print()


def main():

    height = get_int("What's the height? ")

    mario(height)


def mario(h):
    for i in range(1, h+1):

        # loop for printing the spaces
        for k in range(h - i):
            print(" ", end="")

        # loop for printing the hashes
        for j in range(i):
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