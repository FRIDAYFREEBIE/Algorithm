#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string str;
  cin >> str;

  sort(str.begin(), str.end(), greater<>());

  if(str[str.length() - 1] != '0') cout << -1 << "\n";
  else{
    long long sum = 0;
    for(auto a : str) sum += a - '0';

    if(sum % 3 == 0) cout << str << "\n";
    else cout << -1 << "\n";
  }

  return 0;
}