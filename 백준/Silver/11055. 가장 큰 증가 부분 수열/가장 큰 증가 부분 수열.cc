/*
Time : 2022.02.10 (10 mins)
Problem : BOJ11055 (https://www.acmicpc.net/problem/11055)
Algorithm Type : Dynamic Programming
Outline :
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
Method :
DP를 이용한 O(N^2)풀이로 해결하였다.
dp[i]를 i번째 원소 arr[i]를 마지막으로 하는 부분수열의 최대 합으로 정의한다.
0 <= j < i 인 j에 대해서, arr[j] < arr[i]인 j가 존재한다면
arr[j], ..., arr[i] 로 하는 부분수열이 존재하므로 갱신한다.
따라서 위 범위에서 dp[i] = max(dp[i], dp[j]+arr[i]) 점화식으로 갱신하면
모든 i에 대해서 최대 합을 구할 수 있다.
Example :
10
1 100 2 50 60 3 5 6 7 8
-------
113
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

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
  cin >> n;
  int arr[1000+5] = {};
  int dp[1000+5] = {}; // dp[i] : i번째 원소를 포함한 증가하는 부분수열의 최대 합
  for(int i=0; i<n; i++) cin >> arr[i];
  for(int i=0; i<n; i++) {
    dp[i] = arr[i];
    for(int j=0; j<i; j++) {
      if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+arr[i]);
    }
  }
  cout << *max_element(dp,dp+n);
  return 0;
}