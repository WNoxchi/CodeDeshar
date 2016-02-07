/*
 * CS106A - PSet7: Using Interactors
 * BoxDiagram.java
 * ---------------------------------
 * Wayne H. Noxchi
 * S: Study/Prep: 05-Feb-2016 12:20
      Coding: 05-Feb-2016 13:44 -- Stop: 05-Feb-2016 14:43
      Finish: 18:45 - 06-Feb-2016 20:45 | Debug: 21:00 - 20:07
 */
 //

 import acm.program.*;
 import acm.graphics.*;
 import java.util.*;
 import java.awt.event.*;
 import javax.swing.*;


 public class BoxDiagram extends GraphicsProgram {

 // Inititalizes Program
     public void init() {
         contents = new HashMap<String, GObject>();
         createController();
         addActionListeners();
         addMouseListeners();
     }

 // Sets up Control Bar
     private void createController() {
         nameField = new JTextField(MAX_NAME);
         nameField.addActionListener(this);
         addButton = new JButton("Add");
         removeButton = new JButton("Remove");
         clearButton = new JButton("Clear");
         add(new JLabel("Name"), SOUTH);
         add(nameField, SOUTH);
         add(addButton, SOUTH);
         add(removeButton, SOUTH);
         add(clearButton, SOUTH);
     }

 // Adds a box to the screen
     private void addBox(String name) {
         GCompound box = new GCompound();
         GLabel label = new GLabel(name);
         GRect outline = new GRect(BOX_WIDTH, BOX_HEIGHT);
         box.add(outline, -BOX_WIDTH / 2, -BOX_HEIGHT / 2);
         box.add(label, -label.getWidth() / 2, -label.getAscent() / 2);
         add(box, getWidth() / 2, getHeight() / 2);
         contents.put(name, box);
     }
 // remove a box from screen
     private void removeBox(String name) {
         GObject obj = contents.get(name);
         if (obj != null) {
             remove(obj);
         }
     }
 // remove all boxes
     private void removeContents() {
         Iterator<String> iterator = contents.keySet().iterator();
         while (iterator.hasNext()) {
             removeBox(iterator.next());
         }
         contents.clear();   // empty the HashMap
     }

     public void actionPerformed(ActionEvent evt) {
         Object source = evt.getSource();
         if (source == nameField || source == addButton) {
             addBox(nameField.getText());
         } else if (source == removeButton) {
             removeBox(nameField.getText());
         } else if (source == clearButton) {
             removeContents();
         }
     }

     public void mousePressed(MouseEvent evt) {
         last = new GPoint(evt.getPoint());
         currentObject = getElementAt(last);
     }

     public void mouseDragged(MouseEvent evt) {
         if (currentObject != null) {
             currentObject.move(evt.getX() - last.getX(),
                                evt.getY() - last.getY());
             last = new GPoint(evt.getPoint());
         }
     }

     private void mouseClicked() {
         if (currentObject != null) currentObject.sendToFront();
     }

 // Private constants:
     private static final double BOX_WIDTH = 120;
     private static final double BOX_HEIGHT = 50;
     private static final int MAX_NAME = 25;

 // Private Instance Variables
     HashMap<String, GObject> contents;
     JTextField nameField;
     JButton addButton;
     JButton removeButton;
     JButton clearButton;
     GObject currentObject;
     GPoint last;
 }



/*  First try:

import acm.program.*;
import java.awt.event.*;
import javax.swing.*;



public class BoxDiagram extends ConsoleProgram {

    // not too sure what this does:
    public static void main(String[] args) {
        program.main(args);
    }

    public void init() {
        nameField = new JTextField(15);
        add(new JLabel("Name"), SOUTH);
        add(nameField, SOUTH);
        add(new JButton("Add"), SOUTH);
        add(new JButton("Remove"), SOUTH);
        add(new JButton("Clear"), SOUTH);
        nameField.addActionListeners(this);
        addActionListeners();
    }

    public void actionPerformed(ActionEvent evt) {
        String cmd = evt.getActionCommand();
        // some object   .placeObject(cmd); ?
    }

// constants:
    private static final double BOX_WIDTH = 120;
    private static final double BOX_HEIGHT = 50;
}

*/
