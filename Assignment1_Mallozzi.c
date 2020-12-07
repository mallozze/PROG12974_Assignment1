/*
 * Name: Eric Mallozzi
 * Student Number: 991242826
 * Class: PROG10111 1209_24301, Fall 2020
 * Date: 2020 - 09 - 23
 * Program: assignment1_mallozzi.c
 * Description: A number guessing game using a 
 		Random Number Generator versus User Input
 * Sheridan College: Trafalgar Campus
 */

//Packages included to help the programs run!
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	//Setting a seed for the random number generator
	srand(time(NULL));
	
	//Initializing the random number, user number, and user continue.
	int randNum = 0, userNum, userContinue = 2;
	
	/*
	 * A do-while loop which will iterate the game at least once.
	 * The Loop will exit if the user enter's 0 to end the game.
	 */
	do{
		
		//Creating the random number for the user to guess between 10 and 30.
		randNum = (rand() % 20) + 10;
		
		//Initializing userNum so the loop will iterate
		userNum = 2;
		
		//Description of the game to the user
		printf("Guess a magic number between 10 and 30\n");
		
		/*
		 * A loop for the player to guess the number.
		 * The loop will exit when the user enters the same number
		 * as the randomly generated one, or if they enter 0 to exit, 
		 * or if they enter 1 to Give up
		 */
		while(randNum != userNum){
			
			//Prompting the user to input a number.
			printf("Enter your guess (0-Exit / 1-GiveUp): ");
			//Saving the user input into the userNum variable
			scanf("%d", &userNum);
			
			//If the user enters a 1 or a 0, it will break out of the loop.
			if(userNum == 1 || userNum == 0){
				break;
			}
			
			//Checking if the userNum is between 10 and 30
			if(userNum >=10 || userNum <= 30){
				
				/*
				 * Giving the user a clue if their number is lower or higher  
				 * than the random number.
				 */
				if(userNum < randNum && userNum <= 30 && userNum >= 10){
					printf("    == Your guess is too low\n");	
				} else if(userNum > randNum && userNum >= 10 && userNum <= 30){
					printf("    == Your guess is too high\n");
				}
			}
			
			// Checking to see if the user entered a number outside the 
			// randNum's variable range
			if(userNum < 10 || userNum > 30){
				
				//Checking if the number is not 0 or 1
				if(userNum != 0 && userNum != 1){
					printf("    == Your guess should be between 10 to 30\n");
				}
			}
			
		}// end while loop
		
		//Checking if the user got the answer correct, or gave up.
		if(userNum == 1){
			printf("    == Give up? OK, the number is: %d\n", randNum);
		} else if(userNum == randNum){
			printf("    == Yes, the number is %d, Good Job!\n", userNum);
		}
		
		//Prompting the user to play again if they did not enter 0
		if(userNum != 0){
			do{
				printf("    == Play Again? (0-No / 1-Yes): ");
				scanf("%d", &userNum);
			}while(userNum != 0 && userNum !=1);
		}
		
		//If the user entered 0, the game is over.
		if(userNum == 0){
			userContinue = 0;
		}
		
		printf("\n");
	
	//The condition for the loop to keep iterating.	
	}while(userContinue != 0); //end of the do while loop
	
	//Exit message
	printf("See you next time!");
	
	//Terminating Program
	return 0;
}
