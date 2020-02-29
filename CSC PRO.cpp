#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <ctype.h>
#include <cstring.h>

using namespace std;

void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void box(int a,int b,int c,int d)                 //The function that helps you make borders
{

	for(int i=a;i<c;i+=2)
	{
      textcolor(14);
   	gotoxy(i,b);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,d);cprintf("\xcd");
 	}
	for(int j=b;j<d;j+=2)
	{
     	gotoxy(a,j);cprintf("\xba");           // Vertical Lines
		gotoxy(c,j);cprintf("\xba");
   }
   textcolor(9);
   gotoxy(a,b);cprintf("\xc9");
	gotoxy(c,b);cprintf("\xbb");
	gotoxy(a,d);cprintf("\xc8");
	gotoxy(c,d);cprintf("\xbc");
}

void box1(int a,int b,int c,int d)                 //The function that helps you make borders
{

	for(int i=a;i<c;i++)
	{
      if(i%2==0)
      	textcolor(14);
      else
      	textcolor(13);
   	gotoxy(i,b);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,d);cprintf("\xcd");
 	}
	for(int j=b;j<d;j++)
	{
   	if(j%2==0)
      	textcolor(14);
      else
      	textcolor(13);
     	gotoxy(a,j);cprintf("\xba");           // Vertical Lines
		gotoxy(c,j);cprintf("\xba");
   }
   textcolor(9);
   gotoxy(a,b);cprintf("\xc9");
	gotoxy(c,b);cprintf("\xbb");
	gotoxy(a,d);cprintf("\xc8");
	gotoxy(c,d);cprintf("\xbc");
}

int flag=0;                                  //A counter to check whether you
                                             //are logged into the FlyHigh server

void user();                    //Displays the menu for user
void menu();                    //Displays the main menu for customer
void check_name(char *,int);    //Checks for the length and validity of Name
void check_phone(char *,int);   //Checks for the length and validity of Phone Number
int pnsign();
int snsign();

int pc;                         //Passenger code used in functions

class Aircraft
{
	char ac[15];
   char splace[10], dplace[10];
   char at[9], dt[9];
   float exp;
   int Seatw;
   int Seatc;
   char fno[6];
	public:
   	Aircraft()
      {
      	strcpy(fno, "NIL");
      	strcpy(ac, "NIL");
         strcpy(splace, "NIL");
         strcpy(dplace, "NIL");
         exp=Seatw=Seatc=0;
         strcpy(at,"NIL");
         strcpy(at,"NIL");
      }
   	void AIndata();
      void AOutput(int,int);
      void AOutput1(int,int);
      void AInfo(int, int);
      void SAupdate(char);
      void SAdec(char);
      float retexp();
      void flymod();
      void seatres(int v);
      int retsplace(char []);
      int retdplace(char []);
      char* retfno()
      {  return fno; }
      int retsvail()
      {
      	if ((Seatw+Seatc)<250)
         	return 0;
         else
      	{
         	cout<<"Sorry flight full";
            return 1;
         }
      }
      void printexp(int r);
};

void Aircraft::AIndata()
{
   gotoxy(4,5);
   setcolor(4);
	cout<<"Enter aircraft name\n";
   gotoxy(4,6);
   setcolor(13);
   gets(ac);
   gotoxy(4,7);
   setcolor(4);
	cout<<"Enter flight number\n";
   gotoxy(4,8);
   setcolor(13);
   cin>>fno;
   gotoxy(4,9);
   setcolor(4);
   gotoxy(4,10);
   setcolor(4);
   cout<<"Enter starting place\n";
   gotoxy(4,11);
   setcolor(13);
   gets(splace);
   gotoxy(4,12);
   setcolor(4);
   cout<<"Enter destination\n";
   gotoxy(4,13);
   setcolor(13);
   gets(dplace);
   gotoxy(4,14);
   setcolor(4);
   cout<<"Enter departure time\n";
   gotoxy(4,15);
   setcolor(13);
   cin>>dt;
   gotoxy(4,16);
   setcolor(4);
   cout<<"Enter arrival time\n";
   gotoxy(4,17);
   setcolor(13);
   cin>>at;
   gotoxy(4,18);
   setcolor(4);
   cout<<"Enter expense per adult\n";
   gotoxy(4,19);
   setcolor(13);
   cin>>exp;
}

void Aircraft::seatres(int v)
{
   setcolor(10);
   gotoxy(v,6);
   cout<<"No. of seats in flight=250";
   gotoxy(v,8);
   cout<<"No. of seats reserved="<<Seatw ;
   gotoxy(v,9);
   cout<<"No. of seats confirmed="<<Seatc;
   gotoxy(v,11);
   cout<<"No. of seats available="<<(250-Seatw-Seatc);
}

int Aircraft::retsplace(char a[])
{
	if(!strcmpi(splace,a))
   return 1;
   else return 0;
}

int Aircraft::retdplace(char a[])
{
	if(!strcmpi(dplace,a))
   	return 1;
   else return 0;
}

void Aircraft::SAupdate(char c)
{
	if((Seatw+Seatc)<250)
   	if(toupper(c)=='W')
      	Seatw++;
      else if (toupper(c)=='C')
			Seatc++;
}

void Aircraft::SAdec(char c)
{
	if(toupper(c)=='W')
      	Seatw--;
      else if (toupper(c)=='C')
			Seatc--;
}

float Aircraft::retexp()
{
	return exp;
}

void Aircraft::flymod()
{
   gotoxy(4,6);
   setcolor(4);
   cout<<"Enter new place of departure";
   gotoxy(4,7);
   setcolor(13);
   cin>>splace;
   gotoxy(4,9);
   setcolor(4);
   cout<<"Enter new place of arrival";
   gotoxy(4,10);
   setcolor(13);
   cin>>dplace;
   gotoxy(4,12);
   setcolor(4);
   cout<<"Enter new departure time";
   gotoxy(4,13);
   setcolor(13);
   cin>>dt;
   gotoxy(4,15);
   setcolor(4);
   cout<<"Enter arrival time";
   gotoxy(4,16);
   setcolor(13);
   cin>>at;
   gotoxy(4,18);
   setcolor(4);
   cout<<"Fields Updated!";
}

void Aircraft::AInfo(int x, int y)
{
   gotoxy(x,y);
   printf ("%6.2f  ",exp);
  	printf ("%i ",Seatw);
   printf ("%i",Seatc);
}

void Aircraft::AOutput(int x, int y)
{
	gotoxy(x,y);
   printf ("%-9s ",ac);
  	printf ("%-5s ",fno);
   printf ("%-9s  ",splace);
   printf ("%-9s ",dplace);
   printf ("%-8s ",dt);
   printf ("%-8s ",at);
}

void Aircraft::AOutput1(int x, int y)
{
	gotoxy(x,y);
   printf ("%-9s ",ac);
  	printf ("%-5s ",fno);
   printf ("%-9s  ",splace);
   printf ("%-9s ",dplace);
}

void Aircraft::printexp(int r)
{
   gotoxy(58,r);
   printf ("%-6.2f ",exp);
}

class Passenger
{
	char pass[10];
	char fnop[6];
   int pnr;
   int seatno;
   char pname[15];
   int age;
   char depdate[9];
   char sex;
   char ph[10];
   char email[20];
   char stat;
   float pay;
      public:
   	Passenger()
      {
         strcpy(pass, "NIL");
         strcpy(fnop, "NIL");
         seatno=0;
         strcpy(depdate, "NIL");
         strcpy(email, "NIL");
         pnr=sex=stat=pay=0;
         strcpy(ph,"0000");
      }
      char retstat()
      {
      	return stat;
      }
   	void PIndata();
      void PFData();
      void POutput(int);
      void PfOutput(int);
      void PInfo(int);
      int retage();
      char* retpass();
      int retpnr();
      char retres();
      void assignsno(int c)
      {
      	seatno=c;
      }
      int retsno()
      {
      	return seatno;
      }
      void cantick(char []);
      float paycalc(float);
      char* retfn()
      { return fnop;}
      void assignpnr(int p);
};

char* Passenger::retpass()
{
	return pass;
}

void Passenger::assignpnr(int p)
{
	pnr=p;
}

void Passenger::PIndata()
{
   assignpnr(pnsign());
   gotoxy(4,5);
   cout<<"Enter Passenger's name";
   gotoxy(4,6);
   check_name(pname,14);
   gotoxy(4,7);
   cout<<"Enter sex: M-Male, F-Female\n";
   gotoxy(4,8);
   cin>>sex;
   gotoxy(4,9);
   cout<<"Enter age\n";
   gotoxy(4,10);
   cin>>age;
   gotoxy(4,11);
   cout<<"Enter phone number\n";
   gotoxy(4,12);
   check_phone(ph, 9);
   gotoxy(4,13);
   cout<<"Enter email address\n";
   gotoxy(4,14);
   cin>>email;
   gotoxy(4,15);
   cout<<"Enter password\n";
   pass:
   ;
   char a[10]="\0";
   gotoxy(4,16);
   int i=0;
   while(i<10)
   {
   	a[i]=getch();
      if(a[i]=='\b')
      {
      	cout<<"\b \b";
         i-=2;
      }
      else if (a[i]!=13)
      {
      	cout<<"*";
         ++i;
      }
      else
      	break;
   }
   a[i]='\0';
   gotoxy(4,17);
   cout<<"Confirm password\n";
   gotoxy(4,18);
   char pas[10]="\0";
   i=0;
   while(i<10)
   {
   	pas[i]=getch();
      if(pas[i]=='\b')
      {
      	cout<<"\b \b";
         i--;
      }
      else if (pas[i]!=13)
      {
        	cout<<"*";
         ++i;
      }
      	else
      		break;
   }
   pas[i]='\0';
   gotoxy(4,19);
   if (!strcmp(pas,a))
   {
   	cout<<"Password Matched";
      strcpy(pass, pas);
      gotoxy(4,20);
      printf("Please note your pnr code - ");
      printf("%5i",pnr);
      gotoxy(4,21);
      setcolor(15);
      printf("Press any key to continue");
      getch();
    }
   else
   {
     	cout<<"Password does not match! Press enter to try again";
      getch();
      for (int k=17; k<22;k++)
      {
         gotoxy(4,k);
         printf("                                                            ");
      }
    	goto pass;
   }
}

void Passenger::PFData()                 //To help in booking A FLIGHT
{
   gotoxy(4,8);
   setcolor(4);
	cout<<"Enter flight number\n";
   gotoxy(4,9);
   setcolor(8);
   cin>>fnop;
   gotoxy(4,10);
   setcolor(4);
   cout<<"Enter Date of Departure\n";
   gotoxy(4,11);
   setcolor(8);
   cin>>depdate;
   gotoxy(4,12);
   setcolor(4);
   cout<<"Status:Waiting or Confirmed?";
   gotoxy(4,13);
   setcolor(8);
   cin>>stat;
}

int Passenger::retage()
{
	return age;
}

int Passenger::retpnr()
{
	return pnr;
}

void Passenger::cantick(char a[])
{
   strcpy(fnop,a);
}

char Passenger::retres()
{
	return stat;
}

void Passenger::POutput(int r)
{
   gotoxy (3,r);
   printf ("%5i ",pnr);
   printf ("%-10s ",pname);
}

void Passenger::PfOutput(int r)
{
   gotoxy(52,r);
   printf ("%-8s ",depdate);
	printf ("%1c   ",stat);
   printf ("%3i ",seatno);
}

void Passenger::PInfo(int r)
{
	gotoxy(4,r);
   printf ("%5i ",pnr);
   printf ("%-10s ",pname);
   printf ("%c ",sex);
   printf ("%3i ",age);
   printf ("%8i ",ph);
   printf ("%-20s ",email);
}

float Passenger::paycalc(float a)
{
	if (age<=4)
   	pay=0.75*a;
   else
   	pay=a;
   return a;
}

//Non-Member functions

void home()   						//First page of the Airline Reservation System
{
   clrscr();
	box(2,2,79,24);
  	gotoxy(4,3);
   setcolor(10);
  	printf("          Welcome to FlyHigh - India's finest travel company");
   gotoxy(4,4);
  	printf("       Join over 10 million happy travellers to book economical");
  	gotoxy(4,5);
   printf("    flights and plan the most memorable holidays in India and abroad");
	for (int y=6; y<=30; y++)
	{
   	setcolor(15);
      gotoxy(y,7);
   	printf("               _  _                           ");
      gotoxy(y,8);
		printf("             -=\\ \\                          ");
      gotoxy(y,9);
		printf("         |\\ ____\\_\\_______                 ");
      gotoxy(y,10);
		printf("       -=\\c`\F\L\Y\H\I\G\H\"`)               ");
      gotoxy(y,11);
		printf("          `~~~~~/ /~~`\                       ");
      gotoxy(y,12);
		printf("            -==/ /                            ");
      gotoxy(y,13);
		printf("              '-'                             ");
      gotoxy(15,14);
      setcolor(11);
		printf("              _  _                                    ");
      gotoxy(15,15);
      printf("            ( `   )_                                  ");
      gotoxy(15,16);
      printf("           (    )    `)                               ");
      gotoxy(15,17);
		printf("         (_   (_ .  _) _)                             ");
		gotoxy(15,18);
      printf("                                        _             ");
		gotoxy(15,19);
      printf("                                       (  )           ");
		gotoxy(15,20);
      printf("        _ .                         ( `  ) . )        ");
		gotoxy(15,21);
      printf("      (  _ )_                      (_, _(  ,_)_)      ");
		gotoxy(15,22);
      printf("    (_  _(_ ,)                                        ");
      gotoxy(3,23);
      setcolor(10);
   	printf("----------------------- ");
      setcolor(9);
      printf("Don't just fly, FlyHigh ");
      textcolor(12);
      cprintf("\xAF\xAF ");
      setcolor(10);
      printf("-----------------------");
      for (int k=7; k<=13;k++)
      {
      	gotoxy(y,k);
         cout<<"                              ";
      }
      for (int i=0; i<99995145; i++);
   }
   getch();
}

void password9(char pas[])      			//Returns the password typed
{
   box(2,2,79,24);
   int i=0;
   gotoxy(4,10);
   while(i<10)
   {
   	pas[i]=getch();
      if(pas[i]=='\b')
      {
      	cout<<"\b \b";
         i--;
      }
      else if (pas[i]!=13)
      	cout<<"*";
      else
      	break;
      ++i;
   }
   pas[i]='\0';
}

//Functions for user purpose

void addflight()               //To add more flights to the system
{
   clrscr();
   box(2,2,79,24);
	Aircraft a;
   ofstream fout("flight.dat", ios::binary|ios::app);
   int n;
   gotoxy(4,3);
   cout<<"Enter number of flights\n";
   gotoxy(4,4);
   cin>>n;
   for (int i=0; i<n; i++)
   {
   	a.AIndata();
      fout.write((char*)&a, sizeof(a));
      clrscr();
      box(2,2,79,24);
   }
   fout.close();
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void modify()                   //To Modify flight info based on flightnumber
{
   clrscr();
   box(2,2,79,24);
   Aircraft a;
   gotoxy(4,6);
   char f[6];
   cout<<"Enter flight number whose details are to be modified";
   gotoxy(4,7);
   gets(f);
   clrscr();
   box(2,2,79,24);
	fstream file("flight.dat", ios::binary|ios::in|ios::out);
   while (file.read((char*)&a, sizeof(a)))
      if(!strcmpi(a.retfno(),f))
        {
        		a. flymod();
            file.seekp(-sizeof(a),ios::cur);
            file.write((char*)&a, sizeof(a));
            break;
        }
   file.close();
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void del()                          //To delete a particular flight
{
   clrscr();
   box(2,2,79,24);
	Aircraft a;
   int v=0;                         //counter to check presence of flight number
   char ito[6];
   gotoxy(4,6);
   cout<<"Enter flight number to be deleted\n";
   gotoxy(4,7);
   cin>>ito;
   ifstream fin("flight.dat", ios::binary);
   ofstream fout("temp.dat", ios::binary);
   while (fin.read((char*)&a,sizeof(a)))
   	if(strcmpi(a.retfno(),ito))
      {	fout.write((char*)&a,sizeof(a));
         v=1;
      }
   fin.close();
   fout.close();
   remove("flight.dat");
   rename("temp.dat", "flight.dat");
   gotoxy(4,9);
   if (v==0)
   	cout<<"Error-Search unsuccessful";
   else
   	cout<<"Flight Deleted";
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue";
   getch();
}

void fdisp()                     //To display all the flights in the system
{
   clrscr();
   box(2,2,79,24);
	Aircraft A;
   int c=6;
   ifstream fin("flight.dat",ios::binary);
   setcolor(9);
   for(int i=3;i<77;i++)
	{
   	gotoxy(i,3);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,5);cprintf("\xcd");
   }
   setcolor(12);
   gotoxy(4,4);
   printf ("Aircraft  Fno   From       To        Deptime  Arrtime Exp       W C");
 	while (fin.read((char*)&A,sizeof(A)))
   {
   	A.AOutput(4,c);
      A.AInfo(58,c++);
   }
   fin.close();
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void user()                         //Menu Function for user purpose
{
	int ch;
   start:
   do
   {
   	clrscr();
   	box(2,2,79,24);
   	gotoxy(6,5);
   	printf("What would you like to do? Choose from the following options:");
   	gotoxy(6,6);
   	printf("1. Add more flights");
   	gotoxy(6,7);
   	printf("2. Modify flight info");
   	gotoxy(6,8);
   	printf("3. Delete Flight");
   	gotoxy(6,9);
   	printf("4. Display flight information");
   	gotoxy(6,10);
   	printf("5. Go to customer menu");
   	gotoxy(6,11);
   	printf("6. Logout");
   	gotoxy(6,12);
   	cin>>ch;
   	switch(ch)
      {
      	 case 1: addflight();
         	      break;
          case 2: modify();
                  break;
          case 3: del();
          			break;
          case 4: fdisp();
                  break;
          case 5: menu();
                  break;
          case 6: gotoxy(6,13);
          			printf("Thanks for using FlyHigh!");
                  getch();
          			exit(0);
          default: goto start;
      }
   } while(ch<10);
}

//Functions for FlyHigh Customers

int pnsign()                       //Function to assign pnr code to Passenger
{
   int p;
	randomize();
   changepnr:
   p=rand();
   Passenger A;
   ifstream fin("passenger.dat",ios::binary);
   while (fin.read((char*)&A,sizeof(A)))
   {
   	if (A.retpnr()==p || p==22519)
      	goto changepnr;
   }
   fin.close();
   return p;
}

int snsign()
{
	int p;
	randomize();
   changesno:
   p=random(250);
   Passenger A;
   ifstream fin("passenger.dat",ios::binary);
   while (fin.read((char*)&A,sizeof(A)))
   {
   	if (A.retsno()==p)
      	goto changesno;
   }
   fin.close();
   return p;
}

void reg()                          //New Registration
{
   clrscr();
   box(2,2,79,24);
	Passenger a;

   int n;
   gotoxy(4,3);
   cout<<"Enter number of passengers\n";
   gotoxy(4,4);
   cin>>n;

   for (int i=0; i<n; i++)
   {
      a.PIndata();
      ofstream fout("passenger.dat", ios::binary|ios::app);
      fout.write((char*)&a, sizeof(a));
      clrscr();
   	box(2,2,79,24);
      fout.close();
   }
}

void login()                            //Login
{
   clrscr();
   box(2,2,79,24);
   Passenger a;
   char p[10];
   int pco;
   gotoxy(4,6);
   setcolor(6);
   printf("Enter PNR code");
   gotoxy(4,7);
   cin>>pco;
   gotoxy(4,9);
   cout<<"Enter password";
   password9(p);
   gotoxy(4,12);
   ifstream fin("passenger.dat", ios::binary);
   while (fin.read((char*)&a, sizeof(a)))
     	if(!strcmp(a.retpass(),p) && a.retpnr()==pco)
        	{  flag=1;
         	pc=pco;
         	cout<<"Login Successful\n";
            break;
        	}
	if(!flag)
  		if(!strcmp(p,"VAM519") && pco==22519)
      {
         printf("This system welcomes the user");
         flag=1;
         getch();
         user();
      }
   	else
   		cout<<"Password does not match";
   fin.close();
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void book()                                  //To Book flights
{
   clrscr();
   box(2,2,79,24);
	char sp[10],dp[10];
   Aircraft A;
   Passenger P;
   int n;
   int c=8;
   char fno[6];
   gotoxy(4,5);
    setcolor(9);
   for(int i=3;i<79;i++)
	{
   	gotoxy(i,5);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,7);cprintf("\xcd");
   }
   setcolor(12);
   gotoxy(4,6);
   printf ("Aircraft    Fno  From      To        Deptime  Arrtime ");
   fstream fin("flight.dat",ios::binary|ios::in|ios::out);
   while (fin.read((char*)&A, sizeof(A)))
   		A.AOutput(4,c++);
   fin.close();
   gotoxy(4,22);
   setcolor(15);
   cout<<"Press any key to continue";
   getch();
   clrscr();
   box(2,2,79,24);
   gotoxy(4,6);
   cout<<"Enter Passenger Registration number\n";
   gotoxy(4,7);
   cin>>n;
   char y[6];
   char res;
   fstream file("passenger.dat", ios::binary|ios::in|ios::out);
   while(file.read((char*)&P,sizeof(P)))
    	if(P.retpnr()==n)
      {
   		P.PFData();
         strcpy(y,P.retfn());
         gotoxy(4,14);
         P.assignsno(snsign());
         res=P.retres();
         file.seekp(-sizeof(P), ios::cur);
      	file.write((char*)&P, sizeof(P));
         break;
   	}
   fstream fin2("flight.dat",ios::binary|ios::in|ios::out);
   gotoxy(4,15);
   while (fin2.read((char*)&A, sizeof(A)))
   {
   	if(!strcmpi(A.retfno(),y))
   	{	A.SAupdate(res);
         int k= A.retsvail();
         if(k==0)
         {
         	fin2.seekp(-sizeof(A),ios::cur);
            fin2.write((char*)&A,sizeof(A));
         	cout<<"Your ticket has been booked";
         }
         else
         	cout<<"Please BOOK another flight";
         break;
      }
   }
   fin2.close();
   file.close();
   gotoxy(4,23);
   setcolor(15);
  	cout<<"Press any key to continue\n";
   getch();
}

void enq()                                  //Enquiry
{
   char f[6];
   clrscr();
   box(2,2,79,24);
   Aircraft A;
   gotoxy(4,6);
   cout<<"Enter flight number\n";
   gotoxy(4,7);
   cin>>f;
   clrscr();
   box(2,2,79,24);
   ifstream fin("flight.dat", ios::binary);
   while (fin.read((char*)&A, sizeof(A)))
   	if (!strcmpi(A.retfno(),f))
   		A.AOutput(4,8);
   gotoxy(4,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void pay()                                    //Payment information
{
   clrscr();
   box(2,2,79,24);
	Passenger P;
   gotoxy(4,6);
   Aircraft A;
   cout<<"Payment for the given passenger is Rs.";
   ifstream file1("passenger.dat",ios::binary);
  	ifstream file2("flight.dat",ios::binary);
   while (file1.read((char*)&P,sizeof(P)))
   	if(P.retpnr()==pc)
      {
          while (file2.read((char*)&A,sizeof(A)))
          if(!strcmpi(P.retfn(),A.retfno()))
          {  cout<<P.paycalc(A.retexp());
          	 break;
          }
      	break;
	   }
   gotoxy(4,23);
   setcolor(15);
   file1.close();
   file2.close();
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void cancel()                                 //Cancellation of Ticket
{
   clrscr();
   box(2,2,79,24);
   Passenger a;
   Aircraft P;
   gotoxy(4,6);
   int b;
	cout<<"Enter PNR number\n";
   gotoxy(4,7);
   cin>>b;
   gotoxy(4,8);
   fstream file("passenger.dat", ios::binary|ios::in|ios::out);
   fstream file2("flight.dat", ios::binary|ios::in|ios::out);
   while (file.read((char*)&a, sizeof(a)))
   	if (b==a.retpnr())
       while (file2.read((char*)&P, sizeof(P)))
         {
         P.SAdec(a.retstat());
         file2.seekp(-sizeof(P), ios::cur);
         file2.write((char*)&P, sizeof(P));

         a.cantick("NIL");
      	file.seekp(-sizeof(a), ios::cur);
         file.write((char*)&a, sizeof(a));
         }
   file.close();
   file2.close();
   gotoxy(4,21);
   cout<<"Ticket has been cancelled\n";
   gotoxy(4,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void display()                               //Passenger related Information
{
   clrscr();
   box(2,2,79,24);
   int ch,flag;
   Aircraft a;
   int pn;

   ifstream fin1("passenger.dat", ios::binary);
   Passenger p;
   gotoxy(4,6);
   cout<<"What do you want to do?";
   gotoxy(4,7);
   cout<<"Press 1 to check your profile only\n";
   gotoxy(4,8);
   cout<<"Press 2 for details of all members\n";
   gotoxy(4,9);
   cin>>ch;
   clrscr();
   box(2,2,79,24);
   gotoxy(4,5);
   int r=6;

              int k=0;
   switch(ch)
   {
		case 2: printf("PNR   Pass Name  Sex Age Phone   Email              ");
      	     gotoxy(4,6);
              while (fin1.read((char*)&p, sizeof(p)))
              		p.PInfo(r++);
              break;
      case 1: cout<<"Enter pnr code\n";
              gotoxy(4,7);
              cin>>pn;
              flag=0;
              clrscr();
              box(2,2,79,24);
              gotoxy(4,4);
              setcolor(7);
      		  printf("PNR  Pass Name Aircraft  FNo   From       To    DepDate  Res SNO");
      	     gotoxy(3,5);
              setcolor(9);
              while(fin1.read((char*)&p,sizeof(p)))
              {
              		ifstream fin2("flight.dat",ios::binary);
               	if (p.retpnr()==pn)
                       	while(fin2.read((char*)&a, sizeof(a)))
                        	if(strcmpi(p.retfn(),a.retfno())==0 )
                        	{
                              p.POutput(r);
                  				a.AOutput1(19,r);
                              p.PfOutput(r++);
                              k=1;
                        		flag=1;
                  				break;
              					}
               	fin2.close();
              if (k==0)
               	if(p.retpnr()==pn)
                     {		p.POutput(r++);
                        	printf("NIL     NIL    NIL        NIL   NIL      NIL NIL");
                        	flag=1;
                           break;
                     }
              }
              if (flag==0)
                  	cout<<"Sorry code unavailable\n";
              break;
     default: cout<<"Sorry Wrong Choice";
   }
   fin1.close();
   gotoxy(4,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void fres()                                  //Check Flight Reservations
{
   clrscr();
   box(2,2,79,24);
   Aircraft a;
   gotoxy(4,6);
   char f[6];
   cout<<"Enter flight to be searched\n";
   gotoxy(4,7);
   cin>>f;
   int v=6;
   clrscr();
	box(2,2,79,24);
   ifstream fin("flight.dat",ios::binary);
   while(fin.read((char*)&a,sizeof(a)))
   {
    		if (!strcmpi(f,a.retfno()))
   		a.seatres(v++);
   }
   fin.close();
   gotoxy(4,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void info()                                //Flight related info
{
   clrscr();
   box(2,2,79,24);
	Aircraft a;
   int x=5;
   gotoxy(4,5);
   printf("Aircraft   FNO   Splace   Dplace   Deptime  Arrtime  Expenses");
   ifstream fin("flight.dat", ios::binary);
   while(fin.read((char*)&a, sizeof(a)))
   {
   	a.AOutput(4,x);
      a.printexp(x++);
   }
   fin.close();
   gotoxy(4,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void faqs()                    			//Frequently Asked Questions
{
   clrscr();
   box(2,2,79,24);
   gotoxy(4,3);
   setcolor(12);
   printf("Can I use travel vouchers, certificates or frequent flyer miles to ");
   gotoxy(4,4);
   printf("purchase through FlyHigh?");
   gotoxy(4,5);
   setcolor(15);
   printf("You will need to contact the airlines directly to purchase your ticket.");
   gotoxy(4,7);
   setcolor(12);
   printf("How do I know my reservation is confirmed?");
   gotoxy(4,8);
   setcolor(15);
   printf("After your reservation, an immediate e-mail will be sent including");
   gotoxy(4,9);
   printf("your itinerary details and ticket price. Or check Passenger Info.");
   gotoxy(4,11);
   setcolor(12);
   printf("I saw a lower airfare advertised today. Why can't I get that airfare");
   gotoxy(4,12);
   printf("using FlyHigh?");
   gotoxy(4,13);
   setcolor(15);
   printf("Most discounted fares carry certain travel restrictions when pricing your");
   gotoxy(4,14);
   printf("itinerary. The advertisement should outline these restrictions.");
   gotoxy(4,16);
   setcolor(12);
   printf("Do you offer Infant, Child and Companion fares?");
   gotoxy(4,17);
   setcolor(15);
   printf("Children upto age of 4 years have 25 percent less fare. Senior and");
   gotoxy(4,18);
   printf("companion fares would be added as a product enhancement soon.");
   gotoxy(4,20);
   setcolor(12);
   printf("What if I need to change my flight arrangements?");
   gotoxy(4,21);
   setcolor(15);
   printf("To change your flight arrangements at any time, please email or call us.");
   gotoxy(4,23);
   setcolor(14);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void fabout()                                         //About FlyHigh Travels
{
   clrscr();
   box(2,2,79,24);
   gotoxy(5,4);
   setcolor(2);
   printf("Nurtured from the seed of a single great idea-to empower the traveller,");
   gotoxy(5,5);
   setcolor(3);
   printf("FlyHigh went on to bring together the airline industry in India.");
   gotoxy(5,6);
   setcolor(4);
   printf("This is the story of FlyHigh, India's Finest Travel Company. Created");
   gotoxy(5,7);
   setcolor(2);
   printf("to empower the Indian traveller with instant booking and comprehensive");
   gotoxy(5,8);
   setcolor(3);
   printf("choices, the company aims to offer a range of best-value products and");
   gotoxy(5,9);
  	setcolor(4);
   printf("services along with cutting-edge technology and dedicated round-the-");
   gotoxy(5,10);
   setcolor(2);
   printf("clock customer support. Remaining reliable, efficient and at the");
   gotoxy(5,11);
   setcolor(3);
   printf("forefront of technology, FlyHigh's commitment and customer-");
   gotoxy(5,12);
   setcolor(4);
   printf("centricity allows it to better understand and provide for its");
   gotoxy(5,13);
   setcolor(2);
   printf("customers' diverse needs and wants, and deliver consistently. With");
   gotoxy(5,14);
   setcolor(3);
   printf("dedicated 24x7 customer support and offices in 40 cities across India");
   gotoxy(5,15);
   setcolor(4);
   printf("and 4 international offices in Kuwait, UAE, Paris and New York (in");
   setcolor(2);
   gotoxy(5,16);
   printf("addition to several franchise locations), FlyHigh is there for you,");
   setcolor(3);
   gotoxy(5,17);
   setcolor(4);
   printf("whenever and wherever.");
   gotoxy(25,18);
   setcolor(14);
   printf("Don 't Just Fly, FlyHigh!");
   textcolor(12);
   cprintf("\xAF\xAF ");
   gotoxy(5,19);
   setcolor(2);
   printf("You are welcome to write to the Management with feedback ");
   gotoxy(5,20);
   setcolor(3);
   printf("about our services by signing in to ourMy Complaints section.");
   gotoxy(5,22);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void contact()                                 //Displays FlyHigh Contact Info
{
	clrscr();
   box(2,2,79,24);
   gotoxy(35,4);
   setcolor(11);
   cout<<"CONTACT US";
   setcolor(9);
   for(int i=3;i<79;i++)
	{
   	gotoxy(i,3);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,5);cprintf("\xcd");
   }
   gotoxy(8,7);
   setcolor(15);
   cout<<"Head Office: Mumbai";
   gotoxy(8,8);
   setcolor(6);
   cout<<"FlyHigh Pvt. Ltd.";
   gotoxy(8,8);
   cout<<"Tower C, Phoenix City";
   gotoxy(8,9);
   cout<<"Opp. KFC, Linking Road";
   gotoxy(8,10);
   cout<<"Bandra West-400050";
   gotoxy(8,11);
   cout<<"Mumbai, Maharashtra, India";
   gotoxy(42,7);
   setcolor(15);
   cout<<"Toll Free ";
   gotoxy(42,8);
   setcolor(6);
   cout<<"1-800-121-121";
   gotoxy(42,9);
   setcolor(15);
   cout<<"email: ";
   gotoxy(42,10);
   setcolor(6);
   cout<<"flyhigh_121@gmail.com";
   gotoxy(42,11);
   setcolor(15);
   cout<<"Web:";
   setcolor(6);
   cout<<"www.flyhigh_121.com";
   gotoxy(7, 14);
   setcolor(4);
   cout<<"Retail Offices - You can walk in to any of our retail offices";
   gotoxy(7,15);
   cout<<"which are present in more than 20 major cities in india, and";
   gotoxy(7,16);
   cout<<"our travel specialists will help you with your holiday and";
   gotoxy(7,17);
   cout<<"travel needs. Email us to know more about these offices.";
   gotoxy(4,20);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
   menu();
}

void sabout()                                 //About the program
{
	clrscr();
   box1(2,2,79,24);
   box1(15,4,65,6);
   box1(15,7,65,22);
   textcolor(13);
   for(int j=5;j<23;j+=2)
	{
     	gotoxy(5,j);
      cprintf("\xB0");           // Vertical Lines
      gotoxy(76,j);
      cprintf("\xB0");
	}
	gotoxy(31,5);
	setcolor(10);
	printf("   About The Program   ");
   gotoxy (39,7);
	setcolor (10);
	printf ("Made By");
	gotoxy (30,9);
	setcolor(11);
	printf ("Vritika Vijaylal Naik");
	gotoxy (31,11);
	setcolor(10);
	printf ("Under the guidance of");
	gotoxy (34,12);
	setcolor(11);
	printf ("Mr George Swamy");
	gotoxy (37,14);
	setcolor(10);
	printf ("Project");
	gotoxy (26,15);
	setcolor(11);
	printf ("Airline Reservation System V.1.0");
	gotoxy (31,17);
	setcolor(10);
	printf ("Contact Information");
	gotoxy (31,18);
	setcolor(11);
	printf("vritikan@gmail.com");
	gotoxy (24,21);
	setcolor(7);
	printf("THE INDIAN COMMUNITY SCHOOL, KUWAIT");
   gotoxy(28,23);
   setcolor(15);
   cout<<"Press any key to continue\n";
   getch();
}

void feedback()                              //Feedback
{
   clrscr();
   box(2,2,79,24);
   int ch;
   char sug[25];
   gotoxy(4,4);
   setcolor(9);
	printf("How would you like to rate our service?");
   gotoxy(4,5);
   setcolor(11);
   printf("1-Pathetic");
   gotoxy(4,6);
   printf("2-Average");
   gotoxy(4,7);
   printf("3-Good");
   gotoxy(4,8);
   printf("4-Very Good");
   gotoxy(4,9);
   printf("5-Excellent");
   gotoxy(4,10);
   setcolor(15);
   cin>>ch;
   gotoxy(4,12);
   setcolor(9);
   printf("Any suggestions? Please type below");
   gotoxy(4,13);
   setcolor(15);
   gets(sug);
   gotoxy(4,17);
   setcolor(9);
   printf("Thanks for your valuable feedback");
   gotoxy(4,19);
   setcolor(14);
   cout<<"Press any key to continue";
   getch();
   menu();
}

void check_phone(char *ph, int size)
{
	int p=0;
	char s[20],ch;
	do
	{
		ch=getch();
		if( ((ch>='0' && ch<='9')||(ch=='-')) && (p<size-1) )
		{
			*ph=ch;
			 ph++;
			 p++;
			 cout<<ch;
		}
		else if( (ch==8)&&(p>0) )
		{
			cout<<"\b"<<" "<<"\b";
			p--;
			ph--;
		}
	}while(ch!=13/* || p<size-1*/);
	s[p]='\0';
	*ph='\0';
}

void check_name(char *p, int size)
{
	int j=0;
	char x[40],cj;
 	do
	{
	  	cj=getch();

		if(((cj>='a' && cj<='z')||(cj>='A' && cj<='Z')||(cj==' ')) && (j<size-1))
		{
			*p++=cj;
			j++;
			printf("%c",cj);
		}
		else
		if(cj==8 && j>0)
		{
         cout<<"\b"<<" "<<"\b";
			j--; p--;
		}
	}while(cj!=13);
	x[j]='\0';
	*p='\0';
}

void menu()                             //Main Menu
{
  int ch;
  do
  {
   	clrscr();
   	box(2,2,79,24);
      for(int j=5;j<23;j+=2)
		{
     		gotoxy(5,j);
      	cprintf("\xB0");           // Vertical Lines
      	gotoxy(76,j);
      	cprintf("\xB0");
		}
   	gotoxy(12,3);
      setcolor(13);
      printf("\t\t\t\tMENU");
      gotoxy(12,4);
      printf("\t\t\t\t====");
      gotoxy(30,5);
   	setcolor(2);
   	printf("1)Home");
   	gotoxy(30,6);
   	printf("2)Login");
   	gotoxy(30,7);
   	printf("3)Register");
   	gotoxy(30,8);
   	printf("4)Book Flights");
   	gotoxy(30,9);
   	printf("5)Flight Enquiry");
   	gotoxy(30,10);
   	printf("6)Payment");
   	gotoxy(30,11);
   	printf("7)Cancellation of Ticket");
   	gotoxy(30,12);
   	printf("8)Passenger Info\n");
   	gotoxy(30,13);
   	printf("9)Check flight reservation");
   	gotoxy(30,14);
   	printf("10)Flight related info");
   	gotoxy(30,15);
   	printf("11)FAQs");
   	gotoxy(30,16);
   	printf("12)About FlyHigh");
   	gotoxy(30,17);
		printf("13)Contact Us");
   	gotoxy(30,18);
   	printf("14)Feedback");
   	gotoxy(30,19);
   	printf("15)About program");
   	gotoxy(30,20);
   	printf("16)Logout");
   	gotoxy(26,22);
      setcolor(13);
   	printf("Enter your choice from 1-16\n");
      gotoxy(26,23);
   	cin>>ch;
   	switch(ch)
   	{
     	 case 1: start:
        			home();
        	      break;
       case 2: log:
       			login();
               break;
       case 3: reg();
               break;
       case 4: if (!flag) goto log;
       			book();
               break;
       case 5: enq();
        		   break;
       case 6: if (!flag) goto log;
       			pay();
       		   break;
       case 7: if (!flag) goto log;
       			cancel();
       		   break;
       case 8: display();
       		   break;
       case 9: fres();
       		   break;
      case 10: info();
        			break;
      case 11: faqs();
        			break;
      case 12: fabout();
       			break;
      case 13: contact();
        			break;
      case 14: feedback();
       			break;
      case 15: sabout();
      			menu();
       			break;
      case 16: setcolor(15);
      		   gotoxy(10,23);
      			cout<<"You have succesfully logged out\n";
        			getch();
        			exit(0);
               break;
      default: goto start;
   	}
  }while(ch<16);
}

int main()
{
   sabout();
   home();
   menu();
   return 0;
}
