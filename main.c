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
  char userPlay[2], computerPlay[2], winCondition[50];
  int randomNum, winLossTie;
  
  //Welcome user get userPlay
  printf("Welcome to the Rock Paper Scissors Game!\n");
  printf("Enter r, p, or s for rock, paper, or scissors respectively\n");
  printf("What is your play?\n");
    // to simplify the rest of the program I would change user input to uppercase or lowercase, after their input 
  scanf("%s", userPlay);
  
    // get random number for computer play, using seed based on time
    srand(time(NULL));
    randomNum = rand() % 3;

  // set computer's play
    
  if(randomNum < 1){
    computerPlay[0] = 'r';
  } else if (randomNum > 1) {
    computerPlay[0] = 'p';
  } else {
    computerPlay[0] = 's';
  }

  // if userPlay is not r, p, or s skip the rest of the program
  switch (userPlay[0]) {
    case 'r':
    case 'R':
    case 'S':
    case 's':
    case 'p':
    case 'P':
      break;
    default:
      printf("Invalid play, please try again.");
      return 0;
      break;
  }

  // Tell the user what their opponent plays
    printf("Computer plays %c\n", computerPlay[0]);
  // compare values to decide who wins
    if(computerPlay[0] == userPlay[0]){
  // If user and computer play the same thing
      printf("It's a tie!\n");
  // Determine who wins
    } else if (userPlay[0] == 'R' || userPlay[0] == 'r' && computerPlay[0] == 's') {
      printf("You Win\n");
    } else if (userPlay[0] == 'P' || userPlay[0] == 'p' && computerPlay[0] == 'r') {
      printf("You win!\n");
    } else if (userPlay[0] == 's' || userPlay[0] == 'S' && computerPlay[0] == 'p') {
      printf("You win!\n");
    } else {
 // if you don't win or tie you lose
      printf("You lose!\n");
    }
  
    printf("Thanks for playing!\n");


  
  
  return 0;
}