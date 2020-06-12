# include<stdio.h>
# include<stdlib.h>
char a[9];
int chance, totalChance,score1=0,score2=0;
char player1[20],player2[20];

void drawStructure()
{
    int i=0;

    system("cls");

    printf("\n\n\n\n\t\t\t\t\t%s : X \t\t Score : %d \n\t\t\t\t\t%s : O \t\t Score : %d \n\n\n\n",player1,score1,player2,score2);

    while(i<4)
    {
        printf("\n\t\t\t\t\t\t     %c | %c | %c",a[i],a[i+1],a[i+2]);
        printf("\n\t\t\t\t\t\t    ---|---|---");
        i=i+3;
    }

    printf("\n\t\t\t\t\t\t     %c | %c | %c",a[6],a[7],a[8]);

    printf("\n\n\n");
}

void setInitial()
{
    int i,s=49;
    chance=0;
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
        printf("\n\t\t\t\t---------------- Plese Enter Valid Position ----------------\n");
        getInput();
    }
    else
    {
        if(a[p-1]=='X' || a[p-1]=='O')
        {
            drawStructure();
            printf("\n\t\t\t---------- Position Already Occupied,   Plese Enter Valid Position ----------\n");
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
            printf("\n\n\t\t\t\t\t\t    %s won",player1);
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
            printf("\n\n\t\t\t\t\t\t    %s won",player2);
            return 1;
        }
    }

    if(totalChance == 0)
    {
        system("cls");
        drawStructure();
        printf("\n\n\t\t\t\t\t\t     Game Draw");
        return 1;
    }

    return 0;
}

int main()
{
    int k;
    char playAgain;

    setInitial();

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t Enter Player 1 Name : ");
    scanf("%s",player1);

    printf("\n\n\n\t\t\t\t\t Enter Player 2 Name : ");
    scanf("%s",player2);

    play:
        while(totalChance)
        {
            drawStructure();
            getInput();
            k=gameWinner();
            if(k==1)
                break;
        }
        printf("\n\n\t\t\t-----------------------------------------------------------------\n");
        printf("\t\t\t-----------------------------------------------------------------\n\n\n");
        printf("\t\t\t\tYou Want To Play Again??? If Yes then press Y : ");
        fflush(stdin);
        scanf("%c",&playAgain);

        if(playAgain == 'Y' || playAgain== 'y')
        {
            setInitial();
            goto play;
        }
        else
            exit(0);

    return 0;
}
