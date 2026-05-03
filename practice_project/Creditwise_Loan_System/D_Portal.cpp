#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#define gcd __gcd

#define ALL(x) (x).begin(), (x).end()
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "NO\n";
#define cheakmate return;
const int N = 1e5 + 5;
#define Mod 1000000009 + 7

void solve()
{

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> result;

    if (x == 0)
        result.push_back(0);

    int pos1 = 0, pos2 = n;
    for (int i = 0; i < n; i++)
    {
        result.push_back(a[i]);

        if (i + 1 == x)
        {
            result.push_back(0);
            pos1 = i + 1;
        }
        if (i + 1 == y)
        {
            result.push_back(-1);
            pos2 = i + 1;
        }
    }

    int x1 = (int)result.size();
    vector<int> r1 = result, r2 = result, r3 = result, r4 = result;

    for (int i = 0; i < x1; i++)
    {
        if (result[i] == 0)
            pos1 = i;
        if (result[i] == -1)
            pos2 = i;
    }

    if (pos2 + 1 < x1)
    {
        swap(r1[pos2 + 1], r1[pos1]);
    }

    // r2
    if (pos2 - 1 >= 0)
    {
        swap(r2[pos2 - 1], r2[pos1]);
    }

    if (pos1 > 0)
    {
        swap(r3[pos1 - 1], r3[pos2]);
    }

    if (pos1 + 1 < x1)
    {
        swap(r4[pos1 + 1], r4[pos2]);
    }

    auto clean = [&](const vector<int> &v)
    {
        vector<int> t;
        t.reserve(v.size());
        for (int val : v)
        {
            if (val == 0 || val == -1)
                continue;
            t.push_back(val);
        }
        return t;
    };

    vector<vector<int>> cand;
    cand.push_back(clean(a));
    cand.push_back(clean(r1));
    cand.push_back(clean(r2));
    cand.push_back(clean(r3));
    cand.push_back(clean(r4));

    int best = 0;
    for (int i = 1; i < 5; i++)
    {
        if (cand[i] < cand[best])
            best = i;
    }

    for (int val : cand[best])
        cout << val << " ";
    cout << "\n";

    // cout << pos1 << pos2 << endl;
}
// sort(ALL(a),greater<int>());
// int maxi=*max_element(a.begin(),a.end());
//  int maxi = distance(a.begin(), max_element(a.begin(), a.end()));   // return max index

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*===============================================
  :::::::::::::Author :Md.Mursalin:::::::::::::
  ===============================================*/
