# https://www.youtube.com/watch?v=QPZ0pIK_wsc
# fizzbuzz - Wayne H Nixalo 2017

for i in range(1,101):
    print("{}{}{}".format('Fizz' * ((i % 3) == 0), 'Buzz' * ((i % 5) == 0),
                          str(i) * ((i % 3) != 0 and (i % 5) != 0)))
