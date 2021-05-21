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
int R(int l,int r)
{
    return rand()%(r-l+1)+l;
}
int main()
{
	char s[111];
    int ta=1;
    while(1)
    {
        sprintf(s,"D:/OI/thupc_1/day0/E/data/%d.in",ta);
        FILE *p=fopen(s,"r");
        if(p)
        {
            fclose(p);
            ++ta;
        }
        else break;
    }
    freopen(s,"w",stdout);
    int n=io::F();
    printf("%d\n",n);
    srand(time(0));
    int a[4444];
    int k=io::F();
    for(int i=1;i<=k;++i)
        a[i]=R(1,n);
    for(int i=1;i<=n;++i)
        printf("%d%c",a[R(1,k)]," \n"[i==n]);
	return 0;
}