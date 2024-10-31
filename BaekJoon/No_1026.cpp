#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> aVector(n);
  for(int i = 0; i < n; i++){
    cin >> aVector[i];
  }

  sort(aVector.begin(), aVector.end());

  vector<int> bVector(n);
  for(int i = 0; i < n; i++){
    cin >> bVector[i];
  }

  sort(bVector.begin(), bVector.end(), compare);

  int cnt = 0;
  for(int i = 0; i < n; i++){
    cnt += aVector[i] * bVector[i];
  }

  cout << cnt << "\n";

  return 0;
}

bool compare(int a, int b){
  return a > b;
}