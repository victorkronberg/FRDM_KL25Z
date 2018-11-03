/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file parse.h
* @brief parse.h header file
*
* This is the header file for parse.c
*
* @author: Victor Kronberg
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __PARSE_H__
#define __PARSE_H__

#define MAX_CMD_STRING_LENGTH (100)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "checkInput.h"


/**
* @brief Parses space-delimited input string
*
* This function separates an input string by white space 
* and returns a pointer to a string containing the argument
* requested
*
* @param pointer to string of char
* @pointer to const string of char
* @uint32_t argnumber
* @return pointer to a string of char
*/
char *parse(char *str, const char *delimiters, uint32_t argnumber);
void nextToken(char *strin, char *copy, uint32_t ctr);

#endif
