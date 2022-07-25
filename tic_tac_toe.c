

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char b[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char response[4];
   char p[4] ="yes";

   do
   {
      winner = ' ';
      //response ;
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (yes/no): ");
      //scanf("%c");
      scanf("%s", response);
      //response = toupper(response);
   } while (!strcmp(response,p));

   printf("Thanks for playing!");

   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         b[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf(" %c | %c | %c ", b[0][0], b[0][1], b[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", b[1][0], b[1][1], b[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", b[2][0], b[2][1], b[2][2]);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(b[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;

   do
   {
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;

      if(b[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         b[x][y] = PLAYER;
         break;
      }
   } while (b[x][y] != ' ');
   
}
void computerMove()
{
   //creates a seed based on current time
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (b[x][y] != ' ');
      
      b[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(b[i][0] == b[i][1] && b[i][0] == b[i][2])
      {
         return b[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(b[0][i] == b[1][i] && b[0][i] == b[2][i])
      {
         return b[0][i];
      }
   }
   //check diagonals
   if(b[0][0] == b[1][1] && b[0][0] == b[2][2])
   {
      return b[0][0];
   }
   if(b[0][2] == b[1][1] && b[0][2] == b[2][0])
   {
      return b[0][2];
   }

   return ' ';
}
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      printf("YOU WIN!");
   }
   else if(winner == COMPUTER)
   {
      printf("YOU LOSE!");
   }
   else{
      printf("IT'S A TIE!");
   }
}