#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int cnt = 0;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    stack<char> s;
    for(char c : str){
      if(s.empty()){
        s.push(c);
      }
      else if(s.top() == c){
        s.pop();
      }
      else{
        s.push(c);
      }
    }

    if(s.empty()){
      cnt++;
    }
  }

  cout << cnt << "\n";

  return 0;
}