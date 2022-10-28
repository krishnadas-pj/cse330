#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_n = 100000 + 10;

int n, a[max_n], b[max_n];
LL c, fuel[max_n];

int get_start() {
    int valid_start = -1;
    int start_city = 0, current_city = 0;
    LL current_fuel = 0;
    for (int i = 0; i < n * 2 + 10; ++i) {
        fuel[current_city] = current_fuel;
        int next_city = (current_city + 1) % n;
        LL next_fuel = min(current_fuel + a[current_city], c) - b[current_city];
        if (next_fuel < 0) {
            start_city = current_city = next_city;
            current_fuel = 0;
        } else if (next_city == start_city) {
            valid_start = start_city;
            break;
        } else {
            current_city = next_city;
            current_fuel = next_fuel;
        }
    }
    return valid_start;
}

int count_start() {
    int start = get_start();
    if (start == -1)
        return 0;
    int current = start;
    while (true) {
        int pre = (current + n - 1) % n;
        LL tmp = min(max(fuel[current] + b[pre] - a[pre], 0LL), c);
        if (tmp == fuel[pre])
            break;
        fuel[pre] = tmp;
        current = pre;
    }
    return count(fuel, fuel + n, 0);
}

void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    printf("%d\n", count_start());
}

int main() {
    solve();
    return 0;
}


