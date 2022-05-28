//Whole package to deal with long nCrs
  fac[0] = 1;
  for (int i = 1; i < 1000001; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  auto powmod = [&] (int a, int b) {
    int res=1;
    a %= mod;
    for(; b; b >>= 1) {
      if (b & 1) {
        res = (res * a) % mod;
      }
      a = (a*a) % mod;
    }
    return res;
  };
  auto binom = [&] (int x, int y) {
    return fac[x] * powmod(fac[y] * fac[x-y], mod - 2) % mod;
  };
