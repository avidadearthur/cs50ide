# test check sum for credit.py#

def check_sum(n):

    nString = str(n)
    # Luhn's algorithm #

    length = len(nString)
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

        print("Valid\n")

    else:

        print("Not valid\n")

# Auto init #
if __name__ == '__main__':
    check_sum(1234567890)