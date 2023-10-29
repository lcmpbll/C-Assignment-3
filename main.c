#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h> //for truly random
/******************************************************************************
# Author:           Liam Campbell
# Lab:              Assignment #3
# Date:             October 10th, 2023
# Description:      Play rock paper scissors with me.
# Input:            char userPlay
# Output:           Win, loss, tie
# Sources:          None
#******************************************************************************/
int main(void) {
  char userPlay, computerPlay;
  //char userPlay[2], computerPlay[2];
  int randomNum, winLossTie;
  
  //Welcome user get userPlay
  printf("Welcome to the Rock Paper Scissors Game!\n");
  printf("Enter r, p, or s: ");
  
  scanf("%c", &userPlay);
  
  /* get random number for computer play, using seed based 
  on time */
  srand(time(NULL));
  randomNum = rand() % 3;

  // set computer's play
  if(randomNum < 1){
    computerPlay = 'r';
  } else if (randomNum > 1) {
    computerPlay = 'p';
  } else {
    computerPlay = 's';
  }

  /* if userPlay is not r, p, or s skip the rest of the 
  program alter user play to lower case for comparison */
  switch (userPlay) {
    case 'r':
    case 'R': 
      userPlay = 'r';
      break;
    case 's':
    case 'S': 
      userPlay = 's';
      break;
    case 'p':
    case 'P':
      userPlay = 'p';
      break;
    default:
      printf("Invalid play, please try again.");
      return 0;
      break;
  }

  // Tell the user what their opponent plays
  printf("Computer plays %c\n", computerPlay);
  // compare values to decide who wins
  if(computerPlay == userPlay){
  // If user and computer play the same thing
    printf("It's a tie!\n");
  // Determine if the player wins
  } else if (userPlay == 'R' || userPlay == 'r' && computerPlay == 's') {
     printf("User Wins\n");
  } else if ((userPlay == 'P' || userPlay == 'p') && computerPlay == 'r') {
    printf("User wins!\n");
  } else if (userPlay == 's' || userPlay == 'S' && computerPlay == 'p') {
    printf("User wins!\n");
  } else {
  // If it's not a win or tie, it's a loss.
    printf("Computer wins!\n");
  }
  
  printf("Thanks for playing!\n");
  return 0;
}