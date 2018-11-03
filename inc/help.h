/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file help.h
* @brief An abstraction for the command line help function
*
* This header file provides an abstraction of the help command
*
* @author: Victor Kronberg
* @date September 22 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __HELP_H__
#define __HELP_H__
#include <stdint.h>
#include <stdio.h>

/**
* @brief Implements help function
*
* This function prints out available command-line commands
* to stdout and provides details on how to call them
*
* @param void 
* @return void
*/

void help(void);

#endif
