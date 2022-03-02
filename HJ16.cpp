#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, m;
    cin >> N >> m;
    vector<vector<vector<int>>> a(m + 1, vector<vector<int>>(3, { 0,0 }));
    for (int i = 1; i <= m; i += 1) {
        int v, p, q;
        cin >> v >> p >> q;
        if (!q) {
            a[i][0] = { v,p };
        }
        else if (!a[q][1][1]) {
            a[q][1] = { v,p };
        }
        else {
            a[q][2] = { v,p };
        }
    }
    vector<int> dp(N + 1);
    for (int i = 1; i <= m; i += 1) {
        for (int j = N; j >= 0; j -= 1) {
            if (j >= a[i][0][0]) {
                dp[j] = max(dp[j], dp[j - a[i][0][0]] + a[i][0][0] * a[i][0][1]);
            }
            if (j >= a[i][0][0] + a[i][1][0]) {
                dp[j] = max(dp[j], dp[j - a[i][0][0] - a[i][1][0]] + a[i][0][0] * a[i][0][1] + a[i][1][0] * a[i][1][1]);
            }
            if (j >= a[i][0][0] + a[i][2][0]) {
                dp[j] = max(dp[j], dp[j - a[i][0][0] - a[i][2][0]] + a[i][0][0] * a[i][0][1] + a[i][2][0] * a[i][2][1]);
            }
            if (j >= a[i][0][0] + a[i][1][0] + a[i][2][0]) {
                dp[j] = max(dp[j], dp[j - a[i][0][0] - a[i][1][0] - a[i][2][0]] + a[i][0][0] * a[i][0][1] + a[i][1][0] * a[i][1][1] + a[i][2][0] * a[i][2][1]);
            }
        }
    }
    cout << dp[N];
}
