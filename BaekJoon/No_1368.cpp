#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int v, e, cnt, ans;
tuple<int, int, int> edge[100001]; // 비용, 노드, 연결된 노드
vector<int> p(301, -1);

int find(int a);
bool isGroup(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v;

  for(int i = 1; i <= v; i++){
    int cost;
    cin >> cost;
    edge[e++] = {cost, i, v + 1};
  }

  for(int i = 1; i <= v; i++){
    for(int j = 1; j <= v; j++){
      int cost;
      cin >> cost;
      
      if(i >= j) continue;

      edge[e++] = {cost, i, j};
    }
  }

  v++;
  sort(edge, edge + e);

  for(int i = 0; i < e; i++){
    int a, b, cost;
    tie(cost, a, b) = edge[i];

    if(isGroup(a, b)) continue;

    ans += cost;
    cnt++;

    if(cnt == v - 1) break;
  }

  cout << ans << "\n";

  return 0;
}

int find(int a){
  if(p[a] < 0) return a;
  return p[a] = find(p[a]);
}

bool isGroup(int a, int b){
  a = find(a);
  b = find(b);

  if(a == b) return true;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;

  return false;
}