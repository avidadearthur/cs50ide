# Implement a program that identifies a person based on their DNA, per the below.

# The program should require as its first command-line argument the name of
# a CSV file containing the STR counts for a list of individuals and should require
# as its second command-line argument the name of a text file containing the
# DNA sequence to identify.
import re
import sys
import csv

# Check for correct number of args.
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Check for correct file type in args.
if not ((sys.argv[1]).endswith('.csv')) or not ((sys.argv[2]).endswith('.txt')):
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# Your program should open the DNA sequence and read its contents into memory.
dnaSequence = open(sys.argv[2], newline='')
if not dnaSequence:
    print(f"Could not open {sys.argv[2]}.")
    sys.exit(2)

# Gets a a string and a list of char sequences to be matched
# Returns a dictionary with the char sequence and the longuest consecutive
# occurence of it.
def longest_run(string, STRs):
    # STRs is the list of substrings to be searched
    # (the substrings).
    #dictionary of substr's.
    substrs = {}

    for STR in STRs:
        highestSubCount = 0
        subCount, start, last_location, location, next_location = 0, 0, 0, 0, 0
        while True:

            location = string.find(STR, start)

            next_location = string.find(STR, location+len(STR))

            if location == -1: # end of string ?
                break
            # no. continue:

            if next_location != -1: # next location is not out of range

                # avoid double counting
                if last_location + len(STR) != location:
                    if subCount > highestSubCount:
                        highestSubCount = subCount
                    subCount = 0 # start counting again

                # if the current occurence location is right after len(STR) chars of
                # the last ocurrence location, we have consecutive occurences.

                # OR if the next occurence location is right after len(STR) chars of
                # the current ocurrence location, we have consecutive occurences.
                if ((location - last_location) == len(STR)) or ((next_location - location) == len(STR)):
                    subCount += 1

                    if subCount > highestSubCount:
                        highestSubCount = subCount

                else:
                    subCount = 0 # start counting again

            elif next_location == -1: # next location is out of range
                # just consider the last and the current occurence loactions
                if ((location - last_location) == len(STR)):
                    subCount += 1

                    if subCount > highestSubCount:
                        highestSubCount = subCount

                else:
                    subCount = 0 # start counting again

            last_location = location

            # continue looking from the end of the
            # last found substring.
            start = location + len(STR)

        if highestSubCount == 0: # STR didn't appear more than once
            highestSubCount = 1

        substrs[STR] = highestSubCount

    return substrs

# Compares val in a csv file row given a list of headers
# and a dictionary that links the same headers to the values.
# Retruns True if all the values from both src's are the same.
def match(headersList, dictionary):

    index = 0
    for header in headersList:
        #print(f"{header}:{row[header]}, {dictionary[ headersList[index] ]}")
        if int(row[header]) != dictionary[ headersList[index] ]:
            return False
        index += 1

    return True

# Open the CSV file and read its contents into memory.
# If newline='' is not specified, newlines embedded inside quoted fields
# will not be interpreted correctly, and on platforms that use \r\n linendings
# on write an extra \r will be added.
with open(sys.argv[1], newline='') as csvDatabase:
    if not csvDatabase:
        print(f"Could not open {sys.argv[1]}.")
        sys.exit(2)
    # For each of the STRs (from the first line of the CSV file),
    # your program should compute the longest run of consecutive repeats
    # of the STR in the DNA sequence to identify.

    # Look for matches in every row with any of the individuals in the CSV file.
    reader = csv.DictReader(csvDatabase)
    STRs = reader.fieldnames[1:]

    sequence = dnaSequence.readline() # List of STRS in the dna
    STRsDic = longest_run(sequence, STRs)
    #print(STRsDic)
    for row in reader:
        #print(row)
        # If the STR counts match exactly with any of the individuals in the CSV file,
        # your program should print out the name of the matching individual.
        if match(STRs, STRsDic):
            print(row["name"])
            sys.exit(0)

    print("No match")
    sys.exit(0)

csvDatabase.close()
dnaSequence.close()