// TimeKeeper v0.02 Wayne H Nixalo 2017 - for UNIX systems
// 2017-Jun-29 17:18

#include <iostream>     // Console I/O
#include <chrono>       // Time functions
// #include <unistd.h>     // UNIX pause execution (debugging)
#include <ctime>        // Date-Time
#include <fstream>      // File I/O
#include <string>       // File search

void checkTime(std::string dateString);
int main() {

    // open/create file; std::ios::app <-- start at end of file
    std::fstream timelog;
    timelog.open("timelog.txt", std::ios::app);
    if (!timelog.is_open()) {
        std::cout << "Error opening `timelog.txt`" << std::endl;
        return 1;
    }

    // timer variables
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    double duration = 0;
    std::chrono::duration<double> difference;
    std::time_t time_today = std::chrono::system_clock::to_time_t(
                                    std::chrono::system_clock::now());
    std::string dateString = std::string(std::ctime(&time_today), 0, 10);

    // program state
    int MODE = 0;

    std::cout << "TimeKeeper v0.01; Wayne Nixalo 2017" << std::endl;

    // prompt for input
    std::cout << "Enter `s` to start counter, `e` to pause, `q` to quit, or ";
    std::cout << " `t`/`d` to display elapsed time" << std::endl;
    char input = ' ';
    while (std::tolower(input) != 'q') {
        std::cout << "start:s | stop:e | quit:q   >> ";
        std::cin >> input;

        // Start timer
        if (std::tolower(input) == 's') {
            if (!MODE) {
                start = std::chrono::steady_clock::now();
                MODE = 1;
                std::cout << "Timer: ON" << std::endl;
            } else {
                std::cout << " < Timer already running > " << std::endl;
            }
        }

        // Stop timer
        if (std::tolower(input) == 'e') {
            if (MODE) {
                end = std::chrono::steady_clock::now();
                difference = end - start;
                duration +=  difference.count();
                MODE = 0;
                std::cout << "Timer: OFF" << std::endl;
            } else {
                std::cout << " < Timer already stopped > " << std::endl;
            }
        }

        // Quit
        if (std::tolower(input) == 'q') {
            // record final time if running
            if (MODE) {
                end = std::chrono::steady_clock::now();
                difference = end - start;
                duration += difference.count();
            }
            // save time to file
            // use system_clock to get ctime date converstion
            std::chrono::time_point<std::chrono::system_clock> end;
            end = std::chrono::system_clock::now();
            int H = (int)(duration / 3600), M = (int)((duration - H*3600) / 60);
            double S = (duration - H*3600 - M*60);
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            timelog << "Time Log: " << std::ctime(&end_time) << " - ";
            timelog << H << "h" << M << "m " << S << "s";
            timelog << " | " << duration << "\n";
            timelog.close();
            std::cout << "Time Logged: " << duration << " | ";
            std::cout << H << "h" << M << "m " << S << "s" <<std::endl;
            std::cout << "Written to file: timelog.txt" << std::endl;

            checkTime(dateString);
        }

        // Display time
        if (std::tolower(input) == 't' || std::tolower(input) == 'd') {
            end = std::chrono::steady_clock::now();
            difference = end - start;
            std::cout << "Time Elapsed: " << duration + difference.count();
            std::cout << " seconds" << std::endl;
        }
    }
    return 0;
}

/* tallies up time logged for a particular day */
void checkTime(std::string dateString = "") {
    // if no date string input default to today
    if (dateString == "") {
        std::time_t time_today = std::chrono::system_clock::to_time_t(
                                        std::chrono::system_clock::now());
        std::string dateString = std::string(std::ctime(&time_today), 0, 10);
    }
    dateString = "Time Log: " + dateString;

    // open file
    std::ifstream timelog;
    timelog.open("timelog.txt");
    if (!timelog.is_open()) {
        std::cout << "Error opening `timelog.txt`" << std::endl;
        return;
    }

    double total = -1;
    std::string buffer;

    // check if date logged
    while (!timelog.eof()) {        // NOTE: could this give an off-by-1 error?
        std::getline(timelog, buffer);
        buffer = buffer.substr(0, 20);
        if (dateString.compare(buffer) == 0) {
            total = 0;
            break;
        }
    }
    if (total < 0) {
        std::cout << dateString << " not found in log." << std::endl;
        timelog.close();
        return;
    }
    while(!timelog.eof() || dateString.compare(buffer) == 0) {
        // find duratin(seconds) & add to total
        std::getline(timelog, buffer);
        int idx = buffer.find_first_of("|");
        idx += 2;                   //  duration starts a space over from `|`
        buffer = buffer.substr(idx, 12); // will use up to 12 digits+point
        total += std::stod(buffer); // string to double

        // go to next dated line
        std::getline(timelog, buffer);
        buffer = buffer.substr(0, 20);
    }
    timelog.close();
    int H = (int)(total/3600); int M = (int)((total - H*3600)/60);
    dateString.erase(0,10);
    std::cout << "Total time logged for " << dateString << ": " << total;
    std::cout << " seconds" << std::endl;
    std::cout << "                                  ";
    std::cout << H << ":" << M << ":" << total - H*3600 - M*60 << std::endl;
}

/*  Change Log:
v0.02: 2017-Jun-29 17:18    - displays total logged time for given day
v0.01: 2017-Jun-28 14:37-51 - basic functionality
*/

// NOTE:    apparently this doesn't work:
// if (!timelog.open("timelog.txt", std::ios::app)) {
//     printf("Error openning file\n");
//     return 1;
// }

// 2017-Jun-28 14:37-51 figuring out how to use time functions:
// #include <iostream>
// #include <chrono>
// #include <unistd.h>
//
// int main() {
// 	auto start = std::chrono::steady_clock::now();
//
// 	usleep(1e6);
//
// 	auto end   = std::chrono::steady_clock::now();
//
// 	// std::cout << end - start << std::endl;
//
// 	std::chrono::duration<double> diff = end - start;
//
// 	std::cout << diff.count() << std::endl;
// }

// 2017-Jun-29 15:20 figuring out how to find things
// #include <chrono>
// #include <ctime>
// #include <iostream>
// #include <typeinfo>
// #include <string>
//
// int main() {
// 	auto now = std::chrono::system_clock::now();
// 	// std::cout << typeid(now).name() << std::endl;
// 	std::time_t time_now = std::chrono::system_clock::to_time_t(now);
// 	std::cout << std::ctime(&time_now);
// 	std::string datetime = std::ctime(&time_now);
// 	std::cout << datetime << std::endl;
// }

// more time function stuff
// string (const string& str, size_t pos, size_t len = npos);
// std::time_t time_today = std::chrono::system_clock::to_time_t(
//                                 std::chrono::system_clock::now());
// // std::string datetime   = std::ctime(&time_today);
//
// std::string datetime = std::string(std::ctime(&time_today), 0, 10);
