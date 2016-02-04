/*
 * File: Yahtzee.java
 * ---------------------------------------------------
 * This program will eventually play the Yahtzee game.
 * ---------------------------------------------------
 * CS106A Assignment 5
 * Wayne H. Noxchi	| S: 01-Feb-2016 13:49 - 14:30 | S: 02-Feb-2016 09:00 - 11:00
 *					| S: 03-Feb-2016 11:25 - 14:29
 					| Debugging: 04-Feb-2016 11:47 - 12:30  --- Fin.
 */

import acm.io.*;
import acm.program.*;
import acm.util.*;
// needed for object version of arraylists:
import java.util.*;

public class Yahtzee extends GraphicsProgram implements YahtzeeConstants {
	public void run() {
		setupPlayers();
		initDisplay();
		playGame();
	}

	/**
	 * Prompts the user for information about the number of players, then sets up the
	 * players array and number of players.
	 */
	private void setupPlayers() {
		nPlayers = chooseNumberOfPlayers();

		/* Set up the players array by reading names for each player. */
		playerNames = new String[nPlayers];
		for (int i = 0; i < nPlayers; i++) {
			/* IODialog is a class that allows us to prompt the user for information as a
			 * series of dialog boxes.  We will use this here to read player names.
			 */
			IODialog dialog = getDialog();
			playerNames[i] = dialog.readLine("Enter name for player " + (i + 1));
		}
	}

	/**
	 * Prompts the user for a number of players in this game, reprompting until the user
	 * enters a valid number.
	 *
	 * @return The number of players in this game.
	 */
	private int chooseNumberOfPlayers() {
		/* See setupPlayers() for more details on how IODialog works. */
		IODialog dialog = getDialog();

		while (true) {
			/* Prompt the user for a number of players. */
			int result = dialog.readInt("Enter number of players");

			/* If the result is valid, return it. */
			if (result > 0 && result <= MAX_PLAYERS)
				return result;

			dialog.println("Please enter a valid number of players.");
		}
	}

	/**
	 * Sets up the YahtzeeDisplay associated with this game.
	 */
	private void initDisplay() {
		display = new YahtzeeDisplay(getGCanvas(), playerNames);
	}

	/**
	 * Actually plays a game of Yahtzee.  This is where you should begin writing your
	 * implementation.
	 */
	private void playGame() {
		/* You fill this in! */
		scoreCard = new int[N_CATEGORIES][nPlayers];
		for ( int turns = 0; turns < N_SCORING_CATEGORIES; turns++ ) {
			for ( int player = 0; player < nPlayers; player++ ) {
				startFirstRoll(player);
				// after 1st, player does their 2nd & 3rd rolls:
				// secondThirdRoll();
				selectCategory(player);
			}
		}
		totalScore();
		calcWin();
	}

	private void startFirstRoll(int player) {
		display.printMessage(playerNames[player] + "'s turn! Click \"Roll Dice\" button to roll the dice.");
		display.waitForPlayerToClickRoll(player);
		for ( int dice = 0; dice < N_DICE; dice++ ) {
			diceRoll[dice] = rgen.nextInt(1, 6);
		}
		display.displayDice(diceRoll);
	}

	private void secondThirdRoll() {
		for ( int i = 0; i < 2; i++ ) {
			display.printMessage("Select the dice you wish to re-roll and click \"Roll Again\".");
			display.waitForPlayerToSelectDice();
			for ( int dice = 0; dice < N_DICE; dice++ ) {
				if ( display.isDieSelected(dice) ) {
					diceRoll[dice] = rgen.nextInt(1, 6);
				}
			}
			display.displayDice(diceRoll);
		}
	}

	private void selectCategory(int player) {
		display.printMessage("Select a category for this roll.");
		while ( true ) {		// is the while loop necessary? --- TEST THIS
			int category = display.waitForPlayerToSelectCategory();
			if ( checkCategory(player, category) ) {
				calcCatScore(player, category);
				break;
			}
		}
		// This is a stub to be replaced later:
		// if ( YahtzeeMagicStub.checkCategory(diceRoll, category) == true ) {
		// 	display.updateScorecard( category, player, scoreHandler(category) );
		// } else {
		// 	display.updateScorecard( category, player, 0 );
		// }
	}

	private boolean checkCategory(int player, int category) {
		if ( scoreCard[category][player] == 0 && category != UPPER_SCORE && category != UPPER_BONUS
				&& category != LOWER_SCORE && category != TOTAL ) {
			return true;
		}
		return false;
	}

	private void calcCatScore(int player, int category) {
		int score = 0;
		if ( category <= SIXES ) {
			for ( int dice = 0; dice < N_DICE; dice++) {
				if ( diceRoll[dice] == category + 1 ) {
					score += category + 1;										// CLEAR
				}
			}
		}
		else if ( category == THREE_OF_A_KIND || category == FOUR_OF_A_KIND ) {
			if( checkSpecialCat(category) ) {
				for ( int dice = 0; dice < N_DICE; dice++) {
					score += diceRoll[dice] + 1;								// CLEAR
				}
			} else {
				score = 0;
			}
		}
		else if ( category == FULL_HOUSE ) {
		   if ( checkSpecialCat(category) ) {
			   score = 25;
		   } else {
			   score = 0;
		   }
	   }
	   else if ( category == SMALL_STRAIGHT ) {
		   if ( checkSpecialCat(category) ) {
			   score = 30;
		   } else {
			   score = 0;
		   }
	   }
	   else if ( category == LARGE_STRAIGHT ) {
		   if ( checkSpecialCat(category) ) {
			   score = 40;
		   } else {
			   score = 0;
		   }
	   }
	   else if ( category == YAHTZEE ) {
		   if ( checkSpecialCat(category) ) {
			   score = 50;
		   } else {
			   score = 0;
		   }
	   }
	   else if ( category == CHANCE ) {
		   for ( int dice = 0; dice < N_DICE; dice++ ) {
			   score += diceRoll[dice];
		   }
	   }

	   display.updateScorecard(category, player, score);   						// CLEAR
	   scoreCard[category][player] = score;										// CLEAR
	   score = 0;
	}

	private boolean checkSpecialCat(int category) {
		ArrayList <Integer> one = new ArrayList <Integer>();
		ArrayList <Integer> two = new ArrayList <Integer>();
		ArrayList <Integer> three = new ArrayList <Integer>();
		ArrayList <Integer> four = new ArrayList <Integer>();
		ArrayList <Integer> five = new ArrayList <Integer>();
		ArrayList <Integer> six = new ArrayList <Integer>();

		for ( int dice = 0; dice < N_DICE; dice++ ) {
			if ( diceRoll[dice] == 1 ) {
				one.add(1);
			}
			else if ( diceRoll[dice] == 2) {
				two.add(1);
			}
			else if ( diceRoll[dice] == 3) {
				three.add(1);
			}
			else if ( diceRoll[dice] == 4) {
				four.add(1);
			}
			else if ( diceRoll[dice] == 5) {
				five.add(1);
			}
			else if ( diceRoll[dice] == 6) {
				six.add(1);
			}
		}

		if ( category == THREE_OF_A_KIND ) {
			if ( one.size() >= 3 || two.size() >= 3 || three.size() >= 3 || four.size() >= 3 || five.size() >= 3 || six.size() >= 3 ) {
				return true;
			}
		}
		else if ( category == FOUR_OF_A_KIND ) {
			if ( one.size() >= 4 || two.size() >= 4 || three.size() >= 4 || four.size() >= 4 || five.size() >= 4 || six.size() >= 4 ) {
				return true;
			}
		}
		else if ( category == FULL_HOUSE ) {
			if ( one.size() >= 3 || two.size() >= 3 || three.size() >= 3 || four.size() >= 3 || five.size() >= 3 || six.size() >= 3 ) {
				if ( one.size() >= 2 || two.size() >= 2 || three.size() >= 2 || four.size() >= 2 || five.size() >= 2 || six.size() >= 2 ) {
					return true;
				}
			}
		}
		else if ( category == SMALL_STRAIGHT ) {
			if ( one.size() >= 1 && two.size() >= 1 && three.size() >= 1 && four.size() >= 1 ) {
				return true;
			}
			else if ( two.size() >= 1 && three.size() >= 1 && four.size() >= 1 && five.size() >= 1 ) {
				return true;
			}
			else if ( three.size() >= 1 && four.size() >= 1 && five.size() >= 1 && six.size() >= 1 ) {
				return true;
			}
		}
		else if ( category == LARGE_STRAIGHT ) {
			if ( one.size() >= 1 && two.size() >= 1 && three.size() >= 1 && four.size() >= 1 && five.size() >= 1 ) {
				return true;
			}
			else if ( two.size() >= 1 && three.size() >= 1 && four.size() >= 1 && five.size() >= 1 && six.size() >= 1 ) {
				return true;
			}
		}
		else if ( category == YAHTZEE ) {
			if ( one.size() == 1 && two.size() == 1 && three.size() == 1 && four.size() == 1 && five.size() == 1 && six.size() == 1 ) {
				return true;
			}
		}
		else if ( category == CHANCE ) {
			return true;
		}

		return false;
	}

	private void totalScore() {
		int result = 0;
		for ( int player = 0; player <nPlayers; player++ ) {
			for ( int category = 0; category < SIXES; category++ ) {
				result += scoreCard[category][player];
			}
			scoreCard[UPPER_SCORE][player] = result;
			display.updateScorecard(UPPER_SCORE, player, result);

			if ( scoreCard[UPPER_SCORE][player] > 63 ) {
				scoreCard[UPPER_BONUS][player] = 35;
				display.updateScorecard(UPPER_BONUS, player, 35);
			} else {
				scoreCard[UPPER_BONUS][player] = 0;
				display.updateScorecard(UPPER_BONUS, player, 0);
			}

			result = 0;
			for ( int category = 8; category < CHANCE; category++ ) {
				result += scoreCard[category][player];
			}

			scoreCard[LOWER_SCORE][player] = result;
			display.updateScorecard(LOWER_SCORE, player, result);

			scoreCard[TOTAL][player] = scoreCard[UPPER_SCORE][player] + scoreCard[UPPER_BONUS][player] + scoreCard[LOWER_SCORE][player];
			display.updateScorecard(TOTAL, player, scoreCard[TOTAL][player]);

			result = 0;
		}
	}

	private void calcWin() {
		int winner = 0;
		int score = 0;

		for ( int player = 0; player < nPlayers; player++ ) {
			if ( scoreCard[TOTAL][player] > score ) {
				score = scoreCard[TOTAL][player];
				winner = player;
			}
		}

		display.printMessage("Congratulations, " + playerNames[winner] + ", you're the winner with a total score of " + score);
	}

	// private int scoreHandler(int category) {
	//     switch (category) {
	//         case ONES: return
	//         case TWOS:
	// 		case THREES:
	// 		case FOURS:
	// 		case FIVES:
	// 		case SIXES:
	// 		case THREE_OF_A_KIND:
	// 		case FOUR_OF_A_KIND:
	// 		case FULL_HOUSE:
	// 		case SMALL_STRAIGHT:
	// 		case LARGE_STRAIGHT:
	// 		case YAHTZEE:
	// 		case CHANCE:
	//         default: return 9999;
	//     }
	// }

	/* Private instance variables */
	private int[][] scoreCard;
	private int[] diceRoll = new int[N_DICE];

	private int nPlayers;
	private String[] playerNames;
	private YahtzeeDisplay display;

	private RandomGenerator rgen = new RandomGenerator();
}
