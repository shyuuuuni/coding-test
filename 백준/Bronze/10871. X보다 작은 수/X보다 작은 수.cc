/*
Time : 2022.01.06 (10 min)
Problem : BOJ10871 (https://www.acmicpc.net/problem/10871)
Algorithm Type : I/O
Outline :
정수 N개로 이루어진 수열 A에서 정수 X보다 작은 수를 입력 순서대로 출력하는 문제 
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, a;
  cin >> n >> x;
  for(int i=0; i<n; i++) {
    cin >> a;
    if(a < x) cout << a << " ";
  }
  return 0;
}