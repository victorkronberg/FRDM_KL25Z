/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
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
	char *space = (char *)' ';
	char *ret = (char *)"/r";
	char *newline = (char *)"/n";

char *parse(char *str, const char *delimiters, uint32_t argnumber)
{
	
	char *returnStr = NULL;
	char inputcopy[MAX_CMD_STRING_LENGTH];
	char *ptr = inputcopy;
	uint32_t i;
	
	if(argnumber >= 0 && str != NULL && delimiters != NULL)
	{
		uint32_t ctr = 0;


		for(i=0; i <= argnumber; i++) //loop through tokens until argument requested is reached or end of tokens
		{

			nextToken(str,ptr,ctr);
			returnStr = ptr;

			if(strcmp((char *)str[ctr],ret)==0||strcmp((char *)str[ctr],newline)==0){
				return returnStr;
				//End of inputs
			}
		}
			
		return returnStr;

	} 
	else 
	{
		returnStr = 0; //return a null pointer if argnumber is not > 0 or NULL string was passed in
	}
	
	return returnStr;
	
}

void nextToken(char *strin, char *copy, uint32_t ctr){

	uint32_t j = 0;
	for(uint32_t i = ctr; i < MAX_CMD_STRING_LENGTH; i++)
	{
		*(copy+j)=strin[ctr];

			j++;
			while(1){

					}
			if(strcmp((char *)strin[ctr],space)==0\
								||strcmp((char *)strin[ctr],ret)==0\
								||strcmp((char *)strin[ctr],newline))
						{
							return;
						}
	}

}
