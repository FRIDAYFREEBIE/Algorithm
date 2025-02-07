#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int v, e, cnt, ans;
tuple<int, int, int> edge[100001];
vector<int> p(10001, -1);

int find(int a);
bool isGroup(int a, int b);

// 유니온 파인드를 사용하여 BST 구현
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v >> e;

  for(int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edge[i] = {c, a, b}; // 코스트, 간선 1, 간선 2
  }

  sort(edge, edge + e);

  for(int i = 0; i < e; i++){
    int a, b, c;
    tie(c, a, b) = edge[i];

    if(isGroup(a, b)) continue;

    ans += c;
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