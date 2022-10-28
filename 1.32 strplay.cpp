#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char a[3333];
int n;
int f[3033][3033];

int get(int l, int r) {
    if (l > r) return 0;
    if (l == r) {
        f[l][r] = 1;
    }
    if (f[l][r] != 0) {
        return f[l][r];
    }
    f[l][r] = max(get(l + 1, r), get(l, r - 1));
    if (a[l] == a[r]) {
        f[l][r] = max(f[l][r], get(l + 1, r - 1) + 2);
    }
    return f[l][r];
}

int main() {
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        a[i + 1] = s[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, get(1, i) * get(i + 1, n));
    }
    cout << ans << endl;
    return 0;
}