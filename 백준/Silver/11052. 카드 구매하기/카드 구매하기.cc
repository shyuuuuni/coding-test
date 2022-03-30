/*
Time : 2022.02.15 (30 mins)
Problem : BOJ11052 (https://www.acmicpc.net/problem/11052)
Algorithm Type : DP
Outline :
N가지 카드팩의 가격이 주어진다.
카드팩에는 첫번째 카드팩에는 1개, 두번째 카드팩에는 2개, ... 이런식으로 카드가 들어있다.
N개의 카드를 구매하려고 할 때, 가격의 최댓값을 출력한다.
Method :

Example :
4
1 5 6 7
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

int n;
int a[1000+5];
int d[1000+5];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> a[i];
    d[i] = a[i];
  }

  for (int i=1; i<=n; i++) {
    for (int j=0; j<=i; j++) {
      d[i] = max(d[i], d[j]+d[i-j]);
    }
  }

  cout << d[n];

  return 0;
}