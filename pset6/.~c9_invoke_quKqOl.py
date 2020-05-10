# Implement a program that calculates the minimum number of coins
# required to give a user change. #
from cs50 import get_float


def main():

    changeOwned = round(get_float("Change owned: ") * 100)
    format(changeOwned, '.2f')
    while changeOwned == 0 or changeOned < 0:
        changeOwned = round(get_float("Change owned: ") * 100)

    print(changeOwned)
    coins = 0

    while (changeOwned >= 0):

        if ( (changeOwned - 25) > 0 ):
            coins += 1
            changeOwned -= 25

        elif ( (changeOwned - 10) > 0 and changeOwned < 25 ):
            coins += 1
            changeOwned -= 10

        elif ( (changeOwned - 5) > 0 and changeOwned < 10 ):
            coins += 1
            changeOwned -= 5

        elif ( (changeOwned - 1) > 0 and changeOwned < 5):
            coins += 1
            changeOwned -= 1

    print(coins)

    return


if __name__ == "__main__":
    main()
