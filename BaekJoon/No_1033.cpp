#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// 문제 정리
// 필요한 재료의 질량을 모두 더한 값이 최소가 되어야 함
// 재료의 양은 정수이고 질량은 0보다 커야함
// a b p q: a번 재료의 질량을 b번 재료로 나눈 값이 p / q

// 문제 풀이
// N - 1개의 비율로 N개 재료의 전체 비율을 알아낼 수 있음
// -> 사이클이 없는 트리 구조
// 임의의 노드에서 DFS를 수행하며 순회
// DFS 과정에서 유클리드 호제법을 사용해 비율들의 최소 공배수와 최대 공약수를 구해 최소 질량을 구함

vector<tuple<int, int, int>> graph[10]; // 그래프
bool visit[10]; // DFS 방문 체크 배열
long lcm, arr[10]; // 최소 공배수

// 유클리드 호제법 재귀 함수
long func(long a, long b);
// DFS
void DFS(int index);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  lcm = 1;
  for(int i = 0; i < n - 1; i++){
    int a, b, q, p;
    cin >> a >> b >> p >> q;

    graph[a].push_back(make_tuple(b, p, q));
    graph[b].push_back(make_tuple(a, q, p));

    // 최소 공배수는 두 수의 곱을 최대 공약수로 나눈 것과 같다
    lcm *= (p * q / func(p, q));
  }

  arr[0] = lcm;
  DFS(0);
  long result = arr[0];

  // 갱신된 배열 값의 최대 공약수 계산
  for(int i = 1; i < n; i++) result = func(result, arr[i]);

  for(int i = 0; i < n; i++) cout << arr[i] / result << " ";

  cout << "\n";

  return 0;
}

// 유클리드 호제법 재귀 함수
long func(long a, long b){
  if(b == 0) return a;
  else return func(b, a % b);
}

// DFS
void DFS(int index){
  visit[index] = true;

  for(tuple<int, int, int> i : graph[index]){
    int next = get<0>(i);

    if(visit[next]) continue;

    arr[next] = arr[index] * get<2>(i) / get<1>(i);
    DFS(next);
  }
}