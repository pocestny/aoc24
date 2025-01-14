def obid(r,s):
  v,hd,rpt={(r,s):1},0,{}
  while -1<r+dsr[hd][1]<maxr and -1<s+dsr[hd][0]<maxs:
    if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#':
      hd=(hd+1)%4
    else:
      if (hd,r,s) in rpt:  # bol už na políčku r,s v smere hd? 
        return 0           # áno už bol -> chodí v cykle
      else:                # ešte nebol
        rpt[(hd,r,s)]=1    # poznačíme si, že tam je
      r,s=r+dsr[hd][1],s+dsr[hd][0]
      v[r,s]=1
  return len(v)
