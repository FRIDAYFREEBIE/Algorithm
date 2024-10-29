#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  map<string, int> wordMap; // <단어, 횟수>
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    if(str.length() >= m){
      wordMap[str]++;
    }
  }

  // 벡터에 복사
  vector<pair<string, int>> wordVector(wordMap.begin(), wordMap.end());

  sort(wordVector.begin(), wordVector.end(), [](const pair<string, int>& a, const pair<string, int>& b){
    if (a.second == b.second) {
      if (a.first.length() == b.first.length()){
        return a.first < b.first;  // 사전순
      }

      return a.first.length() > b.first.length();  // 길이순
    }
    else{
      return a.second > b.second;  // 횟수 순
    }
  });

  for(auto &pair : wordVector){
    cout << pair.first << "\n";
  }

  return 0;
}