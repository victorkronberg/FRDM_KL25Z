/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file checkInput.c
* @brief This file implements the Check Input function
*
* This file implements the Check Input function
*
* @author: Victor Kronberg
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <checkInput.h>
#include <main.h>

uint32_t CheckInput(char *input_str,char *argument_type,uint32_t additional_args)
{
	
	
	if(input_str!=NULL) //Check for appropriate number of arguments
	{
		if(strlen(input_str) == strspn(input_str,argument_type)) //Make sure argument does not contain illegal characters for argument_type
		{
			return TRUE;
		}
		else
		{
				return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
