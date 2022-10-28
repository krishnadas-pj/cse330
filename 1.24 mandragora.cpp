#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> H(N, 0LL);
        for (int i = 0; i < N; ++i) cin >> H[i];
        
        sort(H.begin(), H.end());
        for (int i = N - 2; i >= 0; --i) H[i] += H[i + 1];
        
        ll ans = 0LL;
        for (int i = 0; i < N; ++i) {
            ans = max(ans, ll(i + 1) * H[i]);
        }
        cout << ans << endl;
    }
    return 0;
}