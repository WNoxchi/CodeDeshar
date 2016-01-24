/*
 * CS106A Programming Methodology
 * Problem Set 5.3 - Unique Names
 * PSET5_UniqueNames.java
 * --------------------
 * Program reads input from user and returns each unique name entered.
 * --------------------
 * Wayne H. Noxchi
 * Start: 24-Jan-2016 12:08 |   Finish: 24-Jan-2016 14:25
 */

import acm.program.*;
// import java.io.*;
import java.util.*;

public class UniqueNames extends ConsoleProgram {

    public void run() {
        ArrayList<String> nameList = new ArrayList<String>();
        while (true) {
            String name = readLine("Ce: ");
            if (name.equals("")) break;
            if (!nameList.contains(name)) {
                nameList.add(name);
            }
        }
        println("Unique names: ");
        printList(nameList);
    }

    private void printList(ArrayList list) {
        for (int i = 0; i < list.size(); i++) {
            println(list.get(i));
        }
    }
}

/*  NOTES:
End: this was a lot simpler and straight forward than I expected.

entering in an array that expands dyanmically.

I got this far by 13:30:
-------------------------------------------------
public class UniqueNames extends ConsoleProgram {

    private ArrayList<String> nameList = new ArrayList<String>();
    private ArrayList<String> uniqueList = new ArrayList<String>();
    // private String[] nameList;
    private static final String SENTINEL = "stop";

    public void run() {
        println("Enter << " + SENTINEL + " >> to finish entering names.\n");
        ArrayList nameList = readArrayList();
        ArrayList uniqueList = findUniqueNames(nameList);
        printNames(uniqueList);
    }

    private ArrayList readArrayList() {
        while (true) {
            String name = readLine("Ce: ");
            if (name.equals(SENTINEL)) break;
            nameList.add(new String(name));
        }
        return nameList;
    }

    private ArrayList findUniqueNames(ArrayList arrlist) {
        for (int i = 0; i < arrlist.size(); i++) {
            boolean check = false;
            for (int j = 0; j < uniqueList.size(); j++) {
                if (arrlist.get(i).equals(uniqueList.get(j))) check = true;
            }
            if (check == true) uniqueList.add((String) (arrlist.get(i)));
        }
        return uniqueList;
    }

    private void printNames(ArrayList arrlist) {
        for (int i = 0; i < arrlist.size(); i++) {
            println(arrlist.get(i));
        }
    }
}


Got this basic thing working:
-------------------------------------------------
public void run() {
    while (true) {
        String name = readLine("Ha ce xhu yu? ");
        nameList.add(name);
    }
    for (int i = 0; i < nameList.size(); i++) {
        println("Ce: nameList[i]");
    }
}

I got this far by 12:30:
-------------------------------------------------
public class UniqueNames extends ConsoleProgram {

    private ArrayList<String> nameList = new ArrayList<String>();

    public void run() {
        String name = readLine("Ha ce xhu yu?");
        nameList.add(name);
    }
}
-------------------------------------------------
 */
