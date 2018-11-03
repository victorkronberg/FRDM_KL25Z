/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file invert.c
* @brief This file implements the InvertCommand function and InvertInvoker function
*
* This file implements the InvertCommand function and InvertInvoker function
*
* @author: Laura Gong
* @date September 30 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <invert.h>
#include <time.h>

void InvertInvoker(void)
{
	if(ptr_to_mem != NULL)
	{
		//Case 1: User provided starting address and number of words for invert command
		if(CheckInput(ARG1,HEXADECIMAL,TRUE) && CheckInput(ARG2,NUMBERS,FALSE))
		{
			char *addr_input=parse(input,delimiters,ARG1);
			char *value_str=parse(input,delimiters,ARG2);
			char **endptr = NULL;
			uint32_t address_int;
			uint32_t num_words;
			
			address_int = (uint32_t)strtol(addr_input,endptr,16);
			num_words = (uint32_t)atoi(value_str);
			
			InvertCommand(address_int,num_words);
		}
		//Case 2: Special flag raised - user specifies offset from memory-pointer and number of words to invert
		else if(CheckInput(ARG1,SPECFLAG,TRUE) && CheckInput(ARG2,NUMBERS,TRUE) && CheckInput(ARG3,NUMBERS,FALSE))
		{
			char *offset_str=parse(input,delimiters,ARG2);
			char *value_str=parse(input,delimiters,ARG3);
			uint32_t offset = (uint32_t)atoi(offset_str);
			uint32_t num_words = (uint32_t)atoi(value_str);
			
			uint32_t address = (uint32_t)((uintptr_t)(ptr_to_mem+offset));
			InvertCommand(address,num_words);
		}
		else
		{
			printf("Invalid arguments to invert command. Nothing will be inverted.\n");
		}
	} 
	else 
	{
		printf("You have no allocated memory to invert.\n");
	}
	
}

void InvertCommand(uint32_t address,uint32_t number)
{
	printf("Inverted %u word(s) starting from 0x%08x\n", number, address);
	//clock_t start = clock();

	uint32_t valid_address_flag = 0;
	uint32_t valid_number_flag = 0;
	uint32_t ptr_increment = 0;
	uint32_t allowed_block_size = mem_block_size;

	while (ptr_increment < mem_block_size)
	{
		if((uint32_t)((uintptr_t)(ptr_to_mem+ptr_increment)) == address)
		{
			valid_address_flag = 1;
			if(number <= allowed_block_size)
			{
				valid_number_flag = 1;
				for(uint32_t i = 0; i < number; i++)
				{
					*(ptr_to_mem+ptr_increment+i) ^= (uint32_t)(~0);
				}
				printf("Invert completed successfuly.\n");
			}
			break;	
		}
		ptr_increment++;
		allowed_block_size--;
	}
	if(valid_address_flag==0)
	{	
		printf("Error- You entered an unaligned address or an address outside of the allocated range.  Please enter an acceptable or aligned address.\n");
	}

	if(valid_number_flag==0)
	{
		printf("Error- Trying to invert values outside of allocated memory. Choose a different number of words to invert.\n");
	}

	//clock_t stop = clock();
	//double time_diff = (double)(stop-start)/CLOCKS_PER_SEC;
	//printf("InvertCommand function took %f seconds\n\n", time_diff); 
	
}
