/*
 * 04 Mirror Bits
 * Reverse the order of bits in a given int
 */
//
#include <iostream>

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
int main() {
    int a;
    std::cout << "integer: ";
    std::cin >> a;
    std::cout << mirrorBits(a) << std::endl;
    return 0;
}


// Reference: http://stackoverflow.com/questions/2602823/in-c-c-whats-the-simplest-way-to-reverse-the-order-of-bits-in-a-byte
        // & http://graphics.stanford.edu/~seander/bithacks.html#BitReverseObvious
        // & http://stackoverflow.com/questions/35844809/how-to-find-the-nth-bit-of-an-integer-in-c
