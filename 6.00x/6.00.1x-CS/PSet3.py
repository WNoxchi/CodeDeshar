# 6.00.1x   -   PSet 3
# Wayne H. Noxchi | 29-Jan-2016 14:27
# ----------------------------------------------------------
# 3.5: Hangman Part II: The Game/Complex Tests
# Start: 29-Jan-2016 21:22 | Stop: 21:32 - 23:23 | Fin: 30-Jan-2016 00:35
# ----------------------------------------------------------

def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the
      partially guessed word so far, as well as letters that the
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...

    # guess = str
    mistakesMade = 0
    lettersGuessed = []

    print ("Welcome to the game, Hangman!")
    print ("I am thinking of a word that is ") + str(wordLength(secretWord)) + (" letters long.")
    print ("------------")

    while mistakesMade < 8:
        if isWordGuessed(secretWord, lettersGuessed):
            return("Congratulations, you win!")
        print ("You have %i guesses left.") % (8 - mistakesMade)
        print ("Available letters: ") + getAvailableLetters(lettersGuessed)
        guess = raw_input("Please guess a letter: ").lower()
        if guess in secretWord:
            if guess in lettersGuessed:
                print ("Oops! You've already guessed that letter: ") + getGuessedWord(secretWord, lettersGuessed)
                print ("------------")
            else:
                lettersGuessed.append(guess)
                print ("Good guess: ") + getGuessedWord(secretWord, lettersGuessed)
                print ("------------")
        else:
            if guess in lettersGuessed:
                print ("Oops! You've already guessed that letter: ") + getGuessedWord(secretWord, lettersGuessed)
                print ("------------")
            else:
                lettersGuessed.append(guess)
                mistakesMade += 1
                print ("Oops! That letter is not in my word: ") + getGuessedWord(secretWord, lettersGuessed)
                print ("------------")
    return ("Sorry, you ran out of guesses. The word was ") + secretWord + (".")

def wordLength(word):
    return len(word)

# ----------------------------------------------------------
# 3.4: Hangman Part 1: Printing Out All Available Letters
# Start: 29-Jan-2016 20:43 | 29-Jan-2016 20:46
# ----------------------------------------------------------

def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    import string
    letterOutput = ""
    for letter in string.ascii_lowercase:
        if letter in lettersGuessed:
            continue
        else: letterOutput += letter
    return letterOutput

# ----------------------------------------------------------
# 3.3: Hangman Part 1: Printing Out the User's Guess
# Start: 29-Jan-2016 20:24  |   Finish: 29-Jan-2016 20:38
# ----------------------------------------------------------

def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...

    # secretWord = "hello"
    # lettersGuessed = "el"
    ouText = ""
    tempText = ""
    for i in secretWord:
        ouText += "_ "
    for i in secretWord:
        if i in lettersGuessed:
            tempText += i + " "
        else: tempText += "_ "
        ouText = tempText
    # print ouText
    return ouText

# test output:
#>>> _ e l l _

# OLD/GARBAGE:
    # ouText = []
    # tempText = []
    # for word in secretWord:
    #     outText += "_ "
    #     for letter in lettersGuessed:
    #         if word in lettersGuessed:
    #             tempText += word
    #         else: tempText += "_ "
    #     outText = tempText
    # return ouText

# --------------------------------------
# 3.2: Hangman Part 1: Is the Word Guessed
# Start: 29-Jan-2016 15:29 | Stop: 16:13 - 19:57 | Fin: 29-Jan-2016 20:21
# --------------------------------------

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...

# Method Cxa':
    if lettersGuessed == []:
        return False
    check = False
    for i in range(len(secretWord)):
        if secretWord[i] in lettersGuessed:
            check = True
        else:
            return False
    return check

# Method Shi':
    if lettersGuessed == []:
        return False

    for word in secretWord:
        resultList = []
        for letter in lettersGuessed:
            result = ( word == letter )     # result equals boolean outcome
            resultList.append(result)
        if True in resultList:
            continue
        else return False
    return True

# --------------------------------------
# 3.1: Radiation Exposure
# Start: 29-Jan-2016 14:28 | Finish: 29-Jan-2016 14:37
# --------------------------------------

# def f(x):         # use for testing
#     import math
#     return 10*math.e**(math.log(0.5)/5.27 * x)

def radiationExposure(start, stop, step):
    '''
    Computes and returns the amount of radiation exposed
    to between the start and stop times. Calls the
    function f (defined for you in the grading script)
    to obtain the value of the function at any point.

    start: integer, the time at which exposure begins
    stop: integer, the time at which exposure ends
    step: float, the width of each rectangle. You can assume that
      the step size will always partition the space evenly.

    returns: float, the amount of radiation exposed to
      between start and stop times.
    '''
    # FILL IN YOUR CODE HERE...
    exposure = 0
    while start < stop:
        stepExposure = f(start) * step
        exposure += stepExposure
        start += step
    print exposure

radiationExposure(start, stop, step)    # do not enter this line into grader

## Test Cases:
#radiationExposure(0, 5, 1)
#>>> 39.1031878433
#radiationExposure(40, 100, 1.5)
#>>> 0.434612356115
