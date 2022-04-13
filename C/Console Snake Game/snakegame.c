/* C program to build a simple snake game in terminal */
  
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
int i, j, height = 40;
int width = 40, gameover, score;
int x, y, fruitx, fruity, flag;
char ch[100];
// Function to draw the gameboard 
void draw(char str[100])
{
  system("cls");
  
  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      if (i == 0 || i == width - 1)
         printf("——");
      else if (j == 0) 
        printf("|");
      else if(j == height -1)
        printf("  |");
    
      else
      {
        if(i == x && j == y)
         {
                printf("Ø "); //snake
           
         }
        else if(i==fruitx && j==fruity)
          printf("∆ "); //fruit
        else
          printf("  ");
      }
    } 
  
    printf("\n");
  }


// Printing player name scores and instructions for the user

  printf("\n~~~WELCOME TO BASIC SNAKE GAME BUILT USING C~~~\n");
  printf("\nPlayer name: %s\t\t\t", str);
  printf("Your current score = %d\n",score);
  printf(" \nToggles:\n 'W'/'w' - Up\n 'S'/'s' - Down\n 'A'/'a' - Left\n 'D'/'d' - Right");
  printf("\nOr press 'X'/'x' to quit the game\n");
  printf("\n\nYou pressed: \n");
}


// Function to generate fruit within the gameboard
void setup()
{
    gameover = 0;
  
    // Stores height and width
    x = height / 2;
    y = width / 2;
label1:
    fruitx = rand() % 40;
    if (fruitx == 0 || (fruitx % 4 != 0))
        goto label1;
label2:
    fruity = rand() % 40;
    if (fruity == 0 || (fruity % 4 != 0))
        goto label2;
    score = 0;
    
}

// Function to take the input
void input()
{
   if(kbhit()){
        switch (getchar())
        {
        case 'a':
        case 'A':
            flag = 1;
            break;
        case 's':
        case 'S':
            flag = 2;
            break;
        case 'd':
        case 'D':
            flag = 3;
            break;
        case 'w':
        case 'W':
            flag = 4;
            break;
        case 'x':
        case 'X':
            gameover = 1;
            break;
        default:
            printf("\nKindly enter a valid option.\n");
            
        }
    }
}

// Function for the logic behind
// each movement
void logic()
{
    sleep(0.0015);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
  
    // If the game is over
    if (x < 0 || x > height
        || y < 0 || y > width)
        gameover = 1;
  
    // If snake reaches the fruit
    // update the score
    if (x == fruitx && y == fruity)
    {
      
    label3:
        fruitx = rand() % 40;
        if (fruitx == 0 || (fruitx % 4 != 0))
            goto label3;
  
    // After eating the above fruit
    // generate new fruit at random spots
    // inside the boundary 
    label4:
        fruity = rand() % 40;
        if (fruity == 0 || (fruity % 4 != 0)) 
            goto label4;
        score += 10;
        
     
    }
}

//Driver Code
void main()
{
    // Taking player name as input
    printf("Enter player name: ");
    scanf("%s", &ch);
    
    // Clears the input buffer (here: the newline)
    while ((getchar()) != '\n');
    
    // To generate boundary
    setup();
  
    // Until the game is over
    while (!gameover)
    {
  
        // Function Call
        draw(ch);
        input();
        logic();
    }
}
