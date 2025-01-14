# idea od žiakov kvinta a 2b na gjh 9.1.2025, vymysleli na hodine
# ideme od konca...
# brutálne rýchlešie a použije len zlomok pamäte
import time
t,d=time.time(),0
vys=0
for r in open('d7.in'):
  n,ns=r.split(':')
  n,ns=int(n),list(map(int,ns.split()))[::-1]
  bol=[n]
  for x in ns:
    nbol=[]
    for c in bol:
      if c%x==0:
        nbol.append(c//x)      
      if x<=c:
        nbol.append(c-x)
      if str(c).endswith(str(x)):     # len pre časť 2
        sc=str(c)
        nsc=sc[:len(sc)-len(str(x))]
        nbol.append(int(nsc) if nsc!='' else 0)            
    bol=nbol  
    d+=len(bol)
  if 0 in bol:
    vys+=n
print(vys,'čas:',time.time()-t,'zápisov do pamäti:',d)

