# Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm. #

def main():

    # Propt user for number #
    number = input("Number: ")
    try:
       val = int(number)
    # Check if its a number #
    except ValueError:
        print("INVALID\n")

        return

    # Check lenght #
    if len(number) not in [13,15,16]:
        print("INVALID\n")

        return

    elif check_sum(number):

        if credit_card(number) == 2:
            print("AMEX\n")

            return

        elif credit_card(number) == 3:
            print("MASTERCARD\n")

            return

        elif credit_card(number) == 4:
            print("VISA\n")

            return

    # Failed Checksum #
    else:
        print("INVALID\n")

        return

def check_sum(n):

    nString = str(n)
    # Luhn's algorithm #

    # Multiply every other digit by two starting by the second #
    # and stoping at the last #

    UnchangedDigSum = 0
    for i in range(-1,0,-2):
        UnchangedDigSum += int(nString[i])

    changedDigSum = 0
    for i in range(-2,0,-2):
        nChanged = int(nString[i])*2
        # Add the product digits together #
        changedDigSum += nChanged

    # Add the doubbled digits to the unchanged digits #
    # and check if the last digit of the sum is zero #
    if ( (UnchangedDigSum + changedDigSum) % 10) == 0:

        return True

    else:

        return False

def credit_card(n):

    nString = str(n)
    length = len(nString)
    # Credit card types #

    # AMEX - 15 digits, starts with 34 or 37 #
    if length == 15 and nString[0:2] in ["34", "37"]:

        return 2

    # MASTERCARD - 16 digits, starts with 51-55 #
    if length == 16 and nString[0:2] in ["51", "52", "53", "54", "55"]:

        return 3

    # VISA - 13 or 16 digits, starts with 4 #
    if length == 13 or length == 16 and nString[0] == "4":

        return 4


# Auto init #
if __name__ == '__main__':
    main()