# 6.006 Intro to Algorithms - MIT|ocw - Problem Set 4: DNA sequence matching
# Wayne H Nixalo - 2017-Apr-24 19:10

#!/usr/bin/env python2.7

import unittest
from dnaseqlib import *

### Utility classes ###

# Maps integer keys to a set of arbitrary values.
class Multidict:                 # 23-Apr-2017 20:50 - 21:00 | 2017-Apr-24 17:25
    # Initializes a new multi-value dictionary, and adds any key-value
    # 2-tuples in the iterable sequence pairs to the data structure.
    def __init__(self, pairs=[]):
        # raise Exception("Not implemented!")
        self.table = dict()
        for pair in pairs:
            self.put(pair[0], pair[1])     # apparently this works in Python eh?

        # self.table = dict()
        # for pair in pairs:
        #     self.put(pair[0], pair[1])

        # self.dict = {}
        # # if key unique: add; if not: append
        # for pair in pairs:
        #     if not dict.has_key(pair[0]):
        #         self.dict[pair[0]] = [pair[1]]
        #     else:
        #         self.dict[pair[0]].append(pair[1])
        
    # Associates the value v with the key k.
    def put(self, k, v):
        # raise Exception("Not implemented!")
        if self.table.has_key(k):
            self.table[k].append(v)
        else:
            self.table[k] = [v]

        # if self.table.has_key(k):
        #     self.table[k].append(v)
        # else:
        #     self.table[k] = [v]

    # Gets any values that have been associated with the key k; or, if
    # none have been, returns an empty sequence.
    def get(self, k):
        # raise Exception("Not implemented!")
        try:
            return self.table[k]
        except KeyError:
            return []

        # if self.table.has_key(k):
        #     return self.table[k]
        # else:
        #     return []

# Given a sequence of nucleotides, return all k-length subsequences
# and their hashes.  (What else do you need to know about each
# subsequence?)
def subsequenceHashes(seq, k):   # 23-Apr-2017 19:05 - 20:17 | 2017-Apr-24 17:25
    # raise Exception("Not implemented!")
    try:
        assert k > 0
        index = 0
        subseq = ''
        for i in xrange(k):
            subseq += seq.next()
        RH = RollingHash(subseq)
        while True:
            yield (RH.current_hash(), (index, subseq))
            previtm = subseq[0]
            subseq = subseq[1:] + seq.next()
            RH.slide(previtm, subseq[-1])
            index += 1
    except StopIteration:
        return

    # index = 0
    # subseq = ''
    # for i in range(k):
    #     subseq += seq.next()
    #     # try:
    #     #     subseq += seq.next()
    #     #     index += 1
    #     # except StopIteration:
    #     #     return
    # RH = RollingHash(subseq)
    # try:
    #     while True:
    #         yield (RH.current_hash(), (index, subseq))
    #         previtm = subseq[0]
    #         subseq = subseq[1:] + seq.next()
    #         RH.slide(previtm, subseq[-1])
    #         index += 1
    # except StopIteration:
    #     return

# Similar to subsequenceHashes(), but returns one k-length subsequence
# every m nucleotides.  (This will be useful when you try to use two
# whole data files.)
def intervalSubsequenceHashes(seq, k, m):   # 2017-Apr-24 20:48
    # raise Exception("Not implemented!")
    assert m > k
    assert k > 0
    index = 0
    try:
        while True:
            subseq = ''
            for i in xrange(k):
                subseq += seq.next()
            RH = RollingHash(subseq)
            yield (RH.current_hash(), (index, subseq))
            for i in xrange(m-k):
                seq.next()
            index += m
    except StopIteration:
        return

# Searches for commonalities between sequences a and b by comparing
# subsequences of length k.  The sequences a and b should be iterators
# that return nucleotides.  The table is built by computing one hash
# every m nucleotides (for m >= k).
def getExactSubmatches(a, b, k, m):     # 23-Apr-2017 21:14-21:38 | Apr-24 17:28
    # raise Exception("Not implemented!")
    print("Building Subsequence Database from A...")
    # a_database = Multidict(subsequenceHashes(a, k))
    a_database = Multidict(intervalSubsequenceHashes(a, k, m))
    # b_info = subsequenceHashes(b, k)
    print("Searching for Subsequence Matches in A, B...")
    for b_hash, (b_index, b_subseq) in subsequenceHashes(b, k):
        for a_index, a_subseq in a_database.get(b_hash):
            # if a_subseq == b_subseq:
            #     yield (a_index, b_index)
            if a_subseq != b_subseq:
                continue
            yield (a_index, b_index)

    # database_a = Multidict(subsequenceHashes(a, k))
    # for b_hash, (b_index, b_subseq) in subsequenceHashes(b, k):
    #     for a_index, a_subseq in database_a.get(b_hash):
    #         if a_subseq == b_subseq:
    #             yield (a_index, b_index)
    #         else:
    #             continue
    # return

    # x, y = -k, -k
    # while True:
    #     subseq_a = subsequenceHashes(a, k)
    #     x += k
    #     y = -k
    #     while True:
    #         subseq_b = subsequenceHashes(b, k)
    #         y += k
    #         if subseq_a[0] == subseq_b[0]:
    #             if subseq_a[1] == subseq_b[1]:
    #                 yield (x, y)


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print 'Usage: {0} [file_a.fa] [file_b.fa] [output.png]'.format(sys.argv[0])
        sys.exit(1)

    # The arguments are, in order: 1) Your getExactSubmatches
    # function, 2) the filename to which the image should be written,
    # 3) a tuple giving the width and height of the image, 4) the
    # filename of sequence A, 5) the filename of sequence B, 6) k, the
    # subsequence size, and 7) m, the sampling interval for sequence
    # A.
    compareSequences(getExactSubmatches, sys.argv[3], (500,500), sys.argv[1], sys.argv[2], 8, 100)
