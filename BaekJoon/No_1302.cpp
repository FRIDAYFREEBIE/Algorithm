#include <iostream>
#include <map>
#include<algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  map<string, int> bookMap;
  while(n--){
    string str;
    cin >> str;

    bookMap[str]++;
  }

  vector<pair<string, int>> copyVector(bookMap.begin(), bookMap.end());

  sort(copyVector.begin(), copyVector.end(), [](const pair<string, int> &a, const pair<string, int> &b){
    if (a.second != b.second){
      return a.second > b.second;
    }
    else{
      return a.first < b.first;
      }
  });

  cout << copyVector[0].first << "\n";

  return 0;
}