def euclidean(a, b):
    if b == 0:
        return a
    return euclidean(b, a % b)


def stein(a, b, c=1):
    if a == 0:
        return b * c
    if b == 0:
        return a * c

    if a % 2 == 0 and b % 2 == 0:
        return stein(a // 2, b // 2, c * 2)
    elif a % 2 == 0:
        return stein(a // 2, b, c)
    elif b % 2 == 0:
        return stein(a, b // 2, c)
    elif a > b:
        return stein(a - b, b, c)
    else:
        return stein(a, b - a, c)


def euler(n):
    result = n
    p = 2

    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1

    if n > 1:
        result -= result // n

    return result


if __name__ == "__main__":
    a, b = map(int, input("Enter two numbers: ").split())
    n = int(input("Enter one number: "))

    print(f"Euclidean GCD is: {euclidean(a, b)}")
    print(f"Stein GCD is: {stein(a, b)}")
    print(f"Euler's Totient is: {euler(n)}")
