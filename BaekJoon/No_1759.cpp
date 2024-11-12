#include <iostream>
#include <algorithm>

using namespace std;

char word[16];
char arr[16];
bool isUsed[16];

int l, c;

// 모음 판별 함수
bool isVowel(char ch){
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void func(int k, int vowelCnt, int consonantCnt, char prev){
  if(k == l){
    // 모음 최소 1개, 자음 최소 2개
    if(vowelCnt >= 1 && consonantCnt >= 2){
      for(int i = 0; i < l; i++){
        cout << arr[i];
      }
      cout << "\n";
    }

    return;
  }

  for(int i = 0; i < c; i++){
    if(!isUsed[i]){
      // 사전순
      if(prev < word[i]){
        arr[k] = word[i];
        isUsed[i] = true;

        // 모음이라면
        if(isVowel(arr[k])){
          func(k + 1, vowelCnt + 1, consonantCnt, word[i]);
        }
        else{
          func(k + 1, vowelCnt, consonantCnt + 1, word[i]);
        }

        isUsed[i] = false;
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> l >> c;

  for(int i = 0; i < c; i++){
    cin >> word[i];
  }

  sort(word, word + c);

  func(0, 0, 0, 'a' - 1);

  return 0;
}