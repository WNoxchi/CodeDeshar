/*  CS106B - Programming Abstractions
 *  Problem Set 2 (2008)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi
 *-------------------------------------------------<*>
 * 17-Jun-2016 00:31 - 01:45| 22-Jun-2016 23:40 - 23-Jun-2016 03:52
 * 23-Jun-2016 06:08 - 07:05
*/


/*------------------------------------------------------------------------------
Problem 1: Vectors (AKA C++ ArrayLists...)
Say we are writing the next version of a nifty new mail reading program and
want to use a Vector (interface in reader appendix) to store all the data.
The following structure is used to hold the data of an email message:

struct eMailMsg {
  string to;
  string from;
  string message;
  string subject;
  int date;
int time;
};

a) How would you declare a Vector that stores eMailMsgs?
*/

//  Nope --> vec<string<eMailMsgs> > Email;

//A)     Vector<eMailMsg> EmailVec;

/*
b) Write a function RemoveSpam that takes a vector containing elements of
type eMailMsg and removes all elements whose subject begins with the string "SPAM".
*/

// First Try:
// void RemoveSpam(vec<eMailMsg> & EmailVec) {
//     for (int i = 0; i < EmailVec.size(); i++) {
//         if (subject.EmailVec[i] == "SPAM") {
//             EmailVec.removeAt(i);
//         }
//     }
// }

// Corrected:
void RemoveSpam(Vector<eMailMsg> & EmailVec) {
    for (int i = EmailVec.size(); i >= 0; i--) {
        eMailMsg mail = EmailVec[i];
        if (mail.subject.find("SPAM") == 0) {
            EmailVec.removeAt(i);
        }
    }
}

/*
c) How could you modify the to field of the eMailMsg structure so that it can
hold the email addresses of an arbitrary number of recipients of an email? With
 the modification in place, given an eMailMsg email, how would you access the
 last address listed in the to field?
*/

// >>> You can do this by using another vector of base type string

// First try:
// struct eMailMsg {
//     string to;
//     string from;
//     string message;
//     string subject;
//     Vector<string> recipients;
//     int date;
//     int time;
// }

// Corrected:
struct eMailMsg {
    Vector<string> to;
    string from;
    string message;
    string subject;
    int date;
    int time;
}

/*------------------------------------------------------------------------------
Problem 2: Queues
Write a function
      void ReverseQueue(Queue<int> & q);
that reverses the elements in the passed in queue.
(Hint: Is there another class that could make doing this a lot easier?)         */

// Use a stack to reverse the Queue;
void ReverseQueue(Queue<int> & q) {
    Stack<int> stack;
    /* move queue onto stack */
    for (int i = 0; i < q.size(); i++) {
        stack.push(q.dequeue())
    }
    /* move stack back onto queue (reverses) */
    for (int i = 0; i < stack.size(); i++) {
        q.enqueue(stack.pop());
    }
}

// Official Solution:
// void ReverseQueue(Queue<int> & queue) {
//     Stack<int> stack;
//     while (!queue.isEmpty())
//     {
//         stack.push(queue.dequeue());
//     }
//     while (!stack.isEmpty())
//     {
//         queue.enqueue(stack.pop());
//     }
// }

/*------------------------------------------------------------------------------
Problem 3: Using the Scanner and Stack classes

Using the Scanner class and the Stack class, write the following function:
      bool IsCorrectlyNested(string htmlStr);                                   */

/* ehh,,,, buggy */
#include <fstream>
#include <iostream>
#include <string>
#include "stack.h"
#include "tokenscanner.h"
using namespace std;

/* function checks if each <X> has a corresp </X> */
bool IsCorrectlyNested(string htmlStr) {
    bool slash = 0;
    string token, text = "";
    TokenScanner scanner(htmlStr);
    Stack<string> stack, slashstack;

    /* search str for <X> & add to stacks */
    while (scanner.hasMoreTokens()) {
        token = scanner.nextToken();
        if (token == "<") {
            slash = 0;
            while (token != ">") {
                token = scanner.nextToken();
                if (token == "/")
                    slash = 1;
                if (token != "/" && token != ">")
                    text += token;
            }
            /* if <...> add to stack, if </...> add to slashstack */
            if (!slash) {
                stack.push(text);
            } else {
                slashstack.push(text);
            }
        }
    }

    /* check if each elem stack == slashstack */
    // return stack.equals(slashstack); <<-- apparently this doesn't want to work
    while (!stack.isEmpty() && !slashstack.isEmpty()) {
		cout << "stack:<" << stack.peek() << ">  slashstack:</" << slashstack.peek() << ">" << endl;
        if (stack.pop() != slashstack.pop()) {
            return false;
        }
    }
    if ((stack.isEmpty() && !slashstack.isEmpty()) || (!stack.isEmpty() && slashstack.isEmpty())) {
        return false;
    }
    return true;
}

/* testing */
int main() {
	ifstream infile;
	string filename = "", filetext = "";

    while (infile.fail() || filename == "") {
        cout << "Filename: ";
        getline(cin, filename);
        infile.open(filename.c_str());

        /* if fail: report */
        if (infile.fail()) {
            cout << "File not found.\n";
        }
    }

	while (!infile.eof()) {
		getline(infile, filetext);
		cout << "Line: " << filetext << endl;
		if (IsCorrectlyNested(filetext)) {
		cout << "Tags are correctly nested" << endl;
		} else {
			cout << "Tags incorrectly nested" << endl;
		}
	}
	infile.close();
}

/* Official Solution */
// #include "stack.h"
// #include "scanner.h"
//
// bool ProcessOpenTag(Scanner& scanner, Stack<string>& tagStack) {
//     string tag = scanner.nextToken();
//     tagStack.push(tag);
//     return true;
// }
//
// bool ProcessCloseTag(Scanner& scanner, Stack<string>& tagStack) {
//     string tag = scanner.nextToken();
//
//     if (!tagStack.isEmpty() && tag == tagStack.pop()) {
//         return true;
//     } else {
//         return false;
//     }
// }
//
// bool ProcessTag(Scanner& scanner, Stack<string>& tagStack) {
//     // read the next token to see if we found an openning or closing tag
//     string token = scanner.nextToken();
//
//     if (token == "/") {
//         return ProcessCloseTag(scanner, tagStack);
//     } else {
//         scanner.saveToken(token);   // So ProcessOpenTag can use it
//         return ProcessOpenTag(scanner, tagStack);
//     }
// }
//
// bool IsCorrectlyNested(string htmlStr) {
//     Scanner scanner;
//     scanner.setSpaceOption(Scanner::IgnoreSpaces);
//
//     Stack<string> tagStack;
//     scanner.setInput(htmlStr);
//
//     // start by assuming it is balanced
//     bool isBalanced = true;
//
//     while (scanner.hasMoreTokens()) {
//         string token = scanner.nextToken();
//
//         if (token == "<") {
//             if (!ProcessTag(scanner, tagStack)) {
//                 isBalanced = false;
//                 break;
//             }
//             // get rid of ">" part of tag
//             scanner.nextToken();
//         }
//     }
//
//     if (!tagStack.isEmpty()) isBalanced = false;
//     return isBalanced;
// }

/*------------------------------------------------------------------------------
Problem 4: Map Warm-up
Write a function:
      char MostFrequentCharacter(ifstream &if, int &numOccurrences);
that given an input file stream, returns the character that occurs the most
frequently and stores the number of times it occurs in the reference parameter
numOccurrences.

To write this function, first start by scanning through the file stream,
analyzing each character and storing an updated count in a map. Then, after
you’ve built this table, iterate over it to find the character that occurred
the most often.                                                                 */

char MostFrequentCharacter(ifstream &infile, int &numOccurrences) {
    Map<int> charFreq;
    int numOccurrences = 0;

    int nextChar, freq;
    while ((nextChar = infile.get()) != EOF) {
        /* convert to string for lookup */
        string character = "";
        character = char(nextChar);

        /* if found: increment; else: add to map */
        freq = 1;
        if (charFreq.containsKey(character)) {
            freq = charFreq[character] + 1;
        }
        charFreq[character] = freq;
    }

    /* use iterator to find most freq character in map */
    Map<int>::Iterator iter = charFreq.iterator();
    string maxChar = "";

    while (iter.hasNext()) {
        character = iter.next();
        if (charFreq[character] > numOccurrences) {
            maxChar = character;
        }
    }
    return maxChar[0];

}

// Halxara Attempt
// /* init map */
// Map<char, int>() numOccurrences;
//
// /* function */
// char MostFrequentCharacter(ifstream &infile, int &numOccurrences) {
//     /* open file */
//     ifstream infile;
//     string filechar;
//
//     infile.open("test.txt");
//
//     /* count chars */
//     int ch;
//     while ((ch = infile.get()) != EOF) {
//         /* if map doesn't have ch, add it; else update count */
//         if (!numOccurrences.containsKey(ch)) {
//             numOccurrences.put(ch, 1);
//         } else {
//             numOccurrences[ch] += 1;
//         }
//     }
//
//     /* close file */
//     infile.close();
//
//     /* find mostFreqChar */
//     int mFreq = 0;
//     char mFreqChar = "";
//     foreach (char ch in numOccurrences) {
//         if (numOccurrences[ch] > mFreq) {
//             mFreq = numOccurrences[ch]
//             mFreqChar = ch;
//         }
//     }
//
//     /* return most frequent character */
//     return mFreqChar;
// }

// Official Solution:
// char MostFrequentCharacter(ifstream &infile, int &numOccurrences)
// {
//     Map<int> charFrequencies;
//     numOccurrences = 0;
//
//     int nextChar;
//     while((nextChar = infile.get()) != EOF)
//     {
//         // convert it to a string for lookup in symbol table
//         string foundChar = "";
//         foundChar += char(nextChar);
//
//         // if found, incrememnt the stored value, otherwise enter in a new one
//         int frequency = 1;
//         if (charFrequencies.containsKey(foundChar))
//             frequency = charFrequencies[foundChar] + 1;
//         charFrequencies[foundChar] = frequency;
//     }
//
//     // now use an iterator to find the most occuring character
//     Map<int>::Iterator iter = charFrequencies.iterator();
//     string maxCharacter = "";
//
//     while (iter.hasNext())
//     {
//         string character = iter.next();
//         int frequency = charFrequencies[character];
//
//         if (frequency > numOccurrences)
//         {
//             maxCharacter = character;
//             numOccurrences = frequency;
//         }
//     }
//     return maxCharacter[0];
// }

/*------------------------------------------------------------------------------
Problem 5: Minesweeper  -   23-Jun-2016 06:08 - 07:05

Given a grid of boolean values, write a function that creates a grid of counts
of the number of surrounding mined grid elements:
        int checkMines(int & row, int & col, Grid<int> & bombLocations)         */

/**
    Since a bool is going to be a 1/0, Ill just add the value of the coords
    around the target point to it; & add 0 if out of bounds.

    NOTE:   My version only checks coords around the grid elem. Heh, oh well,
    official solution is added below mine.                                      **/

/* prototype helper function */
int checkMines(int & row, int & col, Grid<int> & bombLocations);

/* function */
Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations) {
    int rows = bombLocations.numRows(), cols = bombLocations.numCols();
    Grid<int> mineField(rows, cols);

    for (int i = 0; i < rows; i ++) {
        for (int k = 0; k < cols; k++) {
            mineField[i][k] = checkMines(i, k, bombLocations);
        }
    }
    return mineField;
}

/* helper function */
int checkMines(int & row, int & col, Grid<int> & bombLocations) {
    int bombs = 0;

    /* check NW, North, NE of coordinate */
    for (int i = -1; i < 2; i++) {
        if (!bombLocations.inBounds(row + 1, col + i)) {
             bombs += 0;
        } else {
            bombs += bombLocations[row + 1][col + i];
        }
    }
    /* check West & East */
    for (int i = 0; i <= 1; i++) {
        if (!bombLocations.inBounds(row, col - 1 + (i * 2))) {
             bombs += 0;
        } else {
            bombs += bombLocations[row][col - 1 + (i * 2)];
        }
    }
    /* check SW, South, SE */
    for (int i = -1; i < 2; i++) {
        if (!bombLocations.inBounds(row - 1, col + i)) {
             bombs += 0;
        } else {
            bombs += bombLocations[row - 1][col + i];
        }
    }
    return bombs;
}

// Official Solution:
// bool LocationOnGrid(int row, int col, Grid<int> & bombCounts)
// {
//       return row >= 0 && col >= 0 && row < bombCounts.numRows()
//              && col < bombCounts.numCols();
// }
// void MarkBomb(int row, int col, Grid<int> & bombCounts)
// {
//       for(int bombRow = -1; bombRow <= 1; bombRow++)
//       {
//             for(int bombCol = -1; bombCol <= 1; bombCol++)
//             {
// } }
// }
// if(LocationOnGrid(bombRow + row, bombCol + col,
//                   bombCounts))
//       bombCounts(bombRow + row, bombCol + col)++;
// Grid<int> MakeGridOfCounts(Grid<bool> & bombLocations)
// {
//       Grid<int> bombCounts(bombLocations.numRows(),
//                            bombLocations.numCols());
//       for(int row = 0; row < bombLocations.numRows(); row++)
//       {
//             for(int col = 0; col < bombLocations.numCols();col++)
//             {
//                   bombCounts(row, col) = 0;
//             }
// }
//       for(int row = 0; row < bombLocations.numRows(); row++)
//       {
//             for(int col = 0; col < bombLocations.numCols();col++)
//             {
//                   if(bombLocations(row, col))
//                   {
// } }
// }
//       return bombCounts;
// }
