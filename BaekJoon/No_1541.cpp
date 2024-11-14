#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string str;

vector<int> numVector;
vector<char> operatorVector;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str;

  string temp = "";
  for(char ch : str){
    if(isdigit(ch)){
      temp += ch;
    }
    else{
      if(!temp.empty()){
        numVector.push_back(stoi(temp));
        temp.clear();
      }

      operatorVector.push_back(ch);
    }
  }

  // 마지막 숫자
  if(!temp.empty()){
    numVector.push_back(stoi(temp));
  }

  // +
  for(size_t i = 0; i < operatorVector.size();){
    if(operatorVector[i] == '+'){
      int temp = numVector[i] + numVector[i + 1];
      numVector[i] = temp;
      numVector.erase(numVector.begin() + i + 1);
      operatorVector.erase(operatorVector.begin() + i);
    }
    else{
      i++;
    }
  }

  // -
  int result = numVector[0];
  for(size_t i = 1; i < numVector.size(); i++){
    result -= numVector[i];
  }

  cout << result << "\n";

  return 0;
}