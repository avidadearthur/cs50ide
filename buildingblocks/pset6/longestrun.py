import re
import sys
import csv

# Check for correct number of args.
if len(sys.argv) != 3:
    print("Usage: python longestrun.py dna/database/'large or small'.csv dna/sequences/'number'.txt")
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
        # print(STR)
        highestSubCount = 0
        subCount, start, last_location, location, next_location = 0, 0, 0, 0, 0
        while True:

            location = string.find(STR, start)
            # print(f"current: {location}", end= " ")

            next_location = string.find(STR, location+len(STR))
            # print(f"next: {next_location}")

            if location == -1: # end of string ?
                break
            # no. continue:

            if next_location != -1: # next location is not out of range

                if last_location + len(STR) != location:
                    if subCount > highestSubCount:
                        highestSubCount = subCount
                    subCount = 0 # start counting again

                # if the current occurence location is right after len(STR) chars of
                # the last ocurrence location, we have consecutive occurences.

                # OR if the next occurence location is right after len(STR) chars of
                # the current ocurrence location, we have consecutive occurences.
                if ((location - last_location) == len(STR)) or ((next_location - location) == len(STR)):
                    # print(f"difference: {location - last_location} or {next_location - location}", end=" ")
                    # print("consecutive")
                    subCount += 1

                    if subCount > highestSubCount:
                        highestSubCount = subCount

                else:
                    subCount = 0 # start counting again

            elif next_location == -1: # next location is out of range


                if ((location - last_location) == len(STR)):
                    # just consider the last and the current occurence loactions
                    # print(f"difference: {location - last_location}", end=" ")
                    # print("consecutive")
                    subCount += 1

                    if subCount > highestSubCount:
                        highestSubCount = subCount

                else:
                    subCount = 0 # start counting again


            last_location = location

            # continue looking from the end of the
            # last found substring.
            start = location + len(STR)


        # print(STR)
        # print(highestSubCount)

        if highestSubCount == 0: # STR didn't appear more than once
            highestSubCount = 1

        substrs[STR] = highestSubCount

    return substrs


def main():

    sequence = dnaSequence.readline()
    print(sequence)

    with open(sys.argv[1], newline='') as csvDatabase:
        if not csvDatabase:
            print(f"Could not open {sys.argv[1]}.")
            sys.exit(2)

        reader = csv.DictReader(csvDatabase)
        STRs = reader.fieldnames[1:]

        STRsDic = longest_run(sequence, STRs)
        print(STRsDic)

    dnaSequence.close()

if __name__ == '__main__':
    main()