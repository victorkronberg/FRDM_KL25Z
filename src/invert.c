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
			//arg2 = offset from mem block pointer
			scanf("%s",arg2);
			printf(" %s ",arg2);
			//arg3 = number of words to invert
			scanf("%s",arg3);
			printf("%s\r\n",arg3);
			char *arg2ptr = arg2;
			char *arg3ptr = arg3;
			if(CheckInput(arg2ptr,NUMBERS,TRUE) && CheckInput(arg3ptr,NUMBERS,FALSE))
			{
				uint32_t offset;
				uint32_t num_words;

				offset = (uint32_t)atoi(arg2);
				num_words = (uint32_t)atoi(arg3);


				uint32_t starting_address = (uint32_t)((uintptr_t)(ptr_to_mem+offset));

				InvertCommand(starting_address,num_words);
			}
			else
			{
				printf("Invalid arguments for invert command. Please try again.\r\n");
				return;
			}

		}
		else if(CheckInput(arg1ptr,HEXADECIMAL,TRUE))
		{
			//Case 2: No special flag raised, input full address value
			//arg1 = starting address value
			//arg2 = number of workds to invert
			scanf("%s",arg2);
			printf(" %s\r\n",arg2);
			char *arg2ptr = arg2;
			if(CheckInput(arg2ptr,NUMBERS,FALSE))
			{
				char **endptr = NULL;
				uint32_t address_int;
				uint32_t num_words;

				address_int = (uint32_t)strtol(arg1,endptr,16);
				num_words = (uint32_t)atoi(arg2);

				InvertCommand(address_int,num_words);

			}
			else
			{
				printf("Invalid arguments for invert command. Please try again.\r\n");
				return;
			}
		}
		else
		{
			printf("Invalid arguments for invert command. Please try again.\r\n");
		}
	}
	else
	{
		printf("You have no allocated memory to invert.\r\n");
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
