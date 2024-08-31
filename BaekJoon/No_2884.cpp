#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int hour, minute;

  cin >> hour >> minute;

  int newHour, newMinute;
  
  newHour = hour;
  newMinute = minute - 45;

  if(newMinute < 0)
  {
    newHour --;
    newMinute = 60 + newMinute;
  }

  if(newHour < 0)
    newHour = 23; 

  cout << newHour << " " << newMinute << "\n";

  return 0;
}