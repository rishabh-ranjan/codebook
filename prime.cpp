// eg. factor(120) = [(2, 3), (3, 1), (5, 1)]
vpii factor(int n) {
	vpii r;
	int c = 0;
	while (n % 2 == 0) ++c, n /= 2;
	if (c) r.pb({2, c});
	for (int i = 3; i*i <= n; i += 2) {
		c = 0;
		while (n % i == 0) ++c, n /= i;
		if (c) r.pb({i, c});
	}
	if (n != 1) r.pb({n, 1});
	return r;
}
