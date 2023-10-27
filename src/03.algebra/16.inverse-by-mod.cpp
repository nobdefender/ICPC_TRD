int gcd(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }

  int temp_x = 0, temp_y = 0;
  int gcd_result = gcd(b % a, a, temp_x, temp_y);
  x = temp_y - (b / a) * temp_x;
  y = temp_x;

  return gcd_result;
}

int obr_by_mod(int a, int m) {
  int x = 0, y = 0;
  int temp = gcd(a, m, x, y);

  return (x % m + m) % m;
}