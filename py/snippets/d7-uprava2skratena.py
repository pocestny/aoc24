import time
t,d=time.time(),0
vys=0
for n,ns in [it.split(':') for it in open('d7.in').read().split('\n')]:
  n,bol=int(n),[int(n)]
  for x in map(int,ns.split()[::-1]):
    bol=[it//x for it in bol if it%x==0]+[it-x for it in bol if x<=it] \
         +[it//10**len(str(x)) for it in bol if str(it).endswith(str(x))] # len pre 2. časť
    d+=len(bol)
  vys+=n if 0 in bol else 0
print(vys,'čas:',time.time()-t,'zápisov do pamäti:',d)
