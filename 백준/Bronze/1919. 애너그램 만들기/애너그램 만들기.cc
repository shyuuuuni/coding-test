/*
Time : 2022.01.06 (3 min)
Problem : BOJ1919 (https://www.acmicpc.net/problem/1919)
Algorithm Type : Array
Outline :
애너그램이란 철자의 순서를 잘 바꿔서 두 단어가 같아질 수 있을때 애너그램 관계에 있다고 한다.
두 영단어가 주어졌을 때, 두 영단어가 애너그램 관계가 되도록 제거해야 하는 최소 알파뱃 개수를 출력한다.
Method :
각 문자열에 들어있는 각 문자의 개수가 동일한지 비교하면 된다.
두개의 카운트용 배열을 선언한 후 ASCII코드의 특성을 이용하여
문자열의 각 문자에서 'a'를 빼면 인덱스로 표현할 수 있다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string x, y;
  int ans=0, cnt1[26]={}, cnt2[26]={};
  cin >> x >> y;
  for(int i=0; i<x.size(); i++)
    cnt1[x[i]-'a']++;
  for(int i=0; i<y.size(); i++)
    cnt2[y[i]-'a']++;
  for(int i=0; i<26; i++)
    ans += abs(cnt1[i]-cnt2[i]);
  cout << ans;
  return 0;
}