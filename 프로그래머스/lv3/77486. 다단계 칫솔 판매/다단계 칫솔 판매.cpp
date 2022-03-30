#include <bits/stdc++.h>

using namespace std;

map<string, int> converter;

void update(int idx, int price, vector<string> &referral, vector<int> &ans) {
    int royalty = price / 10;
    if (royalty < 1) {
        ans[idx] += price;
    } else if (referral[idx] == "-") {
        ans[idx] += price - royalty;
    } else {
        ans[idx] += (price - royalty);
        update(converter[referral[idx]], royalty, referral, ans);  
    }

    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer((int)enroll.size(), 0);
    
    for (int i=0; i<(int)enroll.size(); i++) {
        converter[enroll[i]] = i;
    }
    
    for (int i=0; i<(int)seller.size(); i++) {
        int idx = converter[seller[i]];
        int val = amount[i] * 100;
        update(idx, val, referral, answer);
    }
    
    return answer;
}