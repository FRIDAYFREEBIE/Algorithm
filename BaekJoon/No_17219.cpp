#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  map<string, string> passwordMap; // <사이트 주소, 비밀번호>
  for(int i = 0; i < n; i++){
    string name, password;
    cin >> name >> password;
    passwordMap[name] = password;
  }

  while(m--){
    string name;
    cin >> name;

    cout << passwordMap[name] << "\n";
  }

  return 0;
}