/*-----------------------------------------------------------------------------+
    CS106B(2013F) Asn2 Problem 1
    WNx - 2017-Feb-15 21:05
------------------------------------------------------------------------------*/

/*  Pseudo Code of Word Ladder Algorithm

Create an empty queue
Add the start word to the end of the queue
while (the queue is not empty) {
    Dequeue the first ladder from the queue
    if (the final word in this ladder is the destination word) {
        Return this ladder as the solution
    }
    for (each word in the lexicon of English words that differs by one letter) {
        if (that word hasnt already been used in a ladder) {
            Create a copy of the current ladder
            Add the new word to the end of the copy
            Add the new ladder to the end of the queue.
        }
    }
}
Report that no word ladder exists

*/

// Cannot reuse words included in a previous ladder. - BFS
