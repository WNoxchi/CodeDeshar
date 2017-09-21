# Wayne Nixalo - 2017-Sep-21 17:50-18:16 - UD359

import numpy as np
from pandas import DataFrame, Series


def avg_medal_count():
    '''
    Using the dataframe's apply method, create a new Series called
    avg_medal_count that indicates the average number of gold, silver,
    and bronze medals earned amongst countries who earned at
    least one medal of any kind at the 2014 Sochi olympics.  Note that
    the countries list already only includes countries that have earned
    at least one medal. No additional filtering is necessary.

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

    olympic_medal_counts = {'country_name':countries,
                            'gold': Series(gold),
                            'silver': Series(silver),
                            'bronze': Series(bronze)}
    df = DataFrame(olympic_medal_counts)

    # YOUR CODE HERE
    # avg_medal_count = df['country_name'].applymap(lambda x: x > 0)
    # print(df)
    # print(df['country_name'])
    # print(df['country_name'].map(lambda x: x == 'Norway'))
    # print(df.applymap(lambda x: x == 'Norway'))
    # print(df[df.country_name == 'Norway'])

    # print(df[df.gold > 1])
    # print(df[(df.gold >= 1) | (df.silver >= 1)])

    # avg_medal_count = df[df.country_name and ((df.gold >= 1) or (df.silver >= 1) or (df.bronze >= 1))]
    # print(avg_medal_count)

    # avg_medal_count = df[(df.gold >= 1)|(df.silver >= 1)|(df.bronze >= 1)]
    # print(avg_medal_count)

    avg_medal_count = df[['gold','silver','bronze']].apply(np.mean)
    # print(help(df.apply))
    # print(avg_medal_count)

    return avg_medal_count

# avg_medal_count()


# # OUTPUT:
# Good job! Your code worked perfectly.
# Output by your program below.
#
# gold      3.807692
# silver    3.730769
# bronze    3.807692
