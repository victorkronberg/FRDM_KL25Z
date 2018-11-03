/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file main.h
* @brief main.h header file
*
* This header file is the header file for main
*
* @author: Victor Kronberg
* @date September 22 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#define MAX_CMD_STRING_LENGTH (100)
#define CMND (0)
#define ARG1 (1)
#define ARG2 (2)
#define ARG3 (3)
#define ARG4 (4)
#define TRUE (1)
#define FALSE (0)
#define NUMBERS "0123456789"
#define HEXADECIMAL "0123456789abcdef"
#define HEXFLAG "X"
#define SPECFLAG "X"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>
#include "help.h"
#include "display.h"
#include "allocate.h"
#include "free.h"
#include "parse.h"
#include "modify.h"
#include "invert.h"
#include "write.h"
#include "verify.h"
#include "checkInput.h"

extern char *input;
extern const char *delimiters;

void mainfunc(void);


#endif

