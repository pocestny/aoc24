for r in open('d7e.in'):
  n,ns=r.split(':')
  n,ns=int(n),list(map(int,ns.split()))
  # to iste ako predch. riadok, inak zapísané
  #n,ns=int(n),[int(x) for x in ns.split()] 
  # tu treba spracovať jedno zadanie úlohy


#alternatívne čítanie vstupu využitím knižnice read
import read
for r in open('d7e.in'):
  n,*ns=list(map(int,re.findall(r'(\d+):?\n?', r)))