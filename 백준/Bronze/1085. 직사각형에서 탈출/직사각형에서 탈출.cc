#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x, y, w, h;
    cin >> x >> y;
    cin >> w >> h;
    
    int result = min({x, y, w-x, h-y});
    cout << result;
    
    return 0;
}