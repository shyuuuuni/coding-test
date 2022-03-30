/*
Time : 2022.01.06 (5 min)
Problem : BOJ1475 (https://www.acmicpc.net/problem/1475)
Algorithm Type : Array
Outline :
플라스틱 숫자 세트에는 0부터 9까지의 숫자가 하나씩 들어있다.
방 번호 N이 주어질때, 구매해야하는 최소 플라스틱 숫자 세트 개수를 출력한다.
Method :
string형으로 방 번호를 입력받아서, 문자열의 각 문자를
ASCII코드의 특성을 이용하여 '0'값을 빼면 해당 숫자가 나온다.
따라서 각 숫자의 빈도를 cnt 배열에 저장한다.
이후 최소 개수는 각 숫자 빈도의 최대값과 같다.
그러나 6과 9 모양을 뒤집어서 사용할 수 있으므로, 세트를 이용하여 6과 9를 만드는
최소 세트 개수는 ((6의 개수)+(9의 개수)+1) / 2 이고,
이 값을 6과 9를 제외한 수의 최대 빈도와 비교하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int cnt[10] = {};
  int x,y;
  string s;
  cin >> s;
  for(int i=0; i<s.size(); i++) {
    cnt[s[i]-'0']++;
  }
  x = (cnt[6]+cnt[9]+1)/2;
  cnt[6] = 0;
  cnt[9] = 0;
  y = *max_element(cnt, cnt+10);
  cout << max(x, y);
  return 0;
}