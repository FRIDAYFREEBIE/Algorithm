#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> numVector(n);
  for(int i = 0; i < n; i++){
    cin >> numVector[i];
  }

  sort(numVector.begin(), numVector.end());

  for(int a : numVector){
    cout << a << "\n";
  }

  return 0;
}