#include <stdio.h>
#include <time.h>
#include "box.h"


#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Function to get the current time
char* current_time() {
    time_t t;
    struct tm* tm_info;
    static char buffer[26]; // Buffer to hold the formatted time string

    time(&t);                      // Get the current time
    tm_info = localtime(&t);       // Store the local time in tm_info

    strftime(buffer, 26, "%H:%M:%S", tm_info); // Format the time into the buffer
    return buffer; // Return the formatted time string
}
