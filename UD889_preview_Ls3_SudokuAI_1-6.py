# Wayne H Nixalo - Jun-14 -> 2017-Jun-15 22:09
# Udacity AI Nanodegree Preview -- UD889                NOTE s

# the string will consist of a concatenation of all the readings of the digits
# in the rows, taking the rows from top to bottom.
# If the puzzle is not solved, we can use a . as a placeholder for an empty box

# ..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3..
# 483921657967345821251876493548132976729564138136798245372689514814253769695417382

rows = 'ABCDEFGHI'
cols = '123456789'

# cross(a,b): given 2 strings, a & b, will return the list formed by all the
# possible concatenations of a letter s in string a w/ letter t in string b.

# So cross('abc', 'def') will return:
    # ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf'].

def cross(a, b):
    return [s+t for s in a for t in b]

# Now to create the labels of the boxes:

boxes = cross(rows, cols)
boxes =
    ['A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'A8', 'A9',
     'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9',
     'C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9',
     'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9',
     'E1', 'E2', 'E3', 'E4', 'E5', 'E6', 'E7', 'E8', 'E9',
     'F1', 'F2', 'F3', 'F4', 'F5', 'F6', 'F7', 'F8', 'F9',
     'G1', 'G2', 'G3', 'G4', 'G5', 'G6', 'G7', 'G8', 'G9',
     'H1', 'H2', 'H3', 'H4', 'H5', 'H6', 'H7', 'H8', 'H9',
     'I1', 'I2', 'I3', 'I4', 'I5', 'I6', 'I7', 'I8', 'I9']

# and for the units:

row_units = [cross(r, cols) for r in rows]
col_units = [cross(rows, c) for c in cols]
square_units = [cross(r, c) for r in ('ABC', 'DEF', 'GHI') for c in ('123','456','789')]

unitlist = row_units + col_units + square_units

# Implement grid_values() - a function to convert the string representation of
# a puzzle into a dictionary form.

# Recall that for the string:
#
# '..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3..'
# ...we'd like to return the dictionary:
#
# {
#   'A1': '.'
#   'A2': '.',
#   'A3': '3',
#   'A4': '.',
#   'A5': '2',
#   ...
#   'I9': '.'
# }


# from utils import *

def grid_values(grid):
    gvals = dict()
    for i in range(len(grid)):
        gvals[boxes[i]] = grid[i]
    return gvals

    # STAFF SOLN:
    # assert len(grid) == 81, "Input grid must be a string of length 81 (9x9)"
    # return dict(zip(boxes, grid))

# # utils.py:
rows = 'ABCDEFGHI'
cols = '123456789'

def cross(a, b):
    return [s+t for s in a for t in b]

boxes = cross(rows, cols)

row_units = [cross(r, cols) for r in rows]
column_units = [cross(rows, c) for c in cols]
square_units = [cross(rs, cs) for rs in ('ABC','DEF','GHI') for cs in ('123','456','789')]
unitlist = row_units + column_units + square_units
units = dict((s, [u for u in unitlist if s in u]) for s in boxes)
peers = dict((s, set(sum(units[s],[]))-set([s])) for s in boxes)

def display(values):
    """
    Display the values as a 2-D grid.
    Input: The sudoku in dictionary form
    Output: None
    """
    width = 1+max(len(values[s]) for s in boxes)
    line = '+'.join(['-'*(width*3)]*3)
    for r in rows:
        print(''.join(values[r+c].center(width)+('|' if c in '36' else '')
                      for c in cols))
        if r in 'CF': print(line)
    return


####################
# Improved grid_values()
# from utils import *
def grid_values(grid):
    """Convert grid string into {<box>: <value>} dict with '123456789' value for empties.

    Args:
        grid: Sudoku grid in string form, 81 characters long
    Returns:
        Sudoku grid in dictionary form:
        - keys: Box labels, e.g. 'A1'
        - values: Value in corresponding box, e.g. '8', or '123456789' if it is empty.
    """
    allnum = '123456789'
    assert(len(grid)==81)
    gvals = dict()
    for i in range(len(grid)):
        if grid[i] == '.':
            gvals[boxes[i]] = allnum
        else:
            gvals[boxes[i]] = grid[i]
    return gvals

    # STAFF SOLN:
    values = []
    all_digits = '123456789'
    for c in grid:
        if c == '.':
            values.append(all_digits)
        elif c in all_digits:
            values.append(c)
    assert len(values) == 81
    return dict(zip(boxes, values))

    think my way's a bit faster because I don't create an entire new list,
    although both algorithms make O(n) comparisons.
    So that's just halving the constant factor.

####################
# Implement eliminate() - takes as input a puzzle in dictionary form. Function
# iterates over all boxes in puzzle that have only one value assigned to them,
# and it will remove this value from every one of its peers.

# from utils import *

def eliminate(values):
    """Eliminate values from peers of each box with a single value.

    Go through all the boxes, and whenever there is a box with a single value,
    eliminate this value from the set of values of all its peers.

    Args:
        values: Sudoku in dictionary form.
    Returns:
        Resulting Sudoku in dictionary form after eliminating values.
    """
    def edit_peers(key, values):
        row = ord(key[0])
        col = ord(key[1]) - ord('0')
        num = values[key]

        # check row
        for i in range(0, col):
            rdx, cdx = chr(row), str(i+1)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')
        # for i in range(col, 9):
        for i in range(9 - col):
            rdx, cdx = chr(row), str(col+i+1)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')

        # check col
        for i in range(0, row - ord('A')):
            rdx, cdx = chr(ord('A') + i), str(col)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')
        for i in range(9 - (row - ord('A'))):
            rdx, cdx = chr(row + i), str(col)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')

        # check square
        rsq, csq = (row - ord('A')) // 3 * 3, (col-1) // 3 * 3

        for r in range(3):
            rdx = chr(ord('A') + rsq + r)
            for c in range(3):
                cdx = str(csq + c + 1)
                if rdx != key[0] and cdx != key[1]:
                    if len(values[rdx + cdx]) > 1:
                        values [rdx+cdx] = values[rdx + cdx].replace(num, '')

        # return values

    for key in values:
        if len(values[key]) == 1:
            edit_peers(key, values)
            # values = edit_peers(key, values)

    return values


# OUTPUT:
# Looks good!
#   145    14578     3    |  149      2      1479  |   6      5789     57
#    9     24678     47   |   3       47      5    |   78     278      1
#   125     1257     17   |   8       79      6    |   4     23579    2357
# ------------------------+------------------------+------------------------
#   1345   13459     8    | 14569   34569     2    |  179   1345679  34567
#    7     123459   149   | 14569   34569    149   |   19    134569    8
#   1345   13459     6    |   7     34589    1489  |   2     13459    345
# ------------------------+------------------------+------------------------
#   1346   134679    2    |  469    46789    4789  |   5     14678    467
#    8      1467    147   |   2      4567     3    |   17     1467     9
#    46     4679     5    |  469      1      4789  |   3     24678    2467

# ################# ################# ################
# STAFF SOLN ELIMINATION:
# ################# ################# ################
from utils import *

def eliminate(values):
    """Eliminate values from peers of each box with a single value.

    Go through all the boxes, and whenever there is a box with a single value,
    eliminate this value from the set of values of all its peers.

    Args:
        values: Sudoku in dictionary form.
    Returns:
        Resulting Sudoku in dictionary form after eliminating values.
    """
    solved_values = [box for box in values.keys() if len(values[box]) == 1]
    for box in solved_values:
        digit = values[box]
        for peer in peers[box]:
            values[peer] = values[peer].replace(digit,'')
    return values

# ################# ################# ################
# ################# ################
# SECTION 2:



# from utils import *

def eliminate(values):
    """Eliminate values from peers of each box with a single value.

    Go through all the boxes, and whenever there is a box with a single value,
    eliminate this value from the set of values of all its peers.

    Args:
        values: Sudoku in dictionary form.
    Returns:
        Resulting Sudoku in dictionary form after eliminating values.
    """
    def edit_peers(key, values):
        row = ord(key[0])
        col = ord(key[1]) - ord('0')
        num = values[key]

        # check row
        for i in range(0, col):
            rdx, cdx = chr(row), str(i+1)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')
        # for i in range(col, 9):
        for i in range(9 - col):
            rdx, cdx = chr(row), str(col+i+1)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')

        # check col
        for i in range(0, row - ord('A')):
            rdx, cdx = chr(ord('A') + i), str(col)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')
        for i in range(9 - (row - ord('A'))):
            rdx, cdx = chr(row + i), str(col)
            if len(values[rdx + cdx]) > 1:
                values[rdx+cdx] = values[rdx + cdx].replace(num, '')

        # check square
        rsq, csq = (row - ord('A')) // 3 * 3, (col-1) // 3 * 3

        for r in range(3):
            rdx = chr(ord('A') + rsq + r)
            for c in range(3):
                cdx = str(csq + c + 1)
                if rdx != key[0] and cdx != key[1]:
                    if len(values[rdx + cdx]) > 1:
                        values [rdx+cdx] = values[rdx + cdx].replace(num, '')

        # return values

    for key in values:
        if len(values[key]) == 1:
            edit_peers(key, values)
            # values = edit_peers(key, values)

    return values


# OUTPUT:
# Looks good!
#   145    14578     3    |  149      2      1479  |   6      5789     57
#    9     24678     47   |   3       47      5    |   78     278      1
#   125     1257     17   |   8       79      6    |   4     23579    2357
# ------------------------+------------------------+------------------------
#   1345   13459     8    | 14569   34569     2    |  179   1345679  34567
#    7     123459   149   | 14569   34569    149   |   19    134569    8
#   1345   13459     6    |   7     34589    1489  |   2     13459    345
# ------------------------+------------------------+------------------------
#   1346   134679    2    |  469    46789    4789  |   5     14678    467
#    8      1467    147   |   2      4567     3    |   17     1467     9
#    46     4679     5    |  469      1      4789  |   3     24678    2467

########################################
# INCLUDING DEBUG STATEMENTS:
# def only_choice(values):
#     """Finalize all values that are the only choice for a unit.
#
#     Go through all the units, and whenever there is a unit with a value
#     that only fits in one box, assign the value to this box.
#
#     Input: Sudoku in dictionary form.
#     Output: Resulting Sudoku in dictionary form after filling in only choices.
#     """
#     # TODO: Implement only choice strategy here
#     def loopcol(key, col, fn):
#         # print(col, key[1])
#         for i in range(0, col - 1):
#             rdx, cdx = chr(row), str(i+1)
#             # if rdx == key[0] and cdx == key[1]:
#             #     print("hey----")
#             #     print(rdx, cdx)
#             #     print(key[0], key[1])
#             #     print("ho-----")
#             # if rdx == row: print("rdx = row", rdx, row)
#             # if cdx == col: print("cdx = col", cdx, col)
#             fn(rdx, cdx)
#         for i in range(9 - (col+1)):
#             # print("col aft: ", col, str(col+i+1))
#             rdx, cdx = chr(row), str(col+i+1)
#             # if rdx == 'E' and cdx == '4': print("hey")
#             # if rdx == row: print("rdx = row", rdx, row)
#             # if cdx == col: print("cdx = col", cdx, col)
#             fn(rdx, cdx)
#
#     def looprow(key, row, fn):
#         for i in range(0, row - ord('A')):
#             rdx, cdx = chr(ord('A') + i), str(col)
#             # if rdx == row: print("rdx = row", rdx, row)
#             # if cdx == col: print("cdx = col", cdx, col)
#             fn(rdx, cdx)
#         for i in range(9 - (row - ord('A') + 1)):
#             rdx, cdx = chr(row + i + 1), str(col)
#             # if rdx == row: print("rdx = row", rdx, row)
#             # if cdx == col: print("cdx = col", cdx, col)
#             fn(rdx, cdx)
#
#     def loopsqu(key, row, col, fn):
#         rsq, csq = (row - ord('A')) // 3 * 3, (col-1) // 3 * 3
#         for r in range(3):
#             rdx = chr(ord('A') + rsq + r)
#             for c in range(3):
#                 cdx = str(csq + c + 1)
#                 # if rdx == row: print("rdx = row", rdx, row)
#                 # if cdx == col: print("cdx = col", cdx, col)
#                 if rdx != chr(row) and cdx != str(col):
#                     # print(rdx, chr(row), cdx, col)
#                     # print(' ', key[0], ' ', key[1])
#                     fn(rdx, cdx)
#
#     # define loop action functions
#     def only(rdx, cdx):
#         replacement = []
#         nums = values[key]
#         # if rdx == key[0] and cdx == key[1]: print(rdx, cdx, key[0], key[1])
#             # print(rdx, cdx)
#             # print(key[0], key[1])
#         for n in nums:
#             if n in values[rdx + cdx]:
#                 # if rdx == 'A' and cdx == '6':
#                 #     print(n, rdx, cdx)
#                 #     print(' ',chr(row), str(col))
#                 #     print(key)
#                 values[key] = values[key].replace(n, '')
#                 # replacement.append(n)
#         # for n in replacement:
#         #     nums = nums.replace(n, '')
#         # values[key] = nums
#
#
#     # Algorithm: if a number is found no where else but box, box = number
#     for key in values:
#         if len(values[key]) > 1:
#             row, col, num = ord(key[0]), ord(key[1]) - ord('0'), values[key]
#             loopcol(key, col, only)
#             looprow(key, row, only)
#             loopsqu(key, row, col, only)
#
#     return values
#
# ################################


# THIS IS HOW FAR I GOT:
# from utils import *

def only_choice(values):
    """Finalize all values that are the only choice for a unit.

    Go through all the units, and whenever there is a unit with a value
    that only fits in one box, assign the value to this box.

    Input: Sudoku in dictionary form.
    Output: Resulting Sudoku in dictionary form after filling in only choices.
    """
    # TODO: Implement only choice strategy here
    def loopcol(key, col, fn):
        for i in range(0, col - 1):
            rdx, cdx = chr(row), str(i+1)
            fn(rdx, cdx)
        for i in range(9 - (col+1)):
            rdx, cdx = chr(row), str(col+i+1)
            fn(rdx, cdx)

    def looprow(key, row, fn):
        for i in range(0, row - ord('A')):
            rdx, cdx = chr(ord('A') + i), str(col)
            fn(rdx, cdx)
        for i in range(9 - (row - ord('A') + 1)):
            rdx, cdx = chr(row + i + 1), str(col)
            fn(rdx, cdx)

    def loopsqu(key, row, col, fn):
        rsq, csq = (row - ord('A')) // 3 * 3, (col-1) // 3 * 3
        for r in range(3):
            rdx = chr(ord('A') + rsq + r)
            for c in range(3):
                cdx = str(csq + c + 1)
                if rdx != chr(row) and cdx != str(col) and len(values[rdx+cdx]) == 1:
                    fn(rdx, cdx)

    # define loop action functions
    def only(rdx, cdx):
        if len(values[rdx, cdx] > 1: return
        replacement = []
        nums = values[key]
        for n in nums:
            if n in values[rdx + cdx]:
                values[key] = values[key].replace(n, '')

    # Algorithm: if a number is found no where else but box, box = number
    for key in values:
        if len(values[key]) > 1:
            row, col, num = ord(key[0]), ord(key[1]) - ord('0'), values[key]
            loopcol(key, col, only)
            looprow(key, row, only)
            loopsqu(key, row, col, only)

    return values

# so, in Python you can pass a function as an argument into a function..
# the * opr is used to unpack sequence/collection into positional arguments,
# so it basically unpacks a tuple.
# the ** opr does the same, but for dictionaries instead of tuples. Hmm..
# https://stackoverflow.com/questions/2921847/what-does-the-star-operator-mean
# https://stackoverflow.com/questions/6289646/python-function-as-a-function-argument





# INPUT (ELIMINATE HAS BEEN RUN):
#    45    4578    3   |   49     2     147  |   6     5789    57
#    9    24678    47  |   3      47     5   |   78    278     1
#    25    257     1   |   8      79     6   |   4    23579   2357
# ---------------------+---------------------+---------------------
#   345    345     8   |   1     3456    2   |   9    34567  34567
#    7    123459   49  |  459   34569    4   |   1    13456    8
#   1345  13459    6   |   7     3459    8   |   2     1345   345
# ---------------------+---------------------+---------------------
#   134    1347    2   |   6     478     9   |   5     1478    47
#    8     1467    47  |   2     457     3   |   17    1467    9
#    46    4679    5   |   4      1      47  |   3    24678   2467

# OUTPUT:
#       4578  3  |       2    1  |  6
#   9    6       |  3         5  |       78   1
#             1  |  8         6  |  4         2
# ---------------+---------------+---------------
#             8  |  1         2  |  9   3456
#   7            |  5         4  |  1         8
#             6  |  7    9    8  |  2
# ---------------+---------------+---------------
#  134        2  |  6    8    9  |  5         7
#   8         47 |  2         3  |            9
#   6    9    5  |  4    1    7  |  3
# #################  #################  #################
#        58   3  |       2    1  |  6
#   9    2       |  3         5  |            1
#             1  |  8         6  |  4    9
# ---------------+---------------+---------------
#             8  |  1   356   2  |  9
#   7         9  |            4  |  1         8
#             6  |  7         8  |  2   345
# ---------------+---------------+---------------
#  134        2  |  6    78   9  |  5
#   8    67      |  2         3  |            9
#             5  |  4    1       |  3   2678
# #################  #################  #################
#               3   |  9     2     1   |  6
#   9     2     47  |  3           5   |  8           1
#         5     1   |  8           6   |  4          237
# ------------------+------------------+------------------
#               8   |  1           2   |  9   34567
#   7               |        6     4   |  1           8
#   1           6   |  7    359    8   |  2
# ------------------+------------------+------------------
#               2   |  6     8     9   |  5
#   8     6         |  2           3   |  7           9
#               5   |  4     1         |  3     28    6
# #################  #################  #################
# # When set to only change key values when length == 1:
# 4 8 3 |9 2 1 |6 5 7
# 9 6 7 |3 4 5 |8 2 1
# 2 5 1 |8 7 6 |4 9 3
# ------+------+------
# 5 4 8 |1 3 2 |9 7 6
# 7 2 9 |5 6 4 |1 3 8
# 1 3 6 |7 9 8 |2 4 5
# ------+------+------
# 3 7 2 |6 8 9 |5 1 4
# 8 1 4 |2 5 3 |7 6 9
# 6 9 5 |4 1 7 |3 8 2

#################  #################  #################
# STAFF SOLN:
#################  #################  #################
# Oh Fuck Me.. it was this easy?:

from utils import *

def only_choice(values):
    """Finalize all values that are the only choice for a unit.

    Go through all the units, and whenever there is a unit with a value
    that only fits in one box, assign the value to this box.

    Input: Sudoku in dictionary form.
    Output: Resulting Sudoku in dictionary form after filling in only choices.
    """
    for unit in unitlist:
        for digit in '123456789':
            dplaces = [box for box in unit if digit in values[box]]
            if len(dplaces) == 1:
                values[dplaces[0]] = digit
    return values

# # ## ########################################################################
# ########################################################################
########################################################################
# TESTING:

# values = {'D7': '9', 'F8': '1345', 'G4': '6', 'E8': '13456', 'F5': '3459', 'H2': '1467', 'A6': '147', 'D2': '345', 'H3': '47', 'B3': '47', 'D3': '8', 'A7': '6', 'A2': '4578', 'F4': '7', 'C7': '4', 'H7': '17', 'G1': '134', 'E5': '34569', 'E3': '49', 'H1': '8', 'A9': '57', 'F6': '8', 'B6': '5', 'D9': '34567', 'B4': '3', 'D1': '345', 'D8': '34567', 'A4': '49', 'C2': '257', 'D4': '1', 'I6': '47', 'I8': '24678', 'G6': '9', 'E6': '4', 'F7': '2', 'D5': '3456', 'H6': '3', 'A8': '5789', 'G3': '2', 'I2': '4679', 'F3': '6', 'E2': '123459', 'H5': '457', 'E4': '459', 'I7': '3', 'I4': '4', 'B8': '278', 'A3': '3', 'E7': '1', 'G2': '1347', 'G8': '1478', 'C3': '1', 'B5': '47', 'I9': '2467', 'G5': '478', 'D6': '2', 'F9': '345', 'H9': '9', 'C5': '79', 'I1': '46', 'I3': '5', 'G7': '5', 'A5': '2', 'E1': '7', 'G9': '47', 'C6': '6', 'C1': '25', 'C9': '2357', 'F2': '13459', 'B2': '24678', 'E9': '8', 'B9': '1', 'B1': '9', 'H4': '2', 'F1': '1345', 'H8': '1467', 'A1': '45', 'I5': '1', 'B7': '78', 'C8': '23579', 'C4': '8'}
values = {'D7': '9', 'F8': '1345', 'G4': '6', 'E8': '13456', 'F5': '3459', 'H2': '1', 'A6': '1', 'D2': '345', 'H3': '4', 'B3': '7', 'D3': '8', 'A7': '6', 'A2': '8', 'F4': '7', 'C7': '4', 'H7': '7', 'G1': '3', 'E5': '34569', 'E3': '9', 'H1': '8', 'A9': '7', 'F6': '8', 'B6': '5', 'D9': '6', 'B4': '3', 'D1': '5', 'D8': '7', 'A4': '9', 'C2': '5', 'D4': '1', 'I6': '7', 'I8': '8', 'G6': '9', 'E6': '4', 'F7': '2', 'D5': '3456', 'H6': '3', 'A8': '5', 'G3': '2', 'I2': '9', 'F3': '6', 'E2': '2', 'H5': '5', 'E4': '5', 'I7': '3', 'I4': '4', 'B8': '2', 'A3': '3', 'E7': '1', 'G2': '7', 'G8': '1', 'C3': '1', 'B5': '4', 'I9': '2', 'G5': '8', 'D6': '2', 'F9': '5', 'H9': '9', 'C5': '7', 'I1': '6', 'I3': '5', 'G7': '5', 'A5': '2', 'E1': '7', 'G9': '4', 'C6': '6', 'C1': '2', 'C9': '3', 'F2': '13459', 'B2': '6', 'E9': '8', 'B9': '1', 'B1': '9', 'H4': '2', 'F1': '1', 'H8': '6', 'A1': '4', 'I5': '1', 'B7': '8', 'C8': '9', 'C4': '8'}

def display(vals):
    """
    Display the values as a 2-D grid.
    Input: The sudoku in dictionary form
    Output: None
    """
    width = 1+max(len(vals[s]) for s in boxes)
    line = '+'.join(['-'*(width*3)]*3)
    for r in rows:
        print(''.join(vals[r+c].center(width)+('|' if c in '36' else '')
                      for c in cols))
        if r in 'CF': print(line)
    return



rows = 'ABCDEFGHI'
cols = '123456789'

# all possible concatenations of a letter
# s in str b w/ number t in str b
def cross(a, b):
	return [s+t for s in a for t in b]

# creating labels of the boxes
boxes = cross(rows, cols)

# and now for the units:
row_units = [cross(r, cols) for r in rows]
col_units = [cross(rows, c) for c in cols]
square_units = [cross(r, c) for r in ('ABC', 'DEF', 'GHI') for c in ('123','456','789')]

unitlist = row_units + col_units + square_units

# for ru in row_units: print(ru)
# print()
# for cu in col_units: print(cu)
# print()
# for su in square_units: print(su)
# print()
# for ul in unitlist: print(ul)
# print()

# NOTE: okay, now I finally understand this. What the below is saying is:
# Go through every box in all 3 units (horz, vert, square),
# for every box, go through every digit (0-9).
# if that digit is found no where else, assign it to that box.

for unit in unitlist:
	# print(unit)
	# print()
	for digit in '123456789':
		# print(digit)

		# dplaces = [box for box in unit if digit in values[box]]

        # the above line, written out:
		dplaces = []
		for box in unit:
			if digit in values[box]:
				dplaces.append(box)

		if len(dplaces) == 1:
			values[dplaces[0]] = digit

display(values)

# OUTPUT:

# first values:
#   45    8     3   |  9     2     1   |  6    5789   57
#   9     6     47  |  3     4     5   |  8    278    1
#   2    257    1   |  8     7     6   |  4   23579  2357
# ------------------+------------------+------------------
#  345   345    8   |  1    3456   2   |  9   34567 34567
#   7     2     9   |  5   34569   4   |  1   13456   8
#  1345 13459   6   |  7    3459   8   |  2    1345  345
# ------------------+------------------+------------------
#  134   1347   2   |  6     8     9   |  5    1478   47
#   8    1467   47  |  2     5     3   |  17    6     9
#   6     9     5   |  4     1     7   |  3     8     2

# second values:
#   4     8     3   |  9     2     1   |  6     5     7
#   9     6     7   |  3     4     5   |  8     2     1
#   2     5     1   |  8     7     6   |  4     9     3
# ------------------+------------------+------------------
#   5    345    8   |  1    3456   2   |  9     7     6
#   7     2     9   |  5   34569   4   |  1   13456   8
#   1   13459   6   |  7    3459   8   |  2    1345   5
# ------------------+------------------+------------------
#   3     7     2   |  6     8     9   |  5     1     4
#   8     1     4   |  2     5     3   |  7     6     9
#   6     9     5   |  4     1     7   |  3     8     2

########################################################################
# ########################################################################
# # ## ########################################################################
