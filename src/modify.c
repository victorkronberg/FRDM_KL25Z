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
	char arg1[MAX_ARG_LENGTH];
	char arg2[MAX_ARG_LENGTH];
	char arg3[MAX_ARG_LENGTH];
	if(ptr_to_mem != NULL)
	{

		scanf("%s",arg1);
		printf("\r\n%s ",arg1);
		char *arg1ptr = arg1;

		//Case 1: Sepcial flag "X" has been raised, use pointer to mem block as starting point for command
		if(CheckInput(arg1ptr,SPECFLAG,FALSE))
		{
			//arg1 = special flag
			//arg2 = offset from mem pointer
			scanf("%s",arg2);
			printf(" %s ",arg2);
			//arg3 = value to write to memory
			scanf("%s",arg3);
			printf("%s\r\n",arg3);
			char *arg2ptr = arg2;
			char *arg3ptr = arg3;
			if(CheckInput(arg2ptr,NUMBERS,TRUE) && CheckInput(arg3ptr,NUMBERS,FALSE))
			{
				uint32_t offset;
				uint32_t value;

				offset = (uint32_t)atoi(arg2);
				value = (uint32_t)atoi(arg3);


				uint32_t starting_address = (uint32_t)((uintptr_t)(ptr_to_mem+offset));

				ModifyCommand(starting_address,value);
			}
			else
			{
				printf("Invalid arguments for modify command. Please try again.\r\n");
				return;
			}

		}
		else if(CheckInput(arg1ptr,HEXADECIMAL,TRUE))
		{
			//Case 2: No special flag raised, input full address value
			//arg1 = address
			//arg2 = value to write to memory
			scanf("%s",arg2);
			printf(" %s\r\n",arg2);
			char *arg2ptr = arg2;
			if(CheckInput(arg2ptr,NUMBERS,FALSE))
			{
				char **endptr = NULL;
				uint32_t address_int;
				uint32_t value;

				address_int = (uint32_t)strtol(arg1,endptr,16);
				value = (uint32_t)atoi(arg2);

				ModifyCommand(address_int,value);

			}
			else
			{
				printf("Invalid arguments for modify command. Please try again.\r\n");
				return;
			}
		}
		else
		{
			printf("Invalid arguments for modify command. Please try again.\r\n");
		}
	}
	else
	{
		printf("You have no allocated memory to modify.\r\n");
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
