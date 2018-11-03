/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file free.h
* @brief free.h header file
*
* This header file is the header file for free.c
*
* @author: Laura Gong
* @date September 29 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __FREE_H__
#define __FREE_H__

#include <stdint.h>
#include <stdio.h>
#include <allocate.h>

/**
* @brief Invokes FreeCommand function
*
* This function invokes the free command to free the last block of memory allocated 
* with functions in allocate.c
*
* @param void 
* @return void
*/
void FreeInvoker(void);

/**
* @brief Frees the last block of memory allocated by functions in allocate.c
*
* This function uses free() to free the memory block that was allocated
*
* @param void
* @return void
*/
void FreeCommand(void);

#endif

