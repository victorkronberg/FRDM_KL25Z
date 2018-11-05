/******************************************************************************************
* Copyright (C) 2018 by Laura Gong
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file display.c
* @brief This file implements the DisplayCommand function and DisplayInvoker function
*
* This file implements the DisplayCommand function and DisplayInvoker function
*
* @author: Laura Gong
* @date September 26 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <display.h>
#include <main.h>


void DisplayInvoker(void)
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
			scanf("%s",arg2);
			printf(" %s ",arg2);
			scanf("%s",arg3);
			printf("%s\r\n",arg3);
			char *arg2ptr = arg2;
			char *arg3ptr = arg3;
			if(CheckInput(arg2ptr,NUMBERS,TRUE) && CheckInput(arg3ptr,NUMBERS,FALSE))
			{
				uint32_t word_int;
				uint32_t num_words;

				word_int = (uint32_t)atoi(arg2);
				num_words = (uint32_t)atoi(arg3);


				uint32_t starting_address = (uint32_t)((uintptr_t)(ptr_to_mem+word_int));

				DisplayCommand(starting_address,num_words);
			}
			else
			{
				printf("Invalid arguments for display command. Please try again.\r\n");
				return;
			}

		}
		else if(CheckInput(arg1ptr,HEXADECIMAL,TRUE))
		{
			//Case 2: No special flag raised, input full address value
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

				DisplayCommand(address_int,num_words);

			}
			else
			{
				printf("Invalid arguments for display command. Please try again.\r\n");
				return;
			}
		}


		/*
		//Case 1: Specified address and number of words to display starting @ that address
		if(CheckInput(ARG1,HEXADECIMAL,TRUE) && CheckInput(ARG2,NUMBERS,FALSE)) 
		{
			char *addr_input=parse(input,delimiters,ARG1);
			char *word_str=parse(input,delimiters,ARG2);
			char **endptr = NULL;
			uint32_t address_int;
			uint32_t num_words;
			
			address_int = (uint32_t)strtol(addr_input,endptr,16);
			num_words = (uint32_t)atoi(word_str);
			
			DisplayCommand(address_int,num_words);
		}
		//Case 2: Only address was entered - display 1 word at that address
		else if(CheckInput(ARG1,HEXADECIMAL,FALSE))
		{
			char *addr_input=parse(input,delimiters,ARG1);
			char **endptr = NULL;
			uint32_t address_int;
			uint32_t num_words = 1;
			
			address_int = (uint32_t)strtol(addr_input,endptr,16);
			num_words = 1;
			
			DisplayCommand(address_int,num_words);
			
		}
		//Case 3: Special flag raised - use address pointer to allocated memory
		else if(CheckInput(ARG1,SPECFLAG,TRUE) || CheckInput(ARG1,SPECFLAG,FALSE))
		{
			uint32_t num_words = 0;
			uint32_t word_int = 0;
			
			//Check for number of words to display and word location to start displaying at. 1 word displayed at start of memory block if none specified
			if(CheckInput(ARG1,SPECFLAG,TRUE) && CheckInput(ARG2,NUMBERS,TRUE) && CheckInput(ARG3,NUMBERS,FALSE))
			{
				char *word_input=parse(input,delimiters,ARG2);
				char *word_str=parse(input,delimiters,ARG3);
				num_words = (uint32_t)atoi(word_str);
				word_int = (uint32_t)atoi(word_input);
			}
			else
			{
				num_words = 1;
			}
			
			uint32_t starting_address = (uint32_t)((uintptr_t)(ptr_to_mem+word_int));
			
			DisplayCommand(starting_address,num_words);
			
		}
		else
		{
			printf("Invalid arguments for display command. Please try again.\n");
		}
		*/
	}
	else
	{
		printf("You have no allocated memory to display.\r\n");
	}
	
}

void DisplayCommand(uint32_t address,uint32_t number)
{
	printf("\r\nDisplaying %u word(s) starting from 0x%08x\r\n", number, address);
	uint32_t valid_number_flag = 0;
	uint32_t valid_address_flag = 0;
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
					printf("Address %p displays value of %08x\r\n", ptr_to_mem+ptr_increment+i, *(ptr_to_mem+ptr_increment+i));
				}
			}
			break;	
		}
		ptr_increment++;
		allowed_block_size--;

	}
	if(valid_address_flag==0)
	{
		printf("Error- You entered an unaligned address or an address outside of the allocated range.  Please enter an acceptable or aligned address.\r\n");
	}

	if(valid_number_flag==0)
	{
		printf("Error- trying to display values outside of allocated memory. Choose a different number of words to display.\r\n");
	}
}
