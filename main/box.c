#include "box.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

bool input_close_box = false;
bool input_open_box = false;
bool exit_program = false;

int current_time_as_int() {
    time_t t;
    struct tm* tm_info;

    time(&t);                        // Get current time
    tm_info = localtime(&t);         // Convert to local time

    int hours = tm_info->tm_hour;    // Get hours
    int minutes = tm_info->tm_min;   // Get minutes

    return hours * 100 + minutes;    // Return time in HHMM format
}

void* user_input_thread() {
    char command[100];
    while (1) {
        printf("From input-thread: Enter command: 'close' or 'exit'\n");
        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "close\n") == 0) {
            input_close_box = true;
        } else if (strcmp(command, "exit\n") == 0) {
            exit_program = true;
        } 
        //for a button inside the box for opening the lock if its locked but door is open.
        else if (strcmp(command, "open\n") == 0) { 
            box_open = true;
        }
        
    }
    return NULL;
}

void start_input_thread() {
    pthread_t thread;
    pthread_create(&thread, NULL, user_input_thread, NULL);
    pthread_detach(thread); // Detach the thread if you don't need to join it later
}

