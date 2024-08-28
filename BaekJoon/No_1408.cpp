#include <iostream>

using namespace std;

// 시간 구조체
struct Time
{
  int hour, minute, second;
};

int main()
{
  Time current, start, remain;

  scanf("%d:%d:%d", &current.hour, &current.minute, &current.second);
  scanf("%d:%d:%d", &start.hour, &start.minute, &start.second);

  Time t;

  t.second = start.second - current.second;
  t.minute = start.minute - current.minute;
  t.hour = start.hour - current.hour;

  // 시간이 음수일 경우
  if(t.second < 0)
  {
    t.second = 60 + t.second;
    t.minute--;
  }

  if(t.minute < 0)
  {
    t.minute = 60 + t.minute;
    t.hour--;
  }

  if(t.hour < 0)
    t.hour = 24 + t.hour;

  printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}