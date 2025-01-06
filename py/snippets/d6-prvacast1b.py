if m[r+dsr[hd][1]][s+dsr[hd][0]] == '#':
  if hd+1<4:
    hd+=1
  else:
    hd=0
  #hd=(hd+1)%4  # elegantnejšie zapísanie predchádajúcich 4 riadkov
else:
  r,s=r+dsr[hd][1],s+dsr[hd][0]


