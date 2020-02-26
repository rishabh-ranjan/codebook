int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int power(int x, int y, int m) { 
	int res = 1;
	while (y > 0) {
		if (y&1) res = res*x % m;
		y /= 2;
		x = x*x % m;
	}
	return res;
}
