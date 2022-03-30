/*
Time : 2022.01.06 (17 min)
Problem : BOJ3273 (https://www.acmicpc.net/problem/3273)
Algorithm Type : Array
Outline :
양의 정수 배열 a1, a2, ..., an에서
ai + aj = x를 만족하는 (ai, aj) 쌍 (1<=i<j<=n) 의 수를 출력한다.
Method :

*/
  int arr[100000 + 1];
  int cnt[2000000 + 1];
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, val, ans=0;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cin >> x;
  for(int i=0; i<n; i++) {
    if(0 <= x-arr[i] && cnt[x-arr[i]])
      ans += cnt[x-arr[i]];
    cnt[arr[i]]++;
  }
  cout << ans;
  return 0;
}