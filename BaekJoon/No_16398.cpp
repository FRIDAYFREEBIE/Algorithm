#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt;
long long ans;
vector<tuple<int, int, int>> edge; // 비용, 행성 i, 행성 j
vector<int> p(1005, -1);

int find(int a);
bool isGroup(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int cost;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> cost;
      if(i == j) continue; // 자기 자신 제외
      edge.push_back({cost, i, j});
    }
  }

  sort(edge.begin(), edge.end());

  int a, b, c;
  for(auto e : edge){
    tie(c, a, b) = e;
    if(isGroup(a, b)) continue;
    ans += c;
    cnt++;
    if(cnt == n - 1) break;
  }

  cout << ans << "\n";

  return 0;
}

int find(int a){
  if(p[a] < 0) return a;
  else return p[a] = find(p[a]);
}

bool isGroup(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return true;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
  return false;
}
