/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2019, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

int main(int argc, char *argv[])
{
    // Get shell was executed from and set
    char *x;
    x = getenv("SHELL");
    x = strcat(x, "/myshell");
    setenv("SHELL", x, 1);

    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char *token_array[BUFFER_LEN];

    // If pass file as argument
    if (argc == 2) {
      FILE *fp;
      char *line = NULL;
      size_t len = 0;
      ssize_t read;

      // Open file
      fp = fopen(argv[1], "r");
      // Error handling
      if (fp == NULL) {
        printf("Error when read the file!\n");
        exit(0);
      }

      // Read every line
      while ((read = getline(&line, &len, fp)) != -1) {
        // Clear buffers
        memset(command, 0, BUFFER_LEN);
        memset(token_array, 0, BUFFER_LEN);

        // Tokenization
        int i = 0;
        token_array[i] = strtok(line, " \n"); // 1st token
        while(token_array[i] != NULL)
           token_array[++i] = strtok(NULL," \n"); // other tokens, if more than 1
        strcpy(command, token_array[0]); // command
        int token_num = i; // number of tokens

        // Check and execute command
        shell_functions(command, token_array, token_num);
      }
      free(line);
      exit(EXIT_SUCCESS);
    }

    // Command line prompt directory
    display_dir();

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // If user only enters carriage return
        // Prevent segmentation fault 11
        if (strcmp(buffer, "\n") == 0) {
          printf("Unsupported command, use help to display the manual\n");
          display_dir();
          continue;
        }

        // Clear buffers
        memset(command, 0, BUFFER_LEN);
        memset(token_array, 0, BUFFER_LEN);

        // Tokenization
        int i = 0;
        token_array[i] = strtok(buffer, " \n"); // 1st token
        while(token_array[i] != NULL)
           token_array[++i] = strtok(NULL," \n"); // other tokens, if more than 1
        strcpy(command, token_array[0]); // command
        int token_num = i; // number of tokens

        // Check and execute command
        shell_functions(command, token_array, token_num);

        // Command line prompt directory.
        display_dir();
    }
    return EXIT_SUCCESS;
}