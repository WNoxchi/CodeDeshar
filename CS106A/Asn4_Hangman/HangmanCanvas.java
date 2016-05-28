/*
 * File: HangmanCanvas.java
 * ------------------------
 * This file keeps track of the Hangman display.
 */

import acm.graphics.*;

public class HangmanCanvas extends GCanvas {

	private GLabel WORD;
	private GLabel GUESSES;

	private static final int APP_WIDTH = 350;
	private static final int APP_HEIGHT = 450;

	private static final int xWORD = APP_WIDTH / 9;
	private static final int yWORD = APP_HEIGHT * 23 / 24;

	private String wrongGuesses = "";
	private int checker = 0;
	private int part = 0;

/** Resets the display so that only the scaffold appears */
	public void reset() {
		removeAll();
		part = 0;
		checker = 0;
		erectScaffold();
	}

/**
 * Updates the word on the screen to correspond to the current
 * state of the game.  The argument string shows what letters have
 * been guessed so far; unguessed letters are indicated by hyphens.
 */
	public void displayWord(String word) {
		if (getElementAt(xWORD, yWORD) != null) remove(getElementAt(xWORD, yWORD));
		WORD = new GLabel(word);
		WORD.setFont("Times-20");
		add(WORD, xWORD, yWORD);
	}

/**
 * Updates the display to correspond to an incorrect guess by the
 * user.  Calling this method causes the next body part to appear
 * on the scaffold and adds the letter to the list of incorrect
 * guesses that appears at the bottom of the window.
 */
	public void noteIncorrectGuess(char letter) {
		addPart();
		checker = 0;
		for (int i = 0; i < wrongGuesses.length(); i++) {
			if (letter == wrongGuesses.charAt(i)) checker++;
		}
		if (checker == 0) {
			wrongGuesses += letter;
		}
		if (getElementAt(xWORD, yWORD + 18) != null) remove(getElementAt(xWORD, yWORD + 18));
		GUESSES = new GLabel(wrongGuesses);
		GUESSES.setFont("Times-16");
		add(GUESSES, xWORD, yWORD + 18);
	}

	private void addPart() {
		if (part == 1) {
			add(new GOval(APP_WIDTH/2 - HEAD_RADIUS, APP_HEIGHT/8, HEAD_RADIUS*2, HEAD_RADIUS*2));
		}

		if (part == 2) {
			add(new GLine(APP_WIDTH/2, APP_HEIGHT/8 + HEAD_RADIUS*2, APP_WIDTH/2, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH));
		}

		if (part == 3) {
			add(new GLine(APP_WIDTH/2, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD, APP_WIDTH/2 - UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD));
			add(new GLine(APP_WIDTH/2 - UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD,
						  APP_WIDTH/2 - UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD + LOWER_ARM_LENGTH));
		}
		if (part == 4) {
			add(new GLine(APP_WIDTH/2, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD, APP_WIDTH/2 + UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD));
			add(new GLine(APP_WIDTH/2 + UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD,
						  APP_WIDTH/2 + UPPER_ARM_LENGTH, APP_HEIGHT/8 + HEAD_RADIUS*2 + ARM_OFFSET_FROM_HEAD + LOWER_ARM_LENGTH));
		}

		if (part == 5) {
			add(new GLine(APP_WIDTH/2, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH, APP_WIDTH/2 - HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH));
			add(new GLine(APP_WIDTH/2 - HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH,
						  APP_WIDTH/2 - HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH));
		}

		if (part == 6) {
			add(new GLine(APP_WIDTH/2, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH, APP_WIDTH/2 + HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH));
			add(new GLine(APP_WIDTH/2 + HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH,
						  APP_WIDTH/2 + HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH));
		}

		if (part == 7) {
			add(new GLine(APP_WIDTH/2 - HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH,
			 			  APP_WIDTH/2 - HIP_WIDTH - FOOT_LENGTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH));
		}

		if (part == 8) {
			add(new GLine(APP_WIDTH/2 + HIP_WIDTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH,
						  APP_WIDTH/2 + HIP_WIDTH + FOOT_LENGTH, APP_HEIGHT/3 + HEAD_RADIUS*2 + BODY_LENGTH + LEG_LENGTH));
		}

		part++;
	}

	private void erectScaffold() {
		add(new GLine(APP_WIDTH/20, APP_HEIGHT, APP_WIDTH/20, APP_HEIGHT - 430));
		add(new GLine(APP_WIDTH/20, APP_HEIGHT - 430, APP_WIDTH/2,  APP_HEIGHT - 430));
		add(new GLine(APP_WIDTH/2, APP_HEIGHT - 430, APP_WIDTH/2, APP_HEIGHT/8));
	}

/* Constants for the simple version of the picture (in pixels) */
	private static final int SCAFFOLD_HEIGHT = 360;
	private static final int BEAM_LENGTH = 144;
	private static final int ROPE_LENGTH = 18;
	private static final int HEAD_RADIUS = 36;
	private static final int BODY_LENGTH = 84;
	private static final int ARM_OFFSET_FROM_HEAD = 28;
	private static final int UPPER_ARM_LENGTH = 72;
	private static final int LOWER_ARM_LENGTH = 44;
	private static final int HIP_WIDTH = 36;
	private static final int LEG_LENGTH = 144;
	private static final int FOOT_LENGTH = 28;

}
