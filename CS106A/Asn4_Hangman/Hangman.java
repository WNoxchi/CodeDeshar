/*
 * File: Hangman.java
 * Wayne H. Noxchi - CS106A Assignment 4
 * ------------------
 * This program will eventually play the Hangman game from
 * Assignment #4.
 * ------------------
 * S: 20-Jan-2016 15:04 |   F:
 */

import acm.graphics.*;
import acm.program.*;
import acm.util.*;

import java.awt.*;

public class Hangman extends ConsoleProgram {

    // Instance Variables
    private HangmanLexicon DoshLex = new HangmanLexicon();
    private String Dosh;
    private String Guess;
    private String guessDosh;
    private String tempDosh;
    private char guessLetter;
    private int Tries;
    private int checker;

    private HangmanCanvas canvas;

    public void init() {
        canvas = new HangmanCanvas();
        add(canvas);
    }

    public void run() {
        canvas.reset();
        playGame();
	}

    private void playGame() {
        Tries = 9;
        Dosh = DoshLex.getWord(rgen.nextInt(0, 9));
        println("Welcome to Hangman!");
        guessDosh = "";
        for (int i = 0; i < Dosh.length(); i++) {
            guessDosh += "-";
        }
        while (true) {
            checker = 0;
            tempDosh = "";
            for (int i = 0; i < Dosh.length(); i++) {
                if (guessLetter == Dosh.charAt(i)) {
                    tempDosh += Dosh.charAt(i);
                    checker++;
                } else {
                    tempDosh += guessDosh.charAt(i);
                }
            }
            guessDosh = tempDosh;
            canvas.displayWord(guessDosh);
            if (checker > 0) {
                println("That guess is correct.");
            } else {
                println("There are no " + Guess + "'s in the word");
                canvas.noteIncorrectGuess(guessLetter);
                Tries--;
            }
            if (Tries == 0) {
                println("You're completely hung.");
                println("The word was: " + Dosh);
                println("You. Lose.");
                println("\n Adam's feet were so close to the ground, if only he drank his milk and ate his vegetables as a child and did his taxes, he would have survived. Don't be like Adam...");
                // break;
                println("\n \n");
                run();
            }
            if (guessDosh.equals(Dosh)) {
                println("You guessed the word: " + Dosh);
                println("You Win.");

                println("\n \n");
                run();
                // break;
            }
            println("The word now looks like this: " + guessDosh);
            println("You have " + (Tries == 1 ? "only one guess" : Tries + " guesses") + " left.");
            Guess = readLine("Your guess: ");
            Guess = Guess.toUpperCase();
            guessLetter = Guess.charAt(0);
        }
    }

    // random gen for picking random word from lex
    RandomGenerator rgen = new RandomGenerator();
}


// computer selects secret word at random from list

// program prints dashes for each letter of word

// asks player for a letter

// if letter in word:   display word w/ all correctly guess letters

// if letter NOT in word:   player charged /w incorrect guess (max 8)

// -------------------------------------
// Choose Random word to use as secret word (from word list)

// Keep track of player's partially guessed word, updating

// Ask for guess -- keep track of guesses remaining -- detect ending

// Instance variable for HangmanLexicon

// both cases should work

// if guess != single letter: tell player illegal & ask new guess (no penalty)

// correct letter twice: no penalty; incorrect: still penalty

/*  FIRST VERSION


import acm.graphics.*;
import acm.program.*;
import acm.util.*;

import java.awt.*;

public class Hangman extends ConsoleProgram {

    // Instance Variables
    private HangmanLexicon DoshLex = new HangmanLexicon();
    private String Dosh;
    private String guessDosh = "";
    private String Guess;
    private char Letter;
    private int Tries = 8;

    public void run() {
        playGame();
	}

    private void playGame() {
        chooseDosh();
        askForLetter();
    }

    private void chooseDosh() {
        String Dosh = DoshLex.getWord(rgen.nextInt(0, 9));
        for (int i = 0; i < Dosh.length(); i++) {
            guessDosh += "-";
        }
    }

    private void askForLetter() {
        String Guess = readLine("Guess a letter: ");
        Guess.toUpperCase();
        char Letter = Guess.charAt(0);
        legalGuessCheck(Guess, Letter);
        checkLetter();
        println("The word now looks like this: " + guessDosh);
        println("You have " + Tries + " guesses left.");
        askForLetter();
    }

    private void legalGuessCheck(String Guess, char Letter) {
        if (Guess.length() != 1 || !Character.isLetter(Letter)) {    //  idk if this should be Character.isLetter(letter) or Letter.isLetter(Letter)
            println("Your guess can only be a single letter.\n");
            askForLetter();                                         //   or something strange like that
        }
    }

    private void checkLetter() {
        int check = 0;
        String tempDosh = "";
        println("Your guess: " + Letter);
        for (int i = 0; i < Dosh.length(); i++) {
            if (Dosh.charAt(i) == Letter) {
                tempDosh += Letter;
                check++;
            } else {
                tempDosh += guessDosh;
            }
            guessDosh = tempDosh;
        }
        if (check == 0) {
            Tries--;
            println("There are no " + Letter + "'s in the word");
            if (Tries == 0) {
                Loss();
            }
        } else {
            println("That guess is correct");
            if (guessDosh.equals(Dosh)) Win();
            askForLetter();
        }
    }

    private void Loss() {
        println("You're completely hung.");
        println("The word was: " + Dosh + ".");
        println("You Lose.");
    }

    private void Win() {
        println("You guessed the word: " + Dosh);
        println("You Win.");
    }

    // random gen for picking random word from lex
    RandomGenerator rgen = new RandomGenerator();
}
 */
