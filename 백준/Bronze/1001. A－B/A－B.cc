/*
Time : 2022.01.15 (1 min)
Problem : BOJ2438 (https://www.acmicpc.net/problem/2438)
Algorithm Type : Math
Outline :
정수 A,B가 주어졌을 때 A-B를 출력한다.
Method :
cin, cout을 이용하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a-b;
  return 0;
}