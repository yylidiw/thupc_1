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
const int N=55,inf=55;int g[N][N][N][N],L[N][N],R[N][N],st[N],c[N];lint s[N];pii f[N][N];
inline pii P(const pii &t,int x,int y) { return mp(t.fir+x,max(t.sec,y)); }
inline lint S(int l,int r) { return s[r]^s[l-1]; }
inline void Min(pii &res,pii t) { res=min(res,t); }
inline void Min(int &res,int t) { res=min(res,t); }
inline int G(int l1,int r1,int l2,int r2)
{
	if(l1>r1&&l2>r2) return 0;
	if(l1>r1) return R[l2][r2];
	if(l2>r2) return L[l1][r1];
	if(S(l1,r1)^S(l2,r2)) return inf;
	return g[l1][r1][l2][r2];
}
inline int getLR(int n)
{
	rep(i,1,n)
	{
		int t=0,ans=0;
		rep(j,i,n)
		{
			ans=max(ans,t+1);
			if(t&&st[t]==c[j]) t--;
			else st[++t]=c[j];
			if(t) L[i][j]=inf;else L[i][j]=ans;
		}
	}
	rep(i,1,n)
	{
		int t=0,ans=0;
		for(int j=i;j;j--)
		{
			ans=max(ans,t+1);
			if(t&&st[t]==c[j]) t--;
			else st[++t]=c[j];
			if(t) R[j][i]=inf;else R[j][i]=ans;
		}
	}
//	rep(i,1,n) rep(j,i,n) debug(i)sp,debug(j)sp,debug(L[i][j])sp,debug(R[i][j])ln;
	return 0;
}
inline int getg(int n)
{
	rep(len1,1,n) rep(len2,1,n-len1) rep(l1,1,n-len1-len2+1)
	{
		int r1=l1+len1-1;
		rep(l2,r1+1,n-len2+1)
		{
			int r2=l2+len2-1,&res=g[l1][r1][l2][r2]=inf;
		//	debug(l1)sp,debug(r1)sp,debug(l2)sp,debug(r2)ln;
			if(S(l1,r1)^S(l2,r2)) continue;
			rep(i,l1+1,r1) if(c[l1]==c[i]) rep(j,l2,r2+1)
			{
				int k=G(l1+1,i-1,j,r2);if(k>n) continue;
				int t=G(i+1,r1,l2,j-1);if(t>n) continue;
				Min(res,max(max(k+1,t),2));
			}
			rep(i,l2,r2) if(c[l1]==c[i]) rep(j,l1,r1)
			{
				int k=G(l1+1,j,i+1,r2);if(k>n) continue;
				int t=G(j+1,r1,l2,i-1);if(t>n) continue;
				Min(res,max(max(k+1,t),2));
			}
			rep(i,l2,r2-1) if(c[r2]==c[i]) rep(j,l1-1,r1)
			{
				int k=G(l1,j,i+1,r2-1);if(k>n) continue;
				int t=G(j+1,r1,l2,i-1);if(t>n) continue;
				Min(res,max(max(k+1,t),2));
			}
			rep(i,l1,r1) if(c[r2]==c[i]) rep(j,l2,r2)
			{
				int k=G(l1,i-1,j,r2-1);if(k>n) continue;
				int t=G(i+1,r1,l2,j-1);if(t>n) continue;
				Min(res,max(max(k+1,t),2));
			}
		//	debug(l1)sp,debug(r1)sp,debug(l2)sp,debug(r2)sp,debug(res)ln;
		}
	}
	return 0;
}
inline int getf(int n)
{
	rep(i,1,n) f[i][i]=mp(1,1),f[i][i-1]=mp(0,0);
	rep(len,2,n) rep(l,1,n-len+1)
	{
		int r=l+len-1;pii &res=f[l][r]=mp(n,n),tp;
		tp=f[l+1][r],Min(res,P(tp,1,tp.sec+1));
		tp=f[l][r-1],Min(res,P(tp,1,tp.sec+1));
		if(c[l]==c[r]) tp=f[l+1][r-1],Min(res,P(tp,0,2));
		rep(i,l+1,r-1)
		{
			if(c[i]==c[l])
			{
				rep(j,l,i-1)
				{
					int k=G(l+1,j,i+1,r);if(k>n) continue;
					tp=f[j+1][i-1],Min(res,P(tp,0,max(k+1,2)));
				}
				rep(j,i+1,r+1)
				{
					int k=G(l+1,i-1,j,r);if(k>n) continue;
					tp=f[i+1][j-1],Min(res,P(tp,0,max(k+1,2)));
				}
			}
			if(c[i]==c[r])
			{
				rep(j,i+1,r)
				{
					int k=G(l,i-1,j,r-1);if(k>n) continue;
					tp=f[i+1][j-1],Min(res,P(tp,0,max(k+1,2)));
				}
				rep(j,l-1,i-1)
				{
					int k=G(l,j,i+1,r-1);if(k>n) continue;
					tp=f[j+1][i-1],Min(res,P(tp,0,max(k+1,2)));
				}
			}
		}
	//	debug(l)sp,debug(r)sp,debug(res.fir)sp,debug(res.sec)ln;
	}
	return 0;
}
int main()
{
	freopen("data.in","r",stdin),freopen("my_std.out","w",stdout);
	for(int n;scanf("%d",&n)!=EOF;)
	{
		assert(n>=1&&n<=50);
		rep(i,1,n) scanf("%d",&c[i]),assert(c[i]>=1&&c[i]<=50),s[i]=s[i-1]^(1ll<<c[i]);
		getLR(n),getg(n),getf(n);
		printf("%d %d\n",f[1][n].fir,f[1][n].sec);
	}
	return 0;
}
