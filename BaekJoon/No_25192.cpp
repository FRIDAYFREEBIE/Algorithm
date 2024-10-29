#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int cnt = 0; // 곰곰티콘

  int n;
  cin >> n;

  set<string> chatSet;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    if(str == "ENTER"){
      chatSet.clear();
    }
    else{
      if(chatSet.find(str) == chatSet.end()) {
        chatSet.insert(str);
        cnt++;
      }
    }
  }

  cout << cnt << "\n";

  return 0;
}