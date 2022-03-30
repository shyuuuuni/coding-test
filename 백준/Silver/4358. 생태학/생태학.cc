/*
Time : 2022.03.29
Problem : BOJ5052 (https://www.acmicpc.net/problem/5052)
Algorithm Type : STL::Map
Outline :
미국 전역의 나무들이 주어졌을 때, 각 종이 전체에서 몇 %를 차지하는지 출력한다.
%는 소수 4째자리까지 반올림해서 출력한다.
Method :

Example :
Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
-------
Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  double n=0LL;
  string buf;
  map<string,double> counter;
  while (getline(cin, buf)) {
    n++;
    if (counter.find(buf) == counter.end()) {
      counter[buf] = 1LL;
    } else {
      counter[buf] += 1LL;
    }
  }
  if (n == 0) return 0;
  cout << fixed;
  for (auto si : counter) {
    cout.precision(4);
    cout << si.first << " " << (100*si.second/n)<< "\n";
  }

  return 0;
}
