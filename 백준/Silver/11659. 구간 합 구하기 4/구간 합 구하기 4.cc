/*
Time : 2022.02.09 (10 mins)
Problem : BOJ11726 (https://www.acmicpc.net/problem/11726)
Algorithm Type : Dynamic Programming
Outline :
N개의 수가 주어졌을 때, i번째 수부터 j번째 수까지의 합을 출력한다.
Method :
d[i]를 첫번째부터 i번째 수까지의 합으로 정의한다.
i~j 수의 합은 d[j] - d[i-1]로 정의할 수 있다.
Example :
5 3
5 4 3 2 1
1 3
2 4
5 5
-------
12
9
1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

bool compare(const string &a, const string &b) {
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
  int d[100000+5] = {};
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) {
    cin >> d[i];
    d[i] += d[i-1];
  }
  while(m--) {
    int i, j;
    cin >> i >> j;
    cout << d[j] - d[i-1] << "\n";
  }
  return 0;
}