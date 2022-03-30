/*
Time : 2022.01.20 (30 min)
Problem : BOJ2448 (https://www.acmicpc.net/problem/2448)
Algorithm Type : Recursion
Outline :
재귀적인 패턴으로 별을 찍는다.
N=3일때 다음과 같이
  *                        
 * *                       
*****  
별을 찍는다.
Method :
star(n,x,y) 는 (x,y)부터 가로/세로 각각 n 범위에 별을 찍는다.
만약 n이 9이상이라면 범위를 9등분한다.
n이 3이라면 별을 찍는다. 이때 중앙의 공간은 비워둔다.
9등분을 할 때 재귀적으로 star함수를 호출한다. 이때 마찬가지로 중앙이 비어야하기 때문에 중앙 범위에서는
space함수를 호출한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

vector<vector<char> > v(1024*3+1, vector<char>((1024*3)*2+1,' '));
void star(int n, int x, int y) {
  int half = n/2;
  if(3 < n) {
    star(half, x, y);
    star(half, x+half, y-half);
    star(half, x+half, y+half);
  } else {
    v[x][y] = '*';
    v[x+1][y-1] = v[x+1][y+1] = '*';
    for(int i=-2; i<3; i++)
      v[x+2][y+i] = '*';
  }
  return;
}

void solve() {
  int n;
  cin >> n;
  star(n,0,n-1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<2*n-1; j++) {
      cout << v[i][j];
    }
    cout << "\n";
  }
  return;
}