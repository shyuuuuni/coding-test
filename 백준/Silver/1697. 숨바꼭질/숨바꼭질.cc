/*
Time : 2022.01.11 (10 min)
Problem : BOJ1697 (https://www.acmicpc.net/problem/1697)
Algorithm Type : BFS
Outline :
수빈이와 동생이 점 N과 K에 있다.
수빈이는 1초마다 X-1 or X+1 or 2*X 위치로 이동할 수 있다.
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
Method :
일차원 배열에서 BFS를 이용하여 해결한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int dist[100000+2];
void solve() {
  int n, m;
  cin >> n >> m;
  queue<int> q;
  fill(dist,dist+100000+1,-1);
  q.push(n);
  dist[n]=0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    if(cur == m) {cout << dist[cur]; return;}
    
    // 1
    int xx = cur+1;
    if(xx < 0 || 100000<xx || dist[xx] != -1) {

    } else {
      dist[xx] = dist[cur] + 1;
      q.push(xx);
    }
    // 2
    xx = cur-1;
    if(xx < 0 || 100000<xx || dist[xx] != -1) {

    } else {
      dist[xx] = dist[cur] + 1;
      q.push(xx);
    }
    // 3
    xx = 2*cur;
    if(xx < 0 || 100000<xx || dist[xx] != -1) {

    } else {
      dist[xx] = dist[cur] + 1;
      q.push(xx);
    }
  }
  
  return;
}