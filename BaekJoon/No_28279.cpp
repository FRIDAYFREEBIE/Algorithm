#include <iostream>
#include <deque>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  deque<int> d;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;

    // 앞에 넣는다
    if(num == 1){
      int temp;
      cin >> temp;
      d.push_front(temp);
    }
    // 뒤에 넣는다
    else if(num == 2){
      int temp;
      cin >> temp;
      d.push_back(temp);
    }
    // 맨 앞 정수 출력 (없다면 -1)
    else if(num == 3){
      if(!d.empty()){
        cout << d.front() << "\n";
        d.pop_front();
      }
      else{
        cout << -1 << "\n";
      }
    }
    // 맨 뒤 정수 출력
    else if(num == 4){
     if(!d.empty()){
        cout << d.back() << "\n";
        d.pop_back();
      }
      else{
        cout << -1 << "\n";
      }
    }
    // 정수 갯수 출력
    else if(num == 5){
      cout << d.size() << "\n";
    }
    // 비어있으면 1 아니면 0
    else if(num == 6){
     if(!d.empty()){
        cout << 0 << "\n";
      }
      else{
        cout << 1 << "\n";
      }
    }
    // 맨 앞 정수 출력 (비어있으면 -1)
    else if(num == 7){
      if(!d.empty()){
        cout << d.front() << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
    // 맨 뒤 정수 출력 (비어있으면 -1)
    else if(num == 8){
      if(!d.empty()){
        cout << d.back() << "\n";
      }
      else{
        cout << -1 << "\n";
      }
    }
  }
  return 0;
}