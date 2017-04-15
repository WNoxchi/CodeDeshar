/*
 * File: CountNames.java
 * ---------------------
 * This program shows an example of using a HashMap. It reads a list o
 * list of names from the user and lists out how many times each name
 * appeared in the list.
 * ---------------------
 * CS106A Handout 34A
 */

import acm.program.*;
import java.util.*;

public class CountNames extends ConsoleProgram {
    public void run() {
        HashMap<String, Integer> nameMap = new HashMap<String, Integer>();

        readNames(nameMap);
        printMap(nameMap);
    }

    /*
     * Reads a list of names from the user, storing names and how many
     * times each appeared in the map that is passed in as a parameter.
     */
    private void readNames(Map<String, Integer> map) {
        while (true) {
            String name = readLine("Enter name: ");
            if (name.equals("")) break;

            // See if that name previously appeared in the map. Update
            // count if it did, or create a new count if it didn't.
            Integer count = map.get(name);
            if (count == null) {
                count = new Integer(1);
            } else {
                count = new Integer (count + 1);
            }

            map.put(name, count);
        }
    }

    /*
     * Prints out list of entries (and assoc counts) from the map
     * that is passed in as a parameter.
     */
     private void printMap(Map<String, Integer> map) {
         Iterator<String> iter = map.keySet().iterator();
         while (iter.hasNext()) {
             String key = iter.next();
             int count = map.get(key);
             println("Entry [" + key + "] has count " + count);
         }
     }
}
