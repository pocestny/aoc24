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
