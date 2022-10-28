#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[6000], b[6000];
int la, lb;
int Pref[5005][5005], Suff[5005][5005];
bool Can[256];

int main() {
    cin >> (a + 1) >> (b + 1);
    la = strlen(a + 1);
    lb = strlen(b + 1);

    for(int i = 1; i <= la; ++i)
        for(int j = 1; j <= lb; ++j) {
            if(a[i] == b[j]) {
                Pref[i][j] = 1 + Pref[i - 1][j - 1];
            } else {
                Pref[i][j] = max(Pref[i - 1][j], Pref[i][j - 1]);
            }
    }
    
    for(int i = la; i >= 1; --i)
        for(int j = lb; j >= 1; --j) {
            if(a[i] == b[j])
                Suff[i][j] = 1 + Suff[i + 1][j + 1];
            else
                Suff[i][j] = max(Suff[i + 1][j], Suff[i][j + 1]);
    }
    
    int best = Pref[la][lb];
    int cnt = 0;
    
    for(int i = 1; i <= la + 1; ++i) {
        memset(Can, 0, sizeof(Can));
        for(int j = 1; j <= lb; ++j) {
            if(Can[b[j]]) continue;
            
            if(Pref[i - 1][j - 1] + Suff[i][j + 1] == best) {
                Can[b[j]] = 1;
                cnt += 1;
            }
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}