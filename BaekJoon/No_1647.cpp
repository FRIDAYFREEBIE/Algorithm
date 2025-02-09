#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans, cnt, finalCost;
vector<tuple<int, int, int>> v; // 유지비용, 집 , 집
vector<int> p; // 마을 집합을 표시(유니온 파인드)

int find(int a);
bool isGroup(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(m);
  p.resize(n + 1, -1);

  for(int i = 0; i < m; i++){
    // a와 b를 연결하는 길의 유지비는 c 
    int a, b, c;
    cin >> a >> b >> c;
    v[i] = {c, a, b};
  }

  // 길 유지비순으로 정렬
  sort(v.begin(), v.end());

  // 마을을 최소 스패닝 트리로 만들기
  for(int i = 0; i < m; i++){
    int a, b, c;
    tie(c, a, b) = v[i];
    
    // a와 b가 같은 집합에 속해있다면 건너뛰기
    if(isGroup(a, b)) continue;

    finalCost = c;
    cnt++;
    ans += c;
    
    // 최소 스패닝 트리가 완성됐다면 정지
    if(cnt == n - 1) break;
  }

  // 제일 비싼 마지막 길을 제거
  ans -= finalCost;

  cout << ans << "\n";

  return 0;
}

// a가 속한 집합의 대표 값을 반환
int find(int a){
  if(p[a] < 0) return a;
  else return p[a] = find(p[a]);
}

// 같은 집합이 맞다면 true 반환, 아니라면 같은 집합에 합치고 false 반환
bool isGroup(int a, int b){
  a = find(a);
  b = find(b);

  if(a == b) return true;

  if(p[a] > p[b]) swap(a, b); // 더 작은 집합이 큰 집합에 병합
  p[a] += p[b];
  p[b] = a;

  return false;
}