# Write a program that prints a list of students for a given house in alphabetical order.
import csv
import sys
# no cs50 this time.
import sqlite3

# Your program should accept the name of a house as a command-line argument.
if len(sys.argv) != 2:
    # If the incorrect number of command-line arguments are provided, your program should print an error and exit.
    print("Usage: python roster.py [ValidHouseName]")
    sys.exit(1)

# connect withe the students database
connection = sqlite3.connect("students.db")
# cursor
db = connection.cursor()

# Your program should query the students table in the students.db database for all of the students in the specified house.
# Your program should then print out each student’s full name and birth year in the following format:
# formatted as, e.g., Harry James Potter, born 1980 or Luna Lovegood, born 1981
def main():
    sql_command = """SELECT first, middle, last, house, birth
                FROM students WHERE house = ?
                ORDER BY last, first;"""

    db.execute(sql_command, [sys.argv[1]])
    # store all the fetched data in the ans variable
    ans = db.fetchall()

    for student in ans:
        if student[1] != None:
            print(f"{student[0]} {student[1]} {student[2]}, born {student[-1]}")
        else:
            print(f"{student[0]} {student[2]}, born {student[-1]}")

    return

if __name__ == "__main__":
    main()


