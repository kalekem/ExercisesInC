/*
	Name: Cleophas Kalekem
	Instructor: Allen Downey
	Class: Software Systems

*/

//Card counter program

#include <stdio.h>
#include <stdlib.h>

/*updates the value based on the card name/value that the user enters
Returns the new value
*/ 

int val;
int count;
char card_name[3];

int get_card_value (int val, char card_name[]){

	switch (card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			val = 0;
			break;
		default:
			val = atoi(card_name);
			if(val < 1 || val > 10){
				puts("I don't understand that value");
				val = 0;
			}
	}
	return val;
}

/*
 updates the count value depending on the value number
 and returns the new updated value

 */

int card_counter (int count, int value){

	if(value > 2 && value < 7) {
		count +=1;

	} else if (value ==10){
			count -=1;
	}
	return count;
}
/*
Main function. Prompts the user to the enter the card value
When the user types 'X', the program ends
Prints the value of the card count
*/

int main() {

	count = 0;

	while (card_name[0] !='X') {
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		
		val = 0;

		val = get_card_value (val, card_name);
		if ( val == 0){
			continue;
		}

		count = card_counter(count, val);
		printf("Current count: %i\n",count);

	}
	return 0;
}


