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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    multiset<int> st1;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st1.insert(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        int p = ((b[i] + 1)) + b[i];
        if (p <= k)
        {
            int c = (k - p) / (b[i] + 1);
            ms.insert(c + 1);
        }
    }

    for (auto it : ms)
    {
        // auto o = lower_bound(ALL(st1), it);

        if (*st1.begin() <= it)
        {
            ans++;
            st1.erase(st1.begin());
        }
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
