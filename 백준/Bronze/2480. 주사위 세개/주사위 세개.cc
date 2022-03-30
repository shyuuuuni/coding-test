/*
Time : 2022.01.06 (1 min)
Problem : BOJ2480 (https://www.acmicpc.net/problem/2480)
Algorithm Type : Math
Outline :
입력으로 주사위 값 3개를 입력받는다.
만약 입력이 모두 같다면 10,000원+(같은 눈)×1,000원의 상금을 받는다.
만약 입력중 두개만 같다면  1,000원+(같은 눈)×100원의 상금을 받는다.
만약 입력이 모두 다르다면  (그 중 가장 큰 눈)×100원의 상금을 받는다.
상금을 계산하여 출력한다.
Method :
입력받은 값을 조건문을 이용하여 비교하여 케이스를 나눠서 처리한다.
세번째 케이스를 처리할때 최대값을 STL max_element 함수를 이용하여 포인터의 값을 얻는 *를 사용하여 처리한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int d[3];
  for(int i=0; i<3; i++) cin >> d[i];

  if(d[0] == d[1]) {
    if(d[1] == d[2]) cout << 10000+d[0]*1000;
    else cout << 1000+d[0]*100;
  } else {
    if(d[0] == d[2] || d[1] == d[2]) cout << 1000+d[2]*100;
    else cout << *max_element(d, d+3)*100;
  }
  return 0;
}