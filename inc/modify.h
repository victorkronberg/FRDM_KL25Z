/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file modify.h
* @brief modify.h header file
*
* This header file is the header file for modify.c
*
* @author: Laura Gong
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __MODIFY_H__
#define __MODIFY_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"

/**
* @brief Invokes ModifyCommand function
*
* This function parses through an argument string and 
* invokes the ModifyCommand function with the arguments
* specified
*
* @param void
* @return void
*/
void ModifyInvoker(void);

/**
* @brief Modifies contents of memory at user-specified address with
* user-specified value.  Value is in unsigned 32bit hex format
*
* This function modifies the contents of memory at an user-inputted 
* address or offset and modifies according to user-inputted value
*
* @param uint32_t address in memory
* @param uint32_t value to modify value at address location
* @return void
*/
void ModifyCommand(uint32_t address,uint32_t value);

#endif

