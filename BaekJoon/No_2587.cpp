#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int avg = 0, center = 0;


  vector<int> numVector(5);
  for(int i = 0; i < 5; i++){
    cin >> numVector[i];
    avg += numVector[i];
  }

  sort(numVector.begin(), numVector.end());

  cout << avg / 5  << "\n";
  cout << numVector[2] << "\n";


  return 0;
}