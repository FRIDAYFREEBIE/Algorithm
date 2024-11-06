#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
bool visit[501];
int dist[501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0 ; i < m; i++){
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  visit[1] = true;
  dist[1] = 0;
  queue<int> q;
  q.push(1);

  int cnt = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(auto &next : adj[current]){
      if(visit[next] || dist[current] == 2){
        continue;
      }

      visit[next] = true;
      dist[next] = dist[current] + 1;
      q.push(next);
      
      if(dist[next] <= 2){
        cnt++;
      }
    }

  }

  cout << cnt << "\n";

  return 0;
}