#include <iostream>
#include <set>

using namespace std;

int t, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  while(t--){
    cin >> k;

    multiset<long long> s;
    for(int i = 0; i < k; i++){
      char ch;
      long long temp;
      cin >> ch >> temp;

      // 삭제 연산
      if(ch == 'D'){
        if(!s.empty()){
          // 최대값 삭제
          if(temp == 1) s.erase(prev(s.end()));
          // 최소값 수 삭제
          else if(temp == -1) s.erase(s.begin());
        }
      }
      // 삽입 연산
      else if(ch == 'I') s.insert(temp);
    }

    if(s.empty()) cout << "EMPTY" << "\n";
    else cout << *prev(s.end()) << " " << *s.begin() << "\n";
  }

  return 0;
}