#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long n, m, l;
        cin >> n >> m >> l;

        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        long long lo = 0, hi = l, ans = l;

        auto ok = [&](long long x)
        {
            long long cnt = 0;
            long long last = 0;

            for (int i = 0; i < n; i++)
            {
                long long gap = a[i] - last;

                if (gap > x)
                {
                    long long need = (gap - 1) / x;
                    cnt += need;
                }

                last = a[i];
            }

            long long gap = l - last;
            if (gap > x)
            {
                long long need = (gap - 1) / x;
                cnt += need;
            }

            return cnt < m;
        };

        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;

            if (ok(mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }
}