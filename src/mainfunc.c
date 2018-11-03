/******************************************************************************************
* Copyright (C) 2018 by Laura Gong and Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg, Laura Gong, and the 
* University of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
****
* @file main.c
* @brief Main function
*
* @author: Laura Gong
* @author: Victor Kronberg
* @date September 25 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <main.h>
#include "board.h"
#include "fsl_lptmr_driver.h"
#include "fsl_debug_console.h"

typedef void (*functionPointerType)(void);
char *input;
const char *delimiters = " \r\n";



void mainfunc(void)
{
    
    struct command 
	{
        const char *cmdName;
        functionPointerType ptrToFn;
    };
    
    // Lookup Table
    const struct command commandTable[] = 
	{
		{"allocate", &AllocateInvoker},
		{"free", &FreeInvoker},
		{"display", &DisplayInvoker},
		{"modify", &ModifyInvoker},
		{"invert", &InvertInvoker},
		{"write", &WriteInvoker},
		{"verify", &VerifyInvoker},
		{"help", &help},
		{"", 0} 
    };
	
printf("\r\nWelcome.\r\nIf you would like to invoke the help function to see a list"
			   " of acceptable commands and how to invoke them, type 'help'.\r\n"
			   "Type 'exit' to exit\r\n"
			   "Please enter a command:\r\n");


     // Main routine that simply echoes received characters forever
	 //PRINTF("\r\nNEW CHAR!\r\n\r\n");
     // First, get character


	while(1)
	{	
		printf(">>");
		char valid_cmd_flag = 0; 
		input = (char*)malloc(MAX_CMD_STRING_LENGTH * sizeof(char));
		char inputarr[MAX_CMD_STRING_LENGTH];
		uint8_t receiveBuffer;
	    for(uint32_t ctr = 0; ctr < MAX_CMD_STRING_LENGTH; ctr++){
	    	receiveBuffer = GETCHAR();
	    	PUTCHAR(receiveBuffer);
	    	inputarr[ctr] = (char) receiveBuffer;
	    	if(receiveBuffer=='\n')
	    	{
	    		break;
	    	}
	    }

		if (input != NULL)
		{
			char *command = parse(input,delimiters,CMND);
			for (uint32_t i = 0; i < (sizeof(commandTable)/sizeof(commandTable[0])); i++)
			{
				if (command !=NULL && strcmp(command,commandTable[i].cmdName) == 0)
				{
					valid_cmd_flag = 1;
					commandTable[i].ptrToFn();
					break;
				}
				if (command !=NULL && strcmp(command,"exit") == 0)
				{
					printf("Exiting program.\r\n");
					exit(EXIT_SUCCESS);
				}
			}
			if (valid_cmd_flag == 0)
			{
				printf("Please enter a valid command.\n");
			}
		} else 
			{
			printf("Error- EOF was reached before any characters were input\n");
			}
		free(input);
	}
	printf("That was the end of a command");
}
