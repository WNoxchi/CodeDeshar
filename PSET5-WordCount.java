/*
 * CS106A Programming Methodology
 * Problem Set 5.1 - Word Count
 * PSET5 WordCount.java
 * --------------------
 * Program reads a text file and returns the number of lines, words, and
 * characters in that file.
 * --------------------
 * Wayne H. Noxchi
 * Start: 23-Jan-2016 15:16 | Finish:   23-Jan-2016 17:46
 */

import acm.program.*;
import java.io.*;

public class WordCount extends ConsoleProgram {

    public void run() {
        int lineCount = 0;
        int wordCount = 0;
        int charCount = 0;
        BufferedReader textReader = openFileReader("File name: ");
        try {
            while (true) {
                String line = textReader.readLine();
                if (line == null) break;
                lineCount++;
                wordCount += countWords(line);
                charCount += line.length();
            }
            textReader.close();
        } catch (IOException wtf) {
            println("An I/O exception has occurred.");
        }
        println("Lines: " + lineCount);
        println("Words: " + wordCount);
        println("Characters: " + charCount);
    }

/** Asks for input file name; returns BufferedReader attached to file contents.
 *  If file doesn't exist, user prompted to enter file name again. */
    private BufferedReader openFileReader(String prompt) {
        BufferedReader textReader = null;
        while (textReader == null) {
            String fileName = readLine(prompt);
            try {
                textReader = new BufferedReader(new FileReader(fileName));
            } catch (IOException wtf) {
                println("Cannot open file.");
            }
        }
        return textReader;
    }

/** Counts words (letters or digits) in input line */
    private int countWords(String line) {
        boolean partWord = false;
        int wordCount = 0;
        for (int i = 0; i < line.length(); i++) {
            char ch = line.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                partWord = true;
            } else {
                if (partWord) wordCount++;
                partWord = false;
            }
        }
        if (partWord) wordCount++;
        return wordCount;
    }

}

/*

I got as far as the below, before I had to use the solution for help:
---------------------------------------------------------------------

import acm.program.*;
import java.util.*;
import java.io.*;

public class PSET5_WordCount extends ConsoleProgram {

    // instantiate an ArrayList composed of datatype: String:
    private ArrayList <String> readFile = new ArrayList <String> ();

    public PSET5_WordCount() {
        try {
            BufferedReader textReader = new BufferedReader(new FileReader("PSET5.txt"));
            while (true) {
                String Line = textReader.readLine();
                if (Line == null) break;
                wordList.add(Line);
            }
            textReader.close();
        } catch (IOException wtf) {
            throw new ErrorException(wtf);
        }
    }

    public int textCount() {
        int wordCount = 0;
        int charCount = 0;
        int lineCount = 0;
        for (i = 0; i < wordList.size(); i++) {
            lineCount++;
            for (j = 0; j < wordList.get(i).size(); j++) {
                charCount++;
                if (Character.isLetter(wordList.get(i).charAt(j)) && (wordList.get(i).charAt(j+1) = ' ' || wordList.get(i).charAt(j+1) == null)) {
                    wordCount++;
                }
            }
        }
    }

}

*/
