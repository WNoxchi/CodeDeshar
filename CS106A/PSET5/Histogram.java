/*
 * CS106A Programming Methodology
 * Problem Set 5.2 - Histogram
 * PSET5 Histogram.java
 * --------------------
 * Program reads scores from a txt file, 1 score/line, & displays historgram.
 * --------------------
 * Wayne H. Noxchi
 * Start: 23-Jan-2016 17:57 |   Finish: 23-Jan-2016 19:10
 */

import acm.program.*;
import acm.util.*;
import java.io.*;

public class Histogram extends ConsoleProgram {

// private instance variable:
    private int[] histogramArray;
// name of data file:
    private static final String DATA_FILE = "MidtermScores.txt";
        
    public void run() {
        initHistogram();
        readScoresIntoHistogram();
        printHistogram();
    }

// Initialize histogram array:
    private void initHistogram() {
        histogramArray = new int[11];
        for (int i = 0; i <= 10; i++) {
            histogramArray[i] = 0;
        }
    }

// Read exam scores, updating histogram:
    private void readScoresIntoHistogram() {
        try {
            BufferedReader scoreReader = new BufferedReader(new FileReader(DATA_FILE));
            while (true) {
                String line = scoreReader.readLine();
                if (line == null) break;
                int score = Integer.parseInt(line);
                if (score < 0 || score > 100) {
                    // throw new ErrorException("That score is out of range"); //   this line is causing crashes in Eclipse but I don't know why
                    break;  //  I'll just break instead of the error exception.
                } else {
                    int range = score / 10;
                    histogramArray[range]++;
                }
            }
        } catch (IOException wtf) {
            throw new ErrorException(wtf);
        }
    }

// Display histogram:
    private void printHistogram() {
        for (int range = 0; range <= 10; range++) {
            String label;
            switch (range) {
                case  0: label = "00-09"; break;
                case 10: label = "  100"; break;
                default:
                    label = (10 * range) + "-" + (10 * range + 9); break;
            }
            String stars = createStars(histogramArray[range]);
            println(label + ": " + stars);
        }
    }

// Create string of stars:
    private String createStars(int n) {
        String stars = "";
        for (int i = 0; i <= n; i++) {
            stars += "*";
        }
        return stars;
    }

}

/*  Got this far before having to look at the solution for help:

import acm.program.*;
import java.io.*;

public class Histogram extends ConsoleProgram {

    private String Zeroes = "";
    private String Tens = "";
    private String Twenties = "";
    private String Thirties = "";
    private String Forties = "";
    private String Fifties = "";
    private String Sixties = "";
    private String Seventies = "";
    private String Eighties = "";
    private String Nineties = "";
    private String Hundred = "";

    // private ArrayList <int> scoreList;

    public void run() {

        scoreList = new ArrayList<int>();
        BufferedReader scoreReader = openScoreReader("Scoresheet name: ");
        try {
            while (true) {
                String line = scoreReader.readLine();
                if (line == null) break;
                // scoreList.add(line);
                scoreTally(line);
            }
            scoreReader.close();
        } catch (IOException wtf) {
            println("I/O exception, wtf.");
        }
        println("00-09: " + Zeroes);
        println("10-19: " + Tens);
        println("20-29: " + Twenties);
        println("30-39: " + Thirties);
        println("40-49: " + Forties);
        println("50-59: " + Fifties);
        println("60-69: " + Sixties);
        println("70-79: " + Seventies);
        println("80-89: " + Eighties);
        println("90-99: " + Nineties);
        println("100: " + Hundred);
    }

    private void scoreTally(int line) {
        if (line < 10) Zeroes += '*';
        if (line < 20 && line > 10) Tens += '*';
        if (line < 30 && line > 20) Twenties += '*';
        if (line < 40 && line > 30) Thirties += '*';
        if (line < 50 && line > 40) Forties += '*';
        if (line < 60 && line > 50) Fifties += '*';
        if (line < 70 && line > 60) Sixties += '*';
        if (line < 80 && line > 70) Seventies += '*';
        if (line < 90 && line > 80) Eighties += '*';
        if (line == 100) Hundred += '*';
    }
}
*/
