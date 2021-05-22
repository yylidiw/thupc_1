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
int f[11][2222];
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
int d[2222],pd;
int main()
{
	int n=io::F(),m=io::F();
    long long k=io::F();
    int ans=0;
    for(int z=1;z<=m;++z)
    {
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=z;++i)
            if(z*k%i==0)
            {
                for(int x=0;x<n;++x)
                    for(int j=0;j+i<=z;++j)
                        f[x+1][j+i]=(f[x+1][j+i]+f[x][j])%M;
            }
        ans=(ans+f[n][z])%M;
        //printf("%d\n",f[n][z]);
    }
    
    printf("%d\n",ans);
	return 0;
}