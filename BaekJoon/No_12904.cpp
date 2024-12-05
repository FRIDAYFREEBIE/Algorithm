#include <iostream>
#include <algorithm>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, t;
  cin >> s >> t;

  // 역순
  while(t.size() > s.size()){
    // A를 제거
    if(t.back() == 'A') t.pop_back();
    
    // B를 제거하고 문자열을 뒤집음
    else if(t.back() == 'B'){
      t.pop_back();
      reverse(t.begin(), t.end());
    }
  }

  if(s == t) cout << 1 << "\n";
  else cout << 0 << "\n";

  return 0;
}