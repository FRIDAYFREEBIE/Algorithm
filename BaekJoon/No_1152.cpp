#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  string s;
  int cnt = 0;

  getline(cin, s);

  if(s.length() == 1 && s[0] == ' ')
  {
    cout << 0;
    return 0;
  }

  for(int i = 1; i < s.length() - 1; i++)
  {
    if(s[i] == ' ')
      cnt ++;
  }

  cout << cnt + 1 << "\n";

  return 0;
}