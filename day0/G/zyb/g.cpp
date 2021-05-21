#include<bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define li long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define md int mid = l + r >> 1
#define ls q << 1
#define rs q << 1 | 1
#define ln ls,l,mid
#define rn rs,mid + 1,r
using namespace std;
const int mo = 1000000007;
inline li read(){
	li x = 0;
	int y = 0,c = gc;
	while(c < '0' || c > '9') y = c,c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	return y == '-' ? -x : x;
}
inline void prt(li x){
	if(x >= 10) prt(x / 10);
	pc(x % 10 + '0');
}
inline void print(li x){
	if(x < 0) pc('-'),x = -x;
	prt(x);
}
int n,m,k;
li f[12][2010],g[12][2010],ans;
int main(){
	int i,j,l,o;
	n = read();m = read();k = read();
	f[0][0] = 1;
	int cnt = 0;
	for(i = 1;i <= m;++i) if(k % i == 0){
		for(j = 0;j < n;++j){
			for(l = 0;l + i <= m;++l) (f[j + 1][l + i] += f[j][l]) %= mo;
		}
	}
	ans = f[n][1];
	for(i = 2;i <= m;++i){
		memcpy(g,f,sizeof(g));
		for(j = 1;j <= i;++j) if(1ll * k * i % j == 0 && k % j){
			for(l = 0;l < n;++l){
				for(o = 0;o + j <= i;++o) (g[l + 1][o + j] += g[l][o]) %= mo;
			}
		}
		ans += g[n][i];
	}
	print(ans % mo);
	//cerr<<endl<<clock()<<endl;
	return 0;
}
