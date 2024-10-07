#include <iostream>
#include <deque>

using namespace std;

int main(void){
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  deque<int> d;

  for(int i = 0; i < n; i ++){
    d.push_back(i + 1);
  }

  while (d.size() > 1) {
    d.pop_front();
    d.push_back(d.front());
    d.pop_front();
  }

  cout << d.front() << "\n";
  
  return 0;
}