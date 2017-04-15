/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.12 simpio.cpp
 *-------------------------------------------------<*>
 *  27-Jun-2016 22:33
*/

/*  Complete the implementation of the simpio.h interface by implementing the
    functions getReal and getLine.                                         */

/*  I'm mainly copying the Stanford C++ Lib implementation & trying to
    understand their reasoning. - I may rewrite this in full later but I'll
    leave it as is for now.                                              */

#include <string>

void (trimInPlace(string & str);
void trimEndInPlace(string & str);
void trimStartInPlace(string & str);
void appendSpace(string & prompt);

/*
 * Function: getReal
 * Usage: double x = getReal(prompt);
 * ----------------------------------
 * Reads a complete line from cin and scans it as a floating-point number.
 * If the scan succeeds, the floating-point value is returned.  If the
 * input is not a legal number or if extraneous characters (other than
 * whitespace) appear in the string, the user is given a chance to reenter
 * the value. If supplied, the optional prompt string is printed before
 * reading the value.
 */
double getReal(std::string prompt = "");

double getReal(const::string prompt) {
    appendSpace(prompt);       // so the idea is they want a space after prompt?
    double value;              // this is whats coming out
    while (true) {
        cout << prompt;
        string line;
        getline(cin, line);     // so you get the string line
        trimInPlace(line);      // & you remove all whitespaces in it
        istringstream stream(line);     // PAC p179 - istringstream object "stream" set up to read data from "line"
        stream >> value;                // read data from "stream" directly into a value
        if (!stream.fail() && stream.eof()) {       // handling failure (wrong format)
            break;
        }
    }
    return value;
}

void trimInPlace(string & str) {
    trimEndInPlace(str);
    trimStartInPlace(str);
}
void trimEndInPlace(string & str) {
    int end = (int) str.length();
    int finish = end;
    while (finish > 0 && isspace(str[finish - 1])) {
        finish--;
    }
    if (finish < end) {
        str.erase(finish, end - finish);
    }
}
void trimStartInPlace(string & str) {
    int start = 0;
    int finish = (int) str.length() - 1;
    while (start <= finish && isspace(str[start])) {
        start++;
    }
    if (start > 0) {
        str.erase(0, start);
    }
}



/*
 * Function: getLine
 * Usage: string line = getLine(prompt);
 * -------------------------------------
 * Reads a line of text from cin and returns that line as a string.  The
 * newline character that terminates the input is not stored as part of the
 * return value.  If supplied, the optional prompt string is printed before
 * reading the value.
 */
std::string getLine(std::string prompt = "");
// looks like this just uses standard getline() to do its work

/*
std::string getLine(const std::string& prompt) {
    std::string line;
    getLine(prompt, line);
    return line;
}

void getLine(const std::string& prompt,
             std::string& out) {
    std::string promptCopy = prompt;
    appendSpace(promptCopy);
    std::cout << promptCopy;
    getline(std::cin, out);
}

void getLine(std::istream& input,
             std::string& out) {
    getline(input, out);
}
*/


void appendSpace(string & prompt) {
    if (!prompt.empty() && !isspace(prompt[prompt.length() - 1])) {
        prompt += ' ';
    }
}
