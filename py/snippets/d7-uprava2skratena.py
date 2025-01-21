import time
t,d=time.time(),0
vys=0
for n,ns in [it.split(':') for it in open('d7.in').read().split('\n')]:
  n,ns=int(n),list(map(int,ns.split()))[::-1]
  bol=[n]
  for x in ns:
    bol=[it//x for it in bol if it%x==0]+[it-x for it in bol if x<=it] \
         +[it//10**len(str(x)) for it in bol if str(it).endswith(str(x))] # len pre 2. časť
    d+=len(bol)
  if 0 in bol:
    vys+=n
print(vys,'čas:',time.time()-t,'zápisov do pamäti:',d)