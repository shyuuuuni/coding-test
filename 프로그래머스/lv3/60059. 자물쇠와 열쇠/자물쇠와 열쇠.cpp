#include <bits/stdc++.h>
using namespace std;

void lotation(int n, vector<vector<int>> &origin) {
    vector<vector<int>> result(n, vector<int>(n,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            result[j][n-i-1] = origin[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            origin[i][j] = result[i][j];
        }
    }
    return;
}

bool check(int x, int y, int n, vector<vector<int>> &key, vector<vector<int>> &lock) {
    bool result = true;
    for (int i=x; i<x+n; i++) {
        for (int j=y; j<y+n; j++) {
            result = result && (key[i][j] == !lock[i-x][j-y]);
        }
    }
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int M = (int)key.size();
    int N = (int)lock.size();
    
    for (int i=0; i<4; i++) {
        const int ALEN = 2*N + M;
        vector<vector<int>> a(ALEN, vector<int>(ALEN, 0));
        lotation(M, key);
        
        for (int j=N; j<N+M; j++) {
            for (int k=N; k<N+M; k++) {
                a[j][k] = key[j-N][k-N];
            }
        }
        for (int j=0; j<=ALEN-N; j++) {
            for (int k=0; k<=ALEN-N; k++) {
                answer = answer || check(j, k, N, a, lock);
            }
        }
    }
    return answer;
}