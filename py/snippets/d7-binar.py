import time
t=time.time()
vys=0
for r in open('d7.in'):
  n,ns=r.split(':')
  n,ns=int(n),list(map(int,ns.split()))
  d=len(ns)-1           # čísla budú d-bitové
  fmt='0'+str(d)+'b'    # vyvoríme si formát
  for x in range(2**d): # všetky d bitové čísla
    v=ns[0]             # prvé číslo zo vstupu
    # vytvoríme dvojice ($c_{j+1}$,bit_j) t.j.
    # $j+1$-vé číslo zo vstupu, $j$-ty bit čísla $x$  
    for op,c in zip(format(x, fmt),ns[1:]):
      v=v+c if op=='0' else v*c
    if v==n:  # podarilo sa vypočítať $n$
      vys+=n
      break
print(vys, time.time()-t)

