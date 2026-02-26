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
    vector<int> a(n), b(m);
    priority_queue<int> pq_a, pq_b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pq_a.push(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        pq_a.push(b[i]);
    }
    int ok = 1;
    while (true)
    {
        if (!pq_b.empty())
        {
            cout << "Alice" << endl;
            cheakmate
        }
        if (!pq_a.empty())
        {
            cout << "Bob" << endl;
            cheakmate
        }
    }
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
