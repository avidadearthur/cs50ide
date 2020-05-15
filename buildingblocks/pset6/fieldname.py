# Trying to get header name from cell in current row
# through Dicreader.
import re
import sys
import csv

# Check for correct number of args.
if len(sys.argv) != 2:
    print("Usage: python fieldname.py data.csv")
    sys.exit(1)

# Gets the max val in a csv file row given a list of headers
def max_val(headersArr):
    vals = []
    for header in headersArr:
        list.append(vals, int(row[header]))
    maxVal = max(vals)

    return maxVal, vals.index(maxVal)


with open(sys.argv[1], newline='') as csvDatabase:
    if not csvDatabase:
        print(f"Could not open {sys.argv[1]}.")
        sys.exit(2)

    # Adaptated to the DNA problem set 6 csv dataset
    reader = csv.DictReader(csvDatabase)
    STRs = reader.fieldnames[1:]
    for row in reader:
        # If the STR counts match exactly with any of the individuals in the CSV file,
        # your program should print out the name of the matching individual.
        maxVal, index = max_val(STRs)

        print(maxVal, index, STRs[index])

csvDatabase.close()