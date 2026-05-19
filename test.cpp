#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 2010, M = N / 2 * N;

int n, c, m;
int ans;
PII a[N];

int fa[N];

struct node
{
    int u, v, w;
} e[M];

int dist(PII x, PII y)
{
    int x1 = x.first, y1 = x.second;
    int x2 = y.first, y2 = y.second;
    int dx = x1 - x2, dy = y1 - y2;

    return dx * dx + dy * dy;
}

bool cmp(node& x, node& y)
{
    return x.w < y.w;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void un(int x, int y)
{
    fa[find(x)] = find(y);
}

bool issame(int x, int y)
{
    return find(x) == find(y);
}

void kk()
{
    sort(e + 1, e + 1 + m, cmp);
    int cnt = 0; // 边数

    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (issame(u, v)) continue;

        cnt++;
        un(u, v);
        ans += w;

        if (cnt == n - 1) break;
    }

    if (cnt == n - 1) cout << ans << endl;
    else cout << -1 << endl;
}

signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        fa[i] = i;
    }


    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int w = dist(a[i], a[j]);
            if (w >= c)
            {
                e[++m] = { i, j, w };
            }
        }

    kk();

    return 0;
}
