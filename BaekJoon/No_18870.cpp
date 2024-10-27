#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<long long> numVector(n);
  for(int i = 0; i < n; i++){
    cin >> numVector[i];
  }

  vector<long long> sortedVector = numVector;

  sort(sortedVector.begin(), sortedVector.end());
  sortedVector.erase(unique(sortedVector.begin(), sortedVector.end()), sortedVector.end());

  unordered_map<long long, int> coordinateMap;
  for(int i = 0; i < sortedVector.size(); i++){
    coordinateMap[sortedVector[i]] = i;
  }

  for(int i = 0; i < n; i++){
    cout << coordinateMap[numVector[i]] << " ";
  }

  cout << "\n";

  return 0;
}
