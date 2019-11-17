#include<iostream.h> 
#include<conio.h> 
#include<fstream.h> 
#include<stdio.h> 
#include<string.h> #include<process.h> char filename[30];	 int pass=1; class flight { 
  private: 
   char flightno[30]; 
   char flight_tict_no[30]; 
   char name[30]; 
   char source[50]; 
   char destination[50]; 
   float distance;    float tict_cost;   public	:    void	 getdata();	    void	 putdata();	 }f1; 
void flight::getdata() 
{ 
  cout<<"\nEnter flight number:"	;   gets(flightno); 
  cout<<"\nEnter the flight ticket number:";   gets(flight_tict_no);   cout<<"\nEnter passengers name:";   gets(name); 
  cout<<"\nEnter the source of flight:";   gets(source); 
  cout<<"\nEnter the destination of flight:";   gets(destination); 
  cout<<"\nEnter the distance of journey(km):";   cin>>distance;   tict_cost=distance*15; 
} 
void flight::putdata() 
{   cout<<"\nDetails of the passenger="<<pass;   cout<<"\nFlight number="<<strupr(flightno);   cout<<"\nFlight ticket number="	        <<strupr(flight_tict_no);   cout<<"\nPassengers name:"<< strupr(name);   cout<<"\nSource of flight:"<< strupr(source);   cout<<"\nDestination of flight:"       <<strupr(destination);   cout<<"\nDistance of journey(KM):"	<< distance;   cout<<"\nTicket cost:"<<tict_cost; 
  cout<<"\n"	;   if(pass%2==0)   {     getch();     clrscr();   }   pass++; } 
void writedata() {   ofstream fout;   cout<<"\nEnter the name to write:";   gets(filename); 
fout.open(filename,ios::out|ios::binary|ios::noreplace);   if(fout==NULL)   { 
    cout<<"\nFile already exist..."; 
  } 
  else 
  { 
    char ans='Y'; 
    while(ans=='Y'||ans=='y') 
    {       f1.getdata(); 
      fout.write((char	 *)&f1,	sizeof	( f1));       cout<<"\nDo you want to enter more info?(Y/N):";       cin>>ans; 
    }   }   fout.close(); } 
void appenddata() {   ofstream fout;   cout<<"\nEnter the name to write:";   gets(filename); 
 
fout.open(filename,ios::app|ios::binary|ios::nocreate); 
  if(fout==NULL)   { 
    cout<<"\nFile not found, append operation failed"; 
  } 
  else   { 
    char	 ans=	'Y' ;     while(ans=='Y'||ans=='y') 
    {       f1.getdata(); 
      fout.write((char	 *)&f1,	sizeof	( f1));       cout<<"\nDo you want to enter more info?(Y/N):";       cin>>ans; 
    }   }   fout.close(); } void readdata() { 
  cout<<"\nEnter the file name to read:";   gets(filename);   ifstream fin; 
  fin.open(filename,ios::in|ios::binary); 
  if(fin==NULL)   { 
    cout<<"\nFile is not present...";     getch();     exit(0);   } 
  while(!fin.eof())   { 
    fin.read((char	*) &f1,sizeof	( f1)); 
    if(fin.eof())      break;     f1.putdata();   }   fin.close(); 
 
 
} 
 
 
 
void main() {   clrscr();   int ch; 
  cout<<"\n1.To Read Passengers information";   cout<<"\n2.To Write Passenger information";   cout<<"\n3.To append Passenger information"	;   cout<<"\nEnter your choice:";   cin>>ch; 
  switch(ch) 
  { 
    case 1:readdata();    break	; 
    case 2:writedata(); 
   break; 
    case 3: appenddata(); 
    break; 
    default:cout<<"\nSee the menu properly...."; 
    break;   }  getch(); 
} 
