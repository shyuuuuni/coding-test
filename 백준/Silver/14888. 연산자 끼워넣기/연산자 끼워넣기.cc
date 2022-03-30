/*
Time : 2022.03.07
Problem : BOJ14888 (https://www.acmicpc.net/problem/14888)
Algorithm Type : Simulation
Outline :
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다.
또한 수 사이에 끼워넣을 수 있는 연산자가 N-1개 주어진다.
식의 계산은 연산자의 우선순위를 무시하고 앞에서부터 진행한다.
수와 연산자가 주어졌을 때, 주어진 값으로 만들 수 있는 최대와 최소 연산 결과를 출력한다.
Method :
Example :
2
5 6
0 0 1 0
-------
30
30
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

int n; // 최대 11
int a[12] = {}; // 수열, zero-indexed
int oper[4] = {}; // +,-,*,/ 의 개수
int mx = - (1<<30);
int mn = 1<<30;


void solve(int x, int s) {
  if (n-1 <= x) {
    mx = max(mx, s);
    mn = min(mn, s);
    return;
  }
  for (int i=0; i<4; i++) {
    if (oper[i] == 0) continue;
    oper[i]--;
    switch (i)
    {
    case 0:
      solve(x+1, s+a[x+1]);
      break;
    case 1:
      solve(x+1, s-a[x+1]);
      break;
    case 2:
      solve(x+1, s*a[x+1]);
      break;
    case 3:
      solve(x+1, s/a[x+1]);
      break;
    default:
      break;
    }
    oper[i]++;
  }
} 

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<4; i++) {
    cin >> oper[i];
  }

  solve(0,a[0]);
  cout << mx << "\n" << mn;

  return 0;
}