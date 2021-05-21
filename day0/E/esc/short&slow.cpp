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
short f[77][77][77][77];
std::pair<int,int> g[77][77];
unsigned h[77],s[77];
int c[77];
short F(int i,int j,int k,int l)
{
    if(i>j&&k>l)return 0;
    if(s[i-1]^s[j]^s[k-1]^s[l])return 0x3f3f;
    if(i>j)i=1,j=0;
    if(k>l)k=1,l=0;
    short& ret=f[i][j][k][l];
    if(ret!=-1)return ret;
    ret=0x3f3f;
    for(int x=i;x<=j;++x)
    {
        if(i!=x&&c[x]==c[i])
        {
            for(int y=l;y>=k-1;y--)
            {
                short tmp=F(i+1,x-1,y+1,l);
                short tmp2=F(x+1,j,k,y);
                cmax(tmp2,1+tmp);
                cmax(tmp2,2);
                cmin(ret,tmp2);
            }
        }
        if(k<=l&&c[x]==c[l])
        {
            for(int y=l-1;y>=k-1;y--)
            {
                short tmp=F(i,x-1,y+1,l-1);
                short tmp2=F(x+1,j,k,y);
                cmax(tmp2,1+tmp);
                cmax(tmp2,2);
                cmin(ret,tmp2);
            }
        }
    }
    for(int x=k;x<=l;++x)
    {
        if(i<=j&&c[x]==c[i])
        {
            for(int y=i+1+(l-x&1);y<=j+1;y+=2)
            {
                short tmp=F(i+1,y-1,x+1,l);
                if(tmp<777)
                {
                    short tmp2=F(y,j,k,x-1);
                    cmax(tmp2,1+tmp);
                    cmax(tmp2,2);
                    cmin(ret,tmp2);
                }
            }
        }
        if(x!=l&&c[x]==c[l])
        {
            for(int y=i+(l-x&1^1);y<=j+1;y+=2)
            {
                short tmp=F(i,y-1,x+1,l-1);
                if(tmp<777)
                {
                    short tmp2=F(y,j,k,x-1);
                    cmax(tmp2,1+tmp);
                    cmax(tmp2,2);
                    cmin(ret,tmp2);
                }
            }
        }
    }
    return ret;
}
std::pair<int,int> G(int l,int r)
{
    if(g[l][r].second)return g[l][r];
    if(l>r)return std::make_pair(0,0);
    auto &ret=g[l][r];
    ret=std::make_pair(7777,7777);
    auto tmp=G(l+1,r);
    tmp.first+=1,tmp.second+=1;
    cmin(ret,tmp);
    tmp=G(l,r-1);
    tmp.first+=1,tmp.second+=1;
    cmin(ret,tmp);
    for(int x=l;x<=r;++x)
    {
        if(x!=l&&c[x]==c[l])
        {
            for(int y=l+1;y<=r;++y)
            {
                short ff=F(l+1,dmin(x,y)-1,dmax(x,y)+1,r);
                auto tmp=x>=y?G(y,x-1):G(x+1,y);
                auto ans=std::make_pair(tmp.first,dmax(dmax(2,ff+1),tmp.second));
                cmin(ret,ans);
            }
        }
        if(x!=r&&c[x]==c[r])
        {
            for(int y=l;y<r;++y)
            {
                short ff=F(l,dmin(x,y)-1,dmax(x,y)+1,r-1);
                auto tmp=x>=y?G(y,x-1):G(x+1,y);
                auto ans=std::make_pair(tmp.first,dmax(dmax(2,ff+1),tmp.second));
                cmin(ret,ans);
            }
        }
    }
    return ret;
}
int main()
{
	int n=io::F();
    for(int i=1;i<=n;++i)c[i]=io::F();
    srand(time(0));
    for(int i=1;i<=n;++i)h[i]=rand();
    for(int i=1;i<=n;++i)s[i]=s[i-1]^h[c[i]];
    memset(f,-1,sizeof(f));
    F(2,5,8,11);
    auto ans=G(1,n);
    printf("%d %d\n",ans.first,ans.second);
	return 0;
}