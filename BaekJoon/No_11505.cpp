#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, m, k, mod = 1000000007;

vector<long long> tree;

long long getMulti(int start, int end); // 구간 곱 반환
void changeValue(int index, long value); // 수 변경
void setTree(int startIndex); // 트리 생성

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  int treeHeight = ceil(log2(n)); // 세그먼트 트리 높이
  int treeSize = pow(2, treeHeight + 1); // 세그먼트 트리 크기
  int startIndex = pow(2, treeHeight) - 1; // 리프노드 시작 인덱스

  tree.resize(treeSize + 1, 1);

  for(int i = startIndex + 1; i <= startIndex + n; i++) cin >> tree[i];

  setTree(startIndex);

  for(int i = 0; i < k + m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    // 바꾸기
    if(a == 1) changeValue(startIndex + b, c);

    // 구간 곱
    if(a == 2){
      cout << getMulti(startIndex + b, startIndex + c) << "\n";
    }
  }

  return 0;
}

long long getMulti(int start, int end){
  long long partMulti = 1;

  while(start <= end){
    if(start % 2 == 1){
      partMulti = (partMulti * tree[start]) % mod;
      start++;
    }

    if(end % 2 == 0){
      partMulti = (partMulti * tree[end]) % mod;
      end--;
    }

    start /= 2;
    end /= 2;
  }

  return partMulti;
}

void changeValue(int index, long value){
  tree[index] = value;

  while(index > 1){
    index /= 2;
    tree[index] =(tree[index * 2] * tree[index * 2 + 1]) % mod;
  }
}

void setTree(int startNode){
  for(int i = startNode - 1; i >= 1; i--) tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % mod;
}