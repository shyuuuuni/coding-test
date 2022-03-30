/*
Time : 2022.02.07 (10 mins)
Problem : BOJ11650 (https://www.acmicpc.net/problem/11650)
Algorithm Type : Sort
Outline :
N개의 2차원 좌표가 (x,y) 순으로 주어진다.
좌표를 x좌표가 증가하는 순으로 -> y좌표가 증가하는 순으로 정렬하여 출력한다.
Method :
STL sort에 compare 함수로 조건을 추가하여 해결하였다.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))

bool compare(const pii a, const pii b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  if(a.X == b.X) return a.Y <= b.Y;
  return a.X <= b.X;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  pii arr[100000+1] = {};
  for(int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    arr[i] = mp(x,y);
  }
  sort(arr, arr+n, compare);
  for(int i=0; i<n; i++) cout << arr[i].first << " " << arr[i].second << "\n";
  return 0;
}