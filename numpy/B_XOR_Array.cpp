#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long
int numberOfBits(long long n)
{
    return floor(log2(n)) + 1;
}

int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        // --------- Problem Logic Starts Here ---------
        int n, l, r;
        cin >> n >> l >> r;
        l--, r--;
        vector<int> v(n);
        int b = 0;
        int y = numberOfBits(r);
        int pt = (1LL << y) - 1;
        int f1 = pt - 1;
        int f2 = pt & ~(1LL << (numberOfBits(r) - 1));
        if (r - l == 1)
        {
            v[l] = pt;
            v[r] = pt;
        }
        else
        {
            int ok = 1;
            for (int i = l; i <= r; i++)
            {

                v[i] = pt & ~(1LL << (numberOfBits(b)));
                b++;
                ok = 1;
            }
        }

        int flag = 1;
        for (int i = 0; i < l; i++)
        {
            if (flag)
            {
                v[i] = f1;
                flag = 0;
            }
            else
            {
                v[i] = f2;
                flag = 1;
            }
        }

        flag = 1;
        for (int i = r + 1; i < n; i++)
        {
            if (flag)
            {
                v[i] = f1;
                flag = 0;
            }
            else
            {
                v[i] = f2;
                flag = 1;
            }
        }

        for (auto it : v)
            cout << it << " ";

        cout << endl;
    }
    return 0;
}