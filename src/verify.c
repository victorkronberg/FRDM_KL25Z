/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
*
* @source http://www.cs.princeton.edu/courses/archive/spr03/cs126/assignments/cycle.html
* Generates pseudo random numbers by multiplying a seed by a large prime number, incrementing it by another, and taking the modulus of the result to fit within uint32_t
* Values taken from:
* https://software.intel.com/en-us/articles/fast-random-number-generator-on-the-intel-pentiumr-4-processor
*
/**
* @file verify.c
* @brief This file implements the VerifyCommand function and VerifyInvoker function
*
* This file implements the VerifyCommand function and VerifyInvoker function
*
* @author: Victor Kronberg
* @date October 1 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <verify.h>

void VerifyInvoker (void)
{
	if (ptr_to_mem!=NULL)
	{
		//Case 1: User specifies starting address, number of words to verify, and a seed value for PRNG
		if(CheckInput(ARG1,HEXADECIMAL,TRUE) && CheckInput(ARG2,NUMBERS,TRUE) && CheckInput(ARG3,NUMBERS,FALSE))
		{
			char *addr_input=parse(input,delimiters,ARG1);
			char *num_words_str=parse(input,delimiters,ARG2);
			char *seed_str=parse(input,delimiters,ARG3);
			char **endptr = NULL;
			uint32_t address_int;
			uint32_t num_words;
			uint32_t seed;
			
			address_int = (uint32_t)strtol(addr_input,endptr,16);
			num_words = (uint32_t)atoi(num_words_str);
			seed = (uint32_t)atoi(seed_str);

			VerifyCommand(address_int,num_words,seed);
		}
		//Case 2: Special flag raised -  starting address is pointer to memory, user specifies offset from address, number of words to verify, and a seed value for PRNG
		else if(CheckInput(ARG1,SPECFLAG,TRUE) && CheckInput(ARG2,NUMBERS,TRUE) && CheckInput(ARG3,NUMBERS,TRUE) && CheckInput(ARG4,NUMBERS,FALSE))
		{
			char *offset_str=parse(input,delimiters,ARG2);
			char *num_words_str=parse(input,delimiters,ARG3);
			char *seed_str=parse(input,delimiters,ARG4);
			uint32_t offset;
			uint32_t num_words;
			uint32_t seed;
			
			offset = (uint32_t)atoi(offset_str);
			num_words = (uint32_t)atoi(num_words_str);
			seed = (uint32_t)atoi(seed_str);
			
			uint32_t starting_address = (uint32_t)((uintptr_t)(ptr_to_mem+offset));
			VerifyCommand(starting_address,num_words,seed);
		}
		else
		{
			printf("Invalid arguments to verify command. Nothing will be verified.\n");
		}
	}
	else 
	{
		printf("You have no allocated memory to verify.\n");
	}
}

void VerifyCommand (uint32_t address,uint32_t number, uint32_t seed)
{
	//double start, stop;
	//double total;
	
	//start = (double)clock();
	
	uint32_t modulus = UINT32_MAX;
	uint32_t multiplier = 214013;
	uint32_t increment = 2531011;
	uint32_t valid_number_flag = 0;
	uint32_t valid_address_flag = 0;
	uint32_t inner_loop_flag = 0;
	uint32_t ptr_increment = 0;
	uint32_t allowed_block_size = mem_block_size;

	while (ptr_increment < mem_block_size)
	{
		if((uint32_t)((uintptr_t)(ptr_to_mem+ptr_increment)) == address)
		{
			printf("This is the verify command, we will verify %u random numbers starting at %p using %u as a seed value.\n\n",number,ptr_to_mem+ptr_increment,seed);
			valid_address_flag = 1;
			if(number <= allowed_block_size)
			{
				valid_number_flag = 1;
				for(uint32_t i = 0; i < number; i++)
				{
					seed = (multiplier*seed + increment)%modulus;
					if(*(ptr_to_mem+ptr_increment+i) != seed)
					{
						printf("Incorrect value stored at %p.\nValue found was %08x and should have been %08x.\n\n",ptr_to_mem+ptr_increment+i,*(ptr_to_mem+ptr_increment+i),seed);
					}
				}
				printf("Verify completed successfully.\n");
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
		printf("Error- Trying to read values outside of allocated memory. Choose a different number of words to verify.\n");
	}
	
	//stop = (double)clock();
	//total = (stop-start)/CLOCKS_PER_SEC;
	//printf("VerifyCommand function took %f seconds\n\n", total); 
}