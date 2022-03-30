/*
Time : 2022.02.16 (30 mins)
Problem : BOJ2293 (https://www.acmicpc.net/problem/2293)
Algorithm Type : DP
Outline :
N가지 동전의 가치가 주어진다.
해당 동전을 사용하여 K원을 만드려고 한다.
그 경우의 수를 출력한다.
Method :

Example :
3 10
1
2
5
-------
10
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

// 문자열을 구분자를 기준으로 나눠서 벡터에 저장
int splitStringByToken(vector<string> &v, string &s, const char &del) {
  if(s.empty()) return 0;
  istringstream ss(s);
  string token;

  v.clear();
  while (getline(ss, token, del)) {
    if(!token.empty()) v.push_back(token);
  }

  return v.size();
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;

  int a[100+5] = {};
  int d[10000+5] = {};
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }

  sort(a, a+n);

  d[0] = 1; // 0으로 두면 dp불가능. 0 = 0 이므로 1
  for (int i=1; i<=n; i++) {
    int val = a[i];
    for (int j=val; j<=k; j++) {
      d[j] += d[j-val]; // j원을 만드는 경우의 수 = (j-a[i])원을 만드는 경우의 수 + a[i]원
    }
  }

  cout << d[k];

  return 0;
}