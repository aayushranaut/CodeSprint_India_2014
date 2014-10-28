t = int(raw_input())

MOD = 10**9 + 7
def modexp(a,b):
    res = 1
    while b:
        if b&1:
            res *= a
            res %= MOD
        a = (a*a)%MOD
        b /= 2
    return res
fn = [1 for _ in xrange(100001)]
ifn = [1 for _ in xrange(100001)]
for i in range(1,100000):
    fn[i] = fn[i-1] * i
    fn[i] %= MOD
    ifn[i] = modexp(fn[i],MOD-2)
def nCr(n,k):
    return fn[n] * ifn[k] * ifn[n-k]
for ti in range(t):
    n = int(raw_input())
    a = map(int,raw_input().split())
    ans = 0
    for i in range(n):
        if i%2==0:
            ans += nCr(n-1,i)%MOD * a[i]%MOD
        else: 
            ans -= nCr(n-1,i)%MOD * a[i]%MOD
        ans %= MOD
    print ans