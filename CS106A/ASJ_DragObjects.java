/*
 * File: DragObjects.java
 * ------------------------
 * ASJ Chapter 8 p204
 */

import java.awt.*;
import java.awt.event.*;
import acm.graphics.*;
import acm.program.*;

/**This clas displays a mouse-draggable rectangle and oval */
public class DragObjects extends GraphicsProgram {

/** Runs the program */
    public void run() {
        GRect rect = new GRect(100, 100, 150, 100);
        rect.setFilled(true);
        rect.setColor(Color.RED);
        add(rect);
        GOval oval = new GOval(300, 115, 100, 70);
        oval.setFilled(true);
        oval.setColor(Color.GREEN);
        add(oval);
        addMouseListeners();
    }

/** Called on mouse press to record the coordinates of the click */
    public void mousePressed(MouseEvent e) {
        lastX = e.getX();
        lastY = e.getY();
        gobj = getElementAt(lastX, lastY);
    }

/** Called on mouse drag to reposition the object */
    public void mouseDragged(MouseEvent e) {
        if (gobj != null) {
            gobj.move(e.getX() - lastX, e.getY() - lastY);
            lastX = e.getX();
            lastY = e.getY();
        }
    }

/** Called on mouse click to move this object to the front */
    public void mouseClicked(MouseEvent e) {
        if (gobj != null) gobj.sendToFront();
    }

    // Instance variables
    private GObject gobj;   //  object being dragged
    private double lastX;   //  last mouse X pos
    private double lastY;   //  last mouse Y pos
}
