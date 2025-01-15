int max_id = 0;
for (int i = 0; i < r; i++)
  for (int j = 0; j < s; j++)
    if (ids[i][j] == -1) {
      ids[i][j] = max_id++;
      ofarbi({i, j});
    }
