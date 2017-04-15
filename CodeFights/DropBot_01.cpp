// iOS password 10 attempts checking:
bool incorrectPasscodeAttempts(std::string passcode, std::vector<std::string> attempts) {
    int miss = 0;
    for (std::vector<std::string>::iterator iter = attempts.begin(); iter != attempts.end(); ++iter) {
        if (*iter != passcode)
            miss++;
        if (*iter == passcode)
            miss = 0;
        if (miss == 10)
            return true;
    }
    return false;
}

// apply sliding-window compression to a string:
str[i - w, i - 1] ; str[i, j]: substring of str[i:j] inclusive. <-- window
•Find start index st st: str[i, i + len - 1] = str[st, st + len - 1]
    and str[st, st + len - 1] is contained w/n window.
•If > 1 pair: choose largest, still: choose smallest startIndex.
•If search successful: append "(startIndex, len)" to result & move to
    index i + len.


// Not working correctly

std::string losslessDataCompression(std::string inputString, int width) {
    string result = "", window = "";
    int start = 0, length = 0, index = 0;
    while (true) {
        window = inputString.substr(start, length);
        if (window.find(inputString[index]) == std::string::npos) {
            result += inputString[index];
            length++;
        } else {
            result += "(" + to_string(start) + "," + to_string(length) + ")";
        }
        index++;
        if (index == inputString.length()) {
            break;
        }
    }
    return result;
}

// Input:
// inputString: "abacabadabacaba"
// width: 7
// Output:
// "ab(0,2)c(0,3)(0,3)(0,3)d(0,4)(0,4)(0,4)(0,4)(0,4)(0,4)(0,4)"
// Expected Output:
// "ab(0,1)c(0,3)d(4,3)c(8,3)"
//
// Input:
// inputString: "abacabadabacaba"
// width: 8
// Output:
// "ab(0,2)c(0,3)(0,3)(0,3)d(0,4)(0,4)(0,4)(0,4)(0,4)(0,4)(0,4)"
// Expected Output:
// "ab(0,1)c(0,3)d(0,7)"
//
// Input:
// inputString: "aaaaaaaaaaaaaaaaaaaaaaaaaaaa"
// width: 12
// Output:
// "a(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)(0,1)"
// Expected Output:
// "a(0,1)(0,2)(0,4)(0,8)(4,12)"
