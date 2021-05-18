#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,v) rep(i,0,(int)v.size()-1)
#define lint long long
#define ull unsigned lint
#define db long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define gc getchar()
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
typedef pair<int,int> pii;
typedef set<int>::iterator sit;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
const int N=55;int c[N],s[N];
inline pii solve(int S,int n)
{
	int l=1,r=n,t=0,ans=0;
	rep(i,0,n-1)
	{
		int x=(((S>>i)&1)?c[l++]:c[r--]);
		ans=max(ans,t+1);
		if(t&&x==s[t]) t--;else s[++t]=x;
	}
	return mp(t,ans);
}
int main()
{
	int cnt=0;
	freopen("data.in","r",stdin);//,freopen("bf.out","w",stdout);
	for(int n;scanf("%d",&n)!=EOF;)
	{
		cnt++;if(cnt%300==0) debug(cnt)ln;
		rep(i,1,n) scanf("%d",&c[i]);pii ans=mp(n,n);
//		rep(i,1,n) cerr<<c[i]sp;cerr ln;
		rep(i,0,(1<<n)-1) ans=min(ans,solve(i,n));
		printf("%d %d\n",ans.fir,ans.sec);
	}
	return 0;
}
