#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void LCS(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    vector<int> lens(m+1,0);
    vector<vector<int>> prev(n+1,vector<int>(m+1,0));
    int topleft;
    for(int i = 1; i <= n; i++) {
        topleft = 0;
        for(int j = 1; j <= m; j++) {
            int len;
            if(A[i-1] == B[j-1]) {
                len = topleft+1;
                prev[i][j] = 1; // topleft
            } else {
                if(lens[j] > lens[j-1]) {
                    len = lens[j];
                    prev[i][j] = 2; // top
                } else {
                    len = lens[j-1];
                    prev[i][j] = 3; // left
                }
            }
            topleft = lens[j];
            lens[j] = len;
        }
    }
    // print LCS
    int i = n, j = m, idx = 0;
    vector<int> lcs(lens[m],0);
    while(prev[i][j] != 0) {
        if(prev[i][j] == 1) {
            lcs[idx++] = A[i-1];
            i--;
            j--;
        } else if(prev[i][j] == 2) {
            i--;
        } else {
            j--;
        }
    }
    for(int i = lcs.size()-1; i >= 0; i--) {
        if(i != 0) {
            cout << lcs[i] << ' ';
        } else {
            cout << lcs[0] << endl;
        }
    }
}

int main() {  
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(int i = 0 ; i < n; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }
    LCS(A,B);
    return 0;
}
