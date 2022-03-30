/*
Time : 2022.03.10
Problem : BOJ13313 (https://www.acmicpc.net/problem/13313)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
평소에 코딩 실력이 부족하다고 느끼고 있는 지구이는 익명게시판에서 “백스페이스 키를 쓰지 않고 코딩하기를 추천합니다” 라는 글을 읽게 되었다.
글의 최하단에는 매우 작은 글씨로 “효과는 보장할 수 없습니다” 같은 내용의 글이 5줄에 걸쳐 알아보기 힘들게 쓰여 있었지만, 지구이는 그래도 한 번은 시도해 볼 만한 방법이라고 생각했고, 직접 해보기로 했다.
지구이가 처음으로 도전한 문제는 다음과 같다.
“정점이 N (1 ≤ N ≤ 100)개 있고, 그래프의 인접행렬이 N*N으로 주어진다. 이때 모든 쌍의 최단거리를 구하시오.”
지구이는 플로이드로 이 문제를 풀려고 했으나, 아쉽게도 첫 번째 줄에서 오타가 나고 말았다.
하지만 지구이는 짧은 시간동안 자기합리화와 함께, “이 정도 실수라면 데이터가 내 코드를 빗겨나가지 않을까?”라는 굳은 믿음으로 계속 코딩을 했다. 하지만 결국 그 실수 때문에 맞을 수 없었고, 지구이는 코드를 밀 수밖에 없었다.
문제를 푼 후, 지구이는 자신의 첫 번째 코드가 얼마나 잘못됐는지 확인해 보려고 한다.
이것은, 첫 번째 코드와 두 번째 코드에서 구한 최단거리가 서로 다른 (i, j) 쌍의 개수가 9700개 이상인 데이터를 찾는 것이다.
하지만, 역시나 지구이는 데이터를 찾을 수 없었다.
지구이의 첫 번째 코드가 얼마나 망한 코드인지 알려주자!
Method :

Example :
6 10
1 2 2
1 3 1
2 4 5
2 5 3
2 6 7
3 4 4
3 5 6
3 6 7
4 6 4
5 6 2
-------
- 2 3 3 2 2
1 - 1 4 5 5
1 1 - 4 5 6
3 2 3 - 6 6
2 2 3 6 - 6
5 5 3 4 5 -
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

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  const int n = 100;
  int d[n+1][n+1] = {}, e[n+1][n+1] = {};
  cout << n << "\n";
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      if (i == n) d[i][j] = 0;
      else if (i == j || j == n) d[i][j] = 0;
      else d[i][j] = 10000;
      cout << d[i][j] << " ";
      e[i][j] = d[i][j];
    }
    cout << "\n";
  }
  for (int k=1; k<n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        d[i][j] = min(d[i][k]+d[k][j], d[i][j]);
      }
    }
  }
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        e[i][j] = min(e[i][k]+e[k][j], e[i][j]);
      }
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if( d[i][j] != e[i][j] ) cnt++;
		}
	}
  // cout << cnt << "\n";
  // if( cnt >= 9700 ) cout << "CORRECT";

  return 0;
}
