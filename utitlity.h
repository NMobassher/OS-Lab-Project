/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2019, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef UTILITY_H_
#define UTILITY_H_
#define BUFFER_LEN 256

// Include your relevant functions declarations here they must start with the
// extern keyword such as in the following example:
// extern void display_help(void);

extern void shell_functions(char command[BUFFER_LEN], char *token_array[BUFFER_LEN], int token_num);
extern void display_dir();

#endif /* UTILITY_H_ */