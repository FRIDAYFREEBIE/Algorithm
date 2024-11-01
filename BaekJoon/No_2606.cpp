#include <iostream>
#include <queue>

using namespace std;

int arr[101][101]; // 0: 존재 X 1: 존재 O
int visit[101]; // 0: 방문 X 1: 바이러스 O

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  queue<int> q;
  visit[1] = 1;
  q.push(1);

  int cnt = 0;
  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i = 1; i <= n; i++){
      if(arr[current][i] == 1 && !visit[i]){
        visit[i] = 1;
        q.push(i);
        cnt++;
      }
    }
  }

  cout << cnt << "\n";

  return 0;
}