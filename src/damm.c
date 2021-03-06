const int m[] = {
  0, 3, 1, 7, 5, 9, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0,
  7, 0, 9, 2, 1, 5, 4, 8, 6, 3, 0, 0, 0, 0, 0, 0,
  4, 2, 0, 6, 8, 7, 1, 3, 5, 9, 0, 0, 0, 0, 0, 0,
  1, 7, 5, 0, 9, 8, 3, 4, 2, 6, 0, 0, 0, 0, 0, 0,
  6, 1, 2, 3, 0, 4, 5, 9, 7, 8, 0, 0, 0, 0, 0, 0,
  3, 6, 7, 4, 2, 0, 9, 5, 8, 1, 0, 0, 0, 0, 0, 0,
  5, 8, 6, 9, 7, 2, 0, 1, 3, 4, 0, 0, 0, 0, 0, 0,
  8, 9, 4, 5, 3, 6, 2, 0, 1, 7, 0, 0, 0, 0, 0, 0,
  9, 4, 3, 8, 6, 1, 7, 2, 0, 5, 0, 0, 0, 0, 0, 0,
  2, 5, 8, 1, 4, 3, 6, 7, 9, 0, 0, 0, 0, 0, 0, 0
};

int damm_digit(const char* data) {
  if (*data == '\0') return 0;

  int x = 0;
  unsigned int d;

  do {
    d = *data++ - 48;
    if (d > 9) return -1;
    x = m[(x<<4) + d];
  } while(*data);

  return x;
}

int damm_valid(const char* data) {
  return damm_digit(data) == 0;
}
