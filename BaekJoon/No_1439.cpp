#include <iostream>
#include <algorithm>

using namespace std;

// 문자열을 뒤집어 모두 같게 만들 수 있는 최소 횟수 구하기
// 00011000 -> 111 11 111 -> 2번
// 00011000 -> 000 00 000 -> 1번

// 1로 만드는 경우, 0으로 만드는 경우를 비교

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  int zero = 0, one = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] != str[i + 1]){
      if(str[i] == '0') zero++;
      else one++;
    }
  }

  cout << min(zero, one) << "\n";

  return 0;
}