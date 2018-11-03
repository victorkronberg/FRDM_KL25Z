/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file free.c
* @brief This file implements the FreeCommand function and FreeInvoker function
*
* This file implements the FreeCommand function and FreeInvoker function
*
* @author: Laura Gong
* @date September 29 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <free.h>

void FreeInvoker(void)
{
	if(ptr_to_mem != 0)
	{
		printf("Freeing the memory block at: %p\n\n", ptr_to_mem);
		FreeCommand();
	} else {
		printf("You have no allocated memory to free.\n");
	}
}

void FreeCommand(void)
{
	free(ptr_to_mem);
	ptr_to_mem = NULL;
	mem_block_size = 0;
}
