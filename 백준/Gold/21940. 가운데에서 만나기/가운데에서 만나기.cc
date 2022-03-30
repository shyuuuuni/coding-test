/*
Time : 2022.03.09
Problem : BOJ21940 (https://www.acmicpc.net/problem/21940)
Algorithm Type : 플로이드
Outline :
N개의 도시에 M개의 도로가 연결되어 있다.
K명의 사람이 각 도시에 살고 있는데, N개의 도시 중 다음 조건을 만족하는 도시를 찾으려고 한다.
1. 왕복시간을 살고있는 도시 A에서 도시X로 이동하는 시간 + 도시X에서 다시 A로 이동하는 시간으로 정의한다.
2. 한 도시를 골랐을 때, K명의 사람의 왕복시간들 중 최댓값이 최소가 되는 도시를 찾는다.
만족하는 도시 번호를 출력한다.
Method :

Example :
4 9
1 2 9
2 3 9
3 1 9
1 4 1
4 1 1
2 4 1
4 2 1
3 4 1
4 3 1
3
1 2 3
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

const int INF = 0x3f3f3f3f;
const int N = 200+5;
int n, m, k; // 도시, 도로, 사람수
int dist[N][N]; // 시간
vector<int> p;


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // fast io
  
  cin >> n >> m;
  fill(&dist[0][0], &dist[N-1][N], INF);
  while (m--) {
    int a,b,c;
    cin >> a >> b >> c;
    if (c < dist[a][b]) {
      dist[a][b] = c;
    }
  }

  cin >> k;
  while (k--) {
    int i;
    cin >> i;
    p.push_back(i); // 출발점
  }

  for (int i=1; i<=n; i++) dist[i][i] = 0;

  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  vector<int> ans;
  int mn = INF;
  for (int i=1; i<=n; i++) {
    // i가 정답 도시인지 확인
    int cur = 0;
    for (int start : p) {
      cur = max(cur, dist[start][i] + dist[i][start]);
    }
    if (cur < mn) {
      ans.clear();
      mn = cur;
      ans.push_back(i);
    } else if (cur == mn) {
      ans.push_back(i);
    } else {
      continue;
    }
  }

  sort(ans.begin(), ans.end());

  for (int a : ans) {
    cout << a << " ";
  }

 
  return 0;
}