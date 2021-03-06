/*
 * File: HelloGUI.java
 * -------------------
 * This program displays a greeting each time a name is
 * entered in a JTextField.
 */

import acm.program.*;
import java.awt.event.*;
import javax.swing.*;

/** This class displays a greeting whenever a name is entered */
public class HelloGUI extends ConsoleProgram {

	public static void main(String[] args) {
		Program.main(args);
	}

	public void init() {
		nameField = new JTextField(10);
		add(new JLabel("Name"), SOUTH);
		add(nameField, SOUTH);
		nameField.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == nameField) {
			println("Hello, " + nameField.getText());
		}
	}

/* Private instance variables */
	private JTextField nameField;
}
