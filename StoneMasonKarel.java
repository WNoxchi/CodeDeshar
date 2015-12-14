/*
 * File: StoneMasonKarel.java
 * --------------------------
 * The StoneMasonKarel subclass as it appears here does nothing.
 * When you finish writing it, it should solve the "repair the quad"
 * problem from Assignment 1.  In addition to editing the program,
 * you should be sure to edit this comment so that it no longer
 * indicates that the program does nothing.
 */

import stanford.karel.*;

public class StoneMasonKarel extends SuperKarel {

	public void run() {
		turnLeft();
		Autorepair();
	}
	
	
	private void Autorepair(){
		BeeperCheck();
	}


	private void BeeperCheck(){	
		if (noBeepersPresent()) {
			putBeeper();
			CheckwallCol();
		} else {
			CheckwallCol();
		}
	}


	//	Checkwall on the way up the column
	private void CheckwallCol(){
		if (frontIsClear()) {
			move();
			Autorepair();
		} else {
			ReturntoBase();
		}
	}

	private void ReturntoBase(){
		turnAround();
		CheckwallDown();
	}

	//	Checkwall on the way down the column
	private void CheckwallDown() {
		if (frontIsClear()) {
			move();
			CheckwallDown();
		} else {
			turnLeft();
			CheckwallBase();
		}
	}

	//	Checkwall while on base level
	private void CheckwallBase() {
		if (frontIsClear()) {
			Leap();
			turnLeft();
			Autorepair();
		}
	}

	private void Leap(){
		move();
		move();
		move();
		move();
	}

/*	private void turnAround(){
		turnLeft();
		turnLeft();
	}
*/ // turnAround(); is included in SuperKarel
}

/*

AutoRepair:

fill column
	-	check, fill empty, move, repeat.
	-	when hit wall -> return to base & face East
move 4 spaces

fill column

when hit Eastern wall: stop.
******************************************************
>>RUN
CHECK CLEAR
AUTOREPAIR
CHECK CLEAR
LEAP
CHECK CLEAR
*repeat*


Procedures:

private void Autorepair(){
	BeeperCheck();
}


private void BeeperCheck(){	
	if (beepersPresent()){
		putBeeper();
		CheckwallCol();
	} else{
		CheckwallCol();
	}
}


//	Checkwall on the way up the column
private void CheckwallCol(){
	if (frontIsClear()) {
		move();
		Autorepair();
	} else {
		ReturntoBase();
	}
}

private void ReturntoBase(){
	turnAround();
	CheckwallDown();
}

//	Checkwall on the way down the column
private void CheckwallDown{
	if (frontIsClear()){
		move();
		CheckwallDown();
	} else{
		turnLeft();
		CheckwallBase();
	}
}

//	Checkwall while on base level
private void CheckwallBase{
	if (frontIsClear()){
		Leap();
		turnLeft();
		Autorepair();
	}
}

private void Leap(){
	move();
	move();
	move();
	move();
}

private void turnAround(){
	turnLeft();
	turnLeft();
}

Conditions:

frontIsClear()
frontIsBlocked()

beepersPresent()
noBeepersPresent()



*/
