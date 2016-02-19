# Problem 4: write a palindrom function

def isPalindrome(aString):
    if len(aString) == 1 or aString == '':
        return True
    elif len(aString) == 2:
        if aString[0] == aString[1]:
            return True
        else: return False
    elif aString[0] == aString[-1]:
        return isPalindrome(aString[1:-1])
    return False

# Problem 5: function tht returns sum of pairwise products of listA & listB
# i.e. Returns dot product of two vectors

def dotProduct(listA, listB):
    dotProductAB = 0
    for i in range(len(listA)):
        dotProductAB += listA[i] * listB[i]
    return dotProductAB

#print dotProduct(listA, listB)

# Problem 6: function to flatten list

def flatten(aList):
    result = []
    def flatter(aList):
        for i in range(len(aList)):
            if isinstance(aList[i], list):
                flatter(aList[i])
            else:
                result.append(aList[i])
        return result
    return flatter(aList)

# test:

# print flatten([1, 2, 3, 4])
# print flatten([[1], [2]])
# print flatten([[[1], 2]])

# # Failed Attempts:
# ########################################
# def flatten(aList):
#     newList = []
#     for i in range(len(aList)):
#         if isinstance(i, list):
#             flatten(aList[i])
#         else:
#             newList.append[i]
#     return newList
# ########################################
# def flatten(aList):
#     kerloList = []
#     for i in range(len(aList)):
#         if not isinstance(aList[i], list):
#             kerloList.append(aList[i])
#         else:
#             flatten(aList[i])
#     return kerloList
# ########################################
# def flatten(listA):
#
#     def flatter(sublistA):
#         if isinstance(sublistA, list):
#             #print "hey!"
#             return flatter(sublistA[0])
#         else:
#             #print "ho!"
#             #print sublistA
#             return sublistA
#
#     result = []
#     for i in range(len(listA)):
#         if isinstance(listA[i], list):
#             #print listA[i]
#             #print flatter(listA[i])
#             result.append(flatter(listA[i]))      # will this return what I want? should recurs until result
#             #print result
#         else:
#             result.append(listA[i])
#     #print result
#     return result
# #print flatten([[[1]], 2])
# print flatten([[1, [2, 3]], [[4, 5, 6], [7, [8, 9]]]])
# ########################################
# def flatten(listA):
#
#     subresult = []
#     def sublist(subA):
#         if not isinstance(subA, list):
#             return subresult.append(subA)
#         else:
#             for item in subA:
#                 sublist(item)
#
#     result = []
#     for index in range(len(listA)):
#         result.append(sublist(listA[index]))
# ########################################


# Problem 7: function returng tuple of 2 dicts: intersect & difference
# function f(a, b) predefined
# S: 15-Feb-2016 23:11 | F: 15-Feb-2016 23:38

# def f(a, b):
#     return a + b
#
# d1 = {'a':1, 'b':2, 'c':[1,2,3]}
# d2 = {'a':10, 'b':20, 'd':'wtf'}

def dict_interdiff(d1, d2):
    inter = {}
    diff = {}
    for key in d1.keys():
        if d2.has_key(key) == True:
            inter[key] = f(d1[key], d2[key])
        else:
            diff[key] = d1[key]
    for key in d2.keys():
        if d1.has_key(key) == False:
            diff[key] = d2[key]
    interdiff = (inter, diff)
    return interdiff
    # print interdiff


# Problem 8: returns # times string spec by f(s) appears in list of strings L.
# Mutates L to include only instns of string spec by f(s). f(s) predefined. (run_satisfiesF) predef.
# S: 15-Feb-2016 23:49 | F: 16-Feb-2016 00:17

# def f(s):
#     return 'a' in s
#
# L = ['a', 'b', 's', 'a']

def satisfiesF(L):
    counter = 0
    M = []
    for i in range(len(L)):
        if f(L[i]) == True:
            counter += 1
            M.append(L[i])
    del L[:]
    for i in range(len(M)):
        L.append(M[i])
    return counter

run_satisfiesF(L, satisfiesF)
# satisfiesF(L)


# def heyo():
#     return 'a' in 'Hakan and Elina'
# print heyo()
