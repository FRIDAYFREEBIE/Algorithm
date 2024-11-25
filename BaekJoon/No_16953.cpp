#include <iostream>
#include <queue>

using namespace std;

// A를 B로 바꾸는 연산의 최소 횟수
// 1. * 2
// 2. 맨 뒤에 1 붙이기

long long a, b;

void BFS();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  BFS();

  return 0;
}

void BFS(){
  queue<pair<long long, long long>> q; // <현재 숫자, 연산 횟수>
  q.push({a, 0});

  while(!q.empty()){
    pair<long long, long long>  current = q.front();
    q.pop();

    // b에 도착
    if(current.first == b){
      cout << current.second + 1 << "\n";
      return;
    }

    if(current.first * 2 <= b) q.push({current.first * 2, current.second + 1});
    if(current.first * 10 + 1 <= b) q.push({current.first * 10 + 1, current.second + 1});
  }

  cout << -1 << "\n";
}