#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<long long, int> m;
  for(int i = 0; i < n; i++){
    long long temp;
    cin >> temp;
    m[temp]++;
  } 

  long long ans = 0, maxCnt = 0;
  for(auto a : m){
    if(a.second > maxCnt){
      maxCnt = a.second;
      ans = a.first;
    }
  }

  cout << ans << "\n";

  return 0;
}