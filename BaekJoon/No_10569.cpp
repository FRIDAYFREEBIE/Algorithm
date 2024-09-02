#include <iostream>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int t, v, e;

  cin >> t;

  for(int i = 0; i < t; i++){
    cin >> v >> e;

    cout << -(v - e - 2) << "\n";
  }

  return 0;
}