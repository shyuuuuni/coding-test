/*
Time : 2022.01.06 (1 min)
Problem : BOJ1000 (https://www.acmicpc.net/problem/1000)
Algorithm Type : I/O
Outline :
10보다 작은 자연수 A, B에 대해서 A+B를 출력한다.
Method :
정수 A,B의 크기가 충분히 작기 때문에 int형으로 A+B를 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a+b;
  return 0;
}