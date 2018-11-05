/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file allocate.c
* @brief This file implements the AllocateCommand function and AllocateInvoker function
*
* This file implements the AllocateCommand function and AllocateInvoker function
*
* @author: Laura Gong
* @date September 26 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <allocate.h>
#include <main.h>

uint32_t *ptr_to_mem = NULL;
uint32_t mem_block_size = 0;

void AllocateInvoker(void)
{

	char arg1[MAX_ARG_LENGTH];
	scanf("%s",arg1);
	printf("\r\n%s\r\n",arg1);
	char *argptr = arg1;
	if(CheckInput(argptr,NUMBERS,FALSE))
	{
		//char *word_str=parse(input,delimiters,ARG1);
		uint32_t words = atoi(arg1);
		ptr_to_mem = AllocateCommand(words);
		
	}
	else
	{
		printf("Invalid arguments to allocate command. No memory will be allocated.\r\n");
	}

	return;

}

uint32_t *AllocateCommand(uint32_t number_words)
{
	if(ptr_to_mem == 0)
	{
		ptr_to_mem = (uint32_t *)malloc((number_words)*(sizeof(uint32_t)));
		mem_block_size = number_words;
		printf("Allocated %u words.\r\n", mem_block_size);
	} 
	else 
	{
		printf("No new memory allocated, %u words are already allocated.\r\n", mem_block_size);
	}

	if(ptr_to_mem != 0)
	{
		printf("Your allocated memory address range is [%p - %p].\r\n\r\n", ptr_to_mem, ptr_to_mem + mem_block_size-1);
	}

	return ptr_to_mem;

}
