/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file modify.c
* @brief This file implements the ModifyCommand function and ModifyInvoker function
*
* This file implements the ModifyCommand function and ModifyInvoker function
*
* @author: Laura Gong
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <modify.h>

void ModifyInvoker(void)
{
	if(ptr_to_mem != NULL)
	{
		// Case 1 - User specifying the address to modify
		if (CheckInput(ARG1,HEXADECIMAL,TRUE) && CheckInput(ARG2,NUMBERS,FALSE))
		{
			char *addr_input=parse(input,delimiters,ARG1);
			char *value_str=parse(input,delimiters,ARG2);
			char **endptr = NULL;
			uint32_t address_int;
			uint32_t value;
	
			address_int = (uint32_t)strtol(addr_input,endptr,16);
			value = (uint32_t)atoi(value_str);
			
			ModifyCommand(address_int,value);
		}
		// Case 2 - User specifying the word number to modify
		else if(CheckInput(ARG1,SPECFLAG,TRUE) && CheckInput(ARG2,NUMBERS,TRUE) && CheckInput(ARG3,NUMBERS,FALSE))
		{
			char *word_input=parse(input,delimiters,ARG2);
			char *value_str=parse(input,delimiters,ARG3);
			uint32_t word_int = (uint32_t)atoi(word_input);
			uint32_t value = (uint32_t)atoi(value_str);

			uint32_t address = (uint32_t)((uintptr_t)(ptr_to_mem+word_int));
			ModifyCommand(address,value);

		}
		else
		{
			printf("Invalid arguments to modify command. Nothing will be modified.\n");
		}
	} 
	else 
	{
		printf("You have no allocated memory to modify.\n");
	}
	
}

void ModifyCommand(uint32_t address,uint32_t value)
{
	
	uint32_t valid_address_flag = 0;
	uint32_t ptr_increment = 0;
	while (ptr_increment < mem_block_size)
	{
		if((uint32_t)((uintptr_t)(ptr_to_mem+ptr_increment)) == address)
		{
			valid_address_flag = 1;
			*(ptr_to_mem+ptr_increment) = value;
			printf("You have modified the value at %p with this value: %u\n\n", ptr_to_mem+ptr_increment, value);
			break;	
		}
		ptr_increment++;
	}
	if(valid_address_flag==0)
	{
		printf("Error- You entered an unaligned address or an address outside of the allocated range.  Please enter an acceptable or aligned address.\n");
	}
}
