# Hello python3 #
# Overcomplicated #


def ask_name():
    name = input("What is your name? ")
    return name


def say_hello(name):
    print(f"hello, {name}")


if __name__ == '__main__':

    say_hello(ask_name())
