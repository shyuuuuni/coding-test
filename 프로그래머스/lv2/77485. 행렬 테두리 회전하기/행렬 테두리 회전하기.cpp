#include <bits/stdc++.h>
using namespace std;

int process_query(vector<int> &query, vector<vector<int>> &a, int r, int c) {
    int result = r * c * 10; // 최솟값
    int x1 = query[0], y1 = query[1]; // (x1,y1)
    int x2 = query[2], y2 = query[3]; // (x2,y2)
    deque<int> dq;
    
    // (x1,y1) -> (x1,y2)
    for (int i = y1; i < y2; i++) {
        dq.push_back(a[x1][i]);
        result = min(result, a[x1][i]);
    }
    // (x1,y2) -> (x2,y2)
    for (int i = x1; i < x2; i++) {
        dq.push_back(a[i][y2]);
        result = min(result, a[i][y2]);
    }
    // (x2,y2) -> (x2,y1)
    for (int i = y2; y1 < i; i--) {
        dq.push_back(a[x2][i]);
        result = min(result, a[x2][i]);
    }
    // (x2,y1) -> (x1,y1)
    for (int i = x2; x1 < i; i--) {
        dq.push_back(a[i][y1]);
        result = min(result, a[i][y1]);
    }
    
    // 회전
    dq.push_front(dq.back());
    dq.pop_back();
    
    // (x1,y1) -> (x1,y2)
    for (int i = y1; i < y2; i++) {
        a[x1][i] = dq.front(); dq.pop_front();
    }
    // (x1,y2) -> (x2,y2)
    for (int i = x1; i < x2; i++) {
        a[i][y2] = dq.front(); dq.pop_front();
    }
    // (x2,y2) -> (x2,y1)
    for (int i = y2; y1 < i; i--) {
        a[x2][i] = dq.front(); dq.pop_front();
    }
    // (x2,y1) -> (x1,y1)
    for (int i = x2; x1 < i; i--) {
        a[i][y1] = dq.front(); dq.pop_front();
    }
    
    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    const int MAX_SIZE = 100+5;
    vector<vector<int> > a(MAX_SIZE, vector<int>(MAX_SIZE, 0));
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            a[i][j] = (i-1) * columns + j;
        }
    }
    
    for (auto query : queries) {
        answer.push_back(process_query(query, a, rows, columns));
    }
    
    
    return answer;
}