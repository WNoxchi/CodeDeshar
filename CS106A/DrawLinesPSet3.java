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
