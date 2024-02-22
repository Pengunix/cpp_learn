#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7 + 10; // 范围
const int P = 1e9 + 7;  // 模数

int fac[N];    // 记录阶乘
int invfac[N]; // 预处理逆元，存储 i! 的逆元

int inv(int x);

// 初始化阶乘数组 fac[]，预处理逆元
void InitFac(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i - 1] * i % P;

    // 把 n! 的逆元存入 invfac[n]
    invfac[n] = inv(fac[n]);
    // 通过转移方程线性递推 invfac[]
    for (int i = n - 1; i >= 0; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % P;
}

// 快速幂取模
int ModExp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// 求逆元：费马小定理 + 快速幂
int inv(int x)
{
    return ModExp(x, P - 2);
}

// 求组合数
int C(int n, int m)
{
    // 特判
    if (n < 0 || m < 0 || n < m)
        return 0;

    // 公式，修改为通过 invfac[] 计算
    return fac[n] * invfac[n - m] % P * invfac[m] % P;
}

void solve()
{
    int q, a, b, c, n, m;
    cin >> q >> a >> b >> c >> n >> m;

    int sum = 0;
    // q 次询问
    for (int i = 1; i <= q; i++)
    {
        sum = (sum + C(n, m)) % P;

        // 准备下一次询问的 n, m
        n = (n * a + b) % c;
        m = (m * b + a) % c;
    }
    cout << sum;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    InitFac(1e7); // 初始化 fac[]

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}