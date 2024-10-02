#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  queue<int> q;

  for(int i = 0; i < n; i++){
    string str;

    cin >> str;

    if(str == "push"){
      int temp;
      cin >> temp;
      q.push(temp);
    }
    else if(str == "pop"){
      if(!q.empty()){
        cout << q.front() << "\n";
        q.pop();
      }
      else cout << "-1" << "\n";
    }
    else if(str =="size") cout << q.size() << "\n";
    else if(str =="empty"){
      if(q.empty()) cout << "1" << "\n";
      else cout << "0" << "\n";
    }
    else if(str =="front"){
      if (!q.empty()) cout << q.front() << "\n";
      else cout << "-1" << "\n";
    }
    else if(str =="back"){
      if (!q.empty()) cout << q.back() << "\n";
      else cout << "-1" << "\n";
    }
  }
}