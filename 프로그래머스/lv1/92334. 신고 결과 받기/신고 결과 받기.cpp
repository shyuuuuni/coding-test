#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

pair<string, string> split(string s, char delim) {
    // "abc def" -> ("abc", "def") (delim = ' ')
    pair<string, string> rtn;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == delim && i) {
            rtn.first = s.substr(0,i);
            rtn.second = s.substr(i+1, s.size()-i-1);
            break;
        }
    }
    return rtn;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int> m; // m["muzi"] = 0 이런식으로 문자열->숫자 변환
    vector< vector<int> > shot(id_list.size()); // shot[i] : i가 신고한 사람의 번호 벡터
    int reports[1000+1] = {0}; // reports[i] : i가 신고당한 횟수
    
    for(int i=0; i<id_list.size(); i++) {
        m.insert(make_pair(id_list[i], i));
    }
    
    for(auto s : report) {
        pair<string,string> pss = split(s, ' ');
        int a = m[pss.first];
        int b = m[pss.second];
        // shot[a].push_back(b);
        if(find(shot[a].begin(), shot[a].end(), b) == shot[a].end()) {
            shot[a].push_back(b);
            reports[b]++;
        } else {
            continue;
        }
    }
    
    for(int i=0; i<id_list.size(); i++) {
        int anscnt = 0;
        for(auto r : shot[i]) {
            if(k <= reports[r]) anscnt++;
        }
        answer[i] = anscnt;
    }
    
    return answer;
}