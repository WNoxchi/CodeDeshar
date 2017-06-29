// TimeKeeper v0.01 Wayne H Nixalo 2017 - for UNIX systems
// 2017-Jun-28 14:37-51

#include <iostream>     // Console I/O
#include <chrono>       // Time functions
// #include <unistd.h>     // UNIX pause execution (debugging)
#include <ctime>        // Date-Time
#include <fstream>      // File I/O

int main() {
    // open/create file; std::ios::app <-- start at end of file
    std::fstream timelog;
    timelog.open("timelog.txt", std::ios::app);

    // timer variables
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    double duration = 0;
    std::chrono::duration<double> difference;

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
            std::cout << H << "h" << M << "m " << S << "s";
            std::cout << "Written to file: timelog.txt" << std::endl;
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


// NOTE:    apparently this doesn't work:
// if (!timelog.open("timelog.txt", std::ios::app)) {
//     printf("Error openning file\n");
//     return 1;
// }

// figuring out how to use time functions:
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
