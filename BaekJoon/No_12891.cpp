#include <iostream>

using namespace std;

int checkArr[4], currentArr[4], secretCnt, s, p, result;
string str;

void add(char ch);
void remove(char ch);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> s >> p >> str;

  for(int i = 0; i < 4; i++){
    cin >> checkArr[i];
    if(checkArr[i] == 0) secretCnt++;
  } 

  for(int i = 0; i < p; i++) add(str[i]);

  if(secretCnt == 4) result++;

  // i 끝 j 시작
  for(int i = p; i < s; i++){
    int j = i - p;

    add(str[i]);
    remove(str[j]);

    if(secretCnt == 4) result++;
  }

  cout << result << "\n";

  return 0;
}

void add(char ch){
  switch(ch){
  case 'A':
    currentArr[0]++;
    if(currentArr[0] == checkArr[0]) secretCnt++;
    break;

  case 'C':
    currentArr[1]++;
    if(currentArr[1] == checkArr[1]) secretCnt++;
    break;

  case 'G':
    currentArr[2]++;
    if(currentArr[2] == checkArr[2]) secretCnt++;
    break;

  case 'T':
    currentArr[3]++;
    if(currentArr[3] == checkArr[3]) secretCnt++;
    break;
  
  default:
    break;
  }
}

void remove(char ch){
  switch(ch){
  case 'A':
    if(currentArr[0] == checkArr[0]) secretCnt--;
    currentArr[0]--;
    break;

  case 'C':
    if(currentArr[1] == checkArr[1]) secretCnt--;
    currentArr[1]--;
    break;

  case 'G':
    if(currentArr[2] == checkArr[2]) secretCnt--;
    currentArr[2]--;
    break;

  case 'T':
    if(currentArr[3] == checkArr[3]) secretCnt--;
    currentArr[3]--;
    break;
  
  default:
    break;
  }
}