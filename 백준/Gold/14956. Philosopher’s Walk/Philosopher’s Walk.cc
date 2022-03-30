/*
Time : 2022.02.19
Problem : BOJ14956 (https://www.acmicpc.net/problem/14956)
Algorithm Type : Recursion
Outline :
2^k x 2^k 크기의 미로가 있다.
해당 미로는 1사분면에서, 왼쪽 아래의 점을 (1,1)로 하는 좌표로 표현할 수 있으며
입구는 항상 (1,1), 출구는 항상 (N,1) 이다. 좌표 : (가로, 세로)
만약 k=1일 경우 앞으로 한칸 이동한 뒤, 시계 방향으로 90도 회전한다.
K가 1보다 클 경우 4개의 sub-k로 나누어서, 왼쪽 아래는 시계 방향으로 90도 회전한 모양을, 오른쪽 아래는 반시계 방향으로 90도 회전한 모양으로
프렉탈 스타일의 모습을 가진다.
미로의 한 변의 길이 n과 걸음수 m이 주어졌을 때, 해당 위치의 좌표를 출력한다.
Method :

Example :
8 19
-------
2 6
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

pii ans[4] = {{1,1}, {1,2}, {2,2}, {2,1}};

pii f(int l, int walk) {
  if (l==2) { // 2x2
    int idx = walk-1;
    return ans[idx];
  }

  ll half = l/2;
  ll half_sq = half*half;
  if (walk <= half_sq) {
    // cout << "왼아래\n";
    pii ans = f(half, walk);
    return {ans.second, ans.first}; // 왼쪽 아래는 y=x 대칭
  } else if (walk<=2*half_sq) {
    // cout << "왼위\n";
    pii ans = f(half, walk-half*half);
    return {ans.first, half + ans.second}; // 왼쪽 위는 half만큼 올라간다음 좌표 이동
  } else if (walk <=3*half_sq) {
    // cout << "오위\n";
    pii ans = f(half, walk-2*half*half);
    return {half + ans.first, half + ans.second}; // 오른쪽 위는 가로/세로 모두 half만큼 오라간다음 좌표 이동 
  } else {
    // y = -x + (half+1) 대칭
    // x = half+1-y
    // y = half+1-x
    // 이때 사분면의 오른쪽 아래에 있으므로 x좌표는 half만큼 추가 이동
    // cout << "오아래\n";
    pii ans = f(half, walk-3*half*half);
    return {half+half+1-ans.second, half+1-ans.first};
  }
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  pii ans = f(n, m);
  cout << ans.first << " " << ans.second;

  
  return 0;
}