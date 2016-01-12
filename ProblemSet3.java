/*
 * File: DrawLinesPSet3.java
 * Name: Wayne H. Noxchi
 * -----------------------------
 * Write a graphicsprogram that allows the user to draw lines on the canvas.
 * Pressing the mouse button sets the starting point for the line. Dragging
 * the mouse moves the other endpoint around as the drag proceeds. Releasing
 * the mouse fixes the line in its current position and gets ready to start a
 * new line.
 * ----------------------------
 * Start:	12-Jan-2016 14:25 |   Fin:    12-Jan-2016 14:41
 */

import java.awt.event.*;
import acm.graphics.*;
import acm.program.*;

public class DrawLinesPSet3 extends GraphicsProgram {

    /** Runs program */
    public void run() {
        addMouseListeners();
    }

    /** Called on mouse press to record initial coordinates */
    public void mousePressed(MouseEvent e) {
        Xstart = e.getX();
        Ystart = e.getY();
        dragLine = new GLine(Xstart, Ystart, 0, 0);
        add(dragLine);
    }

    /** Called on mouse drag to shape dragLine */
    public void mouseDragged(MouseEvent e) {
        dragLine.setEndPoint(e.getX(), e.getY());
    }

    private GLine dragLine;
    private double Xstart;
    private double Ystart;
}

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
