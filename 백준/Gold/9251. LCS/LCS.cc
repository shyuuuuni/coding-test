/*
Time : 2022.02.16 (30 mins)
Problem : BOJ9251 (https://www.acmicpc.net/problem/9251)
Algorithm Type : DP
Outline :
두 문자열이 주어졌을 때 LCS(longest common subsequence)의 길이를 출력한다.
Method :
LCS알고리즘을 dp로 구현한다.
Example :
ACAYKP
CAPCAK
-------
4
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
  string a1, a2;
  cin >> a1 >> a2;
  int d[1000+5][1000+5] = {}; // d[a1size][a2size]
  for (int i=1; i<=(int)a1.size(); i++) {
    for (int j=1; j<=(int)a2.size(); j++) {
      if (a1[i-1] == a2[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      } else {
        d[i][j] =  max(d[i][j-1], d[i-1][j]);
      }
      // cout << d[i][j] << " ";
    }
    // cout << "\n";
  }


  cout << d[(int)a1.size()][(int)a2.size()];
  return 0;
}