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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

// All the shell functionalities here
void shell_functions(char command[BUFFER_LEN], char *token_array[BUFFER_LEN], int token_num) {
  // cd command -- change the current directory
  if (strcmp(command, "cd") == 0)
  {
    // if has argument
    if (token_num > 1) {
      // Change directory
      int ret = chdir(token_array[1]);
      // Error handling
      if (ret != 0)
        perror("Failed");
    }
    // Set PWD and print current dir
    char buf[BUFFER_LEN];
    getcwd(buf, sizeof(buf));
    setenv("PWD", buf, 1);
    printf("%s\n", buf);
  }

  // echo command -- print
  else if (strcmp(command, "echo") == 0)
  {
    for (int j = 1; j < token_num; j++) {
      printf("%s ", token_array[j]);
    }
    printf("\n");
  }

  // dir command -- ls
  else if (strcmp(command, "dir") == 0)
  {
    DIR *d;
    struct dirent *dir;
    // If has arg, set to that dir
    if (token_num > 1)
      d = opendir(token_array[1]);
    // If not, set to current dir
    else
      d = opendir(".");
    // If open success
    if (d) {
      while ((dir = readdir(d)) != NULL)
        printf(" [%s] ", dir->d_name);
      closedir(d);
      printf("\n");
    }
    // Error handling
    else
      perror("Failed");
  }

  // pause command
  else if (strcmp(command, "pause") == 0)
  {
    printf("Press ENTER key to continue\n");
    getchar();
  }

  // clr command -- clear
  else if (strcmp(command, "clr") == 0)
  {
    printf("\e[1;1H\e[2J");
  }

  // help command -- readme
  else if (strcmp(command, "help") == 0)
  {
    FILE *fp;
    fp = fopen("readme", "r");
    if (fp == NULL) {
      printf("Error when open readme! Make sure you are in the correct directory!\n"); // Check if file exists
    }
    else {
      //int c;
      //while ((c = getc(fp)) != EOF)
        //putchar(c);
      system("more readme"); // OPEN WITH MORE FILTER
      fclose(fp);
    }
  }

  // environ command
  else if (strcmp(command, "environ") == 0)
  {
    int i = 0;
    extern char **environ;
    while(environ[i]) {
      printf("%s\n", environ[i++]); // prints in form of "variable=value"
    }
  }

  // quit command -- exit the shell
  else if (strcmp(command, "quit") == 0)
  {
      exit(0);
  }

  // Unsupported command
  else
  {
      printf("Unsupported command, use help to display the manual\n");
  }
}

// Command line prompt directory
void display_dir() {
  char buf[BUFFER_LEN];
  getcwd(buf, sizeof(buf));
  printf("%s$ ", buf);
}