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
int st[333],tst;
int main()
{
	char s[111];
    int ta=1;
    while(1)
    {
        sprintf(s,"../data/%d.in",ta);
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
    int c=io::F();
    int a[333],v[333]={0};
    for(int i=1;i<=c;++i)
    {
        int x;
        do x=R(1,n); while(v[x]);
        v[x]=1;
        a[i]=x;
    }
    int k=io::F();
    int l=1,r=1;
    std::deque<int> q;
    for(int i=1;i<=n;++i)
    {
        int d=R(1,l+r);
        if(tst)
        {
            int x=a[R(1,c)];
            s[++tst]=x;
            if(d<=l)q.push_front(x);
                else q.push_back(x);
        }
        else
        {
            int x=a[R(1,c)];
            if(d<=l)q.push_front(x);
                else q.push_back(x);
        }
        
    }
	return 0;
}