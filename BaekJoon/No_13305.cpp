#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<long long> dist; // 거리
vector<long long> station; // 주유소

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  dist.resize(n);
  station.resize(n + 1);

  for(int i = 0; i < n - 1; i++) cin >> dist[i];
  for(int i = 0; i < n; i++) cin >> station[i];

  // 2 3 1
  // 5 2 4 1
  // -> 18

  // 최소비용
  long long minPrice = station[0];
  // 첫 번째 주유소는 무조건 지나가야함
  long long sum = minPrice * dist[0];
  for(int i = 1; i < n - 1; i++){
    // 최소비용 갱신
    if(minPrice > station[i]) minPrice = station[i];

    sum += minPrice * dist[i];
  }

  cout << sum << "\n";

  return 0;
}