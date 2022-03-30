/*
Time : 2022.01.06 (1 min)
Problem : BOJ10869 (https://www.acmicpc.net/problem/10869)
Algorithm Type : I/O
Outline :
자연수 A, B에 대해서 A+B, A-B, A*B, A/B(몫), A%B(나머지) 를 출력한다.
Method :
연산기호와 입출력 함수를 이용하여 문제를 해결한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a+b << "\n";
  cout << a-b << "\n";
  cout << a*b << "\n";
  cout << a/b << "\n";
  cout << a%b << "\n";
  return 0;
}