// https://leetcode.com/problems/valid-perfect-square

class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        def get_primes_list(n: int):
            probable_primes = [True for _ in range(n)]
            for i in range(2, n):
                if probable_primes[i]:
                    j = 2
                    while i * j < n:
                        probable_primes[i * j] = False
                        j += 1
            return [idx for idx in range(2, len(probable_primes)) if probable_primes[idx]]
        primes = get_primes_list(num // 2)
        idx = 0
        factors = {}
        while num > 1:
            if num % primes[idx] == 0:
                num //= primes[idx]
                try:
                    factors[primes[idx]] += 1
                except:
                    factors[primes[idx]] = 1
            else: idx += 1
        divisors = 1
        for _, exp in factors.items():
            divisors *= (exp + 1)
        return divisors % 2 == 1