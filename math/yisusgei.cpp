def fastExponentiation(base, exponent):
    result = 1
    base = base % MOD
    while exponent > 0:
        if (exponent % 2) == 1:
            result = (result * base) % MOD
        exponent = exponent // 2
        base = (base * base) % MOD
    return result
