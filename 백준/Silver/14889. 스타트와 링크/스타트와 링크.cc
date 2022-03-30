/*
Time : 2022.03.07
Problem : BOJ14889 (https://www.acmicpc.net/problem/14889)
Algorithm Type : BackTracking
Outline :
축구를 하기 위해 N(짝수) 명이 모였다.
사람들을 N/2 명씩 스타트팀과 링크팀으로 나눈다.
사람별로 능력치를 조사하여 S(i,j)라는 값을 구할 수 있다.
S(i,j)는 i번째 사람과 j번째 사람이 같은 팀에 속했을 때 더해지는 능력치를 의미한다.
즉, i와 j가 같은 팀이라면 더해지는 전체 능력치는 S(i,j)+S(j,i)이다.
두 팀을 나눴을 때, 두 팀의 능력치 차이가 최소가 되도록 하려고 한다. 차이의 최솟값을 출력한다.
Method :

Example :
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
-------
0
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

int charToInt(char c) {
  if ('A' <= c && c <= 'Z')
    return (int)(c - 'A');
  else if ('a' <= c && c <= 'z')
    return (int)(c - 'a');
  else if ('0' <= c && c <= '9')
    return (int)(c - '0');
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int s[20+1][20+1] = {};
  cin >> n;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> s[i][j]; // S(i,j)
    }
  }
  vector<int> a(n,0);
  for (int i=n-1; n/2<=i; i--) {
    a[i] = 1;
  }

  int ans = 1<<30;

  do {
    int start_team = 0;
    int link_team = 0;

    /*
    0011
    01 스타터 23 링크
    s01 = 1, s10 = 4 -> 5
    s23 = 2, s32 = 2 -> 4
    */

    for (int i=0; i<n; i++) {
      // cout << i << "\n";
      if (a[i]) {  //  1이면 스타트팀
        for (int j=0; j<n; j++) {
          if (a[j]) {
            // cout << "starter + " << j <<  " " << s[i][j] << "\n";
            start_team += s[i][j];
          }
        }
      } else { // 0이면 링크팀
        for (int j=0; j<n; j++) {
          if (a[j]==0) {
            link_team += s[i][j];
          }
        }
      }
    }
    ans = min(ans, abs(start_team-link_team));
    // cout << start_team << " " << link_team << "\n";
  } while(next_permutation(a.begin(), a.end()));

  cout << ans;

  return 0;
}