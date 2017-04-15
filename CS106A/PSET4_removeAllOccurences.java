/*
 * CS106A PROGRAMMING METHODOLOGY
 * PROBLEM SET 4.2
 * ----------------------------------
 * method reomves all occurrences of character ch from string str.
 * S:  19-Jan-2016 14:39    F:  19-Jan-2016 15:10
 */

import acm.program.*;

public class PSET4_removeAllOccurrences extends ConsoleProgram {
    public void run() {
        while (true) {
            String str = readLine("Type in a character to remove, followed by a sentence or phrase: \n");
            char ch = str.charAt(0);
            println(removeAllOccurrences(str, ch));
        }
    }

    // Removal Method:
    public String removeAllOccurrences(String str, char ch) {
        String clearedStr = "";
        for (int i = 0; i < str.length(); i++) {
            if (ch != str.charAt(i)) {
                clearedStr += str.charAt(i);
            }
        }
        return clearedStr;
    }

}
