/*
 * File: CheckerboardKarel.java
 * ----------------------------
 * When you finish writing it, the CheckerboardKarel class should draw
 * a checkerboard using beepers, as described in Assignment 1.  You
 * should make sure that your program works for all of the sample
 * worlds supplied in the starter folder.
 */

import stanford.karel.*;

public class CheckerboardKarel extends SuperKarel {
	
	public void run() {
		PrelimChecker();
	}

//	First check to det path to take (Left, Straight, Right)
	private void PrelimChecker() {
		if (leftIsBlocked()) {
			if(rightIsBlocked()) {
				LMode();
			} else {
			//	RMode();
			}
		} else {
			if (rightIsBlocked()) {
				if (leftIsBlocked()) {
				//	SMode();
				} else {
					LMode();
				}
			}	
		}
	}

//	Left Path
	private void LMode() {
		putBeeper();
		RunLF();	
	}	

//	First Run turning Left
	private void RunLF() {
		if (frontIsClear()) {
			move();
			if (frontIsClear()) {
				move();
				putBeeper();
				RunL();
			} if (leftIsClear()) {
				TurnLB();
			}
		}
	}
	
//	Turn Left place Beeper
	private void TurnLB() {
		turnLeft();
		move();
		turnLeft();
		putBeeper();
		RunR();
	}

//	Turn Right place Beeper

	private void TurnRB() {
		turnRight();
		move();
		turnRight();
		putBeeper();
		RunL();
	}
//	Run turning Right 
	private void RunR() {
		if (frontIsClear()) {
			move();
			if (frontIsClear()) {
				move();
				putBeeper();
				RunR();
			} if (rightIsClear()) {
				if (leftIsClear()) {
					TurnRB();
				}
			}
		} 
	}
//	Run turning Left
	private void RunL() {
		if (frontIsClear()) {
			move();
			if (frontIsClear()) {
				move();
				putBeeper();
				RunL();
			} if (leftIsClear()) {
				if (rightIsClear()){
					TurnLB();	
				}
			}
		}
	}

}

/*
obsolete code:

//	Straight Path
	private void SMode() {
		putBeeper();
		RunS();
	}
	
//	Right Path
	private void RMode() {
		putBeeper();
		RunR();
	}
	
//	First(&only) Run Straight
	private void RunS() {
		putBeeper();
		WallcheckS();
	}
	
//	Wallcheck for FRS
	private void WallcheckS() {
		if (frontIsClear()) {
			move();
			if (frontIsClear()) {
				move();
				RunS();
			}
		}
	}

private void TurnL() {
	turnLeft();
	move();
	turnLeft();
	RunR();
}

//Turn Right no Beeper
private void TurnR() {
	turnRight();
	move();
	turnRight();
	RunL();
}
*/
