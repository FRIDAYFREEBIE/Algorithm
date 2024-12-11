#include <iostream>
#include <vector>

using namespace std;

void unionFunc(int a, int b);
int findFunc(int a);
bool checkFunc(int a, int b);

vector<int> graph;
int map[201][201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  graph.resize(n + 1);

  for(int i = 1; i <= n; i++){
    graph[i] = i;

    for(int j =1; j <= n; j++) cin >> map[i][j];
  }

  vector<int> plan(m);
  for(int i = 0; i < m; i++) cin >> plan[i];

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(map[i][j] == 1 && graph[i] != graph[j]) unionFunc(i, j);
    }
  }

  bool check = true;
  int currentNode = findFunc(plan[0]);
  for(int i = 1; i < m; i++){
    if(currentNode != findFunc(plan[i])){
      check = false;
      break;
    }
  }

  if(check) cout << "YES" << "\n";
  else cout << "NO" << "\n";

  return 0;
}

// 유니온
void unionFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a != b) graph[b] = a;
}

// 파인드(대표 노드 반환)
int findFunc(int a){
  if(a == graph[a]) return a;
  else return graph[a] = findFunc(graph[a]);
}

// 같은 집합인지 확인
bool checkFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a == b) return true;
  else return false;
}