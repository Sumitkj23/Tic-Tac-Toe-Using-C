									// version 2
									// by Skj..

# include<stdio.h>
# include<stdlib.h>
char a[9];
int chance=0, totalChance, score1=0, score2=0, match=5;
char player1[20], player2[20];

void drawStructure()
{
    int i=0;

    system("cls");

    printf("\n\n\t\t\t\t   -------------------- Battle --------------------");

    printf("\n\n\n\n\t\t\t\t\t%s : X \t\t Score : %d \n\t\t\t\t\t%s : O \t\t Score : %d \n\n\n",player1,score1,player2,score2);

    printf("\t\t\t\t\t\t      Match %d\n\n",6-match);

    while(1)
    {
        printf("\n\t\t\t\t\t\t     %c | %c | %c",a[i],a[i+1],a[i+2]);
        i=i+3;
        if(i>6)
            break;
        printf("\n\t\t\t\t\t\t    ---|---|---");
    }

    printf("\n\n");
}

void setInitial()
{
    int i,s=49;
    totalChance=9;
    for(i=0;i<9;i++)
    {
        a[i]=s;
        s++;
    }
}

void getInput()
{
    int p;

    if(chance==0)
        printf("\n\n\t\t\t\t\t%s Turn \t\t Enter Position : ",player1);
    else
        printf("\n\n\t\t\t\t\t%s Turn \t\t Enter Position : ",player2);

    scanf("%d",&p);

    if(p<1 || p>9)
    {
        drawStructure();
        printf("\n\t\t\t\t---------------- Please Enter Valid Position ----------------\n");
        getInput();
    }
    else
    {
        if(a[p-1]=='X' || a[p-1]=='O')
        {
            drawStructure();
            printf("\n\t\t\t---------- Position Already Occupied,   Please Enter Valid Position ----------\n");
            getInput();
        }
        else
        {
            if(chance==0)
            {
                a[p-1]='X';
                chance=1;
            }
            else
            {
                a[p-1]='O';
                chance=0;
            }
            totalChance--;
        }

    }

}

int gameWinner()
{
    if(chance==1)
    {
        if((a[0]=='X' && a[1]=='X' && a[2]=='X') || (a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[6]=='X' && a[7]=='X' && a[8]=='X') ||
           (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[2]=='X' && a[5]=='X' && a[8]=='X') ||
           (a[0]=='X' && a[4]=='X' && a[8]=='X') || (a[2]=='X' && a[4]=='X' && a[6]=='X'))
        {
            score1+=5;
            drawStructure();
            printf("\n\n\t\t\t\t\t\t     %s win",player1);
            return 1;
        }
    }
    else
    {
        if((a[0]=='O' && a[1]=='O' && a[2]=='O') || (a[3]=='O' && a[4]=='O' && a[5]=='O') || (a[6]=='O' && a[7]=='O' && a[8]=='O') ||
           (a[0]=='O' && a[3]=='O' && a[6]=='O') || (a[1]=='O' && a[4]=='O' && a[7]=='O') || (a[2]=='O' && a[5]=='O' && a[8]=='O') ||
           (a[0]=='O' && a[4]=='O' && a[8]=='O') || (a[2]=='O' && a[4]=='O' && a[6]=='O'))
        {
            score2+=5;
            drawStructure();
            printf("\n\n\t\t\t\t\t\t     %s win",player2);
            return 2;
        }
    }

    if(totalChance == 0)
    {
        drawStructure();
        printf("\n\n\t\t\t\t\t\t     Game Draw");
        return 3;
    }

    return 0;
}

int main()
{
    int k;
    int i,j,waitSecond;
    char playAgain;

    printf("\n\n\n\t\t\t\t-------------------- Tournament Begins ----------------------");
    printf("\n\t\t\t\t\t______________________________________________");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t Enter Player 1 Name : ");
    scanf("%s",player1);

    printf("\n\n\n\t\t\t\t\t Enter Player 2 Name : ");
    scanf("%s",player2);

    while(match)
    {
        waitSecond=5;

        setInitial();

        while(totalChance)
        {
            drawStructure();
            getInput();
            k=gameWinner();
            if(k==1 || k==2 )
                break;
        }

        while(waitSecond>0)
        {
            for(i=0;i<100000;i++)
            {
                for(j=0;j<7777;j++);
            }

            drawStructure();
            if(k==1)
                printf("\n\n\t\t\t\t\t\t     %s win",player1);
            else if(k==2)
                printf("\n\n\t\t\t\t\t\t     %s win",player2);
            else
                printf("\n\n\t\t\t\t\t\t     Game Draw");

            if(match>1)
                printf("\n\n\n\t\t\t\t\t\tPlease Wait %d second",waitSecond);
            else
            {
                printf("\n\n\n\t\t\t\t-------------------- Game Over --------------------");
                //printf("\n\n\t\t\t\t\t\t--------------------Result Calculating--------------------");
                printf("\n\n\n\t\t\t\t\t\tPlease Wait %d second",waitSecond);
            }
            waitSecond--;
        }
        match--;
    }

    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t %s : %d points",player1,score1);
    printf("\n\n\t\t\t\t\t\t %s : %d points",player2,score2);

    printf("\n\n\t\t\t-----------------------------------------------------------------\n");

    if(score1>score2)
        printf("\n\n\n\t\t\t\t\t\t    %s Won",player1);
    else if(score2>score1)
        printf("\n\n\n\t\t\t\t\t\t    %s Won",player2);
    else
        printf("\n\n\n\t\t\t\t\t\t Tournament Draw");

    printf("\n\n\n\t\t\t\t\t\t    ThankYou");
    printf("\n\n\t\t\t-----------------------------------------------------------------\n");
    printf("\t\t\t-----------------------------------------------------------------\n\n\n");

    fflush(stdin);
    getchar();

    return 0;
}
