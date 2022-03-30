/*
Time : 2022.03.08
Problem : BOJ1753 (https://www.acmicpc.net/problem/11779)
Algorithm Type : 다익스트라
Outline :
n(1≤n≤1,000)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라.
항상 시작점에서 도착점으로의 경로가 존재한다.
Method :

Example :
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
-------
4
3
1 3 5
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

int n, m; // 정점, 간선 개수
vector<pair<ll,int> > adj[1000+5]; // 해당 정점의 연결된 간선 (가중치, 다음정점)
ll dst[1000+5]; // 출발점으로부터의 최단 거리
int s, d; // 출발지, 도착지
int prv[1000+5]; // 해당 정점으로 최단 거리로 이동할 때 직전에 이동한 정점
priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
const ll INF = 100000LL * 100000LL * 2;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  cin >> m;
  for (int i=0; i<m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }
  cin >> s >> d;
  fill(dst, dst+1000+5, INF);

  dst[s] = 0;
  prv[s] = -1;
  pq.push({0,s});

  while (!pq.empty()) {
    ll cur_dst = pq.top().first;
    int cur_idx = pq.top().second;
    pq.pop();
    if (dst[cur_idx] != cur_dst) continue; // 최단 거리가 아님! 패스
    for (pair<ll,int> nxt : adj[cur_idx]) {
      ll cur_to_nxt_dst = nxt.first;
      int nxt_idx = nxt.second;
      if (dst[nxt_idx] <= cur_dst + cur_to_nxt_dst) continue; // 이미 최단거리! 패스
      dst[nxt_idx] = cur_dst + cur_to_nxt_dst; // 거쳐가는 방법이 최단거리
      prv[nxt_idx] = cur_idx;
      pq.push({dst[nxt_idx], nxt_idx});
    }
  }

  stack<int> ans;
  int ptr = d;
  while (1) {
    ans.push(ptr);
    if (prv[ptr] == -1) break;
    ptr = prv[ptr];
  }

  cout << dst[d] << "\n";
  cout << ans.size() << "\n";
  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }


  return 0;
}