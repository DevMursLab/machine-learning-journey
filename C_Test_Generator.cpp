#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static inline bool bit_on(long long x, int i)
{
    return (x >> i) & 1LL;
}

// check if we can represent n as sum of N numbers, each ai is submask of m (ai&m==ai)
bool can(long long n, long long m, long long N)
{
    // interval of possible carry values at current bit: [L, R]
    long long L = 0, R = 0;

    // go a bit beyond 60 to flush carry (since n,m <= 1e18)
    for (int i = 0; i < 62; i++)
    {
        int b = (i < 62 ? (int)bit_on(n, i) : 0);
        bool allowed = (i < 62 ? bit_on(m, i) : false); // above 61 -> disallowed

        if (!allowed)
        {
            // we must place digit d_i = 0, so (carry + b) must be even for ALL carry in [L,R]
            // parity must be fixed across interval, otherwise impossible
            if ((L & 1) != (R & 1))
                return false;
            if (((L + b) & 1))
                return false;

            // next carries are fixed: (c+b)/2
            L = (L + b) / 2;
            R = (R + b) / 2;
        }
        else
        {
            // allowed: choose d in [0..N] with same parity as (c+b), and d <= (c+b)
            // This creates a RANGE of next carries.
            // For monotonicity, min next carry happens at smallest c (L), max at largest c (R).

            auto next_low = [&](long long c) -> long long
            {
                long long v = c + b;      // total at this bit
                long long mx = min(N, v); // max digit we can "consume"
                // adjust mx to match parity of v
                if ((mx & 1) != (v & 1))
                    mx--;
                if (mx < 0)
                    return (long long)4e18; // impossible
                // next carry = (v - mx)/2
                return (v - mx) / 2;
            };

            auto next_high = [&](long long c) -> long long
            {
                long long v = c + b;
                long long mn = (v & 1LL); // minimum digit matching parity (0 if v even, 1 if v odd)
                if (mn > N)
                    return (long long)-1; // can't place required parity digit
                if (mn > v)
                    return (long long)-1; // can't consume more than v
                // next carry = (v - mn)/2
                return (v - mn) / 2;
            };

            long long nL = next_low(L);
            long long nR = next_high(R);
            if (nL > (long long)3e18 || nR < 0)
                return false;
            if (nL > nR)
                return false;

            L = nL;
            R = nR;
        }
    }

    // after processing enough bits, carry must be able to reach 0; since remaining bits are disallowed,
    // interval must contain 0
    return (L == 0 && R == 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;

        long long lo = 1, hi = n, ans = -1;

        // quick prune: if m==0 (not possible here since m>=1 in your constraints), keep safe
        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        while (lo <= hi)
        {
            long long mid = (lo + hi) / 2;
            if (can(n, m, mid))
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
    return 0;
}