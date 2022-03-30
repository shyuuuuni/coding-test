/*
Time : 2022.02.20
Problem : BOJ13913 (https://www.acmicpc.net/problem/13913)
Algorithm Type : BFS
Outline :
수직선 상에서 수빈이와 동생이 0~100000 사이에 있다.
수빈이는 1초마다 X-1 또는 X+1, 2*X 위치로 이동할 수 있다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
Method :

Example :
5 17
-------
4
5 10 9 18 17
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

int n, k;
int ans = 300000+5;
int dist[300000+5];
int method[300000+5];

int _next(int x, int i) {
  switch (i)
  {
  case 0:
    return x-1;
  case 1:
    return x+1;
  case 2:
    return x*2;;
  }
  return 0;
}

int _prev(int x, int i) {
  switch (i)
  {
  case 0:
    return x+1;
  case 1:
    return x-1;
  case 2:
    return x/2;;
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;

  if (n == k) {
    cout << 0 << "\n";
    cout << n;
    return 0;
  }

  fill(method, method+300000+5, -1);
  fill(dist, dist+300000+5, 300000+5);
  queue<int> q;
  q.push(n);
  dist[n] = 0;

  while(!q.empty()) {
    int x = q.front();
    // int met = q.front().second;
    q.pop();

    if (ans < dist[x]) break;

    for (int i=0; i<3; i++) {
      int xx = _next(x, i);
      if (xx<0 || 200000<xx) continue;
      if (dist[xx] < dist[x] + 1) continue;
      q.push(xx);
      dist[xx] = dist[x] + 1;
      method[xx] = i;
      if (xx == k) {
        ans = min(ans, dist[xx]);
      }
    }

  }

  cout << dist[k] << "\n";

  int idx = k;
  stack<int> s;
  while(1) {
    s.push(idx);
    if (method[idx] == -1) break;
    idx = _prev(idx, method[idx]);
  }

  while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  
  return 0;
}