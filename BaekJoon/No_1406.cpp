#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;

  list<char> l;

  for(int i = 0; i < str.size(); i++){
    l.push_back(str[i]);
  }

  int n;
  cin >> n;

  auto cursor = l.end();

  for(int i = 0; i < n; i ++){
    char c;
    cin >> c;

    if(c == 'L'){
      if (cursor != l.begin()) {
        cursor --;
      }
    }
    else if(c == 'D'){
      if (cursor != l.end()) {
        cursor ++;
      }
    }
    else if(c == 'B'){
      if(cursor != l.begin()){
        cursor = l.erase(prev(cursor));
      }
    }
    else if(c == 'P'){
      char temp;
      cin >> temp;

      l.insert(cursor, temp);
    }
  }

  for(auto c : l){
    cout << c;
  }

  return 0;
}