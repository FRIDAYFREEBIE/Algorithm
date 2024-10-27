#include <iostream>
#include<string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  while(getline(cin, str)){
    int big = 0, small = 0, num = 0, space = 0;

    for(int i=0; i<str.size(); i++){
      if(str[i] >= 'a' && str[i] <= 'z'){
        small++;
      }
		  else if(str[i] >= 'A' && str[i] <= 'Z'){
        big++;
      }
		  else if(str[i] >= '0' && str[i] <= '9'){
        num++;
      }
		  else{
        space++;
      }
    }

    cout << small << " " << big << " " << num << " " << space << "\n";
  }

  return 0;
}