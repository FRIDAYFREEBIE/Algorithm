#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int line = 1, temp = n;
  while(temp - line > 0){
    temp -= line;
    line++;
  }

  if(line % 2 == 0){
    cout << temp << '/' << line + 1 - temp << "\n";
  }
  else{
    cout << line + 1 - temp << '/' << temp << "\n";
  }

  return 0;
}