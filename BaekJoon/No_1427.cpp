#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string numString;
  cin >> numString;

  vector<int> numVector;
  for(int i = 0; i < numString.length(); i++){
    numVector.push_back(numString[i] - '0');
  }

  sort(numVector.begin(), numVector.end());

  for(int i = numString.length() - 1; i >= 0; i--){
    cout << numVector[i];
  }

  return 0;
}