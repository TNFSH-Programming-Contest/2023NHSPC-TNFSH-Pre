/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;

int n, q;
ll a[2000006], b[2000006];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        ll p, c;
        cin >> p >> c;
        if (p - c < 0)
            b[1] += c - p, a[1]++, a[p + 1] -= 2;
        else
            a[p - c + 1]++, a[p + 1] -= 2;
        if (p + c + 1 <= n)
            a[p + c + 1]++;
    }
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1] + a[i];
    cout << *max_element(b + 1, b + 1 + n) << '\n';
}
