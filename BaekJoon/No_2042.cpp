#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;

vector<long> tree; // 트리

long getSum(int start, int end); // 구간 합 반환
void changeValue(int index, long value); // 수 변경
void setTree(int i); // 트리 생성

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  int treeHeight = 0; // 세그먼트 트리 높이
  int length = n; // 데이터 갯수를 복사하고 나눠가면서 높이를 계산

  while(length != 0){
    length /= 2;
    treeHeight++;
  }

  int treeSize = int(pow(2, treeHeight + 1)); // 세그먼트 트리의 전체 크기 계산
  int startIndex = treeSize / 2 - 1; // 리프 노드 시작 인덱스 계산
  tree.resize(treeSize + 1);

  // 리프 노드 입력
  for(int i = startIndex + 1; i <= startIndex + n; i++) cin >> tree[i];

  setTree(treeSize - 1);

  for(int i = 0; i < m + k; i++){
    long a, s, e;
    cin >> a >> s >> e;
    
    // 값 변경 연산
    if(a == 1) changeValue(startIndex + s, e);
    // 구간 합 연산
    else if(a == 2){
      s += startIndex;
      e += startIndex;
      cout << getSum(s, e) << "\n";
    }
  }

  return 0;
}

long getSum(int start, int end){
  long partSum = 0;

  while(start <= end){
    // 홀수
    if(start % 2 == 1){
      partSum += tree[start];
      start++;
    }
    
    // 짝수
    if(end % 2 == 0){
      partSum += tree[end];
      end--;
    }

    // 부모 노드로 이동
    start /= 2;
    end /= 2;
  }

  return partSum;
}

void changeValue(int index, long value){
  long temp = value - tree[index]; // 값 변화량

  while(index > 0){
    // 값 변화량 적용용
    tree[index] = tree[index] + temp;
    index /= 2;
  }
}

void setTree(int i){
  while(i != 1){
    tree[i / 2] += tree[i];
    i--;
  }
}