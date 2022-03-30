/*
Time : 2022.01.06 (5 min)
Problem : BOJ10808 (https://www.acmicpc.net/problem/10808)
Algorithm Type : Array
Outline :
알파뱃 소문자로 이루어진 단어 S에서 각 알파뱃이 몇개 포함되어 있는지 출력한다.
Method :
입력 순서대로 출력하면 되므로 입력을 받을때마다 x와 비교해서 작다면 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  int cnt[26] = {0};
  cin >> s;
  for(int i=0; i<s.size(); i++) {
    cnt[s[i]-'a']++;
  }
  for(int i=0; i<26; i++) cout << cnt[i] << " ";
  return 0;
}