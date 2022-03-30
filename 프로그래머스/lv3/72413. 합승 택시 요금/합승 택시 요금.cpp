#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    const int DSTSIZE = 200+10;
    const ll INF = 200*200*10000;
    ll answer = INF;
    ll dst[DSTSIZE][DSTSIZE] = {0, };
    
    // ######### 플로이드 와샬 #########
    fill(&dst[0][0], &dst[DSTSIZE-1][DSTSIZE], INF);
    
    for (auto path : fares) {
        dst[path[0]][path[1]] = dst[path[1]][path[0]] = (ll)path[2];
    }
    for (int i=1; i<=n; i++) {
        dst[i][i] = 0;
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dst[i][k] + dst[k][j] < dst[i][j]) {
                    dst[i][j] = dst[i][k] + dst[k][j];
                }
            }
        }
    }
    // ######### 플로이드 와샬 #########
    
    // 분기할 노드를 선택
    for (int i=1; i<=n; i++) {
        if (dst[s][i] + dst[i][a] + dst[i][b] < answer) {
            answer = dst[s][i] + dst[i][a] + dst[i][b];
        }
    }
    
    answer = (int)answer;
    
    return answer;
}