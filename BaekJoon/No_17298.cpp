#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> numVector(n);
  vector<int> result(n);
  stack<int> s;

  
  for (int i = 0; i < n; i++){
    cin >> numVector[i];
  }

  for (int i = n - 1; i >= 0; i--){
    while (!s.empty() && s.top() <= numVector[i]){
      s.pop();
    }

    if (s.empty()){
      result[i] = -1;
    }
    else{
      result[i] = s.top();
    }

    s.push(numVector[i]);
  }

  for (int i = 0; i < n; i++){
    cout << result[i] << " ";
  }

  cout << "\n";

  return 0;
}
