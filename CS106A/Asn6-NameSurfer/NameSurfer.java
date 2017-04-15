/*
 * File: NameSurfer.java
 * ---------------------
 * When it is finished, this program will implements the viewer for
 * the baby-name database described in the assignment handout.
 */

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

		graph = new NameSurferGraph();
		add(graph);

		nameLabel = new JLabel("Name: ");
		add(nameLabel, SOUTH);

		nameField = new JTextField(MAX_NAME);
		add(nameField, SOUTH);
		nameField.addActionListener(this);

		graphButton = new JButton("Graph");
		add(graphButton, SOUTH);

		clearButton = new JButton("Clear");
		add(clearButton, SOUTH);

		addActionListeners();
	}

	/* Method: actionPerformed(e) */
	/**
	 * This class is responsible for detecting when the buttons are
	 * clicked, so you will have to define a method to respond to
	 * button actions.
	 */
	public void actionPerformed(ActionEvent e) {
		// You fill this in //
		if (e.getSource() == graphButton) {
			// println("Graph: " + nameField.getText());
			NameSurferEntry entry = namesDB.findEntry(nameField.getText());
			// println("Graph: " + entry.toString());
			graph.addEntry(entry);
			graph.update();

		} else if (e.getSource() == nameField) {
			// println("Graph: " + nameField.getText());
			NameSurferEntry entry = namesDB.findEntry(nameField.getText());
			// println("Graph: " + entry.toString());
			graph.addEntry(entry);
			graph.update();

		} else if (e.getSource() == clearButton) {
			// println("Clear");
			graph.clear();
			graph.update();
		}
	}

	// Private Instance Variables
	private JLabel nameLabel;
	private JTextField nameField;
	private JButton graphButton;
	private JButton clearButton;

	private NameSurferDataBase namesDB = new NameSurferDataBase("names-data.txt");
	private NameSurferGraph graph;

	private static final int MAX_NAME = 30;
}
