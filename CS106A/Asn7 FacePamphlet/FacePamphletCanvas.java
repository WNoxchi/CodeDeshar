/*
 * File: FacePamphletCanvas.java
 * -----------------------------
 * This class represents the canvas on which the profiles in the social
 * network are displayed.  NOTE: This class does NOT need to update the
 * display when the window is resized.
 */


import acm.graphics.*;
import java.awt.*;
import java.util.*;

public class FacePamphletCanvas extends GCanvas
					implements FacePamphletConstants {

	/**
	 * Constructor
	 * This method takes care of any initialization needed for
	 * the display
	 */
	public FacePamphletCanvas() {
		// You fill this in
	}


	/**
	 * This method displays a message string near the bottom of the
	 * canvas.  Every time this method is called, the previously
	 * displayed message (if any) is replaced by the new message text
	 * passed in.
	 */
	public void showMessage(String msg) {
		// You fill this in
		if (message != null) {
			remove(message);
		}
		message = new GLabel(msg, getWidth() / 2, getHeight() - BOTTOM_MESSAGE_MARGIN);
		message.setFont(MESSAGE_FONT);
		add(message);
	}


	/**
	 * This method displays the given profile on the canvas.  The
	 * canvas is first cleared of all existing items (including
	 * messages displayed near the bottom of the screen) and then the
	 * given profile is displayed.  The profile display includes the
	 * name of the user from the profile, the corresponding image
	 * (or an indication that an image does not exist), the status of
	 * the user, and a list of the user's friends in the social network.
	 */
	public void displayProfile(FacePamphletProfile profile) {
		// You fill this in
		if (profile != null) {
			removeAll();

			GLabel name = new GLabel(profile.getName(), LEFT_MARGIN, TOP_MARGIN);
			name.setFont(PROFILE_NAME_FONT);
			add(name);

			GRect placeholder_image = new GRect(LEFT_MARGIN, IMAGE_MARGIN + TOP_MARGIN + name.getHeight(), IMAGE_WIDTH, IMAGE_HEIGHT);
			add(placeholder_image);
			GLabel image_placeholder_text = new GLabel("NO IMAGE", LEFT_MARGIN, IMAGE_MARGIN + TOP_MARGIN + name.getHeight());
			image_placeholder_text.move(placeholder_image.getWidth() / 2 - image_placeholder_text.getWidth(),
										(placeholder_image.getHeight() + image_placeholder_text.getHeight()) / 2);
			image_placeholder_text.setFont(PROFILE_IMAGE_FONT);
			add(image_placeholder_text);

			if (profile.getImage() != null) {
				GImage image = profile.getImage();
				image.scale(IMAGE_WIDTH / image.getWidth(), IMAGE_HEIGHT / image.getHeight());
				add(image, LEFT_MARGIN, IMAGE_MARGIN + TOP_MARGIN + name.getHeight());
			}

			// if the profile status is not empty string, update status
			if (!profile.getStatus().equals("")) {
				GLabel status = new GLabel(profile.getName() + " is " + profile.getStatus(), LEFT_MARGIN,
																				  STATUS_MARGIN + IMAGE_MARGIN + TOP_MARGIN + name.getHeight() + IMAGE_HEIGHT);
				status.setFont(PROFILE_STATUS_FONT);
				add(status);
			// if profile status is empty string, display 'no current status'
			} else if (profile.getStatus().equals("")) {
				GLabel status = new GLabel("No Current Status", LEFT_MARGIN, STATUS_MARGIN + IMAGE_MARGIN + TOP_MARGIN + name.getHeight() + IMAGE_HEIGHT);
			}

			GLabel friends = new GLabel("Friends:", getWidth() / 2, IMAGE_MARGIN + TOP_MARGIN + name.getHeight());
			friends.setFont(PROFILE_FRIEND_FONT);
			add(friends);
			// using an iterator to display all friends in friend list:
			Iterator<String> iter = profile.getFriends();
			int height_spacing = 0;
			while (iter.hasNext()) {
				height_spacing++;
				GLabel friend = new GLabel(iter.next(), getWidth() / 2, IMAGE_MARGIN + TOP_MARGIN + name.getHeight());
				friend.move(0, friend.getHeight() * height_spacing * 5);
				friend.setFont(PROFILE_FRIEND_FONT);
				add(friend);
			}
		} else {
			removeAll();
		}
	}

	// Private Instance Var
	GLabel message = null;

}
