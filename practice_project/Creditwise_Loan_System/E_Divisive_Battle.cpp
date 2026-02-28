#include <bits/stdc++.h>
using namespace std;

static const int MAXA = 1'000'000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // SPF sieve
    vector<int> spf(MAXA + 1);
    for (int i = 0; i <= MAXA; i++)
        spf[i] = i;
    spf[0] = 0;
    spf[1] = 1;
    for (int i = 2; 1LL * i * i <= MAXA; i++)
    {
        if (spf[i] == i)
        {
            for (long long j = 1LL * i * i; j <= MAXA; j += i)
                if (spf[(int)j] == (int)j)
                    spf[(int)j] = i;
        }
    }

    auto isPrime = [&](int x)
    {
        return x >= 2 && spf[x] == x;
    };

    auto omega = [&](int x) { // prime factors count (with multiplicity)
        int cnt = 0;
        while (x > 1)
        {
            cnt++;
            x /= spf[x];
        }
        return cnt;
    };

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // 1) already sorted?
        bool ok = true;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] > a[i + 1])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Bob\n";
            continue;
        }

        // 2) any inversion with prime left -> Alice
        bool bad = false;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i] > a[i + 1] && isPrime(a[i]))
            {
                bad = true;
                break;
            }
        }
        if (bad)
        {
            cout << "Alice\n";
            continue;
        }

        // 3) parity of total possible splits
        long long moves = 0;
        for (int x : a)
            moves += (omega(x) - 1);

        cout << (moves % 2 == 0 ? "Bob\n" : "Alice\n");
    }
    return 0;
}