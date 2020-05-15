# In import.py, write a program that imports data from a CSV spreadsheet.
import csv
import sys
import cs50

# Your program should accept the name of a CSV file as a command-line argument.
# Check for correct number of args.
if len(sys.argv) != 2:
    print("Usage: python import.py data.csv")
    sys.exit(1)

# Check for correct file type in args.
if not (sys.argv[1]).endswith('.csv'):
    print("Usage: python import.py data.csv")
    sys.exit(1)

# Reference SQL database saved in the same directory.
db = cs50.SQL("sqlite:///students.db")

with open(sys.argv[1], newline='') as csvDatabase:
    if not csvDatabase:
        print(f"Could not open {sys.argv[1]}.")
        sys.exit(2)

    # After making sure the CSV file will exist, confirm it has
    # columns name, house, and birth.
    reader = csv.DictReader(csvDatabase)
    if not (reader.fieldnames == ["name","house","birth"]):
        print("Invalid csv file.")
        sys.exit(3)

    # All good start running over the rows.
    for row in reader:
        # For each student in the CSV file, insert the student into the students table in the students.db database.
        # While the CSV file provided to you has just a name column,
        # the database has separate columns for first, middle, and last names.
        name = [0,0,0]
        name, house, birth = row["name"].split(" "), row["house"], row["birth"]

        # For students without a middle name, you should leave their middle name field as NULL in the table.
        if len(name) == 3:
            # has three names.
            first, middle, last = name[0], name[1], name[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)

        else:
            # Set middle name as NULL use name[1] as last name
            first, last = name[0], name[1]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, NULL, ?, ?, ?)", first, last, house, birth)


csvDatabase.close()