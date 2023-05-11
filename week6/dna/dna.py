import csv
import sys

# STR - short sequence of dna that tends to repeat multiple times in a person's dna


def main():

    # TODO: Check for command-line usage]
    # 1st command-line argument a CSV file containing the STR counts
    # 2nd command-line argument a txt file containing the DNA sequence to identify

    # if the user inputs the incorrect number of command-line-arguments exit
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    csv_file = sys.argv[1]
    txt_file = sys.argv[2]

    # TODO: Read database file into a variable
    dnas = []
    with open(csv_file) as file:
        reader = csv.DictReader(file)

        for row in reader:
            dnas.append(row)

    # TODO: Read DNA sequence file into a variable
    sequence = ""

    with open(txt_file) as f:
        sequence = f.readline().strip()

    # TODO: Find longest match of each STR in DNA sequence

    sub = list(dnas[0].keys())[1:]

    results = {}

    for subsequence in sub:
        results[subsequence] = longest_match(sequence, subsequence)

    # TODO: Check database for matching profiles

    for name in dnas:
        equal = 0
        for subsequence in sub:
            if int(name[subsequence]) == results[subsequence]:
                equal += 1

        if equal == len(sub):
            print(name["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
