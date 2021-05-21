#include<bits/stdc++.h>
#define gc getchar()
#define pc putchar
#define li long long
using namespace std;
inline li read(li l = 0,li r = 1e9){
	li x = 0;
	int c = gc;
	while(c < '0' || c > '9') assert(c == ' ' || c == '\n' || c == '\r'),c = gc;
	while(c >= '0' && c <= '9') x = x * 10 + c - '0',c = gc;
	assert(c == -1 || c == ' ' || c == '\n' || c == '\r');
	assert(x >= l && x <= r);
	return x;
}
inline void eof(){
	char c;
	do{
		c = gc;
		assert(c == ' ' || c == '\n' || c == '\r' || c == -1);
	}while(c != -1);
}
int main(){
	read(1,10);read(1,2000);read(1,1e9);
	eof();
	return 0;
}
