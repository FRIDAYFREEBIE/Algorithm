#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  queue<int> queue;

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    if(str == "push"){
      int temp;
      cin >> temp;

      queue.push(temp); 
    }
    else if(str == "pop"){
      if(!queue.empty()){
        cout << queue.front() << "\n";
        
        queue.pop();
      }
      else{
        cout << -1 << "\n";
      }
    }
    else if(str == "size"){
      if(queue.empty()){
        cout << 0 << "\n";
      }
      else{
        cout << queue.size() << "\n";
      }
    }
    else if(str == "empty"){
      if(queue.empty()){
        cout << 1 << "\n";
      }
      else{
        cout << 0 << "\n";
      }
    }
    else if(str == "front"){
      if(!queue.empty()){
        cout << queue.front() << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
    else if(str == "back"){
      if(!queue.empty()){
        cout << queue.back() << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
  }

  return 0;
}
