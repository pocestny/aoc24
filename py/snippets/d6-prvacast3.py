v={}        # v bude slovník (videné)
v[r,s]=1    # poznačíme si, že na políčku r,s už bol
# v={(r,s):1}  # to isté, čo predch. 2 riadky
while -1<r+dsr[hd][1]<maxr and -1<s+dsr[hd][0]<maxs:
  if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#': # narazili sme?
    hd=(hd+1)%4  # narazil, otočíme sa
  else:
    r,s=r+dsr[hd][1],s+dsr[hd][0] # nenarazili, urobíme krok v smere hd
    v[r,s]=1  # poznačíme si, že sme tu už boli
print('cast 1.:', len(v))
