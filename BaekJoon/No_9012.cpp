#include <iostream>
#include <stack>
#include <string>

using namespace std;

string check(string str);

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;


  for(int i = 0; i < n; i++){
    string str;

    cin >> str;
    cout << check(str) << "\n";
  }

  return 0;
}

string check(string str){
  stack<char> s;

  for(int i = 0; i < str.size(); i++){
    if(str[i] == '('){
      s.push(str[i]);
    }
    else{
      if(s.empty()){
        return "NO";
      }
      else{
        s.pop();
      }
    }
  }

  if(s.empty()){
    return "YES";
  }
  else{
    return "NO";
  }
}