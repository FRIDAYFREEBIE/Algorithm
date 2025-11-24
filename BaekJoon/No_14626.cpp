#include <iostream>

using namespace std;

string str;
int num[14];
int p, result;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;

  for(int i = 0; i < str.length(); i++){
    if(str[i] == '*'){
      num[i] = 0;
      p = i;
    }
    else{
      num[i] = str[i] - '0';
    }
  }

  // ISBN
  long sum = 0;
  for(int i = 0; i < 13; i++){
    if(i == p) continue;
    if((i + 1) % 2 == 1){
      sum += num[i];
    }
    else{ 
      sum += 3 * num[i];
    }
  }

  // °¡ÁßÄ¡
  int w = ((p + 1) % 2 == 1) ? 1 : 3;

  for(int i = 0; i <= 9; i++){
    if((sum + w * i) % 10 == 0){
      result = i;
      break;
    }
  }

  cout << result << "\n";

  // Debug
  // for(int i = 0; i < str.length(); i++){
  //   cout << num[i] << "\n";
  // }

  return 0;
}