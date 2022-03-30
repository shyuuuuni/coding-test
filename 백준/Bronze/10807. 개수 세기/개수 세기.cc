/*
Time : 2022.01.06 (17 min)
Problem : BOJ10807 (https://www.acmicpc.net/problem/10807)
Algorithm Type : Array
Outline :
N개의 정수와 정수 v가 주어진다.
N개의 정수 내에 v가 몇개 들어있는지 출력한다.
Method :
입력 순서가 N->정수들->v 순서이므로 입력과 동시에 처리할 수 없다.
먼저 입력을 받은 후, 한번씩 순회하면서 v의 개수를 카운트하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, v, ans=0, arr[100+10]={0};
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  cin >> v;
  for(int i=0; i<n; i++) {
    if(arr[i] == v) ans++;
  }
  cout << ans;
  return 0;
}