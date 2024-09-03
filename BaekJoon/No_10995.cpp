#include <iostream>

#define MAX 100

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    if(i % 2 == 0) cout << " ";

    for(int j =0; j < n; j++){
      cout << "* ";
    }

    cout << "\n";
  }

  return 0;
}