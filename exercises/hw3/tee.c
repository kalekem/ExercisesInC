/*
 Name: Cleophas Kalekem
 HFC Chapter 3
 Instructor: Prof. Allen Downey
 Date: 3/24/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implements tee command that takes same command-line arguments
int main(int argc, char *argv[]) {

	FILE *outfile; //output file
	printf("Ready.....\n");
	char input[100];  //size

	/*If file name not given, create output file with default name.
	else if it includes a file to write the data to, redirect the output 
	to that file
	*/
	if (argv[1] != '\0')
		if(strcmp(argv[1], "-") !='\0'){
			outfile = fopen("outfile.txt", "w");
	}
	// Else create the file with the given name - the file created will contain no data i.e it will be null/empty
	else {
		outfile = NULL;
	}

	//Prompt the user to enter/read in the piped information/data
	while (scanf("%s\n", input) == 1) {
	
		//Display the entered info to command line 
		printf("%s\n", input);

		//Print the data/input to the output file
		fprintf(outfile, "%s\n", input);

	}

	//close the file
	fclose(outfile);
	
	return 0;	
}
