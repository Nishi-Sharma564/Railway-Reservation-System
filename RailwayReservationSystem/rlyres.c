#include<stdio.h>
#include<conio.h>
#include "rlyres.h"

int enterchoice()
{
    int choice,i;
    textcolor(14);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    printf("\n\nSelect an option\n1-View Trains\n2-Book Ticket\n3-View Ticket\n4-Search Ticket No\n5-View All Bookings\n6-View Train Bookings\n7-Cancel Ticket\n8-Cancel Train\n9-Quit");
    printf("\nEnter choice :");
    scanf("%d",&choice);
    return choice;
}

void add_trains()
{
    FILE *fp;
    fp = fopen("G:\\alltrains.dat","rb");
    if(fp==NULL){
        Train alltrain[4]={
            {
                "123","BPL","GWA",2100,1500,1000,800,150
            },
            {
                "546","BPL","DEL",2100,1500,1000,800,150
            },
            {
                "345","HBJ","AGR",2100,1500,1000,800,150
            },
            {
                "896","HBJ","MUM",2100,1500,1000,800,150
            }
        };
        fp = fopen("G:\\alltrains.dat","wb");
        fwrite(alltrain,4*sizeof(Train),1,fp);
        fclose(fp);
    }
    else{
        fclose(fp);
    }
}

void view_trains(){
    clrscr();
    int i;
    textcolor(14);
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\tTHIRD AC FARE\tSLEEPER FARE\tGENRAL CLASS FARE\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    FILE *fp=fopen("G:\\alltrains.dat","rb");
    Train data;
    while(fread(&data,sizeof(Train),1,fp))
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d",data.train_no,data.from,data.to,data.fac_fare,data.sac_fare,data.tac_fare,data.sle_fare,data.gen_fare);
    }
    fclose(fp);
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    clrscr();
}

int check_train_no(char * p)
{
    FILE *fp=fopen("G:\\alltrains.dat","rb");
    Train data;
    while(fread(&data,sizeof(data),1,fp)==1)
    {
        if(strcmp(data.train_no,p)== 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

Passenger* get_passenger_details()
{
    clrscr();
    gotoxy(100,1);
    textcolor(2);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(14);
    static Passenger p;
    printf("Enter passenger name:");
    fflush(stdin);
    fgets(p.p_name,20,stdin);
    char *a;
    a=strchr(p.p_name,'\n');
    *a = '\0';
    if(strcmp(p.p_name,"0")==0)
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    printf("Enter gender(M/F):");
    fflush(stdin);
    scanf("%c",&p.gender);
    if(p.gender=='0')
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    if(p.gender!='F'&& p.gender!='M')
    {
        gotoxy(1,50);
        textcolor(4);
        printf("ERROR ! GENDER CAN BE M OR F.");
        textcolor(14);
        getch();
        gotoxy(19,2);
        printf(" \b");
        fflush(stdin);
        scanf("%c",&p.gender);
        gotoxy(1,50);
        printf("\t\t\t\t\t");
        gotoxy(1,3);
    }
    printf("Enter mobile no:");
    mobno:
    fflush(stdin);
    fgets(p.mob_no,12,stdin);
    a=strchr(p.mob_no,'\n');
    if(a!=NULL)
        {
            *a = '\0';
        }
    if(strcmp(p.mob_no,"0")==0)
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    if(check_mob_no(&p.mob_no)==0)
    {
        gotoxy(1,50);
        textcolor(4);
        printf("ERROR ! INVALID MOBILE NO.");
        textcolor(14);
        getch();
        gotoxy(17,3);
        printf("\t\b");
        goto mobno;
        gotoxy(1,50);
        printf("\t\t\t\t\t");
        gotoxy(1,4);
    }

    printf("Enter age:");
    scanf("%d",&p.age);
    if(p.age==0)
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    if(p.age<0)
    {
        gotoxy(1,50);
        textcolor(4);
        printf("ERROR ! AGE CANNOT BE NEGETIVE.");
        textcolor(14);
        getch();
        gotoxy(11,4);
        printf("\t\b");
        scanf("%d",&p.age);
        gotoxy(1,50);
        printf("\t\t\t\t\t");
        gotoxy(1,5);
    }
    printf("Enter train no:");
    tno:
    fflush(stdin);
    fgets(p.train_no,10,stdin);
    a=strchr(p.train_no,'\n');
    *a = '\0';
    if(strcmp(p.train_no,"0")==0)
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    if(check_train_no(&p.train_no)==0)
    {
        gotoxy(1,50);
        textcolor(4);
        printf("ERROR ! INVALID TRAIN NO.");
        textcolor(14);
        getch();
        gotoxy(16,5);
        printf("       \b\b\b\b\b\b\b");
        goto tno;
        gotoxy(1,50);
        printf("\t\t\t\t\t");
        gotoxy(1,6);
    }

    printf("Enter class(F for first AC;S for second AC;T for third AC;L for sleeper class;G for general class):");
    clas:
    fflush(stdin);
    scanf("%c",&p.p_class);
    if(p.p_class=='0')
    {
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,50);
        textcolor(4);
        printf("RESERVATION CANCELLED!");
        textcolor(14);
        getch();
        return NULL;
    }
    if(p.p_class!='F'&& p.p_class!='S'&& p.p_class!='T'&& p.p_class!='L'&& p.p_class!='G')
    {
        gotoxy(1,50);
        textcolor(4);
        printf("ERROR ! classes are F for first AC;S for second AC;T for third AC;L for sleeper class;G for general class.");
        textcolor(14);
        getch();
        gotoxy(100,6);
        printf(" \b");
        fflush(stdin);
        goto clas;
        gotoxy(1,50);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,7);
    }
    p.ticket_no = 0;
    return &p;
}

int check_mob_no(char *p)
{
    if(strlen(p)!=10)
    {
        return 0;
    }
    while(*p!='\0'){
        if(isdigit(*p)==0)
        {
            return 0;
        }
        p++;
    }
    return 1;
}

int book_ticket(Passenger p)
{
    int count ;
    int tno = 0;
    count=get_booked_ticket_count(p.train_no ,p.p_class);
    if(count == 2)
    {
        return -1;
    }
    tno = last_ticket_no()+1;
    p.ticket_no = tno;
    FILE *fp;
    fp = fopen("G:\\ticket_booking.dat","ab");
    if(fp==NULL)
    {
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return tno;
}


int get_booked_ticket_count(char* ptno ,char pclas)
{
    int i=0;
    FILE *fp;
    fp = fopen("G:\\ticket_booking.dat","rb");
    if(fp==NULL){
       return 0;
    }
    Passenger t;
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(strcmp(t.train_no,ptno)==0 && pclas == t.p_class)
        {
            i++;
        }
    }
    fclose(fp);
    return i ;
}


int last_ticket_no()
{
    FILE *fp;
    fp = fopen("G:\\ticket_booking.dat","rb");
    if(fp==NULL){
       return 0;
    }
    Passenger t;
    fseek(fp,-1*sizeof(t),SEEK_END);
    fread(&t,sizeof(t),1,fp);
    fclose(fp);
    getch();
    return t.ticket_no ;

}

void view_all_bookings(){
    clrscr();
    FILE *fp;int i;
    fp = fopen("G:\\ticket_booking.dat","rb");
    Passenger t;
    textcolor(14);
    printf("PASSENGER NAME\t\tGENDER\tMOBILE NO\t\tAGE\tTRAIN NO\tTRAVELLING CLASS\tTICKET NO\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    while(fread(&t,sizeof(Passenger),1,fp)){
        printf("%s\t\t%c\t%s\t\t%d\t%s\t\t%c\t\t\t%d\n",t.p_name,t.gender,t.mob_no,t.age,t.train_no,t.p_class,t.ticket_no);
    }
    fclose(fp);
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    textcolor(14);
    clrscr();
}

void view_ticket(int tno)
{
    FILE *fp;int i;
    fp = fopen("G:\\ticket_booking.dat","rb");
    Passenger t;
    textcolor(14);
    printf("PASSENGER NAME\t\tGENDER\tMOBILE NO\t\tAGE\tTRAIN NO\tTRAVELLING CLASS\tTICKET NO\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    while(fread(&t,sizeof(Passenger),1,fp)){
        if(t.ticket_no==tno)
            printf("%s\t\t%c\t%s\t\t%d\t%s\t\t%c\t\t\t%d\n",t.p_name,t.gender,t.mob_no,t.age,t.train_no,t.p_class,t.ticket_no);
    }
    fclose(fp);
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    textcolor(14);
    clrscr();

}

void view_bookings(char *trno)
{
    FILE *fp;int i;
    fp = fopen("G:\\ticket_booking.dat","rb");
    Passenger t;
    textcolor(14);
    printf("PASSENGER NAME\t\tGENDER\tMOBILE NO\t\tAGE\tTRAIN NO\tTRAVELLING CLASS\tTICKET NO\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    while(fread(&t,sizeof(Passenger),1,fp)){
        if(strcmp(trno,t.train_no)==0)
            printf("%s\t\t%c\t%s\t\t%d\t%s\t\t%c\t\t\t%d\n",t.p_name,t.gender,t.mob_no,t.age,t.train_no,t.p_class,t.ticket_no);
    }
    fclose(fp);
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    textcolor(14);
    clrscr();

}
void view_last_ticket()
{
    clrscr();
    FILE *fp;int i;
    fp = fopen("G:\\ticket_booking.dat","rb");
    Passenger t;
    textcolor(14);
    printf("PASSENGER NAME\t\tGENDER\tMOBILE NO\t\tAGE\tTRAIN NO\tTRAVELLING CLASS\tTICKET NO\n");
    for(i=1;i<=116;i++){
        printf("-");
    }
    fseek(fp,-1*sizeof(t),SEEK_END);
    fread(&t,sizeof(t),1,fp);
    printf("%s\t\t%c\t%s\t\t%d\t%s\t\t%c\t\t\t%d\n",t.p_name,t.gender,t.mob_no,t.age,t.train_no,t.p_class,t.ticket_no);
    fclose(fp);
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    textcolor(14);
    clrscr();
}

int cancel_ticket(int tno)
{
    clrscr();
    FILE *fp ,*fp2;
    fp = fopen("G:\\ticket_booking.dat","rb");
    fp2 = fopen("G:\\ticket_booking2.dat","wb");
    Passenger t;
    textcolor(14);
     while(fread(&t,sizeof(Passenger),1,fp)){
        if(t.ticket_no==tno){}
        else
        {
            fwrite(&t,sizeof(t),1,fp2);
        }
    }
    fclose(fp);
    fclose(fp2);
    fp = fopen("G:\\ticket_booking.dat","wb");
    fp2 = fopen("G:\\ticket_booking2.dat","rb");
     while(fread(&t,sizeof(Passenger),1,fp2)){
            fwrite(&t,sizeof(t),1,fp);

    }
    fclose(fp);
    fclose(fp2);
    textcolor(14);
    printf("RESERVATION CANCELLED!!!!!");
    textcolor(15);
    printf("\n\n\n\n\n\nPress any key to main screen");
    getch();
    textcolor(14);
    clrscr();
}

int cancel_train(char *trno)
{
    clrscr();
    FILE *fp ,*fp2;
    fp = fopen("G:\\ticket_booking.dat","rb");
    if(fp==NULL){
        return 0;
    }
    fp2 = fopen("G:\\ticket_booking2.dat","wb");
    if(fp2==NULL){
        return 0;
    }
    Passenger t;
    textcolor(14);
     while(fread(&t,sizeof(t),1,fp)){
        if(strcmp(t.train_no,trno)==0){}
        else
        {
            fwrite(&t,sizeof(t),1,fp2);
        }
    }
    fclose(fp);
    fclose(fp2);
    fp = fopen("G:\\ticket_booking.dat","wb");
    if(fp==NULL){
        return 0;
    }
    fp2 = fopen("G:\\ticket_booking2.dat","rb");
    if(fp2==NULL){
        return 0;
    }
     while(fread(&t,sizeof(Passenger),1,fp2)){
            fwrite(&t,sizeof(t),1,fp);

    }
    fclose(fp);
    fclose(fp2);
    textcolor(14);
    return 1;
}
