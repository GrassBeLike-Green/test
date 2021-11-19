/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Tom Yuet Yi
 * Student ID    : 1155160583
 * Class/Section : 1110F
 * Date          : 8/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            gameBoard[i][j] = 0;
        }
    }// TODO : Complete this part

}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

int row, column;
    for(row = 0; row < 6 ; row=row+1) {
        for(column = 0; column < 7; column=column+1) {
            if (gameBoard[row][column] == 0)
                printf ("| ");
            if (gameBoard[row][column] == 1)
                printf ("|O");
            if (gameBoard[row][column] == 2)
                printf ("|X");
        }
    printf("|\n");
    }
printf (" 1 2 3 4 5 6 7 ");
printf ("\n"); // TODO : Complete this part
}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    int place = 0;
    scanf("%d", &place);

    while (place < 1 || place > 7){
    printf ("Input out of range. Please input again: ");
    scanf("%d", &place);}

    for (int i = 5;  i>=0; i--){
        if (gameBoard[i][place-1] == 0){
                gameBoard[i][place-1] = mark;
                break;
        }
    }

    if (gameBoard[0][place-1] != 0)
      printf ("Column is full. Please input again: \n");


  }  // TODO : Complete this part


/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner (int gameBoard[6][7]){
//Human vs Human
//horizontal, condition 1
for (int i = 0; i < 6; i++){

    //for O
    for (int j = 0; j < 4; j++){
      if (gameBoard[i][j] == 1 && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3]){
        return 1;
      }
    //for X
      if (gameBoard[i][j] == 2 && gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3]){
        return 1;
      }
    }

  }
    //vertical, condition 2
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 7; j++){

    //for O
      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j] && gameBoard[i][j]==gameBoard[i+2][j] && gameBoard[i][j]==gameBoard[i+3][j]){
        return 1;
      }

    //for X
      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j] && gameBoard[i][j]==gameBoard[i+2][j] && gameBoard[i][j]==gameBoard[i+3][j]){
        return 1;
      }
    }
  }
    //right diagonal, condition 3
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 4; j++){

    //for O
      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j+1] && gameBoard[i][j]==gameBoard[i+2][j+2] && gameBoard[i][j]==gameBoard[i+3][j+3]){
        return 1;
      }

    //for X
      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j+1] && gameBoard[i][j]==gameBoard[i+2][j+2] && gameBoard[i][j]==gameBoard[i+3][j+3]){
        return 1;
      }
    }
  }
    //left diagonal, condition 4
  for (int i = 0; i < 3; i++){
    for (int j = 3; j < 10; j++){

    //for O
      if (gameBoard[i][j] == 1 && gameBoard[i][j]==gameBoard[i+1][j-1] && gameBoard[i][j]==gameBoard[i+2][j-2] && gameBoard[i][j]==gameBoard[i+3][j-3]){
        return 1;
      }
    //for X
      if (gameBoard[i][j] == 2 && gameBoard[i][j]==gameBoard[i+1][j-1] && gameBoard[i][j]==gameBoard[i+2][j-2] && gameBoard[i][j]==gameBoard[i+3][j-3]){
        return 1;
      }
    }
  }
  return 0;
}


// TODO : Complete this part




/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {
  if (gameBoard[0][0] != 0 && gameBoard[0][1] != 0 && gameBoard[0][2] != 0 && gameBoard[0][3] != 0 && gameBoard[0][4] != 0 && gameBoard[0][5] != 0 && gameBoard[0][6] != 0 ){
    return 1;
  }
  else return 0;

}
    // TODO : Complete this part



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */
void placeMarkByComputerPlayer(int gameBoard[6][7], int mark) {


}// TODO : Write the placeMarkByComputerPlayer(...) function here

/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;

        printf("Enter the number of human players [1-2]:\n");
        scanf("%d", &numOfHumanPlayers);
          // You can assume that the user input must be valid


    if (numOfHumanPlayers == 2){
        // for (int i = 0; i < 10; i++){
        while(gameContinue!=0){
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 2 wins!");
              break;
            }

            if (isFull (gameBoard) == 1)
              printf ("Draw game. ");

            printf("Player 1's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CIRCLE);
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 1 wins!");
              break;
            }

            if (isFull (gameBoard) == 1)
              printf ("Draw game. ");

            printf("Player 2's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CROSS);
        }
    }
    else if (numOfHumanPlayers == 1){
        while(gameContinue!=0){
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Computer wins!");
              break;
            }

            if (isFull (gameBoard) == 1)
              printf ("Draw game. ");

            printf("Player 1's turn:\n");
            placeMarkByHumanPlayer(gameBoard, CIRCLE);
            printGameBoard(gameBoard);

            if (hasWinner (gameBoard) == 1){
              printf ("Congratulations! Player 1 wins!");
              break;
            }

            if (isFull (gameBoard) == 1)
              printf ("Draw game. ");

            printf ("Computer's turn: \n");
            placeMarkByHumanPlayer(gameBoard, CROSS);

    }


    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part

    return 0;
}}
