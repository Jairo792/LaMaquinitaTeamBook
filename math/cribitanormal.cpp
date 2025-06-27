constexpr int MAXN = 1000000;
bitset<MAXN + 1> is_prime;

void sieve() {
    is_prime.set();      // Mark all as potentially prime
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime

    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                is_prime[j] = 0;  // Mark multiples of i as not prime
        }
    }
}

