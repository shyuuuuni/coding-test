/*
Time : 2022.01.17 (1 min)
Problem : BOJ1330 (https://www.acmicpc.net/problem/1330)
Algorithm Type : Math
Outline :
두 수 A,B가 주어졌을 때 A와 B의 크기를 비교한다.
Method :
cin, cout을 이용하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  if(a > b) cout << ">";
  else if(a < b) cout << "<";
  else cout << "==";
  return 0;
}