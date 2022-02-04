//#include "player.h"
//#include "deck.h"
//#include "player.h"
//#include "gofish.h"
//#include <stdio.h>

// /*
//  * Function: add_card
//  * -------------------
//  *  Add a new card to the player's hand. 
//  *
//  *  target: the target player
//  *  new_card: pointer to the new card to add
//  *
//  *  returns: return 0 if no error, non-zero otherwise
//  */
// /* definition of add_card function */
// int add_card(struct player* target, struct card* new_card) {  
//     struct hand* temp1;  /* create a new temp1 of type hand */
//     temp1 = (struct hand*)malloc(sizeof(struct hand)); /* allocate memory for temp1 */
//     temp1->next = target->card_list; /* set temp1's next to be target's card_list */
//     temp1->top = *new_card; /* set temp1's top card to be the value at new_card */
//     target->card_list = temp1;  /* insert temp1 into where card_list was */
//     target->hand_size++;  /* increment hand_size by 1 */
//     if ( temp1 == NULL ) {  /* if we incorrectly created temp1 */
//         return -1;
//     }  /* end of if statement */
//     else {  /* if we correctly ran add_card */
//         return 0;
//     }  /* end of else statement */
// }  /* end of add_card */


// /*
//  * Function: remove_card
//  * ---------------------
//  *  Remove a card from the player's hand. 
//  *
//  *  target: the target player
//  *  old_card: pointer to the old card to remove
//  *
//  *  returns: return 0 if no error, non-zero otherwise
//  */
// /* definition of remove_card function */
// int remove_card(struct player* target, struct card* old_card) {
//     struct hand* previous = NULL;  /* define previous of type hand to be = NULL */
//     struct hand* iterator = target->card_list;  /* define iterator1 of type hand to be = card_list */

//     if( iterator = NULL ) {  /* if target.card_list == NULL (we have no cards) */
//         return -1;  /* error message */
//     }

//     while( (iterator->top.rank != old_card->rank) && (iterator->top.suit != old_card->suit) ) {  /* checks if we located the card */
//         previous = iterator;  /* set previous = iterator */
//         iterator = iterator->next;  /* set iterator to next card */

//         if ( iterator == NULL ) {  /* if we incorrectly made iterator or cannot locate the correct card, return error} */
//             return -1;
//         }  /* end of if statement */

//     }  /* end of while loop */

//     if (previous == NULL) {
//         target->card_list = iterator->next; /* previous is null, so just set card_list to iterator.next */
//     }

//     else {
//         previous->next = iterator->next; /* make previous card point to iterator's next, skipping iterator */
//     }

//     free(iterator);  /* free memory of iterator */
//     return 0;
// }  /* end of remove_card */


// /*
//  * Function: check_add_book
//  * ------------------------
//  *  Check if a player has all 4 cards of the same rank.
//  *  If so, remove those cards from the hand, and add the rank to the book.
//  *  Returns after finding one matching set of 4, so should be called after adding each a new card.
//  * 
//  *  target: pointer to the player to check
//  *  
//  *  Return: a char that indicates the book that was added; return 0 if no book added.
//  */
// char check_add_book(struct player* target){
//     struct hand* playerhand = target->card_list;  /* declare playerhand var */
//     int counter = 0;  /* intitialize a counter variable */
//     struct card card1;  /* set card1 to use for removal later */
//     char ranks_array1[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}; /* define array of ranks */
//     char rank1;  /* set rank1 to keep track of which rank has 4 of a kind */
//     int cardtracker[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  /* array to count how many cards of each rank are in hand */

//     while (playerhand != NULL)  /* traverse through entire hand */
//     {
//         switch (playerhand->top.rank)  /* switch case comparing the rank of the top card */
//         {
//         case '2':  /* if playerhand's top card has rank 2 */
//             cardtracker[0]++;  /* increment the 1st slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '3':  /* if playerhand's top card has rank 3 */
//             cardtracker[1]++;  /* increment the 2nd slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '4':  /* if playerhand's top card has rank 4 */
//             cardtracker[2]++;  /* increment the 3rd slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */
            
//         case '5':  /* if playerhand's top card has rank 5 */
//             cardtracker[3]++;  /* increment the 4th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '6':  /* if playerhand's top card has rank 6 */
//             cardtracker[4]++;  /* increment the 5th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '7':  /* if playerhand's top card has rank 7 */
//             cardtracker[5]++;  /* increment the 6th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '8':  /* if playerhand's top card has rank 8 */
//             cardtracker[6]++;  /* increment the 7th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case '9':  /* if playerhand's top card has rank 9 */
//             cardtracker[7]++;  /* increment the 8th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case 'T':  /* if playerhand's top card has rank T */
//             cardtracker[8]++;  /* increment the 9th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case 'J':  /* if playerhand's top card has rank J */
//             cardtracker[9]++;  /* increment the 10th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case 'Q':  /* if playerhand's top card has rank Q */
//             cardtracker[10]++;  /* increment the 11th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case 'K':  /* if playerhand's top card has rank K */
//             cardtracker[11]++;  /* increment the 12th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         case 'A':  /* if playerhand's top card has rank A */
//             cardtracker[12]++;  /* increment the 13th slot of cardtracker array by 1 */
//             break;  /* break out of switch statement */

//         }  /* close switch statement */
        
//         playerhand = playerhand->next;  /* move to next card */
//     }  /* close while loop */
//     int a = 0;  /* initialize a for while loop */
//     int b = 0;  /* initialize b for while loop */

//     while (a < 13)  /* traverse through each possible rank */
//     {
//         switch (cardtracker[a])  /* switch statement to check if each rank has all 4 cards */
//         {
//         case 4:  /* if there are 4 of a kind in the hand */
//             rank1 = ranks_array1[a];   /* set ranks1 equal to the rank which has 4 of a kind */
//             card1.rank = rank1;  /* set card1's rank to rank1 */

//             card1.suit = 'S';  /* set card1's suit to S */
//             remove_card(target, &card1);  /* remove 1st card from the player */
//             card1.suit = 'H';  /* set card1's suit to H */
//             remove_card(target, &card1);  /* remove 2nd card from the player */
//             card1.suit = 'D';  /* set card1's suit to D */
//             remove_card(target, &card1);  /* remove 3rd card from the player */
//             card1.suit = 'C';  /* set card1's suit to C */
//             remove_card(target, &card1);  /* remove 4th card from the player */
//             break;  /* exit switch statement */

//             while (target->book[b])  /* iterate through */
//             {
//                 switch (target->book[b])  /* check if player's book[b] = something */
//                 {
//                 case 0:  /* if player's book[b] == 0 */
//                     target->book[b] = rank1;  /* update player's book[b] to rank1 */
//                     return rank1;  /* return rank1 */
//                 default:  /* else */
//                     break;  /* exit switch statement */
//                 }  /* close switch statement */
//                 b++;  /* increment b by 1 */
//             }  /* close while loop */
//         default:  /* else */
//             break;  /* exit switch statement */
//         }  /* close switch statement */
//     }  /* close while loop */
//     return 0;  /* no book added */
// }  /* end check_add_book function */


// /*
//  * Function: search
//  * ----------------
//  *  Search a player's hand for a requested rank.
//  *  
//  *  rank: the rank to search for
//  *  target: the player (and their hand) to search
//  *
//  *  Return: If the player has a card of that rank, return 1, else return 0
//  */
// /* definition of search function */
// int search(struct player* target, char rank) {

//     struct hand* temp1 = target->card_list;  /* set a temp variable to hold card_list */

//     while (temp1 != NULL) {  /* runs until temp1 == NULL */
//         if (rank ==  temp1->top.rank)  /* if the current card matches the inputted rank, return 1 */
//         {
//             return 1;  
//         }  /* end of if statement */
//         temp1 = temp1->next;  /* set temp1 to the next card in the hand */
//     }  /* end of while loop  */

//     return 0;  /* if player does not have inputted card, return 0  */
// }  /* end of search function  */


// /*
//  * Function: transfer_cards
//  * ------------------------
//  *   Transfer cards of a given rank from the source player's 
//  *   hand to the destination player's hand. Remove transferred
//  *   cards from the source player's hand. Add transferred cards
//  *   to the destination player's hand.
//  *   
//  *   src: a pointer to the source player
//  *   dest: a pointer to the destination player
//  *   rank: the rank to transfer
//  *
//  *   Return: 0 if no cards found/transferred, <0 if error, otherwise 
//  *   return value indicates number of cards transferred
//  */   
// int transfer_cards(struct player* src, struct player* dest, char rank){
//     if (src->card_list == NULL)  /* if source player has no cards */
//     {
//         return -1;  /* return error message */
//     }
    
//     struct hand* sourceHand = src->card_list;  /* set sourceHand = source player's hand */
//     int counter = 0;  /* counter to keep track of number of transferred cards */

//     while (sourceHand != NULL)  /* runs until sourceHand has been parsed through */
//     {
//         if (rank == sourceHand->top.rank)  /* check if source player's current card == inputted rank */
//         {
//             counter++;  /* increment counter by 1 */
//             add_card(dest, &sourceHand->top);  /* add current card to destination player */
//             remove_card(src, &sourceHand->top);  /* remove current card from source player */
//         }  /* close if statement */
//         sourceHand = sourceHand->next;  /* move to next card in hand */
//     }  /* close while loop */
//     return counter;  /* return number of cards we switched */
// }  /* end of transfer_cards function */


// /*
//  * Function: game_over
//  * -------------------
//  *   Boolean function to check if a player has 7 books yet
//  *   and the game is over
//  *
//  *   target: the player to check
//  *   
//  *   Return: 1 if game is over, 0 if game is not over
//  */
// int game_over(struct player* target){
//     int counter = 0;  /* initialize counter to keep track of how many books player has */
//     int a = 0;  /* initialize a for while loop */

//     while (a < 7)  /* iterate through each book */
//     {
//         switch (target->book[a])  /* we will look at the a'th book of the player */
//         {
//         case 0:  /* if the player's a'th book == 0 */
//             break;  /* exit switch statement */
        
//         default:  /* if the player's a'th book != 0 */
//             counter++; /* increment counter by 1 */
//             break;  /* exit switch statement */
//         }  /* exit switch statement */
//         a++;  /* increment a by 1 */
//     }  /* end while loop */
    
//     switch (counter)  /* we will be looking at the counter variable */
//     {
//     case 7:  /* if counter == 7 */
//         return 1;
    
//     default:  /* else */
//         return 0;
//     }  /* end of switch statement */
// }  /* end of game_over function */


// /* 
//  * Function: reset_player
//  * ----------------------
//  *
//  *   Reset player by free'ing any memory of cards remaining in hand,
//  *   and re-initializes the book.  Used when playing a new game.
//  * 
//  *   target: player to reset
//  * 
//  *   Return: 0 if no error, and non-zero on error.
//  */
// int reset_player(struct player* target){
//     int a = 0;  /* initialize a as 0 for while loop */

//     while (a < 7)  /* iterate through books of player */
//     {
//         target->book[a] = 0;  /* reset books of player to 0 */
//         a++;  /* increment a by 1 */
//     }  /* end while loop */
    
//     while (target->card_list != NULL)  /* iterate through player's hand */
//     {
//         remove_card(target, &(target->card_list->top));  /* remove player's top card */
//     }  /* end while loop */
    
//     if ( (a != 7) || (target->hand_size != 0) || (target->card_list != NULL))  /* if while loop didn't run correctly or all cards weren't removed */
//     {
//         return -1;  /* return error message */
//     } /* end if statement */
    
//     return 0;  /* no errors */
// }  /* end of reset_player function */


// /* 
//  * Function: computer_play
//  * -----------------------
//  *
//  *   Select a rank randomly to play this turn. The player must have at least
//  *   one card of the selected rank in their hand.
//  *
//  *   target: the player's hand to select from
//  *
//  *   Rank: return a valid selected rank
//  */
// char computer_play(struct player* target){
//     int randomNum = rand() % target->hand_size;  /* random number between 0 and # of cards in hand */
//     int counter = 0;  /* intitialize counter as 0 to iterate through player's hand */
//     char Rank;  /* define rank to return later */
//     while (target->card_list != NULL)  /* iterate through player's hand */
//     {
//         if (counter == randomNum)  /* if this is the random card we have chosen */
//         {
//             Rank = target->card_list->top.rank;  /* set rank = to current card */
//         }  /* end of if statement */

//         target->card_list = target->card_list->next;  /* move to next card */
//         counter++;  /* increment counter by 1 */
//     }  /* end of while loop */
    
//     return Rank;  /* return the rank the computer will play */
// }  /* end of computer_play function */


// /* 
//  * Function: user_play
//  * -------------------
//  *
//  *   Read standard input to get rank user wishes to play.  Must perform error
//  *   checking to make sure at least one card in the player's hand is of the 
//  *   requested rank.  If not, print out "Error - must have at least one card from rank to play"
//  *   and then re-prompt the user.
//  *
//  *   target: the player's hand to check
//  * 
//  *   returns: return a valid selected rank
//  */
// char user_play(struct player* target){
//     char userRank;  /* define userRank to be inputted later */
//     printf("Enter a rank: ");  /* prompt user to enter rank */
//     scanf("%c", userRank);  /* set userRank = user input */
//     char tryAgain;  /* define tryAgain in case this goes awry */

//     while (target->card_list != NULL)  /* iterate through hand */
//     {
//         if (target->card_list->top.rank == userRank)  /* if current card's rank == inputted rank */
//         {
//             return userRank;  /* return inputted rank */
//         }
        
//         target->card_list = target->card_list->next;  /* go to next card */
//     }  /* close while loop */
    
//     printf("Error - must have at least one card from rank to play");  /* print out error message if card not found */
//     tryAgain = user_play(target);  /* set tryAgain = rerunning function */
//     return tryAgain;  /* run it back */
// }  /* end of user_play function */
