/*
Time : 2022.01.06 (1 min)
Problem : BOJ2753 (https://www.acmicpc.net/problem/2753)
Algorithm Type : I/O
Outline :
입력한 년도가 윤년인지 판단한다.
Method :
조건문을 이용하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  cin >> x;
  cout << (x%400==0 || (x%4==0 && x%100!=0));
  return 0;
}