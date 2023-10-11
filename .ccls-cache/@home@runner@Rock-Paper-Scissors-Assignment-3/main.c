#include <stdio.h>
#include <stdlib.h> // for rand()
#include <time.h> //for truly random
#include <string.h> // for string manipulation
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
  char userPlay[2], computerPlay[2], winCondition[50];
  int randomNum;

  //Welcome user get userPlay
  printf("Welcome to the Rock Paper Scissors Game!\n");
  printf("What is your play?\n");
  printf("Enter r, p, or s for rock, paper, or scissors respectively\n");
    // to simplify the rest of the program I would change user input to uppercase or lowercase 
  scanf("%s", userPlay);

  // if userPlay is not r, p, or s skip the rest of the program
  if (strcmp(userPlay, "r") == 0 || strcmp(userPlay, "R") == 0 || strcmp(userPlay, "s") == 0 || strcmp(userPlay, "S") == 0 || strcmp(userPlay, "p") == 0 || strcmp(userPlay, "P") == 0) {
   
    // get random number for computer play, using seed based on time
    srand(time(NULL));
    randomNum = rand() % 3;
  
    // Assign computerPlay based on randomNum
    if(randomNum < 1){
      strcpy(computerPlay, "r");
    } else if (randomNum > 1) {
      strcpy(computerPlay, "p");
    } else {
      strcpy(computerPlay, "s");
    }

    // compare values to decide who wins
    if(strcmp(computerPlay, userPlay) == 0){
      // If user and computer play the same thing
      strcpy(winCondition, "It's a tie!");
      // evaluate win conditions
    } else if ((strcmp(userPlay, "r") == 0 || strcmp(userPlay, "R") == 0) && (strcmp(computerPlay, "s") == 0)) {
      strcpy(winCondition, "You win!");
    } else if ((strcmp(userPlay, "p") == 0 || strcmp(userPlay, "P") == 0) && (strcmp(computerPlay, "r") == 0)) {
      strcpy(winCondition, "You win!");
    } else if ((strcmp(userPlay, "s") == 0 || strcmp(userPlay, "S") == 0) && (strcmp(computerPlay, "p") ==0 )) {
      strcpy(winCondition, "You win!");
    } else {
      // if you don't win or tie you lose
      strcpy(winCondition, "You lose!");
    }
    // tell the user about the outcome
    printf("Computer plays %s\n", computerPlay);
    printf("%s\n", winCondition);
    printf("Thanks for playing!\n");
  } else {
    // calling the program agaian would be helpful at this point
    printf("Invalid play. Please restart the program.\n");

  }
  
  return 0;
}