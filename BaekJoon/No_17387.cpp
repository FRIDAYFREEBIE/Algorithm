#include<iostream>

using namespace std;

pair<int, int> p1, p2, p3, p4;

int CCW(pair<int,int>a,pair<int,int>b,pair<int,int>c){
  long long temp = 1LL * (b.first-a.first) * (c.second-a.second) - 1LL * (b.second-a.second) * (c.first-a.first);
  
  if(temp > 0) return 1;
  if(temp < 0) return -1;

  return 0;
}

bool func(){
  int ab = CCW(p1,p2,p3) * CCW(p1,p2,p4);
  int cd = CCW(p3,p4,p1) * CCW(p3,p4,p2);

  if (ab == 0 && cd == 0)
    return max(p1.first, p2.first) >= min(p3.first, p4.first) && max(p3.first, p4.first) >= min(p1.first, p2.first)
    && max(p1.second, p2.second) >= min(p3.second, p4.second) && max(p3.second, p4.second) >= min(p1.second, p2.second);
  
  return ab <= 0 && cd <= 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

  if(func()) cout << 1 << "\n";
  else cout << 0 << "\n";

  return 0;
}
