typedef struct Train
{
    char train_no[10];
    char from[20];
    char to[20];
    int fac_fare ;
    int sac_fare;
    int tac_fare;
    int sle_fare;
    int gen_fare;
}Train ;

typedef struct Passenger
{
    char p_name[20];
    char gender;
    char mob_no[12];
    int age;
    char train_no[10];
    char p_class;
    int ticket_no;
}Passenger;

int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
void view_all_bookings();
void view_ticket(int);
void view_bookings(char *);
void view_last_ticket();
int cancel_ticket(int);
int cancel_train(char *);

int check_train_no(char *);
Passenger* get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char *);
