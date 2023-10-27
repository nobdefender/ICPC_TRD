// Theme: Factorization

// Algorithm: Trivial Algorithm
// Complexity: O(sqrt(N))

auto factors(int n) {
  vector<int> factors;

  for (int i = 2; i * i <= n; i++) {
    if (n % i)
      continue;
    while (n % i == 0)
      n /= i;
    factors.push_back(i);
  }

  if (n != 1)
    factors.push_back(n);

  return factors;
}

// Algorithm: Factorization With Sieve
// Complexity: O(N*log(log(N)))

auto factors_sieve(int n) {
  vector<int> factors,
      sieve = get_sieve(n + 1);

  while (sieve[n]) {
    factors.push_back(sieve[n]);
    n /= sieve[n];
  }

  if (n != 1)
    factors.push_back(n);

  return factors;
}

// Algorithm: Factorization With Primes
// Complexity: O(sqrt(N)/log(sqrt(N)))

auto factors_primes(int n) {
  vector<int> factors,
      primes = get_primes(n + 1);

  for (auto &i : primes) {
    if (i * i > n)
      break;
    if (n % i)
      continue;
    while (n % i == 0)
      n /= i;
    factors.push_back(i);
  }

  if (n != 1)
    factors.push_back(n);

  return factors;
}

// Algorithm: Ferma Test
// Complexity: O(K*log(N))

bool ferma(int n) {
  if (n == 2)
    return true;

  uniform_int_distribution<int> distA(2, n - 1);

  for (int i = 0; i < 1000; i++) {
    int a = distA(reng);
    if (gcd(a, n) != 1 ||
        binpow(a, n - 1, n) != 1)
      return false;
  }

  return true;
}

// Algorithm: Pollard Rho Algorithm
// Complexity: O(N^(1/4))

int get_random_number(int l, int r) {
  random_device random_device;
  mt19937 generator(random_device());
  uniform_int_distribution<int> distribution(l, r);

  return distribution(generator);
}

int f(int x, int c, int n) {
  return ((x * x + c) % n);
}

int ff(int n) {
  int g = 1;
  for (int i = 0; i < 5; i++) {
    int x = get_random_number(1, n);
    int c = get_random_number(1, n);
    int h = 0;
    while (g == 1) {
      x = f(x, c, n) % n;
      int y = f(f(x, c, n), c, n) % n;
      g = gcd(abs(x - y), n);
      if (g == n) {
        g = 1;
      }
      h++;

      if (h > 4 * (int)pow(n, 1.0 / 4)) {
        break;
      }
    }

    if (g > 1) {
      return g;
    }
  }

  return -1;
}

signed main() {
  // ...read n...
  vector<int> a;
  while (n > 1) {
    int m = ff(n);
    if (m > 0) {
      n = n / m;
      a.push_back(m);
    } else {
      break;
    }
  }

  vector<int> ans;
  a.push_back(n);

  for (auto &it : a) {
    int i = 2;
    int m = it;
    while (i * i <= m) {
      if (m % i == 0) {
        ans.push_back(i);
        m = m / i;
      } else {
        i += 1;
      }
    }

    ans.push_back(m);
  }

  sort(all(ans));
}