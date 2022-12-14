#include <stdio.h>
long long min(long long a, long long b) { return (a<b?a:b); }
int main() {
    int T,n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int t[n];
        long long best[n+3], suff[n+3];
        for (int i=n; i<n+3; i++) best[i] = suff[i] = 0;
        for (int i=0; i<n; i++) scanf("%d", &t[i]);
        for (int i=n-1; i>=0; i--) suff[i] = suff[i+1] + t[i];
        for (int i=n-1; i>=0; i--)
            best[i] = suff[i] - min(best[i+1], min(best[i+2], best[i+3]));
        printf("%lld\n", best[0]);
    }
    return 0;
}

