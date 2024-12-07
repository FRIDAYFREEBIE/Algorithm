#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void BFS();

int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};
bool visit[201][201];
bool answer[201];
int now[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> now[0] >> now[1] >> now[2];
  BFS();

  vector<int> result;
  for(int i = 0; i < 201; i++) if(answer[i]) result.push_back(i);

  sort(result.begin(), result.end());

  for(int i : result) cout << i << " ";
  
  cout << "\n";

  return 0;
}

void BFS() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  visit[0][0] = true;
  answer[now[2]] = true;

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    int a = current.first;
    int b = current.second;
    int c = now[2] - a - b;

    for(int k = 0; k < 6; k++){
      int next[3] = {a, b, c};

      next[receiver[k]] += next[sender[k]];
      next[sender[k]] = 0;

      if(next[receiver[k]] > now[receiver[k]]){
        next[sender[k]] = next[receiver[k]] - now[receiver[k]];
        next[receiver[k]] = now[receiver[k]];
      }

      if(!visit[next[0]][next[1]]){
        visit[next[0]][next[1]] = true;
        q.push({next[0], next[1]});

        if(next[0] == 0) answer[next[2]] = true;
      }
    }
  }
}
