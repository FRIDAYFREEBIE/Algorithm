#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m;

vector<long> tree; // 트리

long getMin(int start, int end); // 최소값 반환
void setTree(int i); // 트리 생성

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  int treeHeight = ceil(log2(n)); // 세그먼트 트리 높이
  int treeSize = pow(2, treeHeight + 1); // 세그먼트 트리 크기
  int startIndex = pow(2, treeHeight) - 1; // 리프 노드 시작 인덱스

  tree.resize(treeSize, LONG_MAX);
  
  // startIndex부터 n개 입력
  for(int i = startIndex + 1; i <= startIndex + n; i++) cin >> tree[i];
  
  // 트리 생성
  setTree(treeSize - 1);

  for(int i = 0; i < m; i++){
    int s, e;
    cin >> s >> e;

    cout << getMin(s + startIndex, e + startIndex) << "\n";
  }

  return 0;
}

long getMin(int start, int end){
  long minValue = LONG_MAX;

  while(start <= end){
    if(start % 2 == 1){
      minValue = min(minValue, tree[start]);
      start++;
    }

    if(end % 2 == 0){
      minValue = min(minValue, tree[end]);
      end--;
    }

    // 부모 노드로 이동
    start /= 2;
    end /= 2;
  }

  return minValue;
}

void setTree(int i){
  while(i != 1){
    // i의 부모 노드 i / 2
    tree[i / 2] = min(tree[i], tree[i - 1]);
    i -= 2;
  }
}