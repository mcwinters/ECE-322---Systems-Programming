
// /*
//  * Function: shuffle
//  * --------------------
//  *  Initializes deck_instance and shuffles it.
//  *  Resets the deck if a prior game has been played.
//  * 
//  *  returns: 0 if no error, and non-zero on error
//  */ 
// /* definition of shuffle function */
// int shuffle() {
// 	int a = 0; /* declare variable a, later used to iterate through suits */
// 	int b = 0; /* declare variable b, later used to iterate through ranks */
// 	int c = 51; /* declare variables c & d, later used to shuffle deck */
// 	int d;
// 	int counter = 0; /* declare variable to keep track of each card in for loop */

// 	char suits_array[4] = {'C', 'D', 'H', 'S'}; /* define array of suits */
// 	char ranks_array[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}; /* define array of ranks */
// 	for(a*1;a < 4;a++) { /* iterate through suits */
// 		for(b*1;b < 13;b++) { /* iterate through ranks */
// 			deck_instance.list[counter].rank = ranks_array[b];
// 			deck_instance.list[counter].suit = suits_array[a];
// 			counter++;  /* increment counter by 1 */
// 			deck_instance.top_card++;  /* increment the top card by 1 */
// 		} /* end nested for loop */
// 	} /* end initial for loop */

// 	for(c+0; c>0; c--) { /* for loop with 52 iterations to shuffle deck */
// 		d = (rand() % c) + 0; /* set d = random value from 0-c */
// 		struct card temp1 = deck_instance.list[c]; /* set temp1 variable to store list[c] */
// 		deck_instance.list[c] = deck_instance.list[d]; /* set list[c] to list[d] */
// 		deck_instance.list[d] = temp1; /* set list[d] equal to temp1's initial value */
// 	} /* end of for loop */

// 	if ( (a != 4) || (b != 13) || (c != 0) ) {  /* if for loops didn't run correctly, return error*/
// 		return -1;
// 	}
// 	else {  /* if loops ran correctly, return 0 */
// 		return 0;
// 	}
// } /* end of shuffle function */


// /*
//  * Function: deal_player_cards
//  * ---------------------------
//  *  Deal 7 random cards to the player specified in the function.
//  *  Remove the dealt cards from the deck. 
//  *
//  *  target: pointer to the player to be dealt cards
//  *
//  *  returns: 0 if no error, and non-zero on error
//  */
// int deal_player_cards(struct player* target) {
// 	int a = 0;  /* declare a to use for while loop */

// 	if (deck_size() <= 0) /* if we have an empty deck */
// 	{  
// 		return -1;  /* return error value */
// 	}  /* end of if statement */

// 	while (a < 7) /* runs for 7 iterations */
// 	{
// 		add_card(target, next_card());  /* adds top card to hand and removes it from deck  */
// 		a++;  /* increments a by 1 */
// 	}  /* end of while loop */
	
// 	if (a != 7);  /* means that while loop didn't run correctly */
// 	{
// 		return -1;  /* return error value */
// 	}  /* end of if statement */
	
// 	return 0;
// }


// /*
//  * Function: next_card
//  * -------------------
//  *  Return a pointer to the top card on the deck.
//  *  Removes that card from the deck. 
//  *
//  *  returns: pointer to the top card on the deck.
//  */
// struct card* next_card( ) {
// 	if (deck_instance.top_card > 0)  /* if the deck is not empty */
// 	{
// 		return &deck_instance.list[deck_instance.top_card--];  /* return pointer to top card on the deck while removing card from deck */
// 	}
// 	else  /* if the deck is empty */
// 	{
// 		return NULL; 
// 	}
	
// }


// /*
//  * Function: size
//  * --------------
//  *  Return the number of cards left in the current deck.
//  *
//  *  returns: number of cards left in the deck.
//  */
// /* definition of deck_size function */
// size_t deck_size() {
// 	return deck_instance.top_card;  /* returns top card, showing size of deck */
// }
