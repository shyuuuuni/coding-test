/*
Time : 2022.02.07 (10 mins)
Problem : BOJ11652 (https://www.acmicpc.net/problem/11652)
Algorithm Type : Sort
Outline :
-2^62 ~ 2^62 사이의 숫자가 적혀있는 숫자 카드 N장 중에서
가장 많이 등장한 정수를 출력한다.
Method :

Example :
5
1
2
1
2
1
=====
1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long
// bool compare(const pii &a, const pii &b) {
//   // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
//   // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
//   // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
//   // 래퍼런스 사용하는게 좋음
// }

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, mx=0, mxn, prv, cnt;
  ll arr[100000+1] = {};
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i]; // n
  sort(arr, arr+n); // nlogn
  prv = arr[0];
  cnt = 1;
  for(int i=1; i<n; i++) {
    if(prv == arr[i]) cnt++;
    else {
      if(mx < cnt) {
        mx = cnt;
        mxn = prv;
      }
      prv = arr[i];
      cnt = 1;
    }
  }
  if(mx < cnt) {
    mx = cnt;
    mxn = prv;
  }
  cout << mxn;
  return 0;
}