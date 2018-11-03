/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/*
* @file write.h
* @brief This is the header file for write.c
*
* @author: Victor Kronberg
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __WRITE_H__
#define __WRITE_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"
#include "main.h"


/**
* @brief Invokes WriteCommand function
*
* This function parses through an argument string and 
* invokes the WriteCommand function with the arguments
* specified
*
* @param void
* @return void
*/
void WriteInvoker(void);

/**
* @brief Writes a psuedo random pattern of bits into the specified
* address values
*
* This function generates a psuedo random pattern of numbers to write
* into a specified address space
*
* @param uint32_t address in memory
* @param uint32_t number of words to write random bit sequences to
* @param uint32_t seed value for random number generator
* @return void
*/
void WriteCommand(uint32_t address,uint32_t number,uint32_t seed);

#endif
