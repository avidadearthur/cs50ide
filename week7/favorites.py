import csv

favorites = {}

# def f(item): # To be used when sorting the dictionary # check out the lamda way
#     return item[1]

with open("CS50 2019 - Lecture 7 - Favorite TV Shows (Responses) - Form Responses 1.csv") as showsData:
    reader = csv.DictReader(showsData)

    for row in reader:

        title = row["title"].lower()

        if title in favorites:
            favorites[title] += 1
        else:
            favorites[title] = 1

    # Let's sort the dictionary using the key argument to determine how
    # we want to sort it
    sortedFavorites = sorted(favorites.items(), key = lambda item: item[1], reverse=True)

    for title, count in sortedFavorites:
        print(title, count, sep = " / ")

showsData.close()