#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;  // 우선순위 큐

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n*n; i++){
    int temp;
    cin >> temp;

    pq.push(-(temp)); // 작은 순서대로 정렬하기 위함

    if(pq.size() > n) pq.pop(); // 메모리 용량 초과 방지를 위해 n개 이상의 원소가 들어가면 제거
  }

  cout << -(pq.top()) << "\n";
  
  return 0;
}