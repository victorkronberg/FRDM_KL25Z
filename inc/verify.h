/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file verify.h
* @brief This is the header file for verify.c
*
* @author: Victor Kronberg
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __VERIFY_H__
#define __VERIFY_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"
#include "main.h"


/**
* @brief Invokes VerifyCommand function
*
* This function parses through an argument string and 
* invokes the VerifyCommand function with the arguments
* specified
*
* @param void
* @return void
*/
void VerifyInvoker(void);

/**
* @brief Verifies a psuedo random pattern of bits in a specified
* memory space
*
* This function verifies a psuedo random pattern of numbers
* written into a specified address space
*
* @param uint32_t address in memory
* @param uint32_t number of words to write random bit sequences to
* @param uint32_t seed value for random number generator
* @return void
*/
void VerifyCommand(uint32_t address,uint32_t number,uint32_t seed);

#endif
