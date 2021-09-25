/*
 *
 *   CODE BY Airbus5717
 *   TicTacToe vs Computer ( Random Numbers )
 *   2020
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

const char human = 'X';
const char computer = 'O';
int game_over = 0; /// 0 : false , 1 : true

int win_combo[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
                       {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {6, 4, 2}};

int x_avail[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int o_avail[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int human_turn = 1; // first human
int comp_turn = 0;  // comp = computer's turn

int input; // user input for play

int winner = -1; // 1 = X wins || 2 = O wins || 0 = tie
char slots[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Game slots

char empty[9] = {' ', ' ', ' ', ' ', ' ',
                 ' ', ' ', ' ', ' '}; // empty game slots

/*char colors[8][7] = {
    BLUE, RESET, RESET,
    RESET, RESET, RESET
    RESET, RESET, RESET
};*/

int print_it() {

  printf(YELLOW "\n");

  // printf();
  printf(" %c |", slots[0]);
  printf(" %c |", slots[1]);
  printf(" %c \n", slots[2]);

  printf(" %c |", slots[3]);
  printf(" %c |", slots[4]);
  printf(" %c \n", slots[5]);

  printf(" %c |", slots[6]);
  printf(" %c |", slots[7]);
  printf(" %c \n\n" RESET, slots[8]);
  return 0;
}
void check_winner() {
  for (int i = 0; i < 8; i++) /// dont confuse 8 with 9 becuz they are different
  {
    if (slots[win_combo[i][0]] == slots[win_combo[i][1]] &&
        slots[win_combo[i][1]] == slots[win_combo[i][2]] &&
        slots[win_combo[i][2]] == 'X') {
      winner = 1;
      game_over = 1;
      break;
    } else if (slots[win_combo[i][0]] == slots[win_combo[i][1]] &&
               slots[win_combo[i][1]] == slots[win_combo[i][2]] &&
               slots[win_combo[i][2]] == 'O') {
      winner = 2;
      game_over = 1;
      break;
    } else if (slots[0] != ' ' && slots[1] != ' ' && slots[2] != ' ' &&
               slots[3] != ' ' && slots[4] != ' ' && slots[5] != ' ' &&
               slots[6] != ' ' && slots[7] != ' ' && slots[8] != ' ') {
      winner = 0;
      game_over = 1;
      break;
    }
  }
}

// main game function
void game() {

  printf(YELLOW "\n");
  printf("[1] | [2] | [3]\n");
  printf("[4] | [5] | [6]\n");
  printf("[7] | [8] | [9]\n");
  printf(GREEN "Start...\n" RESET);
  printf(CYAN "Enter a Number from 1 : 9\n" RESET);
  // game slots

  // winning game combos
  while (!game_over) {
    if (winner != -1) {
      game_over = 1;
      break;
    }

    while (human_turn && winner == -1) {
      scanf("%i", &input);
      input--;
      for (int i = 0; i < 9; i++) {
        int a = i;
        if (input == a && slots[i] == ' ') {
          slots[i] = 'X';
          x_avail[i] = 1;
          human_turn = 0;
          comp_turn = 1;

          print_it();
          break;
        }
      } // end for loop
    }   // end human turn
    check_winner();
    while (comp_turn && winner == -1) {

      int y = rand() % 9;
      if (slots[y] == ' ') {
        slots[y] = 'O';

        human_turn = 1;
        comp_turn = !comp_turn;
        print_it();
      }
    }
    check_winner();

  } // Game loop end

} // end game function

// starting point ( Main function )
int main() {
  // intro
  srand(time(NULL));
  printf(BLUE "\nTicTacToe\n" RESET);
  printf(GREEN "By Airbus5717\n" RESET);

  // game call function
  game();

  // output winner
  switch (winner) {
  case 1:
    printf(GREEN "\n<| X is winner |>\n");
    break;
  case 2:
    printf(RED "\n<| O is winner |>\n");
    break;
  case 0:
    printf(BLUE "\n<| Tie |> \n");
    break;
  }
  printf("\n<| Game Over |>\n\n" RESET);
  return 0;
}
