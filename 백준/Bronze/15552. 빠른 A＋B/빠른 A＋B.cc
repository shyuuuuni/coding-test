/*
Time : 2022.01.06 (3 min)
Problem : BOJ15552 (https://www.acmicpc.net/problem/15552)
Algorithm Type : I/O
Outline :
1~1000 사이의 자연수 A,B가 최대 1,000,000번 주어진다.
A+B를 한줄에 하나씩 출력한다.
Method :
빠른 입출력을 위해 ios::sync_with_stdio(false)와 cin.tie(NULL)을 추가한다.
빠른 코딩을 위해 false와 NULL을 0으로 코딩하였다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc, n = 0;
  cin >> tc;
  while(n < tc) {
    int a, b;
    cin >> a >> b;
    cout << a+b << "\n";
    n++;
  }
  return 0;
}