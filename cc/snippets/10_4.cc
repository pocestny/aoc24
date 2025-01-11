vector<string> in;

string line;
in.push_back("#");                 // prvý riadok je placeholder, potom ho upravíme
                                   // (lebo zatiaľ nevieme, aký bude veľký)
while (getline(cin, line)) 
  in.push_back("#" + line + "#");  // na začiatok aj koniec dáme zarážku
                                   // operácia "A + B" na stringoch vyrobí nový string, 
                                   // do ktorého skopíruje za sebou najprv A a potom B
in.push_back(string(in.back().size(), '#'));  // na koniec dám riadok zarážky
                                              // string(n,'#') vyrobí string dĺžky n
                                              // ktorý obsahuje samé znaky '#'
                                              // in.back().size() je dĺžka posledného riadka
in[0] = in.back();                 // nakoniec posledný riadok skopírujeme do prvého 
