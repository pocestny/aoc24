map<int, bool> m;
m[3] = true;
cout << m.size() << endl;  // tu sa vypíše 1
if (m[4]) cout << "nikdy tu nebudem\n";
cout << m.size() << endl;  // tu sa vypíše 2
