import time
t,d=time.time(),0
vys=0
for r in open('d7.in'):
  n,ns=r.split(':')
  n,ns=int(n),list(map(int,ns.split()))
  bol=[ns[0]]
  for x in ns[1:]:
    nbol=[]
    for c in bol:
      nbol.extend([c*x,c+x,int(str(c)+str(x))])
    bol=list(filter(lambda x: x<=n,nbol))
    d+=len(bol)
  if n in bol:
    vys+=n
print(vys,'cas:',time.time()-t,'zápisov do pamäti:',d)

