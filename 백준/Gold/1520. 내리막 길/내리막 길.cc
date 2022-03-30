/*
Time : 2022.02.19
Problem : BOJ1520 (https://www.acmicpc.net/problem/1520)
Algorithm Type : DP
Outline :
MxN 크기의 지도에 높이가 적혀있다.
지도의 왼쪽 위에서 오른쪽 아래로 이동하고 싶을 때, 높이가 높은 곳에서 낮은 곳으로만 이동하고 싶다고 한다.
가능한 경우의 수를 출력한다.
Method :

Example :
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10
-------
3
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

int a[1024+5][1024+5] = {};
int d[1024+5][1024+5] = {};
int m, n; // 세로, 가로

ll dfs(int x, int y) {
  if (x == m && y == n) return 1;
  else if (outOfBound1(x, y, m, n)) return 0;
  else {
    ll ret = 0;
    for (int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (outOfBound1(xx,yy,m,n)) continue;
      else if (a[x][y] <= a[xx][yy]) continue;
      else if (d[xx][yy] == -1) continue;
      else if (d[xx][yy]) ret += d[xx][yy];
      else {
        ret += dfs(xx,yy);
      }
    }
    if (ret == 0) d[x][y] = -1;
    else d[x][y] = ret;
    return ret;
  }
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> m >> n;
  for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++) {
       cin >> a[i][j];
    }
  }
  
  cout << dfs(1,1);

  return 0;
}