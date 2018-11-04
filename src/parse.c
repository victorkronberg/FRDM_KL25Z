/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
**
* @file parse.c
* @brief This file implements the parse function
*
* This function separates out space-delimited arguments from a string
*
* @author: Victor Kronberg
* @date September 28 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <parse.h>

char *parse(char *str, const char *delimiters, uint32_t argnumber)
{

	char *returnStr;
	char inputcopy[MAX_CMD_STRING_LENGTH];
	char *to;
	char *token[MAX_CMD_STRING_LENGTH];
	uint32_t i;

	if(argnumber >= 0 && str != NULL)
	{
		strcpy(inputcopy,str); //copy str to avoid manipulating input string
		//to = inputcopy;
		//token[0] = strtok(inputcopy,delimiters);
		returnStr = token[0];
/*
		for(i=0; i < argnumber; i++) //loop through tokens until argument requested is reached or end of tokens
		{
			token[i] = strtok(NULL, delimiters);
			returnStr = token[i];
		}
*/
		return returnStr;

	} 
	else 
	{
		returnStr = NULL; //return a null pointer if argnumber is not > 0 or NULL string was passed in
	}

	return returnStr;
	
}
