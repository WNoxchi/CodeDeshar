/*
 * File: NameSurferEntry.java
 * --------------------------
 * This class represents a single entry in the database.  Each
 * NameSurferEntry contains a name and a list giving the popularity
 * of that name for each decade stretching back to 1900.
 */

import acm.util.*;
import java.util.*;

public class NameSurferEntry implements NameSurferConstants {

	/* Constructor: NameSurferEntry(line) */
	/**
	 * Creates a new NameSurferEntry from a data line as it appears
	 * in the data file.  Each line begins with the name, which is
	 * followed by integers giving the rank of that name for each
	 * decade.
	 */
	private String name = "";
	private String nums = "";
	private int[] decadeArray = new int[NDECADES];

	public NameSurferEntry(String line) {
		// You fill this in //
		name = line.substring(0, line.indexOf(" "));
		nums = line.substring(line.indexOf(" ")).trim();
		separateNums(nums);
	}

	private void separateNums(String nums) {
		for (int parts = 0; parts < NDECADES - 1; parts++) {
			// String slice = nums.substring(0, nums.indexOf(" "));
			decadeArray[parts] = Integer.parseInt(nums.substring(0, nums.indexOf(" ")));
			nums = nums.substring(nums.indexOf(" ") + 1);
		}
		decadeArray[NDECADES - 1] = Integer.parseInt(nums);
	}


	/* Method: getName() */
	/**
	 * Returns the name associated with this entry.
	 */
	public String getName() {
		// You need to turn this stub into a real implementation //
		// return null;
		return name;
	}

	/* Method: getRank(decade) */
	/**
	 * Returns the rank associated with an entry for a particular
	 * decade.  The decade value is an integer indicating how many
	 * decades have passed since the first year in the database,
	 * which is given by the constant START_DECADE.  If a name does
	 * not appear in a decade, the rank value is 0.
	 */
	public int getRank(int decade) {
		// You need to turn this stub into a real implementation //
		// return 0;
		return decadeArray[decade];
	}

	/* Method: toString() */
	/**
	 * Returns a string that makes it easy to see the value of a
	 * NameSurferEntry.
	 */
	public String toString() {
		// You need to turn this stub into a real implementation //
		// return "";
		String result = "";
		result += "\"" + name + " [";
		for (int i = 0; i < NDECADES - 1; i++) {
			result += decadeArray[i] + " ";
		}
		result += decadeArray[NDECADES - 1] + "]\"";
		return result;
	}
}
