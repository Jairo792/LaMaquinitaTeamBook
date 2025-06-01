int count_divisors(int n) {
    int res = 1;
    for (int i = 2; i * i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        res *= (count + 1);
    }
    if (n > 1) res *= 2; // n es primo > sqrt(original n)
    return res;
}

