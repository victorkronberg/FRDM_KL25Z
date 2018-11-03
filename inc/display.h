/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file display.h
* @brief display.h header file
*
* This header file is the header file for display.c
*
* @author: Laura Gong
* @date September 26 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"
#include "main.h"
#include "checkInput.h"

/**
* @brief Invokes DisplayCommand function
*
* This function parses through an argument string and 
* invokes the DisplayCommand function with the arguments
* specified
*
* @param void
* @return void
*/
void DisplayInvoker(void);

/**
* @brief Displays contents of memory in unsigned 32bit hex format
*
* This function displays the contents of memory in unsigned 32bit hex
* format, based on an user inputted starting address and user input
* of the number of 32 bit words to display
*
* @param uint32_t starting address in memory
* @param uint32_t number of 32 bit words to display
* @return void
*/
void DisplayCommand(uint32_t address,uint32_t number);

#endif

