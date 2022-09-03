#include <stdio.h>
#include<stdlib.h>
void showGame(int arr[3][3])          
{ /*  
    this function is for displaying the game 
*/
    printf("\n\n");
     printf("     ");
    for(int i=0;i<3;i++)
    {
        printf("  ");
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==88)            // 88 is the ASCII code of 'X'
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
    /*
        this function is for inserting the 0 or X at desired position by user/ computer
        num- it represents the user .
        num=1-> 1 user 
        num 2-> 2 user/ computer
        choice-> desired position to enter.
        this function return -1 -> for overlapping 
        this function return 1-> if user/computer won
        this function return 0-> if game is not over yet
    */
    int x,y,check;
    int flag;
    if(choice%3!=0)
    {
          x= choice/3;                // we are converting choice number entered by  user/computer into indexes of the 2D array
          y=choice%3-1;               // this condition runs for choices which are not divisible by 3.
    }
    else
    {
          x= (choice/3)-1;              // this condition runs for choice which are divisible by 3.
          y=2;                          // x, y represents the indexes of 2D array regarding to the choice entered by the user/computer.
    }
    check=overlapping(arr,x,y);    // this function check whether that  location is already occupied or not. 
    if(check==0)
    {
        printf("\n\nOVERLAPPING IS NOT ALLOWED\n\n");
        return -1;

    }
    if(num==1)
        arr[x][y]='X';     // for user -1 it's predecided symbol 'X'
    else if(num==2)
        arr[x][y]=0;       // for user -2 it's predecided symbol '0'
    showGame(arr);
     flag=winning_condition(arr,x,y);    // this function call returns the value 0 or 1 to determine the user has won or not 
     if (flag==1)                                // flag ==1 represents the winning condition
     {
        printf("\n\nPlayer %d WON\n\n",num);
        return 1;
     }
     else
        return 0;                             // flag ==0 represents the game is not over yet.      
}

int overlapping(int arr[3][3],int x,int y)
{
    /*
        this function checks that position is empty or not at which user wants to enter 
        x,y-> it represnts the idexes of the 2D array. 
    */
    if(arr[x][y]!=0 && arr[x][y]!=88)
        return 1;                             // it returns 1 if that location is empty 
    else                                      // here 88 is the ASCII value of 'X'
        return 0;                             // it returns 0 if that location is already occupied

}
int winning_condition(int arr[3][3],int x,int y)
{
    /*
        this function checks all the possible winning conditions 
        it returns 1 if the winning conition matches
        it return 0 if winning condition does not matches
    */
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
    /*
        this function is specially made for computer as a player 2. 
        this function blocks the user to win 
        it analysis the winning position before inserting 0 (predecided symbol for player 2)
        this function returns -1 -> if game is drawn
        this function returns 0-> if user entered the invalid choice 
        this function returns i i.e 1,0 ,-1   -> 1 for if computer wins and 0 if the game is not over yet.
        -> it will never return -1 as a return of i because we check overlapping condition before inseting.
        -> which means -1 has only one meaning here i.e game is drawn.
    */
    int i,choice,loc;
    loc= empty_choice(arr);    // this function call return the empty location in an 2D array
    if(loc==-1)                 // if it is -1 it means there is no vacant space in 2D array
      {
            printf("\n\nGame drawn\n\n");       // and game is drawn in that condition
            return -1;
      }
      if(userChoice>0 && userChoice<10)          // this condition is for if the turn is of computer. if user input is invalid choice then user retry it again
         printf("\ncomputer turn:\n");

    switch(userChoice)                         // takes the input what user has entered it's last choice
    {
            /*
                       this overlapping function calls determines that it will not overlapp or overwrite the existing location.
                       if function call returns 1 it means no overlapping is there at that location  
                       and cases are  a set of all the possible conditions where the user or player 1 can win the game 
                       and computer as player 2 blocks all the such cases by inserting its symbol '0'
                       if there is no such condition matches it insert at empty position determined by empty_choice function
            */
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
                
        default:
                printf("invalid choice try again");
    }
    return 0;

}
int empty_choice(int arr[3][3])
{
    /*
        this function determines the empty location in 2D array in a consecutive manner
        it returns choice as a empty location if it is found
        otherwise it returns -1 which shows that 2D array is completely filled now
        
    */
    int i,j,choice;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]!=0 && arr[i][j]!=88)
            {
                choice = (i*3)+(j+1);         // this  expression convert that location index into the location number 
                return choice;

            }
        }
    }
    return -1;

}


void play_with_player()
{
    /*
        this function is for if 2 players or users wants to play together
    */
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
    showGame(arr);       // it displays the game
    printf("\n\n");
    while(1)
    {
     level_1:
        printf("player 1 - %s: Enter position Number -> ",first);
        scanf("%d",&choice);
        if(choice>9 || choice<1)
        {
             printf("\nInvalid choice\n\n");
             goto level_1;                      // if choice enetred by user is invalid then it ask that user again to enetr it
        }
        flag= position_insertion(arr,1,choice);
        if(flag==-1)
        {
             goto level_1;                      // if there is overlapping then it again ask that user to enter it again
        }

        if(flag==1)
            break;                            // this is the condition flag==1 where that user wins it and game ends.
        if(flag==0)                           // this condition flag==0  represents 2 stages either the game is drawn or game continues 
        {
            loc= empty_choice(arr);             // if there is no vacant space left in 2D array empty_choice function returns -1 and game is drawn and exit the game.
            if(loc==-1)                         // if it return another value than -1 it means game continues.
            {
                printf("\nGame drawn\n\n");
                break;
            }


        }
        printf("\n\n");
     level_2:
            printf("player 2 - %s Enter position Number-> ",second);             // same conditions for user 2 as well.
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
    /*
        this function is ment for if the user and computer wants to play together.
        here user is the player 1 and computer will be as player 2.
        player 1  as user symbol 'X'
        player 2  as computer symbol '0'
    */
    int i,flag,choice,arr[3][3]={1,2,3,4,5,6,7,8,9};
    char first[20];
    fflush(stdin);
    printf("\nPlayer 1 Name: ");
    gets(first);
    printf("\n\n\n");
    printf("%s  X\n\n",first);
    printf("Computer 0\n\n");
    showGame(arr);     // this function displays the game          
    while(1)
    {
        level_1:
         printf("\n\n");
         printf("player-1- %s Enter position Number-> ",first);
         scanf("%d",&choice);
        flag=position_insertion(arr,1,choice);           // to insert at desired position
        if(flag==-1)                                     // overlapping condition
         goto level_1;
        else if(flag==1)                                // winning condition
            break;
         else
        {
            i=check_winning_condition(arr,choice);            // computer turn  -> it checks the winning condition of user and blocks it by inserting its symbol over there.
            if(i==-1 || i==1)                                 //                   and also determine its winning senarios as well.
                break;                                        // it return -1 if game is drawn and end the game
        }                                                     // it returns 1 if computer wons it and end the game
    }                                                         // it returns 0 if invalid choice enetered by user. but that case is handled in function itself by displaying appropiate message to user
}                                                             // and loop continues and ask user again to enter it.

int evil_moves(int arr[3][3])
{ 
    /*
        these are the all possible cases where the user can win after the insertion of computer.
        by this computer blocks all the possible scenarios of winning the game by user.
        -> here arr[x][y]==88 ensures that it checks the symbol of user i.e 'X' only.
        */
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
    /*
            this function is for to play between user and evil computer . In this it do the cheating whenever the user is going to win it blocks all
            the possible scenarios and computer always win in this game.
            player symbol='X'
            computer symbol='0'
    */

    int i,flag,choice,arr[3][3]={1,2,3,4,5,6,7,8,9};
    char first[20];
    fflush(stdin);
    printf("\nPlayer 1 Name: ");
    gets(first);
    printf("\n\n\n");
    printf("%s  X\n\n",first);
    printf("Computer 0\n\n");
    showGame(arr);    // it displays the game
    while(1)
    {
        level_1:
         printf("\n\n");
         if(empty_choice(arr)==-1)          // checks the vacant spaces in 2D array are available or not
            {
                printf("\n\nGame drawn\n\n");
                break;
            }
          printf("player-1- %s Enter position Number-> ",first);
          scanf("%d",&choice);
        flag=position_insertion(arr,1,choice);       // inserts the symbol of user at desired location
        if(flag==-1)                                 // it represnts the overloading condition
         goto level_1;
        else if(flag==1)                             // it represents the winning scenario
            break;
         else
        {
            i=check_winning_condition(arr,choice);         // computer turn  -> it checks the winning condition of user and blocks it by inserting its symbol over there.
            if(i==-1 || i==1)                             //                     and also determine its winning senarios as well.
                break;                          //   it return -1 if game is drawn and end the game 
                                                //   it returns 1 if computer wons it and end the game
                                                //  it returns 0 if invalid choice enetered by user. but that case is handled in function itself by displaying appropiate message to user
                                                //  and loop continues and ask user again to enter it.
             
             i= evil_moves(arr);                // this function call determines possible all possible cases where user can win and blocks it there by inserting its symbol 0 there.         
             if(i==1)                                    
                break;                                   

        }

    }

}
int menu_driven()
{ /*
        menu driven program
        and return the choice eneterd by user 
  */
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
         switch(menu_driven())               // takes the choice as an input given by menu_driven function.
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

