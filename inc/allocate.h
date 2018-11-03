/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file allocate.h
* @brief allocate.h header file
*
* This header file is the header file for allocate.c
*
* @author: Laura Gong
* @date September 26 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __ALLOCATE_H__
#define __ALLOCATE_H__

#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "checkInput.h"

extern uint32_t *ptr_to_mem;
extern uint32_t mem_block_size;

/**
* @brief Invokes AllocateCommand function
*
* This function parses through an argument string and 
* invokes the AllocateCommand function with the argument
* specified
*
* @param void 
* @return void
*/
void AllocateInvoker(void);

/**
* @brief Allocates a block of memory for use by the application
*
* This function uses malloc() to allocate a block of memory, based
* on the number of 32 bit words that the user specifies
*
* @param uint32_t number of 32 bit words to allocate
* @return pointer to uint32_t value
*/
uint32_t *AllocateCommand(uint32_t number);

#endif

