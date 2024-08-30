#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // n번 반복
  for(int i = 0; i < n; i++)
  {
    int candy, sibling;

    cin >> candy >> sibling;

    cout << "You get " << candy / sibling << " piece(s) and your dad gets " << candy % sibling << " piece(s)." << "\n";
  }

  return 0;
}