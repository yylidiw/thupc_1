import random
cnt=0
for t in range(10000):
    a=[1 for i in range(50)]
    b=[-1 for i in range(50)]
    a=a+b
    random.shuffle(a)
    sum=0
    for i in range(100):
        sum+=a[i]
        if(abs(sum)>11):
            cnt+=1
            break
print(cnt)
