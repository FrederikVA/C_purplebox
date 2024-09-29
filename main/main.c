#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "box.h" 

box_open = false;


int main() {
    printf("Program started\n");
    start_input_thread();

    while (1) {
        
        int current_time = current_time_as_int(); 
        printf("Current time is: %d\n", current_time);

        if (box_open) {
            printf("Box is open\n");
        }
        if (input_close_box) {
            box_open = false;
            input_close_box = false;
            printf("Box is closing\n");
        }
        if (input_open_box) {
            box_open = true;
            printf("Box is opened manually\n");
        }        
        if (exit_program) {
            printf("Exiting program\n");
            return 0;
        }
        else if (current_time == 1250 || current_time == 1255) {
            box_open = true;
            printf("Box opens\n");
        } else {
            printf("Box is closed\n");
        }

        sleep(59);
    }
    return 0;
}
