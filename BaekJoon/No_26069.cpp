#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  map<string, bool> danceMap; // <이름, 춤>
  danceMap["ChongChong"] = true; // 총총이는 춤을 추고있다
  for(int i = 0; i < n; i++){
    string name1, name2;
    cin >> name1 >> name2;

    // 한 명만 추고 있어도 춤을 춘다
    if(danceMap[name1] || danceMap[name2]){
      danceMap[name1] = true;
      danceMap[name2] = true;
    }
  }

  int cnt = 0;
  for(auto &pair : danceMap){
    if(pair.second == true){
      cnt ++;
    }
  }

  cout << cnt << "\n"; 

  return 0;
}