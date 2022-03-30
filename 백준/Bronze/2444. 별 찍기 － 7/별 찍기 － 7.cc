/*
Time : 2022.01.06 (8 min)
Problem : BOJ2444 (https://www.acmicpc.net/problem/24434)
Algorithm Type : I/O
Outline :
Input이 5일때 다음과 같은 별을 찍는 알고리즘을 설계한다.
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
Method :
n번째 줄까지는 n-i개의 공백과 2*i-1개의 별을 찍는다.
그 다음 좁아지는 구간은 i=1일때를 n번째에 했다고 판단하고
i=2이라고 생각하고 i번째 줄에서 i-1개의 공백과 2(n-i)+1개의 별을 찍는다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<n-i; j++) cout << " ";
    for(int j=0; j<(2*i-1); j++) cout << "*";
    cout << "\n";
  }
  for(int i=2; i<=n; i++) {
    for(int j=0; j<i-1; j++) cout << " ";
    for(int j=0; j<2*(n-i)+1; j++) cout << "*";
    cout << "\n";
  }
  return 0;
}