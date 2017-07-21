// 2017-Jul-14 02:56

#include <iostream>

void loop(int power) {
    uint32_t ter = 0;
    uint32_t num = 2;
    for (int i = 0; i < power-1; i++) {
        num *= 2;
    }
    std::cout << "2^" << power << ":" << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << "\r" << std::flush;
        ter++;
        std::bitset<32> b(ter);
        std::cout << b;
        // std::cout << ter;
    }
    // std::cout << ter;
    std::cout << std::endl;
}
int main() {
    // loop(16);
    // loop(18);
    // loop(20);
    // loop(22);
    // loop(24);
    // loop(26);
    // loop(28);
    // loop(30);
    // loop(32);
    std::cout << std::bitset<256> (0) << std::endl;
    return 0;
}


/*      Python counting
ter = 0
for i in range(512):
    if ter == 0: ter += 2
    else: ter *= 2
    if (i+1) < 10: print("{}   {}".format(i+1, (ter)))
    elif (i+1) < 100: print("{}  {}".format(i+1, (ter)))
    else: print("{} {}".format(i+1, (ter)))


num = 2**25
ter = 0
for i in range(num):
    ter += 1
    print("{}".format(ter), end="\r")
    sys.stdout.flush()
    if i == num:
        print("")



    sys.stdout.write("{}   \r".format(ter) )
    sys.stdout.flush()

import sys
for i in range(10**6):
    perc = float(i) / 10**6 * 100
    print(">>> Download is {}% complete".format(perc), end = "\r")
    sys.stdout.flush()
print("")
*/
