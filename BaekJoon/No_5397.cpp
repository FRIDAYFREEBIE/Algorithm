#include <iostream>
#include <list>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    list<char> l;
    auto cursor = l.begin(); // 리스트 반복자

    for(char ch : str){
      if(ch == '<'){
        if(cursor != l.begin()){
          --cursor;
        }
      }
      else if(ch == '>'){
        if(cursor != l.end()){
          ++cursor;
        }
      }
      else if(ch == '-'){
        if (cursor != l.begin()) {
          cursor = l.erase(--cursor);
        }
      }
      else{
        l.insert(cursor, ch);
      }
    }

    for(auto a : l){
      cout << a;
    }

    cout << "\n";
  }

  return 0;
}