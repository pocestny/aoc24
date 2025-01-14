import time
t=time.time()

def trojkove(x,d):  # prevod čísla x do d-ciferného čísla 
  v=[]              # v trojkovej sústave
  for m in range(d):
    v.append(x%3) # vyššia cifra ide na koniec
    x=x//3
  return v  # 'otočený' zoznam cifier trojkovej reprezentácie x

vys=0
for r in open('d7.in'):
  n,ns=r.split(':')
  n,ns=int(n),list(map(int,ns.split()))
  d=len(ns)-1           # čísla budú d-ciferné
  for x in range(3**d): # všetky d ciferné čísla v trojkovej sústave
    trojx=trojkove(x,d) # reprezent. x ako d-ciferné číslo v troj. sústave 
    v=ns[0]             # prvé číslo zo vstupu
    # vytvoríme dvojice ($c_{j+1}$,bit_j) t.j.
    # $j+1$-vé číslo zo vstupu, $j$-ta cifra čísla $x$  
    for op,c in zip(trojx,ns[1:]):
      if op==0:
        v+=c
      elif op==1:
        v*=c
      else:
        v=int(str(v)+str(c))
    if v==n:  # podarilo sa vypočítať $n$
      vys+=n
      break   # keď nájdeme riešenie, pripočítame len raz, preto break
print(vys,'čas:',time.time()-t)

