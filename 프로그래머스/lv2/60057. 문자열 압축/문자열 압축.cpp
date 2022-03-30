#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int len = s.size();
    int answer = len;
    
    for(int i=1; i<=len; i++) {
        string test = "";
        string prv = "";
        int n = 0;
        int cur = 0;
        for (int j=0; j<len; j+=i) {
            string token = s.substr(j, i);
            if (prv == "") {
                prv = token;
            } else if (prv == token) {
                n++;
            } else if (prv != token) {
                if (n==0) {
                    cur += prv.size();
                    test += prv;
                } else {
                    cur += 1 + prv.size();
                    test += to_string(n+1) + prv;
                }
                n = 0;
            }
            prv = token;
        }
        
        if (n==0) {
            cur += prv.size();
            test += prv;
        } else {
            cur += 1 + prv.size();
            test += to_string(n+1) + prv;
        }
        
        // cout << test <<"\n";
        answer = min(answer, (int)test.size());
    }
    
    return answer;
}