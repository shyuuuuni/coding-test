/*
Time : 2022.02.16 (30 mins)
Problem : BOJ1788 (https://www.acmicpc.net/problem/1788)
Algorithm Type : DP
Outline :
피보나치 수열은 F(n) = F(n-1) + F(n-2) 인 수열이다.
이 값을 n이 음수일 경우에도 성립하도록 알아내려고 한다.
n이 주어졌을 때, F(n)을 구하는 프로그램을 작성한다.
Method :

Example :
-2
-------
-1
1
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

  ll pf[1000000+5] = {};
  ll nf[1000000+5] = {};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;


  /*
    f(0) = 0
    f(1) = 1
    f(2) = f(1) + f(2)

    f(1) = f(0) + f(-1)
    -> f(-1) = f(1) - f(0)
    ->       = 1 - 0 = 1

    f(0) = f(-1) + f(-2)
    -> f(-2) = f(0) - f(-1)
    ->       = 0 - 1 = -1

    f(n) = f(n-1) + f(n-2)
    f(n-2) = f(n) - f(n-1)

    f(-1) = f(-2) + f(-3)
    -> f(-3) = f(-1) - f(-2) 
  */

  pf[0] = 0;
  pf[1] = 1;
  for (int i=2; i<=1000000; i++) {
    pf[i] = (pf[i-1] + pf[i-2]) % 1000000000LL;
  }


  if (0 < n) {
    cout << 1 << "\n";
    cout << pf[n];
  } else if (n < 0) {
    cout << (abs(n)%2==0?-1:1) << "\n";
    cout << pf[-n];
  } else {
    cout << 0 << "\n" << 0;
  }

  return 0;
}