/*
Time : 2022.02.09 (10 mins)
Problem : BOJ11726 (https://www.acmicpc.net/problem/11726)
Algorithm Type : Dynamic Programming
Outline :
2xN크기의 직사각형을 1x2, 2x1 타일로 채우는 경우의 수를 출력한다.
Method :
1번째 집부터 N번째 집까지 이전 집의 색과 다른 색을 칠한다는 규칙을 적용해서,
d[i][R/G/B] 는 i번째 집을 R/G/B로 칠했을 때 최소 비용이라고 정의한다.
그럼 d[i-1]이 R이면 G/B만, G면 R/B만, B면 R/G 인 케이스만 확인하면서
i번째 집을 R/G/B로 칠할 비용을 더하면 점화식을 유지할 수 있다.
Example :
9
-------
55
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
  int n;
  int d[1000+5] = {};
  cin >> n;
  d[1] = 1; // 2x1 하나로 채움
  d[2] = 2; // 1x2 or 2x1 두개로 채움
  for(int i=3; i<=1000; i++) {
    // 세로 한줄이 비면 d[i-1]의 경우의 수가 필요
    // 세로 두줄이 비면 d[i-2]의 경우의 수가 필요
    d[i] = (d[i-1] + d[i-2]) % 10007;
  }
  cout << d[n];
  return 0;
}