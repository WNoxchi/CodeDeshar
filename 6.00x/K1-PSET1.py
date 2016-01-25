# 6.00.1x   -   PSet 1
# Wayne H. Noxchi
# --------------------------------------

# 1.1 Counting Vowels
# 25-Jan-2016 09:36 | 25-Jan-2016 09:45
# assume s is a string of lower case characters

vowels = 0
for i in s:
    if i in 'aeiou' or i in 'AEIOU':
        vowels += 1

print("Number of vowels: ", vowels)

# --------------------------------------
# 1.2 Counting Bobs
# 25-Jan-2016 09:53 | 25-Jan-2016 10:34
# count them

bobs = 0
for i in range(len(s)):
    if "bob" in s[i:i+3]:
    # if s[i:i+3] == "bob"
        bobs += 1
print("Number of times bob occurs is: ", bobs);

# --------------------------------------
# 1.3 Counting and Grouping
# 25-Jan-2016 10:43 | 25-Jan-2016 11:18
# count items for order

def item_order(order):
    burger = 0
    salad =  0
    water =  0
    for i in range(len(order)):
        # if order[i:i+5] == "salad":
        #     salad += 1
        # if order[i:i+9] == "hamburger":
        #     burger += 1
        # if order[i:i+5] == "water":
        #     water += 1
        if "salad" in order[i:i+5]:
            salad += 1
        if "hamburger" in order[i:i+9]:
            burger += 1
        if "water" in order[i:i+5]:
            water += 1
    kitchen = 'salad:%(s)d hamburger:%(h)d water:%(w)d' % {"s": salad, "h": burger, "w": water}
    return kitchen
