#include <iostream>
#include <vector>

using namespace std;

int n , m;
vector<int> v;

void unionFunc(int a, int b);
int findFunc(int a);

// 사이클이 생기는 조건: x와 y의 대표 노드가 같으면 사이클 생성
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n);

  for(int i = 0; i < n; i++) v[i] = i;

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;

    // 사이클 검사
    if(findFunc(y) == findFunc(x)){
      cout << i + 1 << "\n";
      return 0;
    }
    
    unionFunc(x, y);
  }

  cout << 0 << "\n";

  return 0;
}

// b의 대표 노드를 a로 업데이트
void unionFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a != b) v[b] = a;
}

// a의 대표 노드를 재귀적으로 반환
int findFunc(int a){
  if(a == v[a]) return a;
  else return v[a] = findFunc(v[a]);
}