vys=0
for n,ns in [it.split(':') for it in open('d7.in').read().split('\n')]:
  n,ns=int(n),list(map(int,ns.split()))
  bol=[ns[0]]
  for x in ns[1:]:
    bol=[it+x for it in bol]+[it*x for it in bol if it*x<=n] \
         +[int(str(it)+str(x)) for it in bol] # len pre časť 2
  if n in bol:
    vys+=n
print('vys:',vys)

