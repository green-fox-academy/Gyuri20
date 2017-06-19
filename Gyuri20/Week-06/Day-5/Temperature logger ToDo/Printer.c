#include "printer.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_usage()
{
    clear_screen();
	printf("Todo application\n");
	printf("====================\n");
	printf("Commands:\n");
	printf(" h -- Show the command list\n");
	printf(" e -- Exit from the program\n");
	printf(" l -- List available ports\n");
	printf(" p -- Set port name\n");
	printf(" w -- Set write filename\n");
	printf(" o -- Open port\n");
	printf(" s -- Start logging / Stop logging\n");
	printf(" c -- Close port\n");
	printf(" r -- Set read filename\n");
	printf(" a -- Calculate average in given period\n\n");
}

void clear_screen()
{
	system("cls");
}
