#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int arr[8];

  int temp = 0;

  for(int i = 0; i < 8; i++)
  {
    cin >> arr[i];

    if(arr[i] == i + 1)
      temp ++;
    else if(arr[i] == 8 - i)
      temp --;
  }

  if(temp == 8)
    cout << "ascending" << "\n";
  else if(temp == -8)
    cout << "descending" << "\n";
  else
    cout << "mixed" << "\n";

  return 0;
}