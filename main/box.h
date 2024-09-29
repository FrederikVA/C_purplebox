#ifndef BOX_H
#define BOX_H
#include <stdbool.h>

int current_time_as_int();
void* user_input_thread();
void start_input_thread();

// Declaration of the global variable
extern bool box_open;
extern bool input_close_box;
extern bool input_open_box;
extern bool exit_program;

#endif
