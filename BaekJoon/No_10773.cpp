#include <iostream>
#include <stack>

using namespace std;

int main(void){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  stack<int> s;

  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    if(temp == 0){
      s.pop();
    }
    else{
      s.push(temp);
    }
  }

  int result = 0;

  while(!s.empty()){
    result += s.top();

    s.pop();
  }

  cout << result << "\n";

  return 0;
}