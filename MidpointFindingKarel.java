/*
 * File: MidpointFindingKarel.java
 * -------------------------------
 * When you finish writing it, the MidpointFindingKarel class should
 * leave a beeper on the corner closest to the center of 1st Street
 * (or either of the two central corners if 1st Street has an even
 * number of corners).  Karel can put down additional beepers as it
 * looks for the midpoint, but must pick them up again before it
 * stops.  The world may be of any size, but you are allowed to
 * assume that it is at least as tall as it is wide.
 */

import stanford.karel.*;

public class MidpointFindingKarel extends SuperKarel {

	public void run() {
		MarkOdd();
	}
	
	//	Initial Marking of every other space
	private void MarkOdd() {
		putBeeper();
		if (frontIsClear()) {
			move();
			if (frontIsClear()) {
			move();
			MarkOdd();
			} else {
				LWallCheck();
			}
		} else {
			LWallCheck();
		}
	}
	
	//	Find left wall & start fill in
	private void LWallCheck() {
		turnAround();
		if (beepersPresent()) {
			pickBeeper();
			FindWall();
		} else {
			move();
			pickBeeper();
			FindWall();
		}
	}
	
	//	Find left Wall
	private void FindWall() {
		while (frontIsClear()) {
			move();
		}
		turnAround();
		move();
		putBeeper();
		FindRightWall();
	}
	
	//	Reset to Right Wall
	private void FindRightWall() {
		while (frontIsClear()) {
			move();
		}
		turnAround();
		StartFindFirstTwo();
	}
	
	//	Start to find first instance of 2 consecutive markers
	private void StartFindFirstTwo() {
		while(noBeepersPresent()) {
			move();
		}
		pickBeeper();
		move();
		FindFirstTwo();
	}
	
	//	Find First instance of 2 consecutive markers
	private void FindFirstTwo() {
		if (noBeepersPresent()) {
			move();
			if (beepersPresent()) {
				move();
				if(beepersPresent()) {
					turnAround();
					move();
					move();
					putBeeper();
					CountSpace();
				} else {
					FindFirstTwo();
				}
			}
		}
	}
	
	//	Count space going East; if 2 consec: trigger cleanup
	private void CountSpace() {
		move();
		move();
		if (noBeepersPresent()) {
			move();
			if (noBeepersPresent()) {
				StartCleanup();
			} else {
				FindRightWall();
			}
		}
	}
	
	//	Start Clean up and finish setup
	private void StartCleanup() {
		turnAround();;
		move();
		move();
		move();
		Cleanup();
	}
	
	//	Cleanup up and finish
	private void Cleanup() {
		if (beepersPresent()) {
			pickBeeper();
			while (frontIsClear()) {
				move();
				Cleanup();
			}
		}
	}
	
}

/****************
LOGIC FRAMEKWORK:

Logical Algorithm for finding the midpoint of any line without counting:

Drop a marker every other space.

When you get to the end, turn around.
Pick up the first marker you come across.

Go forward until you find the end, turn around.
Move one space, and drop the marker.

Continue until the end*. Turn around.
Pick up the first marker you come across.
Go forward until you see two markers in a row. Turn around.
Move two spaces. Drop the marker.

Go forward until you hit the end, and repeat.
You are finished when you see two markers in a row WithOut any empty spaces.

At that point, turn around, move two spaces.
Then turn around, move one space, pick up the marker, and pick up every marker until you hit the end.

You are finished.
-----------------------------
Update to Ending Algo:

When going Left looking for 2 markers in a row:
When found; as usual turn around, move 2 spaces, drop a marker
>>>	THEN: if you count 2 empty spaces, you are finished.

>>>		Turn around, move 3 spaces, pick up every marker until you hit the wall.
		Finished.

-----------------------------

Procedures:

>	Mark every other space.

>	Left Wall Check
>	Two in a row Check
>	Two in a row Solid Check

>	Clean up markers

****************/
