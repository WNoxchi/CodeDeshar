# 6.00.1x Problem Set 4: A Word Game
# Wayne H. Noxchi
# S: 09-Feb-2016 14:11 | F: 09-Feb-2016 14:22  4.7
# S: 09-Feb-2016 14:25 - 15:03 | S: 10-Feb-2016 10:35 | F: 10-Feb-2016 11:27   4.8
# S: 10-Feb-2016 11:30 - 12:30 | S: 12:55 | F: 10-Feb-2016 14:15    4.9

from ps4a import *
import time


#
#
# Problem #6: Computer chooses a word
# S: 09-Feb-2016 14:11 | F: 09-Feb-2016 14:22
#
def compChooseWord(hand, wordList, n):
    """
    Given a hand and a wordList, find the word that gives
    the maximum value score, and return it.

    This word should be calculated by considering all the words
    in the wordList.

    If no words in the wordList can be made from the hand, return None.

    hand: dictionary (string -> int)
    wordList: list (string)
    n: integer (HAND_SIZE; i.e., hand size required for additional points)

    returns: string or None
    """
    # BEGIN PSEUDOCODE <-- Remove this comment when you code this function; do your coding within the pseudocode (leaving those comments in-place!)
    # Create a new variable to store the maximum score seen so far (initially 0)
    MAX_SCORE = 0
    handCopy = hand.copy()

    # Create a new variable to store the best word seen so far (initially None)
    bestWord = None

    # For each word in the wordList
    for word in wordList:

        # If you can construct the word from your hand
        # (hint: you can use isValidWord, or - since you don't really need to test if the word is in the wordList - you can make a similar function that omits that test)
        if isValidWord(word, handCopy, wordList) == True:
            # Find out how much making that word is worth
            wordScore = getWordScore(word, n)
            # If the score for that word is higher than your best score
            if wordScore > MAX_SCORE:
                # Update your best score, and best word accordingly
                MAX_SCORE = wordScore
                bestWord = word

    # return the best word you found.
    return bestWord
    # return the best word you found.
    return bestWord


#
# Problem #7: Computer plays a hand
# S: 09-Feb-2016 14:25 - 15:03
# S: 10-Feb-2016 10:35 | F: 10-Feb-2016 11:27
#
def compPlayHand(hand, wordList, n):
    """
    Allows the computer to play the given hand, following the same procedure
    as playHand, except instead of the user choosing a word, the computer
    chooses it.

    1) The hand is displayed.
    2) The computer chooses a word.
    3) After every valid word: the word and the score for that word is
    displayed, the remaining letters in the hand are displayed, and the
    computer chooses another word.
    4)  The sum of the word scores is displayed when the hand finishes.
    5)  The hand finishes when the computer has exhausted its possible
    choices (i.e. compChooseWord returns None).

    hand: dictionary (string -> int)
    wordList: list (string)
    n: integer (HAND_SIZE; i.e., hand size required for additional points)
    """
    # TO DO ... <-- Remove this comment when you code this function
    totalScore = 0
    handCopy = hand.copy()
    bestWord = compChooseWord(handCopy, wordList, n)    # returns best word computed. already valid.

# displayHand() prints & doesn't return data. put it under a comma'd print statement to tack its output on.
    while bestWord != None:
        print "Current Hand: ",
        displayHand(handCopy)   # display hand
        totalScore += getWordScore(bestWord, n)
        # totalScore += score
        print "\"", bestWord, "\" earned ", getWordScore(bestWord, n), " points. Total: ", totalScore, " points\n"
        handCopy = updateHand(handCopy, bestWord)
        bestWord = compChooseWord(handCopy, wordList, n)

        # when no more words can be generated:
        # case for letters left over and not:
    if bestWord == None:
        if sum(handCopy.values()) > 0:
            print "Current Hand: ",
            displayHand(handCopy)
            print "Total score: ", totalScore, " points."
        else:
            print "Total score: ", totalScore, " points."


#
# Problem #8: Playing a game
# S: 10-Feb-2016 11:30 - 12:30 | S: 12:55 | F: 10-Feb-2016 14:15
#

def playGame(wordList):
    """
    Allow the user to play an arbitrary number of hands.

    1) Asks the user to input 'n' or 'r' or 'e'.
        * If the user inputs 'e', immediately exit the game.
        * If the user inputs anything that's not 'n', 'r', or 'e', keep asking them again.

    2) Asks the user to input a 'u' or a 'c'.
        * If the user inputs anything that's not 'c' or 'u', keep asking them again.

    3) Switch functionality based on the above choices:
        * If the user inputted 'n', play a new (random) hand.
        * Else, if the user inputted 'r', play the last hand again.

        * If the user inputted 'u', let the user play the game
          with the selected hand, using playHand.
        * If the user inputted 'c', let the computer play the
          game with the selected hand, using compPlayHand.

    4) After the computer or user has played the hand, repeat from step 1

    wordList: list (string)
    """
    # TO DO... <-- Remove this comment when you code this function
    # print "playGame not yet implemented." # <-- Remove this when you code this function
    handCopy = {}
    hand = None

    choiceCxa = raw_input("Enter n to deal a new hand, r to replay the last hand, or e to end game: ")
    print

    while choiceCxa != 'e':
        if choiceCxa == 'n':
            hand = dealHand(HAND_SIZE)
            handCopy = hand.copy()
        elif choiceCxa == 'r':
            if handCopy == {}:
                print "You have not played a hand yet. Please play a new hand first!"
                choiceCxa = raw_input("Enter n to deal a new hand, r to replay the last hand, or e to end game: ")
                print
                continue
        else:
            print "Invalid command.\n"
            choiceCxa = raw_input("Enter n to deal a new hand, r to replay the last hand, or e to end game: ")
            print
            continue

        choiceShi = raw_input("Enter u to have yourself play, c to have the computer play: ")
        while choiceShi != 'u' and choiceShi != 'c':
            print "Invalid command.\n"
            choiceShi = raw_input("Enter u to have yourself play, c to have the computer play: ")

        if choiceShi == 'u':
            playHand(handCopy, wordList, HAND_SIZE)
        else:
            compPlayHand(handCopy, wordList, HAND_SIZE)

        choiceCxa = raw_input("Enter n to deal a new hand, r to replay the last hand, or e to end game: ")
        print


    ## FIRST TRY:
    # n = HAND_SIZE
    # handCopy = {}
    # choiceCxa = None
    # choiceShi = None
    # # runFlag = True
    #
    # # while runFlag == True:
    #
    #
    # choiceCxa = raw_input("Enter n to deal a new hand, r to replay the last hand, or e to end game: ")
    # while choiceCxa != "n" and choiceCxa != "r" and choiceCxa != "e":
    #     if choiceCxa == "e":
    #         break
    #
    # while choiceShi != "u" and choiceShi != "c":
    #     choiceShi = raw_input("Enter u to have yourself play, c to have the computer play: ")
    #
    # if choiceShi == "u":
    #     if choiceCxa == "n":
    #         hand = dealHand(HAND_SIZE)
    #         handCopy = hand.copy()
    #         playHand(handCopy, wordList, n)
    #
    #     elif choiceCxa == "r":
    #         if handCopy == {}:
    #             print "You have not played a hand yet. Please play a new hand first!"
    #         else:
    #             playHand(handCopy, wordList, HAND_SIZE)
    #
    #     elif choiceCxa == "e":
    #         return None
    #         # handCopy = {}
    #         # runFlag = False
    #         # break
    #
    #     else:
    #         print "Invalid command."
    #
    # elif choiceShi == "c":
    #     if choiceCxa == "n":
    #         hand = dealHand(HAND_SIZE)
    #         handCopy = hand.copy()
    #         compPlayHand(handCopy, wordList, HAND_SIZE)
    #
    #     elif choiceCxa == "r":
    #         if handCopy == {}:
    #             print "You have not played a hand yet. Please play a new hand first!"
    #         else:
    #             compPlayHand(handCopy, wordList, HAND_SIZE)
    #
    #     elif choiceCxa == "e":
    #         return None
    #         # handCopy = {}
    #         # runFlag = False
    #         # break
    #
    #     else:
    #         print "Invalid command."

#
# Build data structures used for entire session and play game
#
# if __name__ == '__main__':
#     wordList = loadWords()
#     playGame(wordList)
