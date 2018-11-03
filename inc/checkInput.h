/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file checkInput.h
* @brief checkInput.h header file
*
* This header file is the header file for checkInput.c
*
* @author: Victor Kronberg
* @date September 26 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __CHECK_INPUT_H__
#define __CHECK_INPUT_H__

#include <stdint.h>
#include <stdio.h>
#include "allocate.h"
#include "parse.h"
#include "main.h"

/**
* @brief Check input for correct number of arguments and argument format
*
* This function checks input for correct number of tokens and correct format
*
* @param uint32_t argument number to check
* @param uint32_t type of input to check
* @param pointer to char string of input
* @return boolean logic (true or false)
*/
uint32_t CheckInput(uint32_t argument_number,char *argument_type,uint32_t additional_args);

#endif
