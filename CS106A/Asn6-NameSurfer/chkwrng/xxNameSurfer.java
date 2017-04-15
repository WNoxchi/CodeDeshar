/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

 // S: 12-Feb-2016 09:11

import acm.program.*;
import java.awt.event.*;
import javax.swing.*;

public class NameSurfer extends Program implements NameSurferConstants {

	/* Method: init() */
	/**
	 * This method has the responsibility for reading in the data base
	 * and initializing the interactors at the top of the window.
	 */
	public void init() {
	    // You fill this in, along with any helper methods //

		// dataBase = new HashMap<String, GObject>();

		addActionListeners();

		// add(new JLabel("Name"), SOUTH);
		nameLabel = new JLabel("Name");
		add(nameLabel, SOUTH);

		nameField = new JTextField(MAX_NAME);
		nameField.addActionListener(this);
		add(nameField, SOUTH);

		graphButton = new JButton("Graph");
		add(graphButton, SOUTH);

		clearButton = new JButton("Clear");
		add(clearButton, SOUTH);

	}

	/* Method: actionPerformed(e) */
	/**
	 * This class is responsible for detecting when the buttons are
	 * clicked, so you will have to define a method to respond to
	 * button actions.
	 */
	public void actionPerformed(ActionEvent e) {
		// You fill this in //
		Object source = e.getSource();
		if (source == graphButton || source == nameField) {
			print("Graph: " + nameField.getText() + "\n");

			NameSurferEntry nsEntry = namesDataBase.findEntry(nameField.getText());
			println("Graph: " + nsEntry.toString());

		} else if (source == clearButton) {
			print("Clear" + "\n");
		}
	}

	// private void drawGraph(String name, HashMap dataBase) {
	// 	// ??????
	// }

	private void clearGraph() {
		// iteratively remove all objects on screen.
		// need to define proper object in drawGraph() to implementt this
	}

	// Private Constants:
	private static final int MAX_NAME = 30;

	// Private Instance Variables
	JLabel nameLabel;
	JButton graphButton;
	JButton clearButton;
	JTextField nameField;

	private NameSurferDataBase namesDataBase = new NameSurferDataBase(names-data.txt);
}
