#include <iostream>

using namespace std;

int n;
int tree[26][2]; // [i][0]은 왼쪽 쟈식 노드, [i][1]은 오른쪽 자식 노드

void preOrder(int now); // 전위 순회
void inOrder(int now); // 중위 순회
void postOrder(int now); // 후위 순회

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >>  n;

  for(int i = 0; i < n; i++){
    // 숫자로 변환해서 저장
    char nodeC, l, r;
    cin >> nodeC >> l >> r;
    int node = nodeC - 'A';

    if(l == '.') tree[node][0] = -1;
    else tree[node][0] = l - 'A';

    if(r == '.') tree[node][1] = -1;
    else tree[node][1] = r - 'A';
  }

  preOrder(0);
  cout << "\n";

  inOrder(0);
  cout << "\n";

  postOrder(0);
  cout << "\n";
  
  return 0;
}

void preOrder(int now){
  // 노드 없음
  if(now == -1) return;

  // 전위 순회
  cout << (char)(now + 'A'); // 현재 노드(루트)
  preOrder(tree[now][0]);    // 왼쪽 노드
  preOrder(tree[now][1]);    // 오른쪽 노드
}

void inOrder(int now){
  // 노드 없음
  if(now == -1) return;

  // 중위 순회
  inOrder(tree[now][0]);     // 왼쪽 노드
  cout << (char)(now + 'A'); // 현재 노드(루트)
  inOrder(tree[now][1]);     // 오른쪽 노드
}

void postOrder(int now){
  // 노드 없음
  if(now == -1) return;

  // 후위 순회
  postOrder(tree[now][0]);   // 왼쪽 노드
  postOrder(tree[now][1]);   // 오른쪽 노드
  cout << (char)(now + 'A'); // 현재 노드(루트)
}