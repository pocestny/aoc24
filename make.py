#!/usr/bin/python3
"""
Príklady sa inkludujú zo súborov xx.html kde xx je číslo dňa. 
V súbore sa dá použiť 

@file@ na vysádzanie zdrojáku snippets/file.cc 
~program~ na inline vysádzanie kódu

"""
import html
import re

def code(s):
    return '<code class="nowrap language-cpp" style="display:inline;padding:0pt!important;">'+html.escape(s)+'</code>'

def precode(s):
    return '<pre><code class="language-cpp">'+html.escape(s)+'</code></pre>'

def process(s):
    out.write(re.sub('@([^@]*)@',lambda x:precode(open('./snippets/'+x.group(1)+'.cc').read()),re.sub('~([^~]*)~',lambda x: code(x.group(1)),s),flags=re.S))

def include(file):
    out.write('<div class="hidden priklad" id="priklad-{}">'.format(file))
    process(open(file+'.html').read())
    out.write('</div>')


out = open('index.html','w')
out.write(open('header.html').read())

out.write("""
<h1><b>Advent of Code 2024: komentované riešenia v C++</b></h1>
<div class="grid-container">
<div class="grid-menu">
<aside>
<nav><ul>
<li onclick="set_priklad('00')"><a href="#">úvod</a></li>          
""")

nDays=5
for i in range(1,nDays+1):
    out.write('<li onclick="set_priklad(\'{id:02d}\')"><a href="#"> {id:02d} </a></li>'.format(id=i))


out.write("""
</ul></nav></aside></div>
<div class="grid-content">

<div class="priklad" id="priklad-00">
""")          
process(open('uvod.html').read())
out.write("</div>")


for i in range(1,nDays+1):
    include('{:02d}'.format(i))


out.write(open('footer.html').read())
out.close()
