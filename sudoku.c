#include<stdio.h>
#include<stdbool.h>
#define N 9
bool checkvalidity(int r,int c,int s[N][N], int d)
{
    for(int i=0;i<9;i++)    //checks the number in the row
    {
        if(s[r][i]==d)
        {
            return false;
        }
    }
    
    for(int j=0;j<9;j++)    //checks the number in the column
    {
        if(s[j][c]==d)
        {
            return false;
        }
    }
    int srow=r-r%3;
    int scol=c-c%3;
    for(int i=srow;i<srow+3;i++)
    {
        for(int j=scol;j<scol+3;j++)
        {
            if(s[i][j]==d)
            {
                return false;
            }
        }
    }
}
bool solver(int s[N][N])
{
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(s[i][j]==0)
            {
                for(int d= 1 ;d<=9;d++)
                {
                    if(checkvalidity(i,j,s,d))
                    {
                        s[i][j]=d;
                        if(solver(s))
                        {
                            return true;
                        }
                        s[i][j]=0;  //resets the cell value
                    }

                }
                return false;   //no valid digit found
            }
        }
        
    }
    return true;    //no empty cells left
}

void printboard(int s[N][N])
{
    for(int i=0;i<N;i++)
    {
        printf("------------------------------------");
        printf("\n");
        for(int j=0;j<N;j++)
        {
            printf(" %d |",s[i][j]);
        }
        printf("\n");
        
    }
}
int main()
{
    int s[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    printf("Input sudoku: \n");
    printboard(s);
    solver(s);
    printf("Solved sudoku: \n");
    printboard(s);
    return 0;
}
