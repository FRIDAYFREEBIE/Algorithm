#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  int cnt = 0;
  vector<int> numVector;
  for(int i = 1; i <= n; i++){
    if(n % i == 0){
      numVector.push_back(i);
      cnt++;
    }
  }

  if(cnt < k){
    cout << 0 << "\n";
  }
  else{
    cout << numVector[k - 1] << "\n";
  }

  return 0;
}