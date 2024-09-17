#include <stdio.h>
#include <time.h>
#include "box.h"

// Function to print the current time
void print_current_time() {
    time_t t;
    struct tm* tm_info;

    time(&t);                      // Get the current time
    tm_info = localtime(&t);       // Convert to local time

    char time_str[26];             // Buffer to store time string
    strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", tm_info);  // Format the time
    printf("Current time: %s\n", time_str);
}
