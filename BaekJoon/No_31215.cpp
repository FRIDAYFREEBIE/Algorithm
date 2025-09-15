#include <iostream>

using namespace std;

long long t, n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while(cin >> n){
    if(n <= 2) cout << "1\n";
    else cout << "3\n";
  }

  return 0;
}