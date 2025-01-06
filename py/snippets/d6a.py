m=open('d6.in').read().strip().split('\n')
maxr,maxs=len(m),len(m[0])
for zr in range(maxr):
  zs=m[zr].find('^')
  if zs>-1: break
r,s=zr,zs
dsr,hd=[(0,-1),(1,0),(0,1),(-1,0)],0
v={(r,s):1}
while -1<r+dsr[hd][1]<maxr and -1<s+dsr[hd][0]<maxs:
  if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#':
    hd=(hd+1)%4
  else:
    r,s=r+dsr[hd][1],s+dsr[hd][0]
    v[r,s]=1
print(len(v))
