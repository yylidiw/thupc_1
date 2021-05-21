#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 1000000007
#define SIZE_M 2007
#define SIZE_N 11
int f[SIZE_N][SIZE_M];
int main(){
	register int n, m, k, i, x, j, l, ans, *pre, *now;
	scanf("%d %d %d", &n, &m, &k);
	ans = 0;
	for (i = n; i <= m; ++i) {
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (x = 1; x <= i; ++x) {
			if (1ll * k * i % x == 0) {
				for (j = 1; j <= n; ++j) {
					pre = f[j - 1], now = f[j];
					for (l = i; l >= x; --l) (now[l] += pre[l - x]) %= MOD;
				}
			}
		}
		(ans += f[n][i]) %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}