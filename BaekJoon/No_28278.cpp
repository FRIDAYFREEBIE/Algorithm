#include <iostream>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  stack<int> s;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;

    if(num == 1){
      int temp;
      cin >> temp;
      s.push(temp);
    }
    else if(num == 2){
      if(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
      }
      else{
        cout << -1 << "\n";
      }
    }
    else if(num == 3){
      cout << s.size() << "\n";
    }
    else if(num == 4){
      if(s.empty()){
        cout << 1 << "\n";
      }
      else{
        cout << 0 << "\n";
      }
    }
    else if(num == 5){
      if(s.empty()){
        cout << -1 << "\n";
      }
      else{
        cout << s.top() << "\n";
      }
    }
  }

  return 0;
}