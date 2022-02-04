#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include "player.h"
#include "card.h"
#include <time.h>

/*
 * Structure: deck
 * ---------------
 *  An array of 52 cards.
 */
struct deck {
  struct card list[52];
  int top_card;
};

/* 
 * Variable: deck_instance
 * -----------------------
 *
 * Go Fish uses a single deck
 */
struct deck deck_instance; 

/*
 * Function: shuffle
 * --------------------
 *  Initializes deck_instance and shuffles it.
 *  Resets the deck if a prior game has been played.
 * 
 *  returns: 0 if no error, and non-zero on error
 */ 
int shuffle() {
	int a; /* declare variable a, later used to iterate through suits */
	int b; /* declare variable b, later used to iterate through ranks */
	int c; /* declare variables c & d, later used to shuffle deck */
	int d;
	int counter = 0; /* declare variable to keep track of each card in for loop */

	char suits_array[4] = {'C', 'D', 'H', 'S'}; /* define array of suits */
	char ranks_array[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}; /* define array of ranks */
	for(a = 0;a < 4;a++) { /* iterate through suits */
		for(b = 0;b < 13;b++) { /* iterate through ranks */
			deck_instance.list[counter].rank = ranks_array[b];
			deck_instance.list[counter].suit = suits_array[a];
			counter++;  /* increment counter by 1 */
			deck_instance.top_card++;  /* increment the top card by 1 */
		} /* end nested for loop */
	} /* end initial for loop */

  deck_instance.top_card--;  /* must make sure top_card = 51, not 52 */

  srand(time(0));  /* make sure all numbers are random */
	for(c = 51; c>0; c--) { /* for loop with 52 iterations to shuffle deck */
		d = (rand() % c) + 0; /* set d = random value from 0-c */
		struct card temp1 = deck_instance.list[c]; /* set temp1 variable to store list[c] */
		deck_instance.list[c] = deck_instance.list[d]; /* set list[c] to list[d] */
		deck_instance.list[d] = temp1; /* set list[d] equal to temp1's initial value */
	} /* end of for loop */

	if ( (a != 4) || (b != 13) || (c != 0) ) {  /* if for loops didn't run correctly, return error*/
		return -1;
	}
	else {  /* if loops ran correctly, return 0 */
		return 0;
	}
} /* end of shuffle function */


/*
 * Function: next_card
 * -------------------
 *  Return a pointer to the top card on the deck.
 *  Removes that card from the deck. 
 *
 *  returns: pointer to the top card on the deck.
 */
struct card* next_card( ) {
	if (deck_instance.top_card < 0)  /* if the deck is empty */
	{
    return NULL; 
	}

	else  /* if the deck isn't empty */
	{
    return (&deck_instance.list[deck_instance.top_card--]);  /* return pointer to top card on the deck, remove card from deck */
	}
	
	
}

/*
 * Function: size
 * --------------
 *  Return the number of cards left in the current deck.
 *
 *  returns: number of cards left in the deck.
 */
size_t deck_size() {
	return deck_instance.top_card;  /* returns top card, showing size of deck */
}

#endif
