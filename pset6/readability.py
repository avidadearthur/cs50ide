# Implement a program that computes the approximate grade level needed to comprehend some text, per the below. #
# index = 0.0588 * L - 0.296 * S - 15.8 #
# Here, L is the average number of letters per 100 words in the text, #
# and S is the average number of sentences per 100 words in the text. #

def main():

    L, S = 0, 0
    text = input("Text: ")
    nWords = len(text.split(" "))

    for char in text:
        # Split sentences by '.' or '!' or '?' #
        if char.isalpha():
            L += 1
        # Split sentences by '.' or '!' or '?' #
        elif char in ['.','!','?']:
            S += 1

    S = (S/nWords)*100
    L = (L/nWords)*100

    # Coleman-Liau index #
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index < 1:
        print("Before Grade 1\n")

        return

    elif index > 16:
        print("Grade 16+\n")

        return

    else:
        print(f"Grade {index}\n")

        return

if __name__ == '__main__':
    main()