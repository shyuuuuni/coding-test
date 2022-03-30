/*
Time : 2022.01.06 (1 min)
Problem : BOJ10171 (https://www.acmicpc.net/problem/10171)
Algorithm Type : I/O
Outline :
고양이를 출력한다.
Method :
문자열 내의 '\' 문자 출력시 주의해서 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << "\\    /\\" << "\n";
  cout << " )  ( ')" << "\n";
  cout << "(  /  )" << "\n";
  cout << " \\(__)|" << "\n";
  return 0;
}