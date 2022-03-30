#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;      // 반환값
    map<string,int> ans[10+2];            // 정답 요리를 중복없이 저장
    int has[10+10][26+10] = {0};
    int n[10+10] = {0};

    for (int i=0; i<(int)orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        n[i] = (int)orders[i].size();
        for (auto c : orders[i]) {
            has[i][c-'A'] = 1;
        }
    }

    for (auto course_len : course) {
        cout << course_len << "! \n";
        for (int i=0; i<(int)orders.size(); i++) {
            if (n[i] < course_len) continue;
            string cur = orders[i];
            vector<int> comb(n[i], 0);
            for (int j=1; j<=course_len; j++) {
                comb[n[i]-j] = 1;
            }
            do {
                string s = "";
                for (int j=0; j<n[i]; j++) {
                    if (comb[j] == 1) s.push_back(cur[j]);
                }
                if (ans[course_len].find(s) == ans[course_len].end()) {
                    ans[course_len][s] = 1;
                } else {
                    ans[course_len][s]++;
                }
            } while (next_permutation(comb.begin(), comb.end()));
        }
        if (ans[course_len].empty()) continue;
        // 최대인 코스 선택
        vector<pair<string,int>> tmp(ans[course_len].begin(), ans[course_len].end());
        sort(tmp.begin(), tmp.end(), [](pair<string,int> a, pair<string,int> b) {
            return a.second > b.second;
        });
        int mx = tmp[0].second;
        if (mx < 2) continue;
        answer.push_back(tmp[0].first);
        for (int it=1; it<tmp.size(); it++) {
            if (tmp[it].second < mx) break;
            answer.push_back(tmp[it].first);
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}