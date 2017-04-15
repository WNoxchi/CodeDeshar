/*
 * File: RandomCirclesPSet3.java
 * Name: Wayne H. Noxchi
 * -----------------------------
 * Write a graphicsprogram that draws a set of 10 circles with random sizes,
 * random positions, random colors; radius between 5 and 50 px. Position must be
 * inside canvas.
 * ----------------------------
 * Start:	12-Jan-2016 13:11	|	12-Jan-2016 14:15
 */

import acm.program.*;
import acm.graphics.*;
import acm.util.*;

public class RandomCirclesPSet3 extends GraphicsProgram {

	public void run() {
		 for (int i = 0; i < 10; i++) {
			 drawCircle();
		 }
	 }

	 private void drawCircle() {
		 // Radius
		 int Rad = rgen.nextInt(5, 50);
		 // X & Y coordinates
		 int Xpos = rgen.nextInt(Rad / 2, getWidth() - Rad / 2);
		 int Ypos = rgen.nextInt(Rad / 2, getHeight() - Rad / 2);

		 GOval circle = new GOval(Rad, Rad);
		 circle.setFilled(true);
		 add(circle, Xpos, Ypos);
		 circle.setColor(rgen.nextColor());
	 }

public RandomGenerator rgen = new RandomGenerator();

}
