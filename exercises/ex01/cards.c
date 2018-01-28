/*
   A basic program that runs a card counting game
   Written by: Shruti Iyer
   Last updated: 27th Jan, 2018
*/

#include <stdio.h>
#include <stdlib.h>

/* Starts a new turn where it requests a new card name
   Saves the entered card name into a buffer 'card_name'

   card_name: the buffer where the user-inputed card name gets stored
*/
void start_new_turn(char *card_name) {
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/* Calculates and returns the value corresponding to the card card name
   If an invalid number or the user chose to end the program, it returns -1

   card_name: the pointer to where the current card name is stored
*/
int get_card_value(char *card_name) {
  int val;
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
      val = -1;
    default:
      val = atoi(card_name);
      if ((val<1)||(val>10)) {
        puts("I don't understand that value!");
        val = -1;
      }
  }
  return val;
}

/* Depending on the value, the count gets updated and printed

   val: the buffer with the value of the card entered by the user
*/
void update_count(int *val, int *count) {
  if ((*val>2) && (*val<7)) {
    (*count)++;
  } else if (*val==10) {
    (*count)--;
  }
  printf("Current count: %i\n", *count);
}

/* The main function that runs the card game */
int main() {
  char card_name[3];
  int count = 0;
  int val;

  do {
    val = 0;
    start_new_turn(card_name);

    val = get_card_value(card_name);
    if (val == -1) {
      continue;
    }

    update_count(&val, &count);

  } while(card_name[0]!='X');
  return 0;
}
