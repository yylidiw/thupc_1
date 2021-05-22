#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io
{
	int F()
	{
		int n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
	long long G()
	{
		long long n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
}
const int M=1000000007;
int f[2222][11][2222];
int p[777],pp;
class Init
{
    int v[2222];
    public:
    Init()
    {
        const int N=2000;
        for(int i=2;i<=N;++i)
        {
            if(!v[i])v[i]=++pp,p[pp]=i;
            for(int j=1;j<=v[i]&&i*p[j]<=N;++j)
                v[i*p[j]]=j;
        }
    }
}INIT;
std::bitset<2222> d[2222];
int main()
{
	int n=io::F(),m=io::F();
    long long k=io::F();
    f[1][0][0]=1;
    for(int i=1;i<=k&&i<=m;++i)
        if(k%i==0)
        {
            for(int x=0;x<n;++x)
                for(int j=0;j+i<=m;++j)
                    f[1][x+1][j+i]=(f[1][x+1][j+i]+f[1][x][j])%M;
        }
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j)
            if(i*k%j==0)d[i].set(j);
    for(int i=2;i<=m;++i)
    {
        long long min=m,mp;
        for(int j=1;j<=pp&&p[j]<=i;++j)
            if(i%p[j]==0)
            {
                int tmp=(d[i]^d[i/p[j]]).count();
                if(cmin(min,tmp))mp=p[j];
            }
        memcpy(f[i],f[i/mp],sizeof(f[i]));
        int (*F)[2222]=f[i];
        for(int v=1;v<=m;v++)
            if(d[i][v]&&!d[i/mp][v])
                for(int x=0;x<n;++x)
                    for(int j=0;j+v<=m;++j)
                        F[x+1][j+v]=(F[x+1][j+v]+F[x][j])%M;
    }
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        //printf("%d\n",f[i][n][i]);
        ans=(ans+f[i][n][i])%M;
    }
    printf("%d\n",ans);
	return 0;
}