#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> v[1001];
bool visit[1001];

void dfs(int current);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  while(m--){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int cnt = 0;

  // BFS
  /*
  for(int i = 1; i <= n; i++){
    if(visit[i] != 0){
      continue;
    }

    cnt++;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
      int current = q.front();
      q.pop();

      for(auto next : v[current]){
        if(visit[next]{
          continue;
        }

        q.push(next);
        visit[next] = true;
      }
    }
  }
  */

  // 비재귀 BFS
  /*
  for(int i = 1; i <= n; i++){
    if(visit[i]){
      continue;
    }

    cnt++;
    stack<int> s;
    s.push(i);

    while(!s.empty()){
      int current = s.top();
      s.pop();

      for(auto next : v[current]){
        if(visit[next]){
          continue;
        }

        visit[next] = true;
        s.push(next);
      }
    }
  }
  */

  // 재귀 DFS
  /**/
  for(int i = 1; i <= n; i++){
    if(visit[i]){
      continue;
    }

    cnt++;
    dfs(i);
  }

  cout << cnt << "\n";

  return 0;
}

void dfs(int current){
  visit[current] = true;

  for(auto next : v[current]){
    if (!visit[next]) {
      dfs(next);
    }
  }
}