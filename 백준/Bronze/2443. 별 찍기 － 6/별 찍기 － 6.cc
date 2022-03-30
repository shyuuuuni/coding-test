/*
Time : 2022.01.06 (2 min)
Problem : BOJ2443 (https://www.acmicpc.net/problem/2443)
Algorithm Type : I/O
Outline :
첫째줄에 별 2*N-1개, 둘째줄에 2*N-3개, ... N번째 줄에 1개를 찍는다.
이때 별은 가운데 기준 대칭이다.
Method :
i번째 줄에는 공백을 i-1개 입력하고, 별을 2*N - (2*i-1) 개 찍는다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<i-1; j++) cout << " ";
    for(int j=0; j<2*n - (2*i-1); j++) cout << "*";
    cout << "\n";
  }
  return 0;
}