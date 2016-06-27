/*  CS106B - Programming Abstractions
 *  Programming Abstractions in C++ (2012)
 *-------------------------------------------------<*>
 *  Wayne H. Noxchi - 4.09 remove Comments
 *-------------------------------------------------<*>
 * 25-Jun-2016 22:02 - 23:01|26-Jun-2016 05:23 - 06:34
*/

/*
    Write a function
        void removeComments(istream & is, ostream & os);
    that copies characters from the input stream is to the output stream os,
    except for characters that appear inside C++ comments.
*/

/*
    I'm going to try using a state machine to do this one. 4 operating states:
    - Reading/Checking/Standard Comment/Line Comment

    I'm not sure if I can use .eof() to check for an end-line condition for a
    stream. Looks that way in the book. If that doesn't work, I'll use stream
    fail-state checking.
        -- Now do I have to reset the fail-state if it fails inside a function?
        Idk..
    I'm just going to check for the string endline marker "\n"
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* function */
void removeComments(istream & instream, ostream & outstream) {
    // machine states
    int READSTATE = 1;
    int CHECKSTAT = 2;
    int COMMSTATE = 3;
    int LINESTATE = 4;
    int ENDLSTATE = 5;
    // init mach states
    int STATE = READSTATE;

    int ch;
    int chk;

    while (STATE != ENDLSTATE) {
        // read state operation
        while (STATE == READSTATE) {
            ch = instream.get();
            if (ch == EOF) {
                STATE = ENDLSTATE;
                break;
            }
            if (ch != '/') {
                STATE = CHECKSTAT;
                break;
            }
            else {
                outstream.put(ch);
            }
        }
        // check state operation
        while (STATE == CHECKSTAT) {
            chk = instream.get();
            if (chk == EOF) {
                STATE = ENDLSTATE;
                outstream.put(ch);
                break;
            }
            if (chk == '/') {
                STATE = LINESTATE;
                break;
            }
            if (chk == '*') {
                STATE = COMMSTATE;
                break;
            }
            else {
                outstream.put(ch);
                outstream.put(chk);
                STATE = READSTATE;
                break;
            }
        }
        // comment state operation
        while (STATE == COMMSTATE) {
            ch = instream.get();
            if (ch == EOF) {
                STATE = ENDLSTATE;
                break;
            }
            if (ch == '*') {
                chk = instream.get();
                if (chk == '/') {
                    STATE = READSTATE;
                    break;
                }
            }

        }
        // line state operation
        while (STATE == LINESTATE) {
            ch = instream.get();
            if (ch == EOF) {
                STATE = ENDLSTATE;
                break;
            }
            if (ch == '\\') {
                chk = instream.get();
                if (chk == EOF) {
                    STATE = ENDLSTATE;
                    break;
                }
                if (chk == 'n') {
                    STATE = READSTATE;
                    break;
                }
            }
        }
    }
}

/*
    ehh,, not until I learn more about C++ data streams. not too sure how parse
    a stream into a function yet.
*/

/* implementation */
// int main() {
//     return 0;
// }

/*  unfinished first attempt:

void removeComments(istream & instream, ostream & outstream) {
    int ch, chk;        // ch: char, chk: char check for comment
    while (true) {
        ch = instream.get();
        if (ch == EOF) break;
        // ops on encntr /
        if (ch == '/') {
            chk = instream.get();
            // line comment
            if (chk == '/') {
                while (true) {
                    ch = instream.get();
                    if (ch == '/'
                }
            }
            // standard comment
            if (chk == '*')
        }
    }
}

*/
