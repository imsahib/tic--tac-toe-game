#include <stdio.h>
#include<stdlib.h>
void showGame(int arr[3][3])
{
    printf("\n\n");
     printf("     ");
    for(int i=0;i<3;i++)
    {
        printf("  ");
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==88)
                printf("%c",arr[i][j]);
            else
                printf("%d",arr[i][j]);
            if(j!=2)
                printf("  |  ");
            else
                if(i!=2)
               {
                 printf("\n   ---------------------\n");
                 printf("     ");
               }
        }
    }
    printf("\n\n");



}

int position_insertion(int arr[3][3],int num,int choice)
{
    int x,y,check;
    int flag;
    if(choice%3!=0)
    {
          x= choice/3;
          y=choice%3-1;
    }
    else
    {
          x= (choice/3)-1;
          y=2;
    }
    check=overlapping(arr,x,y);
    if(check==0)
    {
        printf("\n\nOVERLAPPING IS NOT ALLOWED\n\n");
        return -1;

    }
    if(num==1)
        arr[x][y]='X';
    else if(num==2)
        arr[x][y]=0;
    showGame(arr);
     flag=winning_condition(arr,x,y);
     if (flag==1)
     {
        printf("\n\nPlayer %d WON\n\n",num);
        return 1;
     }
     else
        return 0;
}

int overlapping(int arr[3][3],int x,int y)
{
    if(arr[x][y]!=0 && arr[x][y]!=88)
        return 1;
    else
        return 0;

}
int winning_condition(int arr[3][3],int x,int y)
{
   // horizontal line test
   if(y==1)
    {
        if(arr[x][y]==arr[x][y-1]&& arr[x][y]==arr[x][y+1])
            return 1;

    }
    else if(y==0)
    {
        if(arr[x][y]==arr[x][y+1] && arr[x][y]==arr[x][y+2])
            return 1;
    }
    else if (y==2)
    {
         if(arr[x][y]==arr[x][y-1] && arr[x][y]==arr[x][y-2])
             return 1;
    }

    // vertical line test
    if (x==1)
    {
        if(arr[x][y]==arr[x-1][y]&& arr[x][y]==arr[x+1][y])
                return 1;
    }
    else  if(x==0)
    {
        if(arr[x][y]==arr[x+1][y] && arr[x][y]==arr[x+2][y])
                return 1;

    }
   else  if(x==2)
   {
        if(arr[x][y]==arr[x-1][y]&& arr[x][y]==arr[x-2][y])
            return 1;
   }

   // diagonal line test
   if(arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2])
            return 1;
   else if(arr[0][2]==arr[1][1]&&arr[0][2]==arr[2][0])
            return 1;

    return 0;
}

int check_winning_condition(int arr[3][3],int userChoice)
{
    int i,choice,loc;
    loc= empty_choice(arr);
    if(loc==-1)
      {
            printf("\n\nGame drawn\n\n");
            return -1;
      }
      if(userChoice>0 && userChoice<10)
         printf("\ncomputer turn:\n");

    switch(userChoice)
    {
        case 1:
                if(arr[0][0]==arr[0][1] && overlapping(arr,0,2)==1)
                    i=position_insertion(arr,2,3);
                else if (arr[0][0]==arr[0][2] && overlapping(arr,0,1)==1)
                    i=position_insertion(arr,2,2) ;
                else if(arr[0][0]==arr[1][0] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7) ;
                else if(arr[0][0]==arr[2][0] && overlapping(arr,1,0)==1)
                   i=position_insertion(arr,2,4);
                else if(arr[0][0]==arr[1][1] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[0][0]==arr[2][2] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                   i=position_insertion(arr,2,loc);
                return i;
                break;



        case 2:
                if(arr[0][1]==arr[0][0] && overlapping(arr,0,2)==1)
                   i= position_insertion(arr,2,3);
                else if(arr[0][1]==arr[0][2] && overlapping(arr,0,0)==1)
                   i= position_insertion(arr,2,1);
                else if(arr[0][1]==arr[1][1] && overlapping(arr,2,1)==1)
                   i= position_insertion(arr,2,8);
                else
                    i= position_insertion(arr,2,loc);
                return i;
                break;
        case 3:
                if(arr[0][2]==arr[0][1] && overlapping(arr,0,0)==1)
                   i= position_insertion(arr,2,1);
                else if(arr[0][2]==arr[0][0] && overlapping(arr,0,1)==1)
                    i=position_insertion(arr,2,2);
                else if(arr[0][2]==arr[1][2] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[0][2]==arr[2][2] && overlapping(arr,1,2)==1)
                    i=position_insertion(arr,2,6);
                else if(arr[0][2]==arr[1][1] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7);
                else if(arr[0][2]==arr[2][0] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                     i=position_insertion(arr,2,loc);
                return i;
                break;
        case 4:
                if(arr[1][0]==arr[0][0] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7);
                else if(arr[1][0]==arr[2][0] && overlapping(arr,0,0)==1)
                    i=position_insertion(arr,2,1);
                else if(arr[1][0]==arr[1][1] && overlapping(arr,1,2)==1)
                    i=position_insertion(arr,2,6);
                else if(arr[1][0]==arr[1][2] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                     i=position_insertion(arr,2,loc);
                return i;
                break;
        case 5:
               if(arr[1][1]==arr[1][0] && overlapping(arr,1,2)==1)
                    i=position_insertion(arr,2,6);
               else  if(arr[1][1]==arr[1][2] && overlapping(arr,1,0)==1)
                    i=position_insertion(arr,2,4);
               else   if(arr[1][1]==arr[0][1] && overlapping(arr,2,1)==1)
                    i=position_insertion(arr,2,8);
                else if(arr[1][1]==arr[2][1] && overlapping(arr,0,1)==1)
                    i=position_insertion(arr,2,2);
                else if(arr[1][1]==arr[0][0] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[1][1]==arr[2][2] && overlapping(arr,0,0)==1)
                    i=position_insertion(arr,2,1);
                else if(arr[1][1]==arr[0][2] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7);
                else if(arr[1][1]==arr[2][0] && overlapping(arr,0,2)==1)
                    i=position_insertion(arr,2,3);
                else
                     i=position_insertion(arr,2,loc);
                return i;
                break;

        case 6:
                if(arr[1][2]==arr[1][1] && overlapping(arr,1,0)==1)
                    i=position_insertion(arr,2,4);
                else if(arr[1][2]==arr[1][0] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else if(arr[1][2]==arr[0][2] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[1][2]==arr[2][2] && overlapping(arr,0,2)==1)
                    i=position_insertion(arr,2,3);
                else
                    i=position_insertion(arr,2,loc);
                return i;
                break;
        case 7:
                if(arr[2][0]==arr[2][1] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[2][0]==arr[2][2] && overlapping(arr,2,1)==1)
                    i=position_insertion(arr,2,8);
                else if(arr[2][0]==arr[1][0] && overlapping(arr,0,1)==1)
                    i=position_insertion(arr,2,1);
                else if(arr[2][0]==arr[0][0] && overlapping(arr,1,0)==1)
                    i=position_insertion(arr,2,4);
                else if(arr[2][0]==arr[1][1] && overlapping(arr,0,2)==1)
                    i=position_insertion(arr,2,3);
                else if(arr[2][0]==arr[0][2] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                    i=position_insertion(arr,2,loc);
                return i;
                break;
        case 8:
                if(arr[2][1]==arr[2][0] && overlapping(arr,2,2)==1)
                    i=position_insertion(arr,2,9);
                else if(arr[2][1]==arr[2][2] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7);
                else if(arr[2][1]==arr[1][1] && overlapping(arr,0,1)==1)
                    i=position_insertion(arr,2,2);
                else if(arr[2][1]==arr[0][1] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                     i=position_insertion(arr,2,loc);
                return i;
                break;
        case 9:
                if(arr[2][2]==arr[2][1] && overlapping(arr,2,0)==1)
                    i=position_insertion(arr,2,7);
                else if(arr[2][2]==arr[2][0] && overlapping(arr,2,1)==1)
                    i=position_insertion(arr,2,8);
                else if(arr[2][2]==arr[1][2] && overlapping(arr,0,2)==1)
                    i=position_insertion(arr,2,3);
                else if(arr[2][2]==arr[0][2] && overlapping(arr,1,2)==1)
                    i=position_insertion(arr,2,6);
                else if(arr[2][2]==arr[1][1] && overlapping(arr,0,0)==1)
                    i=position_insertion(arr,2,1);
                else if(arr[2][2]==arr[0][0] && overlapping(arr,1,1)==1)
                    i=position_insertion(arr,2,5);
                else
                     i=position_insertion(arr,2,loc);
                return i;
                break;
        default:
                printf("invalid choice try again");
    }
    return 0;

}
int empty_choice(int arr[3][3])
{
    int i,j,choice;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]!=0 && arr[i][j]!=88)
            {
                choice = (i*3)+(j+1);
                return choice;

            }
        }
    }
    return -1;

}


void play_with_player()
{
    int flag,choice,loc,arr[3][3]={1,2,3,4,5,6,7,8,9};
    char first[20],second[20];
    fflush(stdin);
    printf("\nPlayer 1 Name: ");
    gets(first);
    fflush(stdin);
    printf("\nPlayer 2 Name: ");
    gets(second);
    printf("\n\n\n");
    printf("%s  X\n\n",first);
    printf("%s  O\n\n",second);
    printf("\n\n\n");
    showGame(arr);
    printf("\n\n");
    while(1)
    {
     level_1:
        printf("player 1 - %s: Enter position Number -> ",first);
        scanf("%d",&choice);
        if(choice>9 || choice<1)
        {
             printf("\nInvalid choice\n\n");
             goto level_1;
        }
        flag= position_insertion(arr,1,choice);
        if(flag==-1)
        {
             goto level_1;
        }

        if(flag==1)
            break;
        if(flag==0)
        {
            loc= empty_choice(arr);
            if(loc==-1)
            {
                printf("\nGame drawn\n\n");
                break;
            }


        }
        printf("\n\n");
     level_2:
            printf("player 2 - %s Enter position Number-> ",second);
            scanf("%d",&choice);
            if(choice>9 || choice<1)
            {
                printf("\nInvalid choice\n\n");
                goto level_2;
            }
            flag= position_insertion(arr,2,choice);
            if(flag==-1)
            {
               goto level_2;

            }
            if(flag==1)
                break;
            if(flag==0)
            {
                loc= empty_choice(arr);
                if(loc==-1)
                {
                    printf("\nGame drawn\n\n");
                    break;
                }
            }

            printf("\n\n");
    }

}
void play_with_smart_computer()
{
    int i,flag,choice,arr[3][3]={1,2,3,4,5,6,7,8,9};
    char first[20];
    fflush(stdin);
    printf("\nPlayer 1 Name: ");
    gets(first);
    printf("\n\n\n");
    printf("%s  X\n\n",first);
    printf("Computer 0\n\n");
    showGame(arr);
    while(1)
    {
        level_1:
         printf("\n\n");
         printf("player-1- %s Enter position Number-> ",first);
         scanf("%d",&choice);
        flag=position_insertion(arr,1,choice);
        if(flag==-1)
         goto level_1;
        else if(flag==1)
            break;
         else
        {
            i=check_winning_condition(arr,choice);
            if(i==-1 || i==1)
                break;
        }

    }
}

int evil_moves(int arr[3][3])
{
    int i=0;
    if(arr[0][0]==88 && arr[0][0]==arr[1][1] && arr[2][2]==9)
         i= position_insertion(arr,2,9);

    else  if(arr[0][2]==88 && arr[0][2]==arr[1][1] && arr[2][0]==7)
         i= position_insertion(arr,2,7);

     else if(arr[1][0]==88 && arr[1][0]==arr[1][1] && arr[1][2]==6)
           i= position_insertion(arr,2,6);

    else if (arr[2][0]==88 && arr[2][0]==arr[2][2] && arr[1][2]==6)
        i=position_insertion(arr,2,6);
     else if (arr[2][0]==88 && arr[2][0]==arr[2][2] && arr[1][1]==5)
        i=position_insertion(arr,2,5);
        return i;


}

void play_with_evil_computer()
{

    int i,flag,choice,arr[3][3]={1,2,3,4,5,6,7,8,9};
    char first[20];
    fflush(stdin);
    printf("\nPlayer 1 Name: ");
    gets(first);
    printf("\n\n\n");
    printf("%s  X\n\n",first);
    printf("Computer 0\n\n");
    showGame(arr);
    while(1)
    {
        level_1:
         printf("\n\n");
         if(empty_choice(arr)==-1)
            {
                printf("\n\nGame drawn\n\n");
                break;
            }
          printf("player-1- %s Enter position Number-> ",first);
          scanf("%d",&choice);
        flag=position_insertion(arr,1,choice);
        if(flag==-1)
         goto level_1;
        else if(flag==1)
            break;
         else
        {
            i=check_winning_condition(arr,choice);
            if(i==-1 || i==1)
                break;
           i= evil_moves(arr);
           if(i==1)
                break;

        }

    }

}
int menu_driven()
{
    int choice;
    printf("\n1.want to play with Smart computer");
    printf("\n2.want to play with Evil computer");
    printf("\n3.want to play with player");
    printf("\n4.Exit");
    printf("\n\nEnter your choice");
    scanf("%d",&choice);
    return choice;


}
void main()
{
    while(1)
    {
         switch(menu_driven())
         {
            case 1:
                   play_with_smart_computer();
                    break;
            case 2:
                    play_with_evil_computer();
                    break;
            case 3:
                    play_with_player();
                    break;
            case 4:
                    exit(0);

         }
    }
}

