#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define SIZE_M 2007
#define SIZE_N 11
int f[SIZE_M][SIZE_N][SIZE_M], cnt[SIZE_M];
int main(){
	register int n, m, k, i, j, l, *pre, *now, x, t, xcnt, ans;	// x: a choice to re-use dp results from
	scanf("%d %d %d", &n, &m, &k);
	f[1][0][0] = 1;
	cnt[1] = 0;
	for (i = 1; i <= m && i <= k; ++i) {
		if (k % i == 0) {
			++cnt[1];
			for (j = 1; j <= n; ++j) {
				pre = f[1][j - 1], now = f[1][j];
				for (l = m; l >= i; --l) (now[l] += pre[l - i]) %= MOD;
			}
		}
	}
	ans = f[1][n][1];	// need marginal cases for this
	for (t = 2; t <= m; ++t) {
		xcnt = x = 0;
		for (i = 1; i < t; ++i) {
			if (t % i == 0 && xcnt < cnt[i]) xcnt = cnt[x = i];
		}
		memcpy(f[t], f[x], sizeof(int) * SIZE_M * SIZE_N);
		cnt[t] = xcnt;
		for (i = 1; i <= m; ++i) {       
			if (1ll * k * t % i == 0 && 1ll * k * x % i) {
				for (j = 1; j <= n; ++j) {
					pre = f[t][j - 1], now = f[t][j];
					for (l = m; l >= i; --l) (now[l] += pre[l - i]) %= MOD;
				}
				++cnt[t];
			}
		}
		(ans += f[t][n][t]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}