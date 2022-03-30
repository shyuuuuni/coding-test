/*
Time : 2022.01.06 (10 min)
Problem : BOJ9498 (https://www.acmicpc.net/problem/9498)
Algorithm Type : I/O
Outline :
시험점수 x를 입력받아서 x의 값이 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력한다.
Method :
조건문을 이용하여 처리한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  if (90 <= x && x <= 100) cout << "A";
  else if (80 <= x && x <= 89) cout << "B";
  else if (70 <= x && x <= 79) cout << "C";
  else if (60 <= x && x <= 69) cout << "D";
  else cout << "F";
  return 0;
}