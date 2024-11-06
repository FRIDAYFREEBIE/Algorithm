#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int student[100001];
bool visit[100001];
bool finish[100001];
int cnt = 0;

void DFS(int current);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> student[i];
    }

    memset(visit, false, sizeof(visit));
    memset(finish, false, sizeof(finish));
    cnt = 0;

    for (int i = 1; i <= n; i++) {
      if (!visit[i]) {
        DFS(i);
      }
    }

    cout << n - cnt << "\n";
  }
  
  return 0;
}

void DFS(int current){
  visit[current] = true;
  int next = student[current];

  if(!visit[next]){
    DFS(next);
  }
  else if(!finish[next]){
    int temp = next;
    cnt++;

    while(temp != current){
      cnt++;
      temp = student[temp];
    }
  }

  finish[current] = true;
}