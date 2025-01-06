
while -1<r+dsr[hd][1]<maxr and -1<s+dsr[hd][0]<maxs: #pokiaľ sme na ploche
  if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#': # narazili sme?
    hd=(hd+1)%4  # narazil, otočíme sa
  else:
    r,s=r+dsr[hd][1],s+dsr[hd][0] # nenarazili, urobíme krok v smere hd

