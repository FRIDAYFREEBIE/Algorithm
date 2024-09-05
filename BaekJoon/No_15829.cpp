#include <iostream>
#include <string>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int l;
  long long sum = 0, r = 1, m = 1234567891;

  cin >> l >> s;

  // 모듈러 연산
  for(int i = 0; i < l; i++){
    sum += ((long(s[i]) - 96) * r) % m;
    r = (r * 31) % m;
  }

  // 모듈러 연산 한번더
  cout << sum % m << "\n";

  return 0;
}
