# 6.00.2x Intro to Data Science
# WH Noxchi - 29-Mar-2016 19:53

def noReplacementSimulation(numTrials):
    '''
    Runs numTrials trials of a Monte Carlo simulation
    of drawing 3 balls out of a bucket containing
    3 red and 3 green balls. Balls are not replaced once
    drawn. Returns the a decimal - the fraction of times 3
    balls of the same color were drawn.
    '''
    # Your code here
    def pickBall():
        balls = ['r','r','r','g','g','g']

        choice1 = random.choice(balls)
        balls.remove(choice1)
        choice2 = random.choice(balls)
        balls.remove(choice2)
        choice3 = random.choice(balls)
        balls.remove(choice3)

        if choice1 == choice2 and choice2 == choice3:
            return 1
        else:
            return 0;

    trials = 10000
    same = 0
    count = 0

    for i in range(trials):
        same += pickBall()
        count += 1

    average = same / float(count)

    return average
