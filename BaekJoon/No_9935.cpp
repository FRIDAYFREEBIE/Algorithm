#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str, boom, result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str >> boom;

  // 문자열 사용
  for(auto ch : str){
    result += ch;

    // 폭발 문자열보다 길이가 긴가?
    if(result.size() >= boom.size()){
      // 폭발 문자열 발견 시 제거
      if(result.substr(result.size() - boom.size(), boom.size()) == boom) result.erase(result.size() - boom.size(), boom.size());
    }
  }

  if(result.empty()) cout << "FRULA" << "\n";
  else cout << result << "\n";

  return 0;
}

  // 스택 사용 -> 시간 초과
  // stack<char> s;
  // for(auto current : str){
  //   s.push(current);

  //   // 폭발 문자열보다 길이가 긴가?
  //   if(s.size() >= boom.size()){
  //     bool isBoom = true;
  //     string temp = "";

  //     for(int i = 0; i < boom.size(); i++){
  //       temp = s.top() + temp;
  //       s.pop();
  //     }

  //     if(temp != boom) isBoom = false;

  //     // 스택 복원
  //     if(!isBoom){
  //       for(auto ch : temp) s.push(ch);
  //     }
  //   }
    
  // }
  
  // if(s.empty()) cout << "FRULA" << "\n";
  // else{
  //   // 스택 역순
  //   string result = "";
  //   while (!s.empty()) {
  //     result = s.top() + result;
  //     s.pop();
  //   }

  //   cout << result << "\n";
  // }