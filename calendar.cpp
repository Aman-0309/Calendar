
#include<iostream>
#include <vector>
#include <iomanip>
#include<string>
using namespace std;

                            // Calendar App Project...

  // Function to check leap year..
  bool leapYear(int & year){
    if(year % 4 == 0 and year % 100 != 0 or year % 400 == 0 ){
    }
  }

  // Fuction to find no of days in each month..
  int daysinmonth(int month, int year){
   int nummonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
   if(month == 2 && leapYear(year)){
      return 29 ;
    } 
    return nummonth[month -1];
   }
  
   // Function to find first day of the week..
   int dayofweek(int month, int year){ 
                                  // we use ziggle congurence alg. to find first day of week
    if (month <= 2){               // in this algo. a formula is given and we consider jan and feb as 13 & 14 month of previous year
      month += 12;
      year -= 1;
    }
    int m = month ;
    int k = year % 100;               // last two digit of year
    int j = year / 100;              // first two digit of year
                      // formula is :
       int firstday = (1+(13*(m+1))/5 + k + (k/4) + (j/4) - (2*j)) % 7;
        return (firstday);         // (0-sat),(1-sun),(2-mon)...(6-fri).
                                  
   }
   
   // Function to display the Calendar.
   void calendar(int month , int year){
    string months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
                                
    cout << "The Calendar of the month: \n" ;
    cout << "       " << months[month -1] << " " << year <<endl;
    cout << "Sat Sun Mon Tue Wed Thu Fri" << endl;
              //we can not start with mon because in zigler formula mon refers to 2.
              // so we start the calendar with sat which refer to 0 in the formula.

       // we made two varible to use in the loop 
    int firstday = dayofweek(month, year);
    int dayinmonth = daysinmonth(month , year);

       // loop to print space before the start of month
    for ( int i=0; i<firstday; i++){
      cout << "    ";            // 4 space - (m+o+n+" ")
    }

       //loop to print all the days.
    for (int day=1; day<=dayinmonth; day++ ){
      cout  << "" << setw(3) << day << " ";
      if((day + firstday) % 7 == 0){
        cout << endl;
      }
    }
    cout << endl;
   }
  
int main (){
  int year , month;
   cout << "Enter the Year: ";
   cin >> year;
   cout << "Enter the Month(1-12): ";
   cin >> month;
   
   calendar(month,year);
    
}