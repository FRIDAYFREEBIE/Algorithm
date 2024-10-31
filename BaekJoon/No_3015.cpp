#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  stack<pair<int, int>> personStack; // <키, 나온 횟수>
  long long pairSum = 0;
  while(n--){
    int temp;
    cin >> temp;

    int cnt = 1;
    while(!personStack.empty() && personStack.top().first <= temp){
      pairSum += personStack.top().second;
      
      if(personStack.top().first == temp){
        cnt += personStack.top().second;
      }

      personStack.pop();
    }

    if(!personStack.empty()){
      pairSum++;
    }

    personStack.push({temp, cnt});
  }

  cout << pairSum << "\n";

  return 0;
}