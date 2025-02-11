#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef struct Edge{
  int cost, a, b; // 비용, 시작, 도착
}Edge;

int n, ans, edgeCnt;
vector<tuple<int, int, int, int>> v; // 행성 벡터 x, y, z, index
vector<Edge> edges; // 터널 벡터
vector<int> p;

int find(int a); // a의 대표 노드 반환
void unionFunc(int a, int b); // a와 b를 같은 집합으로 묶기

// 1. 입력
// 2. 각 좌표축에 대해 정렬 후 터널 저장
// 3. 최소 스패닝 트리 구성
// 4. 총합 출력

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  v.resize(n);

  // 1. 입력
  for(int i = 0 ; i < n; i++){
    int x, y, z;
    cin >> x >> y >> z;
    v[i] = {x, y, z, i};
  }

  // 2. 각 좌표축에 대해 정렬 후 터널 저장
  // X좌표
  sort(v.begin(), v.end());
  for(int i = 0; i < n - 1; i++){
    int x1, y1, z1, idx1, x2, y2, z2, idx2;
    tie(x1, y1, z1, idx1) = v[i];
    tie(x2, y2, z2, idx2) = v[i + 1];

    int cost = abs(x1 - x2);
    edges.push_back({cost, idx1, idx2});
  }

  // Y좌표
  sort(v.begin(), v.end(), [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b){return get<1>(a) < get<1>(b);});
  for(int i = 0; i < n - 1; i++){
    int x1, y1, z1, idx1, x2, y2, z2, idx2;
    tie(x1, y1, z1, idx1) = v[i];
    tie(x2, y2, z2, idx2) = v[i + 1];

    int cost = abs(y1 - y2);
    edges.push_back({cost, idx1, idx2});
  }

  // Z좌표
  sort(v.begin(), v.end(), [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b){return get<2>(a) < get<2>(b);});
  for(int i = 0; i < n - 1; i++){
    int x1, y1, z1, idx1, x2, y2, z2, idx2;
    tie(x1, y1, z1, idx1) = v[i];
    tie(x2, y2, z2, idx2) = v[i + 1];

    int cost = abs(z1 - z2);
    edges.push_back({cost, idx1, idx2});
  }

  // 터널 벡터를 비용순으로 정렬
  sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){return a.cost < b.cost;});

  // 유니온 파인드 초기화
  p.resize(n);
  for(int i = 0; i < n; i++) p[i] = i;

  // 3. 최소 스패닝 트리 구성
  for(size_t i = 0; i < edges.size(); i++){
    int cost, a, b;
    tie(cost, a, b) = make_tuple(edges[i].cost, edges[i].a, edges[i].b); // tie()로 값 저장

    if(find(a) != find(b)){
      unionFunc(a, b);
      ans += cost;
      edgeCnt++;
    }

    if(edgeCnt == n - 1) break;
}
  
  // 4. 총합 출력
  cout << ans << "\n";

  return 0;
}

// a의 대표 노드 반환
int find(int a){
  if(p[a] == a) return a;
  // 대표 노드를 재귀적으로 탐색
  else return p[a] = find(p[a]);
}

// a와 b를 같은 집합으로 묶기
void unionFunc(int a, int b){
  a = find(a);
  b = find(b);

  // a와 b가 다를 때 같은 집합으로 묶기
  if(a != b) p[b] = a;
}