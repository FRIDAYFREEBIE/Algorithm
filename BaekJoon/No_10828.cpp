#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  stack<int> s;

  for(int i = 0; i < n; i++){
    string str;

    cin >> str;

    if(str == "push"){
      int n;
      cin >> n;

      s.push(n);
    }
    else if(str == "pop"){
      if(s.empty()){
        cout << "-1" << "\n";
      }
      else{
        cout << s.top() << "\n";

        s.pop();
      }
    }
    else if(str == "size"){
      cout << s.size() << "\n";
    }
    else if(str == "empty"){
      if(s.empty()){
        cout << "1" << "\n"; 
      }
      else{
        cout << "0" << "\n"; 
      }
    }
    else if(str == "top"){
      if(s.empty()){
        cout << "-1" << "\n";
      }
      else{
        cout << s.top() << "\n";
      }
    }
  }

  return 0;
}