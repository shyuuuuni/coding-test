/*
Time : 2022.03.08
Problem : BOJ1261 (https://www.acmicpc.net/problem/1261)
Algorithm Type : 다익스트라
Outline :
N개의 도시에 K개의 면접장이 설치되어 있다.
N개의 도시 각각에서 가장 가까운 면접장으로 최단 거리로 이동했을 때,
면접장까지의 거리가 가장 먼 도시와 그 거리를 출력한다.
Method :

Example :
6 10 2
2 6 2
1 4 1
6 1 5
2 5 1
5 1 4
4 5 6
6 2 3
3 5 1
3 1 1
5 2 2
1 2
-------
4
8
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

int n, m, k;
const ll INF = 100000LL * 100000LL * 10LL;
ll dist[100000+1];
vector<pair<ll,int> > adj[100000+1];
vector<pair<ll,int> > invadj[100000+1];


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> k;

  for (int i=0; i<m; i++) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    adj[u].push_back(mp(c,v)); // u에서 v로 가는 가중치 c 간선이 있다.
    invadj[v].push_back({c,u}); // v에게 u로부터 오는 가중치 c 간선이 있다.
  }

  fill(dist, dist+100000+1, INF);

  priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int>>> pq;
  for (int i=0; i<k; i++) {
    int xxx;
    cin >> xxx;
    dist[xxx] = 0LL;
    pq.push({0LL,xxx});
  }

  while (!pq.empty()) {
    int cur = pq.top().second;
    ll cur_dist = pq.top().first;
    pq.pop();
    if (dist[cur] != cur_dist) continue;
    for (auto prv : invadj[cur]) {
      if (dist[prv.second] <= cur_dist + prv.first) continue;
      dist[prv.second] = cur_dist + prv.first;
      pq.push({dist[prv.second], prv.second});
    }
  }

  ll ans = -1;
  int ansidx = -1;
  for (int i=1; i<=n; i++) {
    if (ans < dist[i]) {
      ansidx = i;
      ans = dist[i];
    }
  }

  cout << ansidx << "\n" << ans;

  return 0;
}