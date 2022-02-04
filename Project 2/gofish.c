#include <stdio.h>
#include "gofish.h"

int main(int args, char* argv[]) {
	char turn;  /* initialize turn to keep track of whose turn it is */
	char userRank;  /* userRank is used during game for user inputted rank */
	char ans[2];  /* initialize char ans to record if they want to play again */
	char newBook;  /* initialize newBook to hold check_add_book()'s return */
	int play = 1; 

	while (play == 1)  
	{
		reset_player(&user);  /* reset user's hand to start game */
		reset_player(&computer); /* reset computer's hand */

		printf("Shuffling deck...\n");
		shuffle();  /* shuffle deck */
 
		deal_player_cards(&user);  /* deal cards to user */
		deal_player_cards(&computer);  /* deal cards to computer */

		turn = 'U';  /* reset turn to be = 'U'  */

		while ( (game_over(&computer) != 1) && (game_over(&user) != 1))  /* while neither player has 7 books */
		{
			printf( "Player 1's Hand - " );
			printHand(&user);  /* print user's hand */

			printf("Player 1's Book - ");  
			printBooks(&user);  /* print user's books */

			printf("Player 2's Book - ");  
			printBooks(&computer);  /* print computer's books */


			if (turn == 'U')  /* if it is the user's turn */
			{
				if (user.card_list == NULL)  /* if user has empty hand */
				{
					printf("Player 1 is out of cards, time to draw!");
					add_card(&user, next_card());  /* give card to user */
					continue;  /* call next iteration of while loop */
				}  /* end of if statement */

				printf("Player 1's turn, ");
				
				userRank = user_play(&user);  /* gets a user inputed rank */
				//userRank = computer_play(&user);  /* gets a user inputed rank */

				switch (search(&computer, userRank))  /* if computer has card, 1. Otherwise, 0 */
				{
				case 0:  /* computer doesn't have card */
					printf( "\t-Player 2 has no %c's\n", userRank);

					char newRank = deck_instance.list[deck_instance.top_card].rank;  /* create var newRank to keep track of new rank added to hand */
					char newSuit = deck_instance.list[deck_instance.top_card].suit;  /* create var newSuit to keep track of new suit added to hand */
					add_card(&user, next_card());  /* add a card to user, "go fish!" */

					printf("\t-Go fish. Player 1 draws %c%c\n", newRank, newSuit);

					// CODE STOPS WORKING HERE, I THINK IT IS AN ISSUE W/ CHECK_ADD_BOOK(), also TRANSFER_CARDS()? //

					newBook = check_add_book(&user); 

					if (newBook != 0)  /* if new card created a book */
					{
						printf( "\t-Player 1 books %c\n", newRank);
						printf( "\t-Player 1 gets another turn\n\n" );
						continue;  /* re-iterate through while loop */
					} /* end of if statement */

					else if (userRank == newRank)  /* if user draws card they requested, they get another turn */
					{
						printf( "\t-Player 1 drew the rank they requested, they go again\n\n" );
						continue;  /* re-iterate through while loop */
					}				
					printf("\t-Player 2's Turn\n\n");
					turn = 'C';   /* change turn to 'C' for computer */
					continue;  /* re-iterate through while loop */
			
				default:  /* computer has card */
					printf("\t-Player 2 has ");
					printRanks(&computer, userRank);  /* prints every card computer has of inputted rank */
					transfer_cards(&computer, &user, userRank);  /* transfer cards of rank userRank from computer to user */
					if (check_add_book(&user) != 0)  /* if this created a book */
					{
						printf( "\t-Player 1 books %c\n", newRank);
						printf( "\t-Player 1 gets another turn\n\n" );
						continue;  /* re-iterate through while loop */
					}  /* end of if statement */
					
					else  /* if this did not create a book */
					{
						turn = 'C';  /* change turn to 'C', representing computer's turn */
						printf( "\t-Player 2's turn\n\n" );
						continue;  /* re-iterate through while loop */
					}  /* end of else statement */
					
				}  /* end of switch statement */

			}  /* end of User's Turn */
			
			else if (turn == 'C')  /* Computer's Turn */
			{
				if (computer.card_list == NULL)  /* if user has empty hand */
				{
					printf("Player 2 is out of cards, time to draw!");
					add_card(&computer, next_card());  /* give card to user */
					continue;  /* call next iteration of while loop */
				}  /* end of if statement */

				char computerRank = computer_play(&computer);  /* sets computerRank equal to an approved random rank */
				printf("Player 2's turn, enter a Rank: ");
				printf("%c\n", computerRank); 

				switch (search(&user, computerRank))  /* if user has card, 1. Otherwise, 0 */
				{
				case 0:  /* user doesn't have card */
					printf( "\t-Player 1 has no %c's\n", computerRank);

					char newRank = deck_instance.list[deck_instance.top_card].rank;  /* create var newRank to keep track of new rank added to hand */
					char newSuit = deck_instance.list[deck_instance.top_card].suit;  /* create var newSuit to keep track of new suit added to hand */

					add_card(&computer, next_card());  /* add a card to user, "go fish!" */

					printf("\t-Go fish. Player 2 draws %c%c\n", newRank, newSuit);

					newBook = check_add_book(&user);

					if (newBook != 0)  /* if new card created a book */
					{
						printf( "\t-Player 2 books %c\n", newRank);
						printf( "\t-Player 2 gets another turn\n\n" );
						continue;  /* re-iterate through while loop */
					} /* end of if statement */

					else if (computerRank == newRank)  /* if computer draws card they requested, they get another turn */
					{
						printf( "\t-Player 2 drew the rank they requested, they go again\n\n" );
						continue;  /* re-iterate through while loop */
					}
					
					printf("\t-Player 1's Turn\n\n");
					turn = 'U';   /* change turn to 'U' for user */
					continue;  /* re-iterate through while loop */

					break;  /* break out of switch statement */
				
				default:  /* computer has card */
					printf("\t-Player 1 has ");
					printRanks(&user, computerRank);  /* prints every card computer has of inputted rank */

					transfer_cards(&user, &computer, computerRank);  /* transfer cards of rank userRank from computer to user */

					if (check_add_book(&computer) != 0)  /* if this created a book */
					{
						printf( "\t-Player 2 books %c\n", newRank);
						printf( "\t-Player 2 gets another turn\n\n" );
						continue;  /* re-iterate through while loop */
					}  /* end of if statement */
					
					else  /* if this did not create a book */
					{
						turn = 'U';  /* change turn to 'U', representing user's turn */
						printf( "\t-Player 1's turn\n\n" );
						continue;  /* re-iterate through while loop */
					}  /* end of else statement */
					break;  /* break out of switch statement */

				}  /* end of switch statement */

			}  /* end of Computer's Turn */

		}  /* end of turns */

		if ( (game_over(&computer) == 1) || (game_over(&user) == 1) )  /* if either user or computer has 7 books */
		{
			int a = 0;  /* initialize a for while loop */
			int userBooks = 0;  /* initialize userBooks to print how many books user has */
			int computerBooks = 0;  /* initialize computerBooks to print how many books computer has */

			while (a < 7)  /* iterate through all 7 books */
			{
				switch (computer.book[a])  /* looking at current book for computer */
				{
				case 0:  /* if they don't have a book here */
					break;  /* break out of switch statement */
				
				default:  /* if they do have a book here */
					computerBooks++;  /* increment computerBooks by 1 */
					break;  /* break out of switch statement */
				}  /* end switch case */

				switch (user.book[a])  /* looking at current book for user */
				{
				case 0:  /* if they don't have a book here */
					break;  /* break out of switch statement */
				
				default:  /* if they do have a book here */
					userBooks++;  /* increment userBooks by 1 */
					break;  /* break out of switch statement */
				}  /* end switch case */

				a++;  /* increment a by 1 */
			}  /* end while loop */
			
			switch (game_over(&computer))  /* if the computer won, case 1. Else, default */
			{
			case 1:  /* computer won */
				printf( "Player 2 Wins! %d-%d\n", computerBooks, userBooks);
				break;  /* break out of switch statement */
			
			default:  /* computer did not win */
				break;  /* break out of switch statement */
			}  /* end switch case */

			switch (game_over(&user))  /* if the user won, case 1. Else, default */
			{
			case 1:  /* user won */
				printf( "Player 1 Wins! %d-%d\n", userBooks, computerBooks);
				break;  /* break out of switch statement */
			
			default:  /* user did not win */
				break;  /* break out of switch statement */
			}  /* end switch case */

			printf("Do you want to play again [Y/N]: ");
			scanf(" %c", ans);  /* record user input for if they want to play again */

			switch (ans[0])  /* looking at user input */
			{
			case 'N':  /* if they say no */
				printf("Exiting.\n");
				return 0;  /* end code */
			
			default:  /* anything else */
				printf("default");
				break;
			}  /* end switch case */			

		}  /* end of game_over code */

	}  /* game ends */
	
}  /* end of main */