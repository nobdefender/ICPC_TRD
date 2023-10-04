// Theme: Prime Numbers

// Algorithm: Eratosthenes Sieve
// Complexity: O(N*log(log(N)))

//  = 0 - Prime, 
// != 0 - Lowest Prime Divisor
auto get_sieve(int n) {
    vector<int> sieve(n);  // Sieve
    sieve[0] = sieve[1] = 1;

    for (int i = 2; i * i < n; i++)
        if (!sieve[i])
            for (int j = i * i; j < n; j += i)
                sieve[j] = i;

    return sieve;
}

// Algorithm: Prime Numbers With Sieve
// Complexity: O(N*log(log(N)))

auto get_primes(int n) {
    vector<int> primes, sieve = get_sieve(n);

    for (int i = 2; i < sieve.size(); i++)
        if (!sieve[i])
            primes.push_back(i);

    return primes;
}

// Algorithm: Linear Algorithm
// Complexity: O(N)

// lp[i] = Lowest Prime Divisor
auto get_sieve_primes(int n, vector<int> &primes) {
    vector<int> lp(n);
    lp[0] = lp[1] = 1;

    for (int i = 2; i < n; i++) {
        if (!lp[i]) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() &&
                    primes[j] <= lp[i] &&
                    i * primes[j] < n; j++)
            lp[i * primes[j]] = primes[j];
    }

    return lp;
}