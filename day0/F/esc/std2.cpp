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
const int T=41;
unsigned long long m[2][100][100][T];
struct idea
{
    int l[6];
    int g[6];
}id[222];
const int dx[6]={-1,-1,0,1,1,0};
const int dy[6]={1,0,-1,-1,0,1};
const int Z=20;
const int B=20;
unsigned long long (*f)[100][T]=m[0];
unsigned long long (*g)[100][T]=m[1];
int main()
{
	int n=io::F(),p=io::F();
    for(int i=1;i<=n;++i)
        for(int k=0;k<6;++k)
            id[i].l[k]=io::F(),id[i].g[k]=io::F();
    srand(time(0));
    std::random_shuffle(id+1,id+n+1);
    f[0][0][Z]=1llu<<Z;
    for(int i=1;i<=n;++i)
    {
        memset(g,0,sizeof(m[0]));
        for(int l=0;l<p;++l)
            for(int gg=0;gg<p;++gg)
            {
                for(int k=0;k<3;++k)
                {
                    int tol=(l+id[i].l[k])%p;
                    int tog=(gg+id[i].g[k])%p;
                    unsigned long long *F=f[l][gg],*G=g[tol][tog];
                    for(int y=Z-B;y<=Z+B;++y)
                        G[y+dy[k]]|=F[y]>>-dx[k];
                }
                for(int k=3;k<6;++k)
                {
                    int tol=(l+id[i].l[k])%p;
                    int tog=(gg+id[i].g[k])%p;
                    unsigned long long *F=f[l][gg],*G=g[tol][tog];
                    for(int y=Z-B;y<=Z+B;++y)
                        G[y+dy[k]]|=F[y]<<dx[k];
                }
            }
        std::swap(f,g);
    }
    int l=io::F(),g=io::F();
    if(f[l][g][Z]>>Z&1)
        puts("Chaotic Evil");
    else
        puts("Not a true problem setter");
   // for(int i=0;i<p;++i,puts(""))
    //    for(int j=0;j<p;++j)
      //      printf("%d ",(int)(f[Z][Z][i]>>j&1));
	return 0;
}