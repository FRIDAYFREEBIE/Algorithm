#include <iostream>
#include <vector>

using namespace std;


vector<int> arr;
void unionFunc(int a, int b);
int findFunc(int a);
bool checkFunc(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  arr.resize(n + 1);

  // 배열 초기화
  for(int i = 0; i <= n; i++) arr[i] = i;

  // 0: 합집합, 1: 집합 확인
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    // 파인드
    if(a == 1){
      if(checkFunc(b, c)) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
    else if(a == 0) unionFunc(b, c);
  }

  return 0;
}

// 유니온
void unionFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a != b) arr[b] = a;
}

// 파인드(대표 노드 반환)
int findFunc(int a){
  if(a == arr[a]) return a;
  else return arr[a] = findFunc(arr[a]);
}

// 같은 집합인지 확인
bool checkFunc(int a, int b){
  a = findFunc(a);
  b = findFunc(b);

  if(a == b) return true;
  else return false;
}