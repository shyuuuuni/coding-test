/*
Time : 2022.02.17
Problem : BOJ9657 (https://www.acmicpc.net/problem/9657)
Algorithm Type : DP
Outline :
N개의 돌을 가져가는 게임을 한다.
돌은 한번에 1개,3개,4개씩 가져갈 수 있고,
상근(SK)이가 선공, 선영(SY)이가 후공을 한다.
게임을 정확하게 했을 때 이기는 사람을 출력한다.
Method :
d[i]를 i번째 돌을 가져가는 사람으로 정의한다.
0이면 상근이, 1이면 선영이로 정의할 수 있다.
처음에 상근이가 선공이므로, 1,3,4번째 돌은 상근이가 가져갈 수 있고,
2번째 돌은 선영이만 가져갈 수 있다.
이후 i=5부터는 i-1, i-3, i-4를 체크해서 만약 모두 상근이만 도착할 수 있다면, i번째는 선영이만 도착할 수 있다.
만약 하나라도 선영이가 도착할 수 있다면, 상근이가 먼저 출발하므로 선영이를 해당 위치에 도착시킬 수 있으므로
i번째는 상근이가 도착할 것이다.
Example :
6
-------
SK
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


int a[1024+5][1024+5] = {};
int d[1024+5][1024+5] = {}; // d[i][j] : i번째 row에서 1번째부터 j번째 원소까지의 합

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int d[1000+5] = {};
  int jump[3] = {-1,-3,-4};
  d[1] = d[3] = d[4] = 0;
  d[2] = 1;
  for (int i=5; i<=1000; i++) {
    int flag = 1;
    for (int j=0; j<3; j++) {
      if (d[i+jump[j]] == 1) {
        flag = 0;
        break;
      }
    }
    d[i] = flag;
  }
  if(d[n]) cout << "CY";
  else cout << "SK";
  return 0;
}