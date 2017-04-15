import acm.program.*;
import acm.graphics.*;

public class testProfile extends ConsoleProgram {

	private FacePamphletProfile profile = new FacePamphletProfile("Adam");
	private GImage image;

	public void run() {
		profile.setImage(image);
		profile.setStatus("eating");

		profile.addFriend("Jenny");
		profile.addFriend("James");

		println(profile.toString());
	}
}
