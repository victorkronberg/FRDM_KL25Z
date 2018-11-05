/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Victor Kronberg and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file help.c
* @brief Command line help function
*
* This function prints out available command-line commands
* to stdout and provides details on how to call them
*
* @author: Victor Kronberg
* @date September 22 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#include <help.h>

void help(void)
{
	// Struct to help format help text for each command
	typedef struct
	{
		//command name and what it does
		char const *func;
		//how to call command
		char const *usage;
		//details of command arguments
		char const *details;
	} helpMsg;
	
	helpMsg allocate;
	
	allocate.func = "allocate - Allocates a block of memory";
	allocate.usage = "  usage: allocate <words>";
	allocate.details = "    words: number of 32-bit words to allocate";
	
	helpMsg free;
	
	free.func = "free - Releases previously allocated block of memory";
	free.usage = "  usage: free";
	free.details = "    no arguments";
	
	helpMsg display;
	
	display.func = "display - Displays contents of memory in hexadecimal format";
	display.usage = "  usage: display [address] [words] OR display 'X' [word position (starting from 0)] [words]";
	display.details = "    address: hex value of displayed starting address\r\n    word position: word position\r\n    words [optional]: number of 32-bit words to display\r\n    X: flag tells program to use word position instead of address";
	
	helpMsg write;

	write.func = "modify - Writes a specified value to a specified address or word position";
	write.usage = "  usage: modify <address> <value> OR modify 'X' <word position> <value>";
	write.details = "    address: address in hex value\r\n    word position: word position\r\n    value: value to write to memory\r\n    X: flag tells program to use word position instead of address";
	
	helpMsg invert;
	
	invert.func = "invert - Inverts bits starting from a specified memory address and going on for a number of words";
	invert.usage = "  usage: invert <address> <words> OR invert 'X' <word position> <words>";
	invert.details = "    address: address in hex value\r\n    word position: word position\r\n    words: number of 32-bit words to invert\r\n    X: flag tells program to use word position instead of address";

	helpMsg writePattern;
	
	writePattern.func = "write - Writes pseudo-random pattern to specified address";
	writePattern.usage = "  usage: write <address> <words> <seed> OR write 'X' <word position> <number of words> <seed>";
	writePattern.details = "    address: hex value of address\r\n    word position: word position\r\n    words: number of words to write\r\n    seed: seed value for pseudo-random number generator\r\n    X: flag tells program to use word position instead of address";

	helpMsg verifyPattern;
	
	verifyPattern.func = "verify - Verifies pseudo-random pattern in specified area of memory";
	verifyPattern.usage = "  usage: verify <address> <words> <seed> OR verify 'X' <word position> <words> <seed>";
	verifyPattern.details = "    address: hex value of address\r\n    word position: word position\r\n    words: number of words to verify\r\n    seed: seed value for pseudo-random number generator\r\n    X: flag tells program to use word position instead of address";
	
	printf("\r\nhelp file contents:\r\n\r\n");
	printf("%s\r\n%s\r\n%s\r\n\r\n",allocate.func,allocate.usage,allocate.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",free.func,free.usage,free.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",display.func,display.usage,display.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",write.func,write.usage,write.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",invert.func,invert.usage,invert.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",writePattern.func,writePattern.usage,writePattern.details);
	printf("%s\r\n%s\r\n%s\r\n\r\n",verifyPattern.func,verifyPattern.usage,verifyPattern.details);
	
}


