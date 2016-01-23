Hangman Notes:

20-Jan-2016 15:36
Putting together the basic structure of the program.

20-Jan-2016 16:10
Working on guess checking. I got an idea. 2 things need to happen when a letter is guessed:
    First program needs to check if that letter is in the word at all.
    Second the program needs to build a new string that includes all correctly guessed letters.
This issue is that both these processes require program to look through every letter in the word, so it's done twice. Instead what I can do is specify a check integer at 0. If a matching letter is found, program builds the updated guessed word normally, but also adds 1 to the check integer. At the end of the for-loop, if check-integer == 0: # of tries goes down by 1, otherwise it proceeds normally.

20-Jan-2016 17:15
Finished first version of part one. Time to check and make sure the Console part works.

20-Jan-2016 17:18
Trying to figure out how to use the HandmanLexicon stub in the 1st part program. How to put it as an instance variable.

20-Jan-2016 17:31
I had to move my instance variables outside the run method... which is odd b/c it says in the handout that for the test version it should be inside...; and I defined another isntance variable: DoshDatabase the same way I'd initialize (or instantiate?) a RandomGenerator, by: private HangmanLexicon DoshDatabase = new HangmanLexicon(); Now when I want to pick a new word I pass the getWord(); method defined in the HangmanLexicon class into DoshDatabase. Ahaa, that's how you use methods defined in other classes.

20-Jan-2016 17:43
Taking a break. Having issue with Strings and char. Idk how to specify if a character in a string is equal to another character, and how to tell if a character is a letter. the .isLetter(); method isn't working.

20-Jan-2016 18:13
Back to work.

20-Jan-2016 18:27
Okay so the way you use .isLetter() is: Character.isLetter(theletter)

20-Jan-2016 18:36
Finally got program syntactically correct, however it crashes when I input a guess. It's getting convoluted as I go along, I'm going to start over and rewrite. The issue is, I think, I'm confusing the usage of instance variables and internally defined variables in my many method calls. I'm going to try instantiating what I'll need first, then make limited use of methods, or at least pass variables into them intelligently.

20-Jan-2016 20:58 Starting again after a 2 hour break.

20-Jan-2016 21:09
Apparently you CAN use << == >> to test the equality of characters, but not Strings. Is this because characters return a ASCII/UNICODE value and Strings return a memory address? Hmm, I wasn't sure if that was the case.

20-Jan-2016 21:19
Don't know how to get the input to be returned as uppercase -- going to make the console version work first, then figure that out.

20-Jan-2016 21:54
Got the console working. I kept losing, was worried it wasn't taking correct answers. Nah, turns out I'm really bad at hangman ))). But it doesn't accept letters of a different case, so that I have to fix.

20-Jan-2016 23:26
Got the console working. Fuck yeah. Job interview tomorrow morning - in 12 hours. get some.

--------------------------------------------------------------------------------

21-Jan-2016 20:58
Starting part II.

21-Jan-2016 21:29
Figured out how to clear GLabel graphical text on the screen in order to print new stuff. If you just say remove(getElementAt(x, y)) --- remove whatever graphical object is at (x,y), but nothing is there, then the program will crash. So use a conditional check: IF something is there, remove it. Then print the new guessed word.

21-Jan-2016 21:51
Got the Guessed word and wrong-guesses labels to work properly! Now on to drawing the hangman.

21-Jan-2016 22:27
Taking a break. Tired, head hurts. Working on drawing the hangman and scaffold. I'll draw the whole thing in the beginning and set it invisible, then set pieces visible as the game goes on. The issue, realy non-issue, is how to cleanly implement drawing all these GObjects. When my brain's fatigued this basic stuff becomes hard.

22-Jan-2016 11:34
Back to work.

22-Jan-2016 11:53
I don't know if this is a stupid way of going about things, but I think I'll make a private draw method with a counter inside it. Everytime it's called it checks what the counter is then executes one of 8 if statements. I wasn't able to make a switch that returns a GObject so I'm doing it this way. I'm sure when I see someone else's solution I'll realize how obvious a more elegant way was, but this is the 3rd day I'm working on this and I want it done now.

22-Jan-2016 13:49
Got the game working. Now I just need to do the 3rd part: read the lexicon from a file.

22-Jan-2016 14:14
I'm all finished, but I don't know why they had the last part of the assignment require information unknown until a later lecture. Something about buffered readers and arraylists; anyway, I used someone else's solution on line to see how this works. Apaprently they expected their students to see how the implementation works in class the next day anyway. This was supposed to be the easiest part of the assignment so I'm not concerned; I'll just look out for it in lecture.
