/*
Time : 2022.01.06 (5 min)
Problem : BOJ2577 (https://www.acmicpc.net/problem/2577)
Algorithm Type : Array
Outline :
100이상이며 1000보다 작은 자연수 A,B,C에 대해서
A*B*C를 계산한 값에 각 숫자가 몇개 들어있는지 출력한다.
Method :
세 정수가 1000보다 작기때문에 곱해도 int형에서 오버플로우가 발생하지 않는다.
세 정수의 곱을 int 변수 mul에 저장한 후, to_string함수를 통해 모양 그대로
string형으로 변환한다.
이후 ASCII 코드의 특성을 이용하여 문자열의 각 문자에서 '0'을 빼면
그 문자의 숫자가 나오게 된다. 따라서 cnt 배열에 카운팅하며 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, mul = 1;
  int cnt[10] = {};
  string s;
  for(int i=0; i<3; i++) {
    cin >> x;
    mul *= x;
  }
  s = to_string(mul);
  for(int i=0; i<s.size(); i++)
    cnt[s[i]-'0']++;
  for(int i=0; i<10; i++) cout << cnt[i] << "\n";
  return 0;
}