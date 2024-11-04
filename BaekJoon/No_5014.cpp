#include <iostream>
#include <queue>

using namespace std;

int visit[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int f, s, g, u, d;
  cin >> f >> s >> g >> u >> d;

  int dir[2] = {u, -d};

  queue<int> q;
  q.push(s);
  visit[s] = 1;

  while(!q.empty()){
    if(visit[g] != 0){
      cout << visit[g] - 1 << "\n";
      return 0;
    }

    int current = q.front();
    q.pop();

    for(int i = 0; i < 2; i++){
      int next = current + dir[i];

      // 범위
      if(next < 1 || next > f){
        continue;
      }

      // 방문 여부
      if(visit[next] != 0){
        continue;
      }

      visit[next] = visit[current] + 1;
      q.push(next);
    }
  }

  cout << "use the stairs" << "\n";

  return 0;
}