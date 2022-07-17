#include <bits/stdc++.h>

using namespace std;

pair<char, char> arr[26];

void preOrder(int idx) {
    pair<char, char> node = arr[idx];

    cout << (char)(idx + 'A');

    if (node.first != '.') {
        preOrder(node.first - 'A');
    }
    if (node.second != '.') {
        preOrder(node.second - 'A');
    }

    return;
}

void inOrder(int idx) {
    pair<char, char> node = arr[idx];
    
    if (node.first != '.') {
        inOrder(node.first - 'A');
    }

    cout << (char)(idx + 'A');

    if (node.second != '.') {
        inOrder(node.second - 'A');
    }
}

void postOrder(int idx) {

    pair<char, char> node = arr[idx];
    
    if (node.first != '.') {
        postOrder(node.first - 'A');
    }
    if (node.second != '.') {
        postOrder(node.second - 'A');
    }
    cout << (char)(idx + 'A');
}

int main(void) {
    int n;
    cin >> n;

    while (n--) {
        char head, le, ri;
        cin >> head >> le >> ri;

        arr[head - 'A'].first = le;
        arr[head - 'A'].second = ri;
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);

    return 0;
}