// 1-indexed, i.e. g[1] .. g[n] should exist
bool is_bipartite(int n, vi g[]) {
	queue<int> q; int side[n+1]; mems(side, -1);
	irep(i, n) if (side[i] == -1) {
		q.push(i); side[i] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int u: g[v]) {
				if (side[u] == -1) side[u] = side[v] ^ 1, q.push(u);
				else if (side[u] == side[v]) return false;
			}
		}
	}
	return true;
}
