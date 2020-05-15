# Mario less #
from cs50 import get_int


def make_hash(start, n):
    # Trying to use recursion #
    if start > n:
        return 0

    else:
        gap = n - start

        print(" "*gap, end="")
        print("#"*start)

        start += 1
        make_hash(start, n)


def ask():
    # Prompt user asking a integer between 1 and 8 #
    n = get_int("Give a number between 1 and 8: ")
    if n not in range(1, 9):
        ask()
    else:
        return n


if __name__ == '__main__':
    make_hash(1, ask())