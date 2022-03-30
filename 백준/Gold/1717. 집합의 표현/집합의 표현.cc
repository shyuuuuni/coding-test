/*
Time : 2022.03.22
Problem : BOJ1717 (https://www.acmicpc.net/problem/1717)
Algorithm Type : 집합, 유니온파인드
Outline :
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다.
여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.
집합을 표현하는 프로그램을 작성하시오.
Method :

Example :
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
-------
NO
NO
YES
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

int n, m;
const int N = 1000000+100;
int parent[N], byrank[N];

int getParent(int x) {
  if (x == parent[x]) return x;

  return parent[x] = getParent(parent[x]);
}

void unionSet(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return;
  if (byrank[x] > byrank[y]) swap(x, y); // x < y 유지
  if (byrank[x] == byrank[y]) byrank[x]++; // 트리의 높이가 같다면 전체 높이가 +1
  parent[y] = x;
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  cin >> n >> m;

  for (int i=1; i<=n; i++) parent[i] = i;

  for (int i=1; i<=n; i++) byrank[i] = 1; 

  while (m--) {
    int c, a, b;
    cin >> c >> a >> b;
    if (!c) {
      unionSet(a, b);
    } else {
      if (getParent(a) == getParent(b)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}
