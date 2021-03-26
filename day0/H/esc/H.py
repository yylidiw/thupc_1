n,k,x = map(int,input().split())
ans = 0
k=k+1
if n<k*k:
    ans = (n+n//k-1)//(n//k)
else:
    r = n%k
    if r==0:
        ans = k
    else:
        ans = k+1

if ans==x :
    print("Correct, but it doesn't necessarily mean that you can win the Turing Award.")
else:
    print("Wrong, don't cheat me, you are too far away from the Turing Award.")
    if x>ans:
        print("1")
    else:
        print("0")