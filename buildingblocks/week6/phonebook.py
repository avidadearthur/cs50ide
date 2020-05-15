from sys import exit
from sys import argv

def main():
    people = {
        "EMMA": "617-555-0105",
        "JHON": "617-555-0104",
        "ETAN": "617-555-0103",
        "AMON": "617-555-0102",
        "TAYLOR": "617-555-0101",
    }

    if len(argv) != 2 :
        print("Usage: phonebook.py name")
        exit(1)

    elif argv[1].upper() in people:
        print(f"Found {people[argv[1].upper()]}")
        exit(0)

    else:
        print(f"{argv[1].upper()} not found")
        exit(0)

    return

main()