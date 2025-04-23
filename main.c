#include <stdlib.h>
#include <stdio.h>
#include "autoid.h"

#define CONTROLLER_UNIQUE_ID 0x12345678

/**
 * @file main.c
 * @brief Entry point for the firmware candidates test application.
 *
 * This file contains the main function, which serves as the starting point
 * for the execution of the program. It processes command-line arguments
 * and initializes the application.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @return An integer representing the exit status of the program.
 */
int main(int argc, char *argv[])
{
    uint32_t *terminals_list = NULL;
    int32_t terminal_count = auto_identify_terminals(CONTROLLER_UNIQUE_ID, &terminals_list);

    if (0 == terminal_count)
    {
        printf("No terminals found\n");
    }
    else
    {
        printf("Found %d terminal/s\n", terminal_count);
        for (size_t i = 0; i < terminal_count; i++)
        {
            printf("Terminal ID %08X\n", terminals_list[i]);
        }
    }
    return 0;
}