# Problem 5 - Linear Search
# 18-Feb-2016 12:02

def search(L, e):
    for i in range(len(L)):
        if L[i] == e:
            return True
        if L[i] > e:
            return False
    return False

def newsearch(L, e):
    size = len(L)
    for i in range(size):
        if L[size-i-1] == e:
            return True
        if L[i] < e:
            return False
    return False

L = [1, 2, 3]
#L = [1, 2, 3, 4, 5]
#L = []
#L = [1, 2]
e = 2

print ("List: " + str(L))
print ("Search: " + str(search(L,e)))
print ("newSearch: " + str(newsearch(L,e)))

#Output:
#
#    %run "c:\users\wayne\appdata\local\temp\tmpj15hfy.py"
#List: [1, 2, 3, 4, 5]
#Search: True
#newSearch: False
#
#%run "c:\users\wayne\appdata\local\temp\tmp6ylknv.py"
#List: []
#Search: False
#newSearch: False
#
#%run "c:\users\wayne\appdata\local\temp\tmppl09e4.py"
#List: [1, 2]
#Search: True
#newSearch: True
#
#%run "c:\users\wayne\appdata\local\temp\tmptwswbc.py"
#List: [1, 2, 3]
#Search: True
#newSearch: False
