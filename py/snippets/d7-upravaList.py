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
      q=c*x
      nbol.append(q)      
      q=c+x
      nbol.append(q) 
    bol=nbol  
    d+=len(bol)
  if n in bol:
    vys+=n
print(vys,'cas:',time.time()-t,'zápisov do pamäti:',d)

