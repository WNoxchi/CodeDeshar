/*
 *  Wayne Hakan Nixalo - 04-Dec-2016 00:34
 *  CodeFights - Corner of 0s and 1s
 *  01 Kill K-th Bit
 */

// sets k'th bit (1-index) to zero
int killKthBit(int n, int k) {
    return n &= ~(1 << (k-1));
}

// return &= ~(1 << k) for zero-indexing.
// References:
// http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
// https://www.tutorialspoint.com/cplusplus/cpp_operators.htm
// http://www.bogotobogo.com/cplusplus/quiz_bit_manipulation.php

/*
 * 02 Array Packing    -   04-Dec-2016 00:50
 * Takes array of ints, packs them into one number, st 1st int
 * is 1st 8 bits, & so on.
 */

int arrayPacking(std::vector<int> a) {
    int pkg = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
    //  shift pkg by 8 bits
     pkg <<= 8;
    //  add a[i] to pkg by ORing
     pkg |= a[i];
    }
    return pkg;
}

/*
 * 03 Range Bit Count   -   04-Dec-2016 01:17
 * Count 1's in all ints btwn a & b inclusive; 0 ≤ a ≤ b
 */
// Brian Kernighan Algorithm - http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
//  & http://stackoverflow.com/questions/12383002/please-explain-the-logic-behind-kernighans-bit-counting-algorithm
int rangeBitCount(int a, int b) {
    int bitcount = 0;
    for (int i = a; i <= b; i++) {
        int n = i;
        while (n) {
            n &= (n-1);
            bitcount++;
        }
    }
    return bitcount;
}

// a dumber, simpler way:
// while(n)
// {
//   bitcount += n & 1;
//   n >>= 1;
// }
// return count;

/*
 * 04 Mirror Bits   -   04-Dec-2016 12:29
 * Reverse the order of bits in a given int
 */
//
// #include <iostream>

int mirrorBits(int a) {
    int b = 0, mask = 0, index = 0;
    while (a) {
        b <<= 1;
        mask = 1 << index;
        mask &= a;
        b += mask;
        a >>= 1;
    }
    return b;
}
// int main() {
//     int a;
//     std::cout << "integer: ";
//     std::cin >> a;
//     std::cout << mirrorBits(a) << std::endl;
//     return 0;
// }


// Reference: http://stackoverflow.com/questions/2602823/in-c-c-whats-the-simplest-way-to-reverse-the-order-of-bits-in-a-byte
        // & http://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
        // & http://stackoverflow.com/questions/35844809/how-to-find-the-nth-bit-of-an-integer-in-c



// // This is the way to fully mirror an 8-bit number:
// int mirrorBits(int a) {
//     a = (a & 0xF0) >> 4 | (a & 0x0F) << 4;
//     a = (a & 0xCC) >> 2 | (a & 0x33) << 2;
//     a = (a & 0xAA) >> 1 | (a & 0x55) << 1;
//     return a;
// }

/*
 * 05 Second-Rightmost Zero Bit -   04-Dec-2016 15:07
 * Find the 0-based pos of the 2nd rightmost bit (counting right to left) in an int.
 */
//
int secondRightmostZeroBit(int n) {
  return ~(~n & (~n - 1)) ^ (~((~n & (~n - 1)) & ((~n & (~n - 1)) - 1)));
}

// Formula: set rightmost 1 -> 0:
//     x & (x - 1)
// --> rightmost 0 -> 1:
//     ~(x & (x - 1))
// Full Formula:
//     x = ~n & (~n - 1)
//     ~x ^ (x & (x - 1)

// Formula to change rightmost set bit to 0: x & (x - 1)
// Changing rightmost 0s to 1s, and XORing w/ n having only rightmost 0 to 1
//     yields result.
// -->
// ~n&(~n-1) : x&(x-1) ; x = ~n                            // n = 100101
// now instead have: x = (~n&(~n-1))
//             -->   x&(x-1) = (~n&(~n-1))&((~n&(~n-1))-1) //   = 100000
//     this is n, negated, w/ rightmost 1 bits set to 0
//     Now we negate it iot have n w/ 2 rightmost 0s to 1:
//             -->   ~((~n&(~n-1))&((~n&(~n-1))-1))        //   = 101111
//     Now we XOR this with n w/ the rightmost 0 set to 1:
//             -->   ~(~n&(~n-1)) ^ ~((~n&(~n-1))&((~n&(~n-1))-1)) // = 2**3 = 8
// // solution from DerReinhardt: https://codefights.com/forum/uqyXAGHmyb27BBbEH
// // another reference: http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know/


// multi-line way:
// int secondRightmostZeroBit(int n) {
//     int pos = -1, zeropos = -1, zero = 0;
//     while (a && (zero < 2)) {
//         pos++;
//         if (!(1 & a)) {
//             zero++;
//             zeropos = pos;
//         }
//         a >>= 1;
//     }
//   return 1 << zeropos ;
// }
