#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int upper_(int num, int div) {
    if(num % div == 0) {
        return num / div;
    } else {
        return (num + div) / div;
    }
}

void str_divider_(string s, vector<string> &v) {
    // "05:34 5961 IN" -> (("05:34", "5961"), "IN") 6 10 13
    int j=0, cnt=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            v[cnt++] = s.substr(j,i-j);
            j = i+1;
        } else if(i == s.size()-1) {
            v[cnt] = s.substr(j,i-j+1);
        }
    }
    return;
}

int time_diff(string t1, string t2) {
    // t1 ~ t2 사이의 시간 차이를 분으로 리턴
    int t1_h, t1_m;
    int t2_h, t2_m;
    int flag = 0, tmp = 0;
    int ans = 0;
    
    // t1 string to time(int)
    for(int i=0; i<t1.size(); i++) {
        if(t1[i] != ':') {
            tmp *= 10;
            tmp += t1[i] - '0';
        } else {
            t1_h = tmp;
            tmp = 0;
        }
    }
    t1_m = tmp;

    // t2 string to time(int)
    tmp = 0;
    for(int i=0; i<t2.size(); i++) {
        if(t2[i] != ':') {
            tmp *= 10;
            tmp += t2[i] - '0';
        } else {
            t2_h = tmp;
            tmp = 0;
        }
    }
    t2_m = tmp;
    
    if(t2_m < t1_m) {
        t2_h--;
        t2_m += 60;
    }
    ans += t2_m - t1_m;
    ans += (t2_h - t1_h) * 60;
    
    return ans;
}

int str_to_int(string s) {
    int rtn = 0;
    for(int i=0; i<s.size(); i++) {
        rtn *= 10;
        rtn += s[i] - '0';
    }
    return rtn;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // fees[0] : 기본시간
    // fees[1] : 기본요금
    // fees[2] : 단위시간
    // fees[3] : 단위요금
    vector<int> answer;
    vector<int> ans;
    vector<string> car_nums;
    string in_time[10000+1] = {};
    int status[10000+1] = {0}; // 0 : 입력X-출력X, 1 : 입력O
    int total_in[10000+1] = {0};
    map<string,int> m;
    vector<string> temp(3);
    int cnt = 0;
    
    for(auto s : records) {
        str_divider_(s, temp);
        if(temp[2] == "IN") {
            int idx;
            if(m.count(temp[1])) {
                // 이전에 들어온 차량
                idx = m[temp[1]];
            } else {
                answer.push_back(0); 
                car_nums.push_back(temp[1]);
                m.insert(make_pair(temp[1], cnt));
                idx = cnt;
                cnt++;
            }
            in_time[idx] = temp[0];
            status[idx] = 1;
        } else {
            // "OUT"
            int idx = m[temp[1]];
            int t_dif = time_diff(in_time[idx], temp[0]);
            total_in[idx] += t_dif;
            status[idx] = 0;
        }
    }
    
    for(int i=0; i<cnt; i++) {
        if(status[i]) {
            int t_dif = time_diff(in_time[i], "23:59");
            total_in[i] += t_dif;
        }
        if(total_in[i] <= fees[0]) {
            answer[i] += fees[1];
        } else {
            int u_dif = upper_(total_in[i] - fees[0], fees[2]);
            answer[i] += fees[1] + u_dif * fees[3];
        }
    }
    
    sort(car_nums.begin(), car_nums.end());
    for(auto c : car_nums) {
        int idx = m[c];
        ans.push_back(answer[idx]);
    }
    
    return ans;
}