/*
Time : 2022.03.08
Problem : BOJ1504 (https://www.acmicpc.net/problem/1504)
Algorithm Type : 다익스트라
Outline :
방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다.
이때 임의로 주어진 두 정점은 반드시 통과해야 한다.
두 개의 정점을 지나는 최단 경로의 길이를 출력한다.
Method :

Example :
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
-------
7
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

const int INF = 200000000+1000000;
int n, e; // 정점, 간선
vector<pii> adj[800+5]; // 간선
int a, b; // 거쳐야 하는 정점 두개 (a가 1 가능, b가 N 가능)
int dist_1[800+5], dist_a[800+5], dist_b[800+5];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> e;
  for (int i=0; i<e; i++) {
    int s, d, w;
    cin >> s >> d >> w;
    adj[s].push_back({w,d});
    adj[d].push_back({w,s}); // 양방향이므로 추가
  }
  cin >> a >> b;

  fill(dist_1, dist_1+800+5, INF);
  fill(dist_a, dist_a+800+5, INF);
  fill(dist_b, dist_b+800+5, INF);

  // 1. Start -> All, A -> All, B -> All 최단경로 계산
  dist_1[1] = 0;
  pq.push({0,1});
  while (!pq.empty()) {
    int cur = pq.top().second; int cur_dist = pq.top().first; pq.pop();
    if (dist_1[cur] != cur_dist) continue;
    for (pii nxt : adj[cur]) {
      if (dist_1[nxt.second] <= cur_dist + nxt.first) continue;
      dist_1[nxt.second] = cur_dist + nxt.first;
      pq.push({dist_1[nxt.second], nxt.second});
    }
  }

  dist_a[a] = 0;
  pq.push({0,a});
  while (!pq.empty()) {
    int cur = pq.top().second; int cur_dist = pq.top().first; pq.pop();
    if (dist_a[cur] != cur_dist) continue;
    for (pii nxt : adj[cur]) {
      if (dist_a[nxt.second] <= cur_dist + nxt.first) continue;
      dist_a[nxt.second] = cur_dist + nxt.first;
      pq.push({dist_a[nxt.second], nxt.second});
    }
  }

  dist_b[b] = 0;
  pq.push({0,b});
  while (!pq.empty()) {
    int cur = pq.top().second; int cur_dist = pq.top().first; pq.pop();
    if (dist_b[cur] != cur_dist) continue;
    for (pii nxt : adj[cur]) {
      if (dist_b[nxt.second] <= cur_dist + nxt.first) continue;
      dist_b[nxt.second] = cur_dist + nxt.first;
      pq.push({dist_b[nxt.second], nxt.second});
    }
  }


  int ans = min(dist_1[a] + dist_a[b] + dist_b[n], dist_1[b] + dist_b[a] + dist_a[n]);
  if (INF <= ans) cout << -1;
  else cout << ans;

  return 0;
}