#include <iostream>
#include <queue>

using namespace std;

int n, sum, edgeCnt, ans;

typedef struct Edge{
  int s, e, v; // 시작, 도착, 거리
  // 오퍼레이터 연산자 정의(우선순위 큐)
  bool operator > (const Edge& temp) const{return v > temp.v;}
}Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
vector<int> p;

int find(int a); // a의 대표 노드 반환
void unionFunc(int a, int b); // a와 b를 같은 집합으로 묶기

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      char tempC;
      cin >> tempC;

      if(tempC == '\n') tempC = cin.get();

      int temp = 0;
      if(tempC >= 'a' && tempC <= 'z') temp = tempC - 'a' + 1;
      else if(tempC >= 'A' && tempC <= 'Z') temp = tempC - 'A' + 27;

      sum += temp;
      
      if(i != j && temp != 0) pq.push({i, j, temp});
    }
  }

  p.resize(n);

  for(int i = 0; i < n; i++) p[i] = i;

  while(!pq.empty()){
    Edge current = pq.top();
    pq.pop();

    if(find(current.s) != find(current.e)){
      unionFunc(current.s, current.e);
      ans += current.v;
      edgeCnt++;
    }
  }

  if(edgeCnt == n - 1) cout << sum - ans << "\n";
  else cout << -1 << "\n";

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