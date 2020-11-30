#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TURN_NUMBER 2
int randomNumber();
void putInArray(int put, int array[], int index);

int main()
{
    int turn = 1;
    int numberHolder[10];
    bool win = true;
    int currTime, elapsedTime = 0;
    
    printf("Let's play concentration game with 10 numbers\n");
    int index = 0;
    while ( turn <= TURN_NUMBER && win)
    {
        int newNumber = randomNumber();
        int j;
        
        putInArray(newNumber, numberHolder, index);
        index ++;
        for(j = 0; j <= turn; j++)
        {
            printf("%d \n", numberHolder[j]);
            
        }
        currTime = time(NULL);

        do
        {
            elapsedTime = time(NULL);
        } while ((elapsedTime - currTime) < 3);
        system("cls");

        printf("What were the numbers? \n");
        int d = 0;
        for(d; d <= turn;d++)
        {
            int ans;
            scanf("%d", &ans);
            if(ans != numberHolder[d])
            {
                win = false;
                goto loss;
            }
        }

        system("cls");
        
        if(turn == TURN_NUMBER && win)
        {
            printf("congratultions you won");
        }
         turn ++;
    }
    
    loss:
    if(!win)
        printf("shame you lost");
    return 0;
}

int randomNumber()
{
    int gen = 0;
    srand(time(NULL));
    gen = rand() % 100;
    return gen;
}

void putInArray(int put, int array[], int index)
{
    array[index] = put; 
}