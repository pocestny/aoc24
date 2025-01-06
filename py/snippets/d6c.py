dsr=[(0,-1),(1,0),(0,1),(-1,0)]
m=open('d6.in').read().split('\n')
maxr,maxs=len(m),len(m[0])
for zr in range(maxr):
  zs=m[zr].find('^')
  if zs > -1: break

def obid(r,s):
  v,hd,rpt={(r,s):1},0,{}
  while -1 < r+dsr[hd][1] < maxr and -1 < s+dsr[hd][0] < maxs:
    if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#':
      if (hd,r,s) in rpt: return None
      rpt[(hd,r,s)]=1
      hd=(hd+1)%4
    else:
      r,s=r+dsr[hd][1],s+dsr[hd][0]
      v[r,s]=1
  return v

v=obid(zr,zs)
print('part1:',len(v))
vys,m=0,[list(r) for r in m]
for r,s in v: # ideme len cez tie, kde sme už boli - pozorovanie Rasťa
  m[r][s]='#'
  if obid(zr,zs) == None:
    vys+=1
  m[r][s]='.'
print('part2:',vys)
