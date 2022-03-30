/*
Time : 2022.03.22
Problem : BOJ3780 (https://www.acmicpc.net/problem/3780)
Algorithm Type : 집합, 유니온파인드
Outline :
테스트케이스마다 기업의 수와, 명령이 주어진다.
명령은 두 가지로 주어지는데,
1. E i : 기업 i와 i의 센터까지의 거리를 출력한다.
2. I i j : 센터 i를 기업 j에 연결한다. 즉, 센터 i를 j의 "센터"에 연결한다. 즉 j가 센터가 되서 i로 가는 경로를 생성한다.
경로의 길이는 | i - j | mod 1000으로 결정한다
Method :

Example :
1
4
E 3
I 3 1
E 3
I 1 2
E 3
I 2 4
E 3
O
-------
0
2
3
5
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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const int N = 20000+100;
int parent[N], dist[N]; // dist[x] : x -> parent[x]까지의 거리
int n;

int getParent(int x) {
  if (x == parent[x]) return x;
  int p = getParent(parent[x]);
  dist[x] = dist[x] + dist[parent[x]]; // (x -> parent[x]) : 이동 거리, (parent[x] -> root) : 이동거리

  return parent[x] = p;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i=1; i<=n; i++) {
      parent[i] = i;
      dist[i] = 0;
    }
    while (1) {
      char o;
      int i, j;
      cin >> o;
      if (o == 'O') break;
      else if (o == 'E') {
        cin >> i;
        getParent(i);
        cout << dist[i] << "\n";
      } else {
        cin >> i >> j;
        dist[i] = abs(i-j) % 1000; // i는 무조건 root임, i -> j 이동
        parent[i] = j;
      }
    }
  }

  return 0;
}
