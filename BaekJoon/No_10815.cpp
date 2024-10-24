#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<int, int> numMap; // 숫자 카드 맵

  int n;
  cin >> n;

  vector<int> haveNumVector(n); // 상근이의 숫자 카드 벡터
  for(int i = 0; i < n; i++){
    cin >> haveNumVector[i];
    numMap[haveNumVector[i]]++;
  }

  int m;
  cin >> m;

  vector<int> newNumVector(m); // 새로운 숫자 벡터
  for(int i = 0; i < m; i++){
    cin >> newNumVector[i];
    numMap[newNumVector[i]]++;
  }

  for(int i = 0; i < m; i++){
    if(numMap[newNumVector[i]] == 2){
      cout << 1;
    }
    else{
      cout << 0;
    }

    if(i != m - 1){
      cout << " ";
    }
  }
  return 0;
}
