dsr=[(0,-1),(1,0),(0,1),(-1,0)]
m=open('d6.in').read().split('\n')
maxr,maxs=len(m),len(m[0])
for zr in range(maxr):
  zs=m[zr].find('^')
  if zs>-1: break

def obid(r,s):
  v,hd,rpt={(r,s):1},0,{}
  while -1<r+dsr[hd][1]<maxr and -1<s+dsr[hd][0]<maxs:
    if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#':
      hd=(hd+1)%4
    else:
      if (hd,r,s) in rpt:
        return 0
      else:
        rpt[(hd,r,s)]=1
      r,s=r+dsr[hd][1],s+dsr[hd][0]
      v[r,s]=1
  return len(v)

print('part1:',obid(zr,zs))
vys=0
m=[list(r) for r in m]
for r in range(maxr):
  for s in range(maxs):
    if m[r][s] != '#':
      m[r][s]='#'
      if obid(zr,zs) == 0:
        vys+=1
      m[r][s]='.'
print('part2:',vys)
