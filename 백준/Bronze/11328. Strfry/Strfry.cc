/*
Time : 2022.01.06 (5 min)
Problem : BOJ11328 (https://www.acmicpc.net/problem/11328)
Algorithm Type : Array
Outline :
strfry 함수는 문자열을 무작위로 재배치하는 함수이다.
두개의 문자열에 대해서 strfry 함수를 적용하여 얻을 수 있는지 판단한다.
Method :
성별과 학년에 따른 학생수를 각각 저장하기 위해 이중배열로 students[][] 배열을 선언한다.
각 성별-학년에 대하여 필요한 방의 수를 구하기 위해, 학생수가 0이 아닌 집단에 대해서
(student[i][j]+k-1) / k 를 통해 필요한 방의 개수를 모두 더해 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n=0, tc;
  cin >> tc;
  while(n < tc) {
    string x, y;
    int cnt1[26]={}, cnt2[26]={};
    int flag = 1;
    cin >> x >> y;
    for(int i=0; i<x.size(); i++)
      cnt1[x[i]-'a']++;
    for(int i=0; i<y.size(); i++)
      cnt2[y[i]-'a']++;
    for(int i=0; i<26; i++) {
      if(cnt1[i]!=cnt2[i]) flag=0;
    }
    if(flag) cout << "Possible\n";
    else cout << "Impossible\n";
    n++;
  }
  return 0;
}