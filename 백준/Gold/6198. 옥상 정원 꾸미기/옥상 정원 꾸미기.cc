/*
Time : 2022.01.07 (30 min)
Problem : BOJ6198 (https://www.acmicpc.net/problem/6198)
Algorithm Type : Stack
Outline :
도시에 N개의 빌딩이 있다.
빌딩은 모두 일렬로 서있고 오른쪽으로만 볼 수 있다.
빌딩은 자신보다 높이가 낮은 빌딩의 옥상을 볼 수 있다.
만약 더 높은 빌딩이나 같은 빌딩이 있다면 그 이후의 옥상들은 볼 수 없다.
모든 건물마다 관리인들이 빌딩의 옥상을 볼 수 있는 총 합을 출력한다.
Method :
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int check[80000+1];
int solve1() {
  int n;
  long long ans=0;
  stack<pair<int,int> > buf;
  cin >> n;
  for(int i=0; i<n; i++) {
    int h; cin >> h;
    pair<int,int> cur = make_pair(i, h); // i번째 타워의 높이 h
    if(buf.empty() || cur.second < buf.top().second) {
      buf.push(cur);
    } else {
      while(!buf.empty() && buf.top().second <= cur.second) {
        check[buf.top().first] = i - buf.top().first-1;
        buf.pop();
      }
      buf.push(cur);
    }
  }
  while(!buf.empty()) {
    check[buf.top().first] = n-buf.top().first-1;
    buf.pop();
  }
  for(int i=0; i<n; i++) ans += (long long)check[i];
  cout << ans;
  return 0;
}