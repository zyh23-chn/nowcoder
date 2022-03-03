#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i += 1) {
        cin >> a[i];
    }
    vector<int> dp1(N), dp2(N);
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < i; j += 1) {
            if (a[j] < a[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 1; i -= 1) {
        for (int j = N - 1; j > i; j -= 1) {
            if (a[i] > a[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i += 1) {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    cout << N - ans - 1;
}
