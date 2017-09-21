# Wayne Nixalo - 2017-Sep-21 17:26 - UD359 Udacity Intro to Data Science

from pandas import DataFrame, Series

#################
# Syntax Reminder:
#
# The following code would create a two-column pandas DataFrame
# named df with columns labeled 'name' and 'age':
#
# people = ['Sarah', 'Mike', 'Chrisna']
# ages  =  [28, 32, 25]
# df = DataFrame({'name' : Series(people),
#                 'age'  : Series(ages)})

def create_dataframe():
    '''
    Create a pandas dataframe called 'olympic_medal_counts_df' containing
    the data from the table of 2014 Sochi winter olympics medal counts.

    The columns for this dataframe should be called
    'country_name', 'gold', 'silver', and 'bronze'.

    There is no need to  specify row indexes for this dataframe
    (in this case, the rows will automatically be assigned numbered indexes).

    You do not need to call the function in your code when running it in the
    browser - the grader will do that automatically when you submit or test it.
    '''

    countries = ['Russian Fed.', 'Norway', 'Canada', 'United States',
                 'Netherlands', 'Germany', 'Switzerland', 'Belarus',
                 'Austria', 'France', 'Poland', 'China', 'Korea',
                 'Sweden', 'Czech Republic', 'Slovenia', 'Japan',
                 'Finland', 'Great Britain', 'Ukraine', 'Slovakia',
                 'Italy', 'Latvia', 'Australia', 'Croatia', 'Kazakhstan']

    gold = [13, 11, 10, 9, 8, 8, 6, 5, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0]
    silver = [11, 5, 10, 7, 7, 6, 3, 0, 8, 4, 1, 4, 3, 7, 4, 2, 4, 3, 1, 0, 0, 2, 2, 2, 1, 0]
    bronze = [9, 10, 5, 12, 9, 5, 2, 1, 5, 7, 1, 2, 2, 6, 2, 4, 3, 1, 2, 1, 0, 6, 2, 1, 0, 1]

    # your code here
    import pandas as pd

    # data = dict()
    # data['countries'] = countries; data['gold'] = gold;
    # data['silver'] = silver; data['bronze'] = bronze
    # olympic_medal_counts_df = pd.DataFrame(data)

    olympic_medal_counts_df = pd.DataFrame(
                                {'country': countries, 'gold': gold, 'silver': silver,
                                 'bronze': bronze})

    return olympic_medal_counts_df


# OUTPUT:
# Good job! Your code worked perfectly.
# Output by your program below.
#
#     bronze         country  gold  silver
# 0        9    Russian Fed.    13      11
# 1       10          Norway    11       5
# 2        5          Canada    10      10
# 3       12   United States     9       7
# 4        9     Netherlands     8       7
# 5        5         Germany     8       6
# 6        2     Switzerland     6       3
# 7        1         Belarus     5       0
# 8        5         Austria     4       8
# 9        7          France     4       4
# 10       1          Poland     4       1
# 11       2           China     3       4
# 12       2           Korea     3       3
# 13       6          Sweden     2       7
# 14       2  Czech Republic     2       4
# 15       4        Slovenia     2       2
# 16       3           Japan     1       4
# 17       1         Finland     1       3
# 18       2   Great Britain     1       1
# 19       1         Ukraine     1       0
# 20       0        Slovakia     1       0
# 21       6           Italy     0       2
# 22       2          Latvia     0       2
# 23       1       Australia     0       2
# 24       0         Croatia     0       1
# 25       1      Kazakhstan     0       0
