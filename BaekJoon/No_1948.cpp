#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int, int>>> v, rv;
vector<int> indegree, result;
vector<bool> visited;

//위상정렬로 임계 경로 구하기
// **에지 뒤집기** 아이디어
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n + 1);
  rv.resize(n + 1);
  indegree.resize(n + 1);
  result.resize(n + 1);
  visited.resize(n + 1);

  for(int i = 0; i < m; i++){
    int S, E, V;
    cin >> S >> E >> V;
    
    v[S].push_back({E, V});
    rv[E].push_back({S, V});
    indegree[E]++;
  }

  int start, end;
  cin >> start >> end;

  queue<int> q;
  q.push(start);

  // 위상 정렬
  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(auto next : v[current]){
      indegree[next.first]--;
      result[next.first] = max(result[next.first], result[current] + next.second);

      if(indegree[next.first] == 0) q.push(next.first);
    }
  }

  int resultCnt = 0;
  queue<int> rq;
  rq.push(end);
  visited[end] = true;

  // 역방향 위상 정렬
  while(!rq.empty()){
    int current = rq.front();
    rq.pop();

    for(auto next : rv[current]){
      // 1분도 쉬지 않는 도로
      if(result[next.first] + next.second == result[current]){
        resultCnt++;

        // 중복방지
        if(!visited[next.first]){
          visited[next.first] = true;
          rq.push(next.first);
        }
      }
    }
  }

  cout << result[end] << "\n";
  cout << resultCnt << "\n";

  return 0;
}