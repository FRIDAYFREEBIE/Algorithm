#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  int arr[21] = {0, }; // 0: X 1: O
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    if(str == "add"){
      int temp;
      cin >> temp;

      if(arr[temp] == 0){
        arr[temp] = 1;
      }
    }
    else if(str == "remove"){
      int temp;
      cin >> temp;
      
      arr[temp] = 0;
    }
    else if(str == "check"){
      int temp;
      cin >> temp;

      if(arr[temp] != 0){
        cout << 1 << "\n";
      }
      else{
        cout << 0 << "\n";
      }
    }
    else if(str == "toggle"){
      int temp;
      cin >> temp;

      if(arr[temp] != 0){
        arr[temp] = 0;
      }
      else{
        arr[temp] = 1;
      }
    }
    else if(str == "all"){
      for(int i = 0; i < 21; i++){
        arr[i] = i;
      }
    }
    else if(str == "empty"){
      for(int i = 0; i < 21; i++){
        arr[i] = 0;
      }
    }
  }

  return 0;
}