int t[4*N], z[4*N];

void apply(int v, int x) {
	t[v] += x;
	z[v] += x;
}

void push(int v) {
	apply(v*2, z[v]);
	apply(v*2+1, z[v]);
	z[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
	if (ql >= r || qr <= l) return;
	if (ql <= l && qr >= r) apply(v, x);
	else {
		push(v);
		int m = (l+r)/2;
		update(v*2, l, m, ql, qr, x);
		update(v*2+1, m, r, ql, qr, x);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int l, int r, int ql, int qr) {
	if (ql >= r || qr <= l) return 0;
	if (ql <= l && qr >= r) return t[v];
	else {
		push(v);
		int m = (l+r)/2;
		return query(v*2, l, m, ql, qr) + query(v*2+1, m, r, ql, qr);
	}
}

inline void update(int ql, int qr, int x) { update(1, 0, n+1, ql, qr, x); }

inline int query(int ql, int qr) { return query(1, 0, n+1, ql, qr); }
