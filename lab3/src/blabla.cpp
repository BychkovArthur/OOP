#include <bits/stdc++.h>

using namespace std;

void foo(vector<int> a) {
    cout << &a[0] << endl;
    for (int i = 0; i < 5; ++i) {
        a[i] += 228;
        cout << a[i] << endl;
    }
}

int main() {
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        a[i] = i + 1;
    }

    foo(a);

    cout << "HERE" << endl;
    cout << &a[0] << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << endl;
    }
}