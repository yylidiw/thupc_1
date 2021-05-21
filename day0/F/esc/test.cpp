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
double f[111][111][44];
int main()
{
    const int B=10;
	int n=io::F();
    f[0][0][22]=1;
    for(int i=0;i<=n/2;++i)
        for(int j=0;j<=n/2;++j)
            if(i+j!=n)
                for(int x=22-B;x<=22+B;++x)
                if(f[i][j][x])
                {
                    f[i+1][j][x+1]+=f[i][j][x]*(double)(n/2-i)/(n-i-j);
                    f[i][j+1][x-1]+=f[i][j][x]*(double)(n/2-j)/(n-i-j);
                }
    printf("%.9lf\n",f[n/2][n/2][22]);
	return 0;
}