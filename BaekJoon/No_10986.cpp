#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  vector<long long> num(n, 0);
  cin >> num[0];

  // 누적합
  for(int i = 1 ; i < n; i++){
   int temp;
   cin >> temp;
   num[i] = num[i - 1] + temp;
  }

  long long ans = 0;
  vector<long> temp(m, 0);
  for(int i = 0; i < n; i++){
    int remainder = num[i] % m;

    // 나누어 떨어짐
    if(remainder == 0) ans++;

    // 나머지가 같은 인덱스의 갯수   
    temp[remainder]++;
  }

  // 나머지가 같은 인덱스 중 2개를 고르는 경우의 수
  for(int i = 0; i < m; i++){
   if(temp[i] > 1) ans = ans + (temp[i] * (temp[i] - 1) / 2); 
  }

  cout << ans << "\n";

  return 0;
}