#include<iostream.h>
#include<ctype.h>
#include<string.h>
#include<iomanip.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
  void box(int a,int b,int c,int d)
{
	for(int i=a;i<c;i++)
	{	gotoxy(i,b);cprintf("\xcd");        	// Horizontal Lines
		gotoxy(i,d);cprintf("\xcd");
  	}

	for(int j=b;j<d;j++)
	{
   	gotoxy(a,j);cprintf("\xba");           // Vertical Lines
		gotoxy(c,j);cprintf("\xba");
   }

	gotoxy(a,b);cprintf("\xc9");
	gotoxy(c,b);cprintf("\xbb");
	gotoxy(a,d);cprintf("\xc8");
	gotoxy(c,d);cprintf("\xbc");
}
void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
  HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
class BOOKING
{
    public :
        char name[20];
        char add[50];
        char email[50];
        char mobile[10];
        char age[2];
        char gender[10];
        char departure[25];
        char arrival[25];
        char date[10];
        char  civilid[15];
        int sNo  ;
    public :
       void check_digit(char *ph, int size)
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

		else

		if( (ch==8)&&(p>0) )
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










        void getInfo()
        {   box(12,2,68,40); setcolor(6);
         gotoxy(20,8);
            cout << "Enter Passenger's Name :- ";
            check_name(name,20);cout<<endl;
              gotoxy(20,11);
            cout << "Enter the Address Details :- ";
            check_name(add,50);cout<<endl;
                gotoxy(20,14);
            cout << "Enter your email address :- ";
            gets(email);  cout<<endl;
              gotoxy(20,17);
            cout << "Enter your Phone Number :- ";
          check_digit(mobile,8);cout<<endl;
               gotoxy(20,20);
            cout << "Enter your Age :- ";
            check_digit(age,3); cout<<endl;
              gotoxy(20,23);
            cout <<"Enter Gender :- ";
           check_name(gender,10);cout<<endl;
             gotoxy(20,26);
            cout << "Enter Civil Id Number :- ";
            check_digit(civilid,12); cout<<endl;
             clrscr();
            int n;
            int k = 0;
            do
            {   c1:    box(12,2,68,40);
             gotoxy(20,8);
                cout << "Select Your City of Departure";
                gotoxy(20,9);cout << "\t-----------------------------\n";
		       gotoxy(20,12); cout << "\t1. Dubai\n";
		        gotoxy(20,15);cout << "\t2. Singapore\n";
		        gotoxy(20,18);cout << "\t3. Mumbai\n";
		       gotoxy(20,21); cout << "\t4. London\n";
		       gotoxy(20,24); cout << "\t5. New York\n";
		       gotoxy(20,27);cout << "\t6. Japan\n";

		        gotoxy(20,31);cout << "Please Input Your Choice Number :-  ";
               gotoxy(60,31); cin >> n;
		        switch (n)
                {
                    case 1:
                        strcpy(departure, "Dubai");
                        break; k++;
                    case 2:
                        strcpy(departure, "Singapore");
                        break;k++;
                    case 3:
                        strcpy(departure, "Mumbai");
                        break; k++;
                    case 4:
                        strcpy(departure, "London");
                        break; k++;
                    case 5:
                        strcpy(departure, "New York");
                        break; k++;
                    case 6:
                        strcpy(departure, "Japan");
                        break;k++;
                    default:
                        cout << "Invalid Choice . Please Try Again.\n";
                        k=0;clrscr();goto c1;
		        }
            }while(k = 0);
              clrscr();
            int p = 0;  c2:
            do
            {      box(12,2,68,40);
               gotoxy(20,8);
                cout << "Select Your City of Arrival";
                gotoxy(20,9);cout << "-----------------------------\n";
		       gotoxy(20,12); cout << "\t1. Dubai\n";
		        gotoxy(20,15);cout << "\t2. Singapore\n";
		        gotoxy(20,18);cout << "\t3. Mumbai\n";
		       gotoxy(20,20); cout << "\t4. London\n";
		       gotoxy(20,23); cout << "\t5. New York\n";
		       gotoxy(20,26);cout << "\t6. Japan\n";

		        gotoxy(20,30);cout << "Please Input Your Choice Number :-  ";
               gotoxy(60,30); cin >> n;

                switch(n)
                {
                    case 1:
                        strcpy(arrival,"Dubai");
                        break;p++;
                    case 2:
                        strcpy(arrival,"Singapore");
                        break; p++;
                    case 3:
                        strcpy(arrival,"MUMBAI");
                        break; p++;
                    case 4:
                        strcpy(arrival,"London");
                        break; p++;
                    case 5:
                        strcpy(arrival,"New York");
                        break;p++;
                    case 6:
                        strcpy(arrival,"Japan");
                        break; p++;
                   default:
                        cout << "Invalid choice . Please Try Again.\n";
                        p=0; clrscr(); goto c2;
                }
            }while(p != 0);

           gotoxy(20,34); cout << "Date of Journey ( DD/MM/YYYY ) :- ";
            gotoxy(56,34);cin >> date;
        }

        void disInfo()
        {
            
            cout.setf(ios::left);
            cout <<setw(8)<<setw(15)<< name <<setw(12)<< date <<setw(20)<< add <<setw(15)<< mobile <<setw(20)<<civilid<<setw(12)<< departure <<setw(12)<< arrival<<endl;
        }

};
class FLIGHTS
{
    char flight_no[10];
    char flight_carrier[20];
    char time_depart[10];
    char time_arrival[10];

    public :
        int flightInfo()
        {   box(12,2,68,40); setcolor(6);
        gotoxy(20,8);
            cout << "Enter the Flight Number :- ";
            gotoxy(50,8);
            cin >>flight_no;
            gotoxy(20,11);
            cout << "Enter the Flight Carrier Name :- ";
            gotoxy(56,11);
            cin >> flight_carrier;
             gotoxy(20,14);
            cout << "Enter the departure time :- ";
            gotoxy(55,14);
            cin >> time_depart;
            gotoxy(20,17);
            cout << "Enter the arrival time :- ";
            gotoxy(55,17);
            cin >> time_arrival;
        }
};




void menu()

{start: setcolor(6); clrscr();
box(12,2,68,40);
int op=2375427;
   char i=234;
setcolor(10);
gotoxy(20,3) ;
 cout<<i<<" WELCOME TO FLYEASY TRAVEL PROGRAM "<<i;
 gotoxy(20,4) ;
 cout<<"-------------------------------------";
 gotoxy(20,6) ;
  cout<<" FLYING MADE EASY WITH FLY EASY.";
 gotoxy(20,8) ;
  cout<<" USE CODE FOR DISCOUNT";
 gotoxy(20,10) ;
 cout<<"~CHOOSE FROM THE FOLLOWING OPTIONS~" ;
  gotoxy(20,15) ;
 cout<<" 1.BOOK A FLIGHT";
 gotoxy(20,18) ;
 cout<<" 2.FLIGHT DETAILS";
  gotoxy(20,21) ;
 cout<<" 3.SEARCH A FLIGHT";
 gotoxy(20,24) ;
 cout<<" 4.MODIFY A TICKET";
  gotoxy(20,27) ;
    cout<<" 5.CANCEL FLIGHT";
  gotoxy(20,30) ;
       cout<<" 6.PASSANGER DETAILS\n\n";
     gotoxy(20,33) ;
     cout<<" 7.EXIT";
   gotoxy(20,36) ;
     cout<<"ENTER YOUR DESIRED CHOICE  ";
      setcolor(12);
     cin>>op;
      while(op!=2375427)
    { switch(op)
     { case 1:{    clrscr();
                BOOKING b;
                fstream f1;
                char ch;
                int book_id = 1;
                f1.open("booking.dat",ios::in|ios::out|ios::app|ios::binary);
                 gotoxy(28,3); setcolor(14);
                cout << "FLYEASY TRAVEL PROGRAM";
                gotoxy(28,4);
                cout << "----------------------\n";
                gotoxy(25,5);
                cout<<"FLYING MADE EASY WITH FLYEASY";

                do
                {
                    b.getInfo();
                    f1.write((char *)&b , sizeof(b));
                    box(12,2,68,40);clrscr();
                    cout << "\n\t\tBooking Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(8)<<"S.No."<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                    cout <<setw(8)<<"-----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                    b.disInfo();
                    gotoxy(20,6);cout << "Do you want to register again ?\n";
                    gotoxy(20,9);cout << "(Y for yes,N for no)";
                    cin >> ch;clrscr();
                }while (ch == 'Y'|| ch == 'y');
               gotoxy(20,6); cout << "\n\t..........Booking Successful...............\n";

                char c1;
                gotoxy(20,10);
                cout << "Press 'q' to terminate or 'h' to return to HomeScreen :- ";
                cin >>c1;
                if(c1 == 'q' || c1 == 'Q')
                    exit(EXIT_FAILURE);
                else
                   clrscr(); goto start;
                f1.close();
            }
            break;
       case 2:{    clrscr();
                FLIGHTS f;
                fstream f2;
                f2.open("flights.dat",ios::in|ios::out|ios::app);
                box(12,2,68,40);
                char ch = 'Y';
                while (ch == 'Y'||ch == 'y')
                  {
                      f.flightInfo();
                      f2.write((char *)&f,sizeof(f));
                      gotoxy(20,26);
                      cout << "Do you want to add more Flights:- ";
                      gotoxy(60,26);
                      cin >> ch;
                  }
            }
       case 3: {    clrscr();
                BOOKING s;
                int choice;
                fstream f3;
                char sName[20];
                char sEmail[20];
                char sMobile[8];
                char sCivil_Id[15];
                f3.open("booking.dat",ios::in|ios::out|ios::binary);
                box(12,2,68,40);
                gotoxy(20,8);
                cout << "\tChoose the Criteria to search\n";
                gotoxy(20,11);
                cout <<"\t1. By Name\n";
                gotoxy(20,14);
                cout <<"\t2. By Email\n";
                gotoxy(20,17);
                cout <<"\t3. By Civil Id Number(Recommended)\n";
                gotoxy(20,20);
                cout<<"\t4. By Phone Number\n";
                gotoxy(20,22);
                cout << "Enter your Preferred Choice :- ";
                gotoxy(52,22);
                cin >> choice;clrscr();

                switch (choice)
                {
                    case 1:
                        {

                            int flag = 0;
                            box(12,2,68,40);
                            gotoxy(20,8);
                            cout << "Enter the name :- ";
                            gotoxy(50,8);
                            cin >> sName; clrscr();
                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));
                            cout.setf(ios::left);
                            cout <<setw(8)<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(8)<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 1)
                            {
                                if (strcmp(sName,s.name) == 0)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                               f3.read((char *)&s,sizeof(s));
                            }

                            if (flag == 0)
                            {
                            gotoxy(20,8);
                            cout << "\t!!!!!!Search Query Not Found!!!!!!!!\n";
                            }
                            f3.close();

                            char c3_1;
                            gotoxy(20,8);
                            cout << "\tEnter 'q' to quit or any key for home\n";
                            cin >> c3_1; clrscr();

                            if(c3_1 == 'q'|| c3_1 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 2:
                        {
                            int flag = 0;
                            box(12,2,68,40);
                            gotoxy(20,8);
                            cout << "Enter the Email-id  :- ";
                            gotoxy(50,8);
                            cin >> sEmail; clrscr();

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(8)<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(8)<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 1)
                            {
                                if (strcmp(sEmail,s.email) == 0)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                               f3.read((char *)&s,sizeof(s));
                            }

                            if(flag == 0)
                            {
                             gotoxy(20,10);
                                cout << "\t\tSearch Query Not Found !!!\n";
                            }
                            char c3_2;
                            gotoxy(20,8);
                            cout << "\tPress 'q' to quit or any key for home\n";
                            cin >> c3_2; clrscr();

                            if(c3_2 == 'q' || c3_2 == 'Q')
                               exit (EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 3:
                        {    char scivilid[15];
                            int flag = 0;
                            box(12,2,68,40);
                            gotoxy(20,8);
                            cout << "Enter the Civil Id  :- ";
                            gotoxy(60,8);
                            cin >> scivilid; clrscr();

                            f3.seekg(0,ios::beg);
                            f3.read((char*)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(8)<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(8)<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while (f3.eof() != 1)
                            {
                                if(strcmpi(scivilid,s.civilid))
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                            }

                            if(flag == 0)
                            {
                            gotoxy(20,8);
                            cout << "\t\tSearch Query Not Found !!!!\n";
                            }
                            char c3_3;
                            gotoxy(20,8);
                            cout << "\tPress 'q' to quit or any key for home\n";
                            cin >> c3_3; clrscr();

                            if(c3_3 == 'q' || c3_3 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 4:
                        {
                            int flag = 0;
                            box(12,2,68,40);
                            gotoxy(20,8);
                            cout << "Please Enter the phone number:- ";
                            gotoxy(60,8);
                            cin >> sMobile;  clrscr();

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(8)<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(8)<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 0)
                            {
                                if (sMobile==s.mobile)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                            }

                            if(flag == 0)
                            {
                              gotoxy(20,8);
                                cout << "\tSearch Query Not Found !!!!!!!!\n";
                            }
                            char c3_4;
                            gotoxy(20,8);
                            cout << "\tPress 'q' to quit or Any other key to go to HomeScreen\n";
                            cin >> c3_4; clrscr();

                            if(c3_4 == 'q' || c3_4 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                }

            }
            break;
       case 4: {   clrscr();
                BOOKING m;
                int line;
                fstream f4;
                 BOOKING p;
                int count = 0;
                fstream f6;
               c3: f6.open("booking.dat",ios::in|ios::out|ios::binary);

                f6.seekg(0,ios::beg);
                f6.read ((char *)&p,sizeof(p));
                cout.setf(ios::left);
                cout <<endl;
                cout <<setw(8)<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                cout <<setw(8)<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                while(f6.eof() != 1)
                {
                    p.disInfo();
                    f6.read ((char *)&p,sizeof(p));
                    count++;
                }
                f6.close();

                gotoxy(20,8);
                cout << "\n\tTotal Number of passengers is "<<count<<endl;
                gotoxy(20,11);
                cout << "Enter the line number which you want to modify :- ";
                cin >> line;
                 if(line>(count+1)||line==0)
                { cout<<"\nINVALID"; sleep(1);clrscr();goto c3;}
                int pos;
                pos = (line -1) *sizeof(m);
                f4.open("booking.dat",ios::in|ios::out|ios::binary);
                 clrscr();
                f4.seekp(pos,ios::beg);
                m.getInfo();
                f4.write((char *)&m,sizeof(m));
                f4.close();  clrscr();

                gotoxy(20,15);
                cout << "\t\tSuccessfully Modified.....\n";

                char c4;
                gotoxy(20,8);
                cout << "\tEnter 'q' to quit\n";
                cin >> c4;

                if(c4 == 'q'|| c4 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
            }
            break;

       case 5:{    clrscr();
                BOOKING c;
                fstream f4,fr;
                f4.open("booking.dat",ios::in|ios::out|ios::binary);
                fr.open("b.dat",ios::in|ios::out|ios::binary|ios::app);
                box(12,2,68,40);
                char nam[20];
                gotoxy(20,8);
                cout << "Enter the Name :- ";
                gotoxy(40,8);
                cin >> nam;
                 clrscr();
                f4.seekg(0,ios::beg);
                f4.read((char*)&c,sizeof(c));

                while (f4.eof() != 1)
                {
                    if(strcmp(nam,c.name) != 0)
                        fr.write((char *)&c,sizeof(c));
                    f4.read((char*)&c,sizeof(c));
                }
                gotoxy(20,8);clrscr();

                cout << "\n\t******Ticket Cancellation Successful******\n";

                remove("booking.dat");
                rename("b.dat","booking.dat");

                f4.close();
                fr.close();
                char c5;

                gotoxy(20,12);
                cout << "\tEnter 'q' to quit or Any Other key \n";
                cin >> c5;

                if(c5 == 'q'|| c5 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;

            }
            break;
            case 6: {  clrscr();
                BOOKING p;
                int count = 0;
                fstream f6;
                f6.open("booking.dat",ios::in|ios::out|ios::binary);

                f6.seekg(0,ios::beg);
                f6.read ((char *)&p,sizeof(p));

                cout.setf(ios::left);
                cout <<endl;
                cout <<setw(8)<<"S.No."<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(20)<<"Civil Id"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                cout <<setw(8)<<"-----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                while(f6.eof() != 1)
                {
                    p.disInfo();
                    f6.read ((char *)&p,sizeof(p));
                    count++;
                }
                f6.close();

                gotoxy(20,8);
                cout << "\n\tTotal Number of passengers is "<<count<<endl;
                char c6;
                gotoxy(20,11);
                cout << "\tEnter 'q' to quit or Any Other key \n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
            }
       case 7:exit(7);
       default:{ box(12,2,68,40); gotoxy(45,36) ; cout<<"INVALID!  "; sleep(1);clrscr();  menu();cin>>op;}
       }
       clrscr();
       }

 }
   void main()
   {gotoxy(10,11);  cout<<"****THIS PROGRAM WOULD NOT HAVE BEEN POSSIBLE WITHOUT OUR  COMPUTER SCIENCE TEACHER MR.A GEORGE SWAMY****";sleep(3);
     gotoxy(10,14); cout<<"****DONE BY SHUBHAM GANDHI OF CLASS XII-D****";sleep(3);

    menu();



   getch();
   }
