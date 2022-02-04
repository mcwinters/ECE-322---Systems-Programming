#ifndef GOFISH_H
#define GOFISH_H
#include "player.h"
#include "card.h"
#include "deck.h"
#include <stdlib.h>
#include <stdio.h>


/* function printHand prints player's hand */
void printHand(struct player* target) {
   struct hand* temp = target->card_list;  /* set temp = player's hand */

   while (temp != NULL)  /* iterate through hand */
   {
      fprintf(stdout, "%c%c ", temp->top.rank, temp->top.suit);  /* print out current card's rank and suit */
      temp = temp->next;  /* move to next card */
   }  /* end of while loop */

   printf("\n");  /* print a new line for formatting */
}  /* end of printHand function */


/* function printBooks prints player's books */
void printBooks(struct player* target) {
   int a = 0;  /* initialize a = 0 for while loop */
   while (a < 7)  /* iterate through player's books */
   {
      switch (target->book[a])  /* we will bee looking ta the current book */
      {
      case 0:  /* if the book == 0 */
         break;  /* break out of switch statement */
      
      default:  /* if book != 0 */
         printf(" %c ", target->book[a]);  /* print the current book */
         break;  /* break out of switch statement */
      }  /* close switch statement */
      a++;  /* increment a by 1 */
   }  /* close while loop */
   printf("\n");  /* print new line for formatting */
}  /* end of printBooks function */


/* function printRanks prints every card a player has of a certain rank */
void printRanks(struct player* target, char rank1) {
   struct hand* temp = target->card_list;  /* set temp equal to player's hand */
   while (temp != NULL)  /* iterate through hand */
   {
      if (temp->top.rank == rank1)  /* if current card has inpuuted rank */
      {
         printf("%c%c ", temp->top.rank, temp->top.suit);  /* print current card's rank & suit */
      }  /* end of if statement */
      
      temp = temp->next;  /* move to next card */

   } /* end of while loop */
   
printf("\n");

}  /* end of printRanks function */

#endif