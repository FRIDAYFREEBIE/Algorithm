  #include <iostream>
  #include <queue>
  #include <algorithm>

  using namespace std;

  // 0 + 1 + 2 + 3 + 4 + 5 = 15
  // 0 + 1 + (2 * 3) + (4 * 5) = 27
  // 1. 정렬
  // 2. 0 제외 큰 수까리 묶음(단 음수는 음수끼리)

  int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 오름차순 우선순위 큐
    priority_queue<int> plus;
    // 내림차순 우선순위 큐
    priority_queue<int, vector<int>, greater<int>> minus;
    int one = 0, zero = 0;

    for(int i = 0; i < n; i++){
      int temp;
      cin >> temp;

      // 양수
      if(temp > 1) plus.push(temp);
      // 1
      else if(temp == 1) one++;
      // 0
      else if(temp == 0) zero++;
      // 음수
      else if(temp < 0) minus.push(temp);
    }

    int sum = 0;
    // 2개씩 묶음
    while(plus.size() > 1){
      int a = plus.top();
      plus.pop();
      int b = plus.top();
      plus.pop();
      
      sum += a * b;
    }
    
    // 큐에 남아있을 때
    if(!plus.empty()){
      sum += plus.top();
      plus.pop();
    }

    // 2개씩 묶음
    while(minus.size() > 1){
      int a = minus.top();
      minus.pop();
      int b = minus.top();
      minus.pop();

      sum += a * b;
    }
    
    // 큐에 남아있을 때
    if(!minus.empty()){
      // 0이 없을 때
      if(zero == 0){
        sum += minus.top();
        minus.pop();
      }
    }

    sum += one;
    cout << sum << "\n";

    return 0;
  }