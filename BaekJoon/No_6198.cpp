#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  long long sum = 0;
  stack<int> rooftopStack;
  while(n--){
    int temp;
    cin >> temp;

    while(!rooftopStack.empty() && rooftopStack.top() <= temp){
      rooftopStack.pop();
    }

    sum += rooftopStack.size();

    rooftopStack.push(temp);
  }

  cout << sum << "\n";

  return 0;
}