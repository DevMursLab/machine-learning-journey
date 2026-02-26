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

    // 2d input
    // vector<vector< int>> d(n, vector< int>(m));
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    int ans = 0;
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int p = 0, ck = 0, b = n;
        for (auto it : mp)
        {
            if (it.second >= mid)
            {
                p += mid;
                ck++;
            }
            else
            {
                p += it.second;
                p += (mid - it.second) / 2;
            }
        }
        // b -= ck;
        // if (p > 0)
        //     int l = 2 * p;
        if (n - mp.size() > 0)
        {
            int e = n - mp.size();
            p += (mid / 2) * e;
        }
        if (p >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans << endl;
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
