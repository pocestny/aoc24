#!/usr/bin/python3
"""
Príklady sa inkludujú zo súborov xx.html kde xx je číslo dňa. 

V súbore sa dá použiť 
@file@ na vysádzanie zdrojáku snippets/file.cc 
~program~ na inline vysádzanie kódu

"""
import html
import re
import os
from distutils.dir_util import copy_tree

# vyrob destination
outDir = './build'
os.makedirs(outDir, exist_ok=True)

# skopiruj css a js
copy_tree("./js",outDir+"/js")
copy_tree("./css",outDir+"/css")

# nazvy prikladov a dní
nazvy=["úvod","Historian Hysteria","Red-Nosed Reports","Mull It Over","Ceres Search","Print Queue",
       "Guard Gallivant","Bridge Repair","Resonant Collinearity","Disk Fragmenter","Hoof It",
       "Plutonian Pebbles","Garden Groups","Claw Contraption","Restroom Redoubt","Warehouse Woes",
       "Reindeer Maze","Chronospatial Computer","RAM Run","Linen Layout","Race Condition",
       "Keypad Conundrum","Monkey Market","LAN Party","Crossed Wires","Code Chronicle"]

dni=["","Prvý","Druhý","Tretí","Štvrtý","Piaty","Šiesty","Siedmy","Ôsmy","Deviaty","Desiaty","Jedenásty",
     "Dvanásty","Trinásty","Štrnásty","Pätnásty","Šestnásty","Sedemnásty","Osemnásty","Devätnásty",
     "Dvadsiaty","Dvadsiaty prvý","Dvadsiaty druhý","Dvadsiaty tretí","Dvadsiaty štvrtý","Dvadsiaty piaty"]

# ###########################  VYROBA INDEXU ##############################################
# riadok tabulky s obsahom na hlavnej stranke
def zapis_index_toc_riadok(index,i):
    index.write("""
<tr><td align="center"><a href="./c-{:02d}.html"> cc </a>
</td><td><span style="padding-left:3ex;">{:02d}: {}</span></td> 
<td align="center"><a href="./p-{:02d}.html"> py </a>
</td></tr>
    """.format(i,i,nazvy[i],i))                


# vyrob hlavny index.html
# vlozi sa text z  ./templates/uvod.html
def vyrob_index():
    index = open(outDir+'/index.html','w')
    index.write(open('./template/header.html').read())
    index.write(open('./template/uvod.html').read())
    index.write("""
<div class="two-col" style="grid-gap:20%!important;">            
<div class="col">
<table>""")
    for i in range(13):
        zapis_index_toc_riadok(index,i)
    index.write("""
</table>
</div>            
<div class="col">
<table>""")
    for i in range(13,26):
        zapis_index_toc_riadok(index,i)
    index.write("""
</table>
</div>            
</div>""")
    index.write(open('./template/footer.html').read())
    index.close()



################################  VYROBA SUBOROV ###############################################
# vyroby subor s dnom v danom jazyku
# puzije sa text z cc/<day>.html resp. py/<day>.html
hljsl=['language-cpp','language-python']
def code(lang,s):
    return '<code class="nowrap '+hljsl[lang]+'" style="display:inline;padding:0pt!important;">'+html.escape(s)+'</code>'

def precode(lang,s):
    return '<pre><code class="'+hljsl[lang]+'">'+html.escape(s)+'</code></pre>'

def open_s(f):
    x = open(f,'a+')
    x.close()
    return open(f)

def vyrob_den(day,lang):
    prefix=['c','p']
    dst=['cc','py']
    vjazyku=['C++','Pythone']

    out = open(outDir+'/{}-{:02d}.html'.format(prefix[lang],day),'w')
    out.write(open('./template/header.html').read())
    out.write("""
<h1><b>Advent of Code 2024: komentované riešenia v {}</b></h1>
<div class="grid-container">
<div class="grid-menu"><aside><nav><ul><li><a href="./index.html">úvod</a></li>""".format(vjazyku[lang]))
   
    for i in range(1,26):
        if i==day:
            out.write('<li><a href="./{}-{:02d}.html">{:02d}-{}</a></li>'.format(prefix[1-lang],i,i,dst[1-lang]))
        else:
            out.write('<li><a href="./{}-{:02d}.html">{:02d}</a></li>'.format(prefix[lang],i,i))
     
    out.write("""
</ul></nav></aside></div>
<div class="grid-content">""")
    if day>0:
        out.write('<h2>{} deň: {}</h2>'.format(dni[day],nazvy[day]))
        out.write('<a href="https://adventofcode.com/2024/day/{}" target=_blank>zadanie</a><hr/>'.
              format(day))
    
    out.write(
        re.sub(
            '@([^@]*)@',
            lambda x:precode(lang,open_s('./{d}/snippets/{g}.{d}'.format(d=dst[lang],g=x.group(1))).read()),
            re.sub(
                '~([^~]*)~',
                lambda x:code(lang, x.group(1)), 
                open_s('./{}/{:02d}.html'.format(dst[lang],day)).read(),flags=re.S)))

    out.write("</div></div>")
    out.write(open('./template/footer.html').read())
    out.close()




vyrob_index()

for day in range(26):
    vyrob_den(day,0)    
    vyrob_den(day,1)    

