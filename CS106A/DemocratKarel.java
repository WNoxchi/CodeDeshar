/*
 *	CS106A PROGRAMMING METHODOLOGY
 *	PROBLEM SET 1: KAREL DEFENDS DEMOCRACY	(Handout #10, 1 Oct 2007)
 *  If Karel encounters a beeper in the center square, he moves on.
 *  If Karel finds no beeper in center square, he checks the entire slot and cleans it, then moves on.
 *  Karel will start on 1:3 and should end on 11:3.
 */

 /*
  * Pseudo:
  *   MOVE.
  *   BEEPCHECK.
  * Start:  19-Dec-2015 17:29
  * File: DemocratKarel.java
  */


import stanford.karel.*;

public class DemocratKarel extends SuperKarel {

	public void run() {
    move();
    BeepCheck();
  }
  private void BeepCheck() {
    if (noBeepersPresent()) {
      RunClean();
    } else {
      move();
      Continue();
    }
  }
  private void Continue() {
    if(frontIsClear()) {
      run();
    }
  }
  private void RunClean() {
    Clean();
    turnLeft();
    move();
    Clean();
    turnAround();
    move();
    move();
    Clean();
    turnAround();
    move();
    turnRight();
    move();
    Continue();
  }
  private void Clean() {
    while (beepersPresent()) {
      pickBeeper();
    }
  }
}
