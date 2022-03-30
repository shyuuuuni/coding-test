/*
Time : 2022.01.06 (1 min)
Problem : BOJ2576 (https://www.acmicpc.net/problem/2576)
Algorithm Type : Math
Outline :
7개의 100 이하의 자연수 중 홀수인 자연수의 총 합과 최솟값을 출력한다.
Method :
반복문을 이용하여 입력받으면서 홀수일때만 더해주면서 최소인지 비교한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, sum = 0, mini = 101;
  for(int i=0; i<7; i++) {
    cin >> x;
    if(x%2==1) {
      sum += x;
      if(x<mini) mini=x;
    }
  }
  if(sum) cout << sum << "\n" << mini;
  else cout << "-1";
  return 0;
}