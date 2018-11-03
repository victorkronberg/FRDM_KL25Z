/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file invert.h
* @brief invert.h header file
*
* This header file is the header file for invert.c
*
* @author: Laura Gong
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __INVERT_H__
#define __INVERT_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"
#include "main.h"

/**
* @brief Invokes InvertCommand function
*
* This function parses through an argument string and 
* invokes the InvertCommand function with the arguments
* specified
*
* @param void
* @return void
*/
void InvertInvoker(void);

/**
* @brief Inverts all bits in an area of memory at user-specified address for
* user-specified number of words.  
*
* This function inverts all the bits in an area of memory using XOR at an user-inputted 
* address for user-specified number of words
*
* @param uint32_t address in memory
* @param uint32_t number of words to perform XOR on
* @return void
*/
void InvertCommand(uint32_t address,uint32_t number);

#endif

