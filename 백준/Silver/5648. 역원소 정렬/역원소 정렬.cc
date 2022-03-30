/*
Time : 2022.02.08 (10 mins)
Problem : BOJ5648 (https://www.acmicpc.net/problem/5648)
Algorithm Type : Sort
Outline :
N개의 수가 주어졌을 때, 해당 수를 뒤집은 수열을 오름차순으로 정렬하여 출력한다.
Method :
N개의 수를 String으로 입력받고, 뒤집는 연산을 한 뒤 배열에 넣어서
해당 배열을 정렬하여 출력한다.
Example :
10 5 2233
1601 90100 13009 802
50000000
301 7654321
210
-------
5
5
12
103
109
208
1061
3322
90031
1234567
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

bool compare(const pii &a, const pii &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  if(a.Y == b.Y) return a.X <= b.X;
  return a.Y <= b.Y;
}

int n;
ll arr[1000000+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll num = stoll(s);
    arr[i] = num;
  }
  sort(arr, arr+n);
  for(int i=0; i<n; i++) cout << arr[i] << "\n";
  return 0;
}