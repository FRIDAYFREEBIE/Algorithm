#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans;
int map[11][11]; // 지도

// BFS
bool visited[11][11]; // 방문 체크
int directionX[4] = {0, 1, 0, -1}, directionY[4] = {1, 0, -1, 0}; // 방문 노드 방향
int islandCnt = 1; // 섬 번호

// 다리 구조체
typedef struct Edge{
  int s, e, v; // 시작 노드, 도착 노드, 다리 거리
  // 오퍼레이터 연산자 정의(우선순위 큐)
  bool operator > (const Edge& temp) const{return v > temp.v;}
}Edge;

// 다리 짓기
vector<vector<pair<int, int>>> islandVector; // 섬 저장 벡터
vector<pair<int, int>> tempIslandVector; // BFS에서 섬을 저장할 벡터
priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Edge를 오름차순으로 정렬하는 우선순위 큐

// 유니온 파인드
vector<int> parent; // 각 노드의 대표 노드 저장

// 최소 스패닝 트리
int edgeCnt;

int find(int a); // a의 대표 노드 반환
void unionFunc(int a, int b); // a와 b를 같은 집합으로 묶기
void BFS(int i, int j); // BFS로 섬 분할하기

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  // 입력
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < m; j++)
      cin >> map[i][j];
  }

  // 섬 분할하기(BFS)
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      // map[i][j]가 바다가 아니고 방문한 적 없을 때
      if(map[i][j] != 0 && !visited[i][j]){
        BFS(i, j);
        islandVector.push_back(tempIslandVector);
      }
    }
  }

  // 다리 짓는 경우의 수 구하기(브루트포스)
  for(int i = 0 ; i < islandVector.size(); i++){
    vector<pair<int, int>> current = islandVector[i];

    for(int j = 0; j < current.size(); j++){
      int currentX = current[j].first, currentY = current[j].second;
      int currentPos = map[currentX][currentY];

      for(int dir = 0; dir < 4; dir++){
        int nextX = currentX + directionX[dir], nextY = currentY + directionY[dir];
        int bridgeLength = 0; // 현재 다리 길이

        while(true){
          // 지도 범위 체크
          if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) break;
          // 같은 섬 체크
          if(map[nextX][nextY] == currentPos) break;

          // 다른 섬을 만나면 다리 완성
          if(map[nextX][nextY] > 0){
            if(bridgeLength > 1) pq.push(Edge{currentPos, map[nextX][nextY], bridgeLength});
            break;
          }

          // 바다라면 다리 연장
          bridgeLength++;
          nextX += directionX[dir];
          nextY += directionY[dir];
        }
      }
    }
  }

  // 우선순위 큐 디버깅
  // priority_queue<Edge, vector<Edge>, greater<Edge>> tempPQ = pq; // pq 복사
  // while(!tempPQ.empty()){
  //   Edge edge = tempPQ.top();
  //   tempPQ.pop();
  //   cout << "start: " << edge.s << ", end: " << edge.e << ", length: " << edge.v << "\n";
  // }

  // 유니온 파인드
  parent.resize(islandCnt);

  // 각 노드의 초기 대표 노드는 자기 자신
  for(int i = 0; i < parent.size(); i++)
    parent[i] = i;

  // 최적의 해 구하기 (최소 스패닝 트리)
  while(!pq.empty()){
    Edge current = pq.top();
    pq.pop();

    // Egde의 시작 노드와 도착 노드의 대표 노드가 다르다면
    if(find(current.s) != find(current.e)){
      // 연결
      unionFunc(current.s, current.e);
      ans += current.v;
      edgeCnt++;
    }
  }

  // 간선 갯수가 노드 갯수 - 1이면 최소 스패닝 트리가 완성
  // islandCnt가 실제 섬보다 1 많으므로 -2
  if(edgeCnt == islandCnt - 2) cout << ans << "\n";
  else cout << -1 << "\n";

  // 지도 디버깅
  // for(int i = 0; i < n; i++){
  //   for(int j = 0 ; j < m; j++)
  //     cout << map[i][j] << " ";
  //  
  //   cout << "\n";
  // }

  return 0;
}

void BFS(int i, int j){
  tempIslandVector.clear();
  map[i][j] = islandCnt;

  visited[i][j] = true;
  queue<pair<int, int>> q; // BFS 큐
  q.push({i, j});
  tempIslandVector.push_back({i, j});

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + directionX[dir], y = current.second + directionY[dir];
      
      // 지도 범위 검사
      if(x >= n || x < 0 || y >= m || y < 0) continue;
      // 방문 검사
      if(visited[x][y]) continue;
      // 바다 검사
      if(map[x][y] == 0) continue;

      visited[x][y] = true;
      q.push({x, y});
      tempIslandVector.push_back({x, y});
      // 섬 분할
      map[x][y] = islandCnt;
    }
  }

  islandCnt++;
}

// a의 대표 노드 반환
int find(int a){
  if(parent[a] == a) return a;
  // 대표 노드를 재귀적으로 탐색
  else return parent[a] = find(parent[a]);
}

// a와 b를 같은 집합으로 묶기
void unionFunc(int a, int b){
  a = find(a);
  b = find(b);

  // a와 b가 다를 때 같은 집합으로 묶기
  if(a != b) parent[b] = a;
}