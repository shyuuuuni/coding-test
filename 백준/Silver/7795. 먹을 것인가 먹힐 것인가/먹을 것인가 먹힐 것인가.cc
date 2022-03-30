/*
Time : 2022.02.10 (10 mins)
Problem : BOJ7795 (https://www.acmicpc.net/problem/7795)
Algorithm Type : Sort
Outline :
A = {a1,a2,...,}
B = {b1,b2,...,}
와 같이 A,B가 주어진다.
A의 값이 B보다 큰 쌍이 몇 개나 있는지 구하는 프로그램을 작성하시오.
Method :

Example :
2
5 3
8 1 7 3 1
3 6 1
3 4
2 13 7
103 11 290 215
-------
7
1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define mt make_tuple
typedef long long ll;

bool compare(const int &a, const int &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--) {
    int n, m; // a길이,b길이
    cin >> n >> m;
    int ans = 0;
    int a[20000+5] = {};
    int b[20000+5] = {};
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    for(int i=0; i<n; i++) {
      int num = a[i];
      for(int j=0; j<m; j++) {
        if(num <= b[j]) break;
        ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}