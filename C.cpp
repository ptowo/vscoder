#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 3e5 + 10; typedef long long ll; int n, m, a[N];
std::map<ll, int> bkt;
inline void clr() { bkt.clear(); }
int main()
{
    int qwq; scanf("%d", &qwq);
    while (qwq--)
    {
        clr(); scanf("%d", &n); ll s = 0;
        for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++bkt[a[i]], s += a[i];
        if (n == 1) { puts("YES"); continue; }
        std::queue<ll> q; q.push(s);
        for (int i = 1; i < n; ++i)
        {
            ll u = q.front(); q.pop();
            ll x = u / 2, y = u - x;
            if (!bkt.count(x)) q.push(x);
            else if (--bkt[x] == 0) bkt.erase(x);
            if (!bkt.count(y)) q.push(y);
            else if (--bkt[y] == 0) bkt.erase(y);
        }
        puts(bkt.empty() && q.empty() ? "YES" : "NO");
    }
    return 0;
}

