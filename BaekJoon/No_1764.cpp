#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<string, int> personMap; // 듣보잡 맵 <이름, 수>
  vector<string> personVector; // 듣보잡 벡터
  int personCnt = 0; // 듣보잡 수

  int n, m;
  cin >> n >> m;

  vector<string> seeVector(n); // 듣도 못 한 사람 벡터
  for(int i = 0; i < n; i++){
    cin >> seeVector[i];
    personMap[seeVector[i]]++;
  }

  vector<string> hearVector(m); // 보도 못 한 사람 벡터
  for(int i = 0; i < m; i++){
    cin >> hearVector[i];
    personMap[hearVector[i]]++;

    if(personMap[hearVector[i]] == 2){
      personVector.push_back(hearVector[i]);
      personCnt++;
    }
  }

  sort(personVector.begin(), personVector.end());

  cout << personCnt << "\n";
  for(auto a : personVector){
    cout << a << "\n";
  }

  return 0;
}
