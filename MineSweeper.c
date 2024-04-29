
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 9
int mine[N][N],game[N][N];
int row=0,col=0,a,b;
int main()
{
    void putmine(int n1);
    int expand(int row,int col);
    int Remain();
    void myprintf1();
    void myprintf2();
    int aroundmine(int row,int col);

    /*  提示说明  */
    printf(" -------------------------------------------------------------------\n*You're going to play a %d*%d game of minesweeper next.*\n*Please follow the prompts (otherwise there will be an accident),*\n*         In this game, the * stands for the mine and the # stands for the unopened box.\n*When you open all the non-thunder boxes, you win!*\n*Thank you for participating in the game *\n -------------------------------------------------------------------",N,N);

    int n1,i=0,j=0;

    /*初始化雷区*/
    for(i=0;i<N;i++)
    {  for(j=0;j<N;j++)
        mine[i][j]=46, game[i][j]='#';
    }


    printf("\n\nThis game is %d*%d thunderstorm, please enter the amount of mines to be laid (within %d)>> ",N,N,N*N);
    scanf("%d",&n1);
    printf("\nBelow are the minefields laid>> \n");
    putmine(n1);
    myprintf1();

	   for(i=0;i<N;i++)
           for(j=0;j<N;j++)
           { if(mine[i][j]!='*')
               mine[i][j]=aroundmine(i,j)+48;
           }
	   printf("\nCount thunderstorms>>     \n");
    myprintf1();

    while(Remain()!=n1)
    {  	 printf("\nPlease enter the minesweeper below is the coordinates of the minefield, to ,separated>>   ");
        scanf("%d,%d",&row,&col);
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
            {  if(i==row-1&&j==col-1)
                a=i,b=j;
            }

        if(mine[a][b]==42)    goto end;
        else expand(a,b);
        myprintf2();

    }
    printf("\nHey, you win! Have the ability to do it again!  \n");
end:    if(Remain()!=n1)      printf("\npity, you stepped on thunder, so you lost!\n");

    return 0;
}

/*布雷*/
void putmine(int n1)
{   int minenumber();
    int i=0,j=0;
    srand(time(NULL));
    for(i=0; minenumber()<n1;i++)     {
        row=rand()%N , col=rand()%N;
        mine[row][col]=42;     }
}

/*打开相关不是地雷的数组元素*/

int expand(int row,int col)
{   int aroundmine(int row,int col);
    int inminearea(int row,int col);
    int i=0,j=0;
    if( mine[row][col]=='*')   return 0;
    if( aroundmine(row,col)!=0 )
    {   game[row][col]=aroundmine(row,col)+48;return 0;

    }
    game[row][col]='0';
    for(i=row-1;i<=row+1;i++)
        for(j=col-1;j<=col+1;j++)
        {
            if( !inminearea(i,j) )    continue;
            if(game[i][j]!='#')       continue;
            game[i][j]=aroundmine(i,j)+48;
            if (aroundmine(i,j)==0)   expand(i,j);
        }
    return 0;//add by wxyun
}

/*获得周围地雷个数*/
int aroundmine(int row,int col)
{   int inminearea(int row,int col);
    int around=0;
    int i=0,j=0;
    for(i=row-1;i<=row+1;i++)
        for(j=col-1;j<=col+1;j++)
        {   if(!inminearea(i,j))  continue;
            if(mine[i][j]==42)   around++;   }
    return around;
}

/*是否在雷区*/
int inminearea(int row,int col)
{  if(row>=0&&row<N&&col>=0&&col<N)  return 1;
    return 0;
}

/* 计雷区的地雷个数*/
int minenumber()
{  int minenum=0;
    int i=0,j=0;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        { if(mine[i][j]==42)  minenum++; }
    return minenum;
}

/*计算game[][]中剩余的'#'*/
int Remain()
{  int odd=0,i=0,j=0;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(game[i][j]=='#')  odd++;
    return odd;
}

/*打印当前雷区状态*/
void myprintf1()
{
    int i=0,j=0;
    printf("Line \t");
    for(i=0;i<N;i++)
        printf("%d\t",i+1);
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("Row %d\t",i+1);
        for(j=0;j<N;j++)
            printf("%c\t",mine[i][j]);
        printf("\n\n");
    }
}
void myprintf2()
{
    int i=0,j=0;
    printf("\n Below is the game thunderstorm>>  \n");
    printf("Line \t");
    for(i=0;i<N;i++)
        printf("%d\t",i+1);
    printf("\n");
    for(i=0;i<N;i++)
    {
        printf("Row %d\t",i+1);
        for(j=0;j<N;j++)
            printf("%c\t",game[i][j]);
        printf("\n\n");
    }
}

