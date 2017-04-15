/*
 * CS106A PROGRAMMING METHODOLOGY
 * PROBLEM SET 4.1 - PSET4_CommaString.java
 * ----------------------------------
 * method adds commas to any number over 999.
 * S:  18-Jan-2016 19:12    F:  18-Jan-2016 20:01
 */

import acm.program.*;

public class PSET4_CommaString extends ConsoleProgram {

    public void run() {
        while (true) {
            String digits = readLine("Enter a numeric string: ");
            if (digits.length() == 0) break;
            println(addCommasToNumericString(digits));
        }
    }

    private String addCommasToNumericString(String digits) {
        String commaDigit = "";
        for (int i = 0; i < digits.length(); i++) {
            if (((digits.length() - i) % 3 == 0) && digits.length() > 3) {
                commaDigit += ",";
            }
            commaDigit += digits.charAt(i);
        }
        return commaDigit;
    }
}
