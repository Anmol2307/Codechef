def modpow(base, exp, modulus):
  base %= modulus
  result = 1
  while (exp > 0):
    if (exp and 1):
      result = (result * base) % modulus
    base = (base * base) % modulus
    exp >>= 1
  return result

def modInverse(a, m):
  return modpow(a,m-2,m)


def main():
  t = int(raw_input())
  while (t > 0):
    x = int(raw_input())
    m = int(raw_input())
    n = int(raw_input())
    if (n == 1):
      print "0"
      t -= 1
      continue
    if (x == 1):
      print (m+1)%n
      t -= 1
      continue
    first = modpow(x,m+1,n)
    first -= 1
    if (first < 0):
      first += n
    second = modInverse(x-1,n)
    ans = (first*second)%n
    t -= 1
    print ans

main()
