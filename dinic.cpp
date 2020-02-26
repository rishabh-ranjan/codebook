// constructor parameter n+1 for 1-index, n for 0-index;
// n = number of vertices
struct Dinic {
	typedef long long fl; static const fl INF = 0x3f3f3f3f;
	typedef vector<int> vi; typedef vector<bool> vb; typedef vector<fl> vfl;
	vector<vi> g; vi l; int n, s, t; vector<vfl> c, f; vector<vb> r, d;
	Dinic(int n): n(n), g(n), l(n), c(n, vfl(n)), f(n, vfl(n)), r(n, vb(n)), d(n, vb(n)) {}
	bool bfs() {
		l.assign(n, -1); l[s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int u: g[v]) {
				if (l[u] != -1 || !c[v][u]) continue;
				l[u] = l[v]+1; q.push(u);
			}
		}
		d.assign(n, vb(n));
		return l[t] != -1;
	}
	int mn;
	bool dfs(int v) {
		if (v == s) mn = INF; if (v == t) return true;
		for (int u: g[v]) {
			if (!c[v][u] || l[u]<=l[v] || d[v][u]) continue;
			int omn = mn; mn = min(mn, c[v][u]);
			if (dfs(u)) {
				f[v][u] += mn; c[v][u] -= mn; c[u][v] += mn;
				return true;
			}
			d[v][u] = true; mn = omn;
		}
		return false;
	}
	fl max_flow(int s, int t) {
		this->s = s; this->t = t;
		while (bfs()) while (dfs(s));
		fl a = 0; for (int u: g[s]) a += f[s][u] - f[u][s];
		return a;
	}
	void add_edge(int a, int b, fl cap) {
		if (a == b) return;
		if (!r[a][b]) g[a].pb(b), g[b].pb(a);
		r[a][b] = r[b][a] = true;
		c[a][b] += cap;
	}
};
