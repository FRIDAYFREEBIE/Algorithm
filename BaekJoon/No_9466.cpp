#include <iostream>
#include <stack>

using namespace std;

int student[1000001];
int visit[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    // 초기화
    for(int i = 0; i < n; i++){
      student[i] = 0;
      visit[i] = 0;
    }

    // 입력
    for(int i = 0; i < n; i++){
      cin >> student[i];
    }
  
    visit[0] = 1;
    stack<int> s;
    s.push(0);

    
  }

  return 0;
}