#include <bits/stdc++.h>
using namespace std;

#define int long long
#define gcd __gcd
#define ALL(x) (x).begin(), (x).end()
#define py cout << "Yes\n";
#define pm cout << "-1\n";
#define pz cout << "0\n";
#define pn cout << "No\n";
#define cheakmate return;

const int N = 1e5 + 5;
const int Mod = 1000000016LL;

void solve()
{
    set<int> st;
    int n;
    cin >> n;

    vector<int> a(n), d;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        d.push_back(it);
    }

    int ok = 0;

    for (int i = 0; i < (int)d.size(); i++)
    {
        if (d[i] % 5 == 0)
        {
            ok = 1;
        }
    }
    for (int i = 0; i < (int)d.size(); i++)
    {
        if (ok && (d[i] % 5 != 0))
        {
            pn cheakmate
        }
    }
    if (ok)
    {
        if ((int)d.size() > 2)
        {
            pn
        }
        else
        {
            py
        }
        cheakmate
    }
    map<int, int> mp;
    int six_odd = 0, six_evn = 0, t_f_8_ev = 0, t_f_8_od = 0;

    for (int i = 0; i < (int)d.size(); i++)
    {
        
    }

    for (int i = 0; i < (int)d.size(); i++)
    {
    }

    py
}

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