#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"

int main()
{
    int choice;
    int tno;int i;
    char trno[10],trno2[10];
    Passenger *p;
    add_trains();
    while(1)
    {

        choice=enterchoice();
        if(choice==9){
            exit(0);
        }
        switch(choice)
        {
            case 1:
                view_trains();
                break;
            case 2:
                p = get_passenger_details();
                if(p!=NULL)
                {
                    tno = book_ticket(*p);
                    clrscr();
                    if(tno==-1){
                        textcolor(4);
                        printf("Sorry!Seat not available");
                    }
                    else
                    {
                        textcolor(2);
                        printf("Ticket successfully booked\nyour ticket no is %d ",tno);
                    }
                    textcolor(15);
                    printf("\nPress any key to continue");
                    textcolor(14);
                    getch();
                }

                clrscr();
                break;
            case 3:
                view_last_ticket();
                break;
            case 4:
                clrscr();
                printf("Enter ticket no:");
                scanf("%d",&tno);
                view_ticket(tno);
                break;
            case 5:
                view_all_bookings();
                break;
            case 6:
                clrscr();
                printf("Enter train no:");
                fflush(stdin);
                fgets(trno,10,stdin);
                int *a=strchr(trno,'\n');
                *a = '\0';
                view_bookings(&trno);
                break;
            case 7:
                clrscr();
                printf("Enter ticket no:");
                scanf("%d",&tno);
                cancel_ticket(tno);
                break;
            case 8:
                clrscr();
                printf("Enter train no:");
                fflush(stdin);
                fgets(trno2,10,stdin);
                int *b=strchr(trno2,'\n');
                *b = '\0';
                i=cancel_train(&trno2);
                if(i==1){
                    printf("TRAIN CANCELLED!!!!!");
                    textcolor(15);
                    printf("\n\n\n\n\n\nPress any key to main screen");
                    getch();
                    textcolor(14);
                    clrscr();
                }
                break;
            default:
                textcolor(4);
                printf("Wrong Choice! Try Again");
                getch();
                clrscr();
        }
    }
    return 0;
}
