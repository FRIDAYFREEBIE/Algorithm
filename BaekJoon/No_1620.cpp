#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // 이중 맵
  map<int, string> idName; // <번호, 이름>
  map<string, int> nameId; // <이름, 번호>

  for(int i = 0; i < n; i++){
    string temp;
    cin >> temp;

    idName[i + 1] = temp;
  }

  for(auto &a : idName){
    nameId[a.second] = a.first;
  }

  for(int i = 0; i < m; i++){
    string temp;
    cin >> temp;

    if(isdigit(temp[0])){
      cout << idName[stoi(temp)] << "\n";
    }
    else{
      cout << nameId[temp] << "\n";
    }
  }

  return 0;
}
