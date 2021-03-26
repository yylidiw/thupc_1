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
__int128 m[2][66][66][100];
struct idea
{
    int l[6];
    int g[6];
}id[222];
const int dx[6]={-1,-1,0,1,1,0};
const int dy[6]={1,0,-1,-1,0,1};
const int Z=33;
const int B=30;
__int128 (*f)[66][100]=m[0];
__int128 (*g)[66][100]=m[1];
__int128 P;
#define cshl(x,d) ((x)<<(d)&P|(x)>>p-(d))
int main()
{
	int n=io::F(),p=io::F();
    for(int i=1;i<=n;++i)
        for(int k=0;k<6;++k)
            id[i].l[k]=io::F(),id[i].g[k]=io::F();
    srand(time(0));
    std::random_shuffle(id+1,id+n+1);
    P=1;
    P=(P<<p)-1;
    f[Z][Z][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int x=Z-B;x<=Z+B;++x)
            for(int y=Z-B;y<=Z+B;++y)
                for(int k=0;k<6;++k)
                {
                    int ox=x-dx[k];
                    int oy=y-dy[k];
                    __int128* F=f[ox][oy];
                    __int128* G=g[x][y];
                    if(k==0)
                        for(int j=0;j<p;++j)
                        {
                            int to=(j+id[i].l[k])%p;
                            G[to]=cshl(F[j],id[i].g[k]);
                        }
                    else
                        for(int j=0;j<p;++j)
                        {
                            int to=(j+id[i].l[k])%p;
                            G[to]|=cshl(F[j],id[i].g[k]);
                        }
                }
        std::swap(f,g);
    }
    int l=io::F(),g=io::F();
    if(f[Z][Z][l]>>g&1)
        puts("yes");
    else
        puts("no");
	return 0;
}