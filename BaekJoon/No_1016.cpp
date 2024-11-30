#include <iostream>
#include <vector>

using namespace std;

// 제곱 ㄴㄴ수 갯수 구하기
// 제곱 ㄴㄴ수: N이 1보다 큰 제곱수로 나누어 떨어지지 않을 때

// 1. 에라스토네스의 체를 응용해서 min ~ max사이의 제곱수 찾기
// 2. 제곱수가 아닌 수의 갯수 카운트


int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long min, max;
  cin >> min >> max;  

  vector<bool> check(max - min + 1);

  for(long i = 2; i * i <= max; i++){
    long pow = i * i;
    long index = min / pow;

    // 나머지가 있으면 1을 더해야 함
    if(min % pow != 0) index++;

    for(long j = index; pow * j <= max; j++) check[(int)((j * pow) - min)] = true;
  }

  long cnt = 0;
  for(int i = 0; i <= max - min; i++){
    if(!check[i]) cnt++;
  }

  cout << cnt << "\n";

  return 0;
}