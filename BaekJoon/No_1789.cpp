#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long s;
  cin >> s;

  long long sum = 0, num = 1, cnt = 0;
  while(true){
    sum += num;
    cnt++;

    if(sum > s) break;

    num++;
  }

  cout << cnt - 1 << "\n";

  return 0;
}