# WNixalo - 2017-Sep-21 18:19-18:24

import numpy as np
from pandas import DataFrame, Series

# def numpy_dot():
def points():
    '''
    Imagine a point system in which each country is awarded 4 points for each
    gold medal,  2 points for each silver medal, and one point for each
    bronze medal.

    Using the numpy.dot function, create a new dataframe called
    'olympic_points_df' that includes:
        a) a column called 'country_name' with the country name
        b) a column called 'points' with the total number of points the country
           earned at the Sochi olympics.

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

    # YOUR CODE HERE
    scale = [4,2,1]
    olympic_points_df = DataFrame({'country_name':countries,
                            'points': np.dot(scale, [gold, silver, bronze])})

    return olympic_points_df

# Course Solution:
# olympic_medal_counts = {'country_name': Series(countries), 'gold': Series(gold),
#                         'silver': Series(silver), 'bronze': Series(bronze)}
# olympic_medal_counts_df = DataFrame(olympic_medal_counts)
#
# medal_counts = olympic_medal_counts_df[['gold', 'silver', 'bronze']]
# points = np.dot(medal_counts, [4,2,1])
#
# olympic_points = {'country_name': Series(countries), 'points': Series(points)}
# olympic_points_df = DataFrame(olympic_points)

# OUTPUT:
# Good job! Your code worked perfectly.
# Output by your program below.
#
#       country_name  points
# 0     Russian Fed.      83
# 1           Norway      64
# 2           Canada      65
# 3    United States      62
# 4      Netherlands      55
# 5          Germany      49
# 6      Switzerland      32
# 7          Belarus      21
# 8          Austria      37
# 9           France      31
# 10          Poland      19
# 11           China      22
# 12           Korea      20
# 13          Sweden      28
# 14  Czech Republic      18
# 15        Slovenia      16
# 16           Japan      15
# 17         Finland      11
# 18   Great Britain       8
# 19         Ukraine       5
# 20        Slovakia       4
# 21           Italy      10
# 22          Latvia       6
# 23       Australia       5
# 24         Croatia       2
# 25      Kazakhstan       1
