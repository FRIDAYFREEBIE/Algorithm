#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b;
  cin >> a >> b;

  // 집합 A
  vector<int> aVector(a);
  for(int i = 0; i < a; i++){
    cin >> aVector[i];
  }

  sort(aVector.begin(), aVector.end());

  // 집합 B
  vector<int> bVector(b);
  for(int i = 0; i < b; i++){
    cin >> bVector[i];
  }

  sort(bVector.begin(), bVector.end());

  int numCnt = 0;
  vector<int> numvector;
  for(int i = 0; i < aVector.size(); i++){
    int start = 0, end = bVector.size() - 1, target = aVector[i], mid;
    bool isIn = false;

    while(start <= end){
      mid = (start + end) / 2;

      if(bVector[mid] < target){
        start = mid + 1;
      }
      else if(bVector[mid] > target){
        end = mid - 1;
      }
      else{
        isIn = true;
        break;
      }
    }

    if(!isIn){
      numCnt++;
      numvector.push_back(target);
    }
  }

  cout << numCnt << "\n";

  for(int & a : numvector){
    cout << a << " ";
  }


  return 0;
}