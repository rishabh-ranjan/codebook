#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ "; for(auto v : V) os << v << " "; return os << "]";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1> void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1<<" | ";
	__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mems(x, y) memset(x, y, sizeof(x))
#define rep(i, n) for (int i = 0; i < n; ++i)
#define irep(i, n) for (int i = 1; i <= n; ++i)
#define print(x) cout << x << '\n'
#define err(x) clog << x << '\n'
typedef long long ll;
#define int ll
typedef long double ld;
#define double ld
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = (119<<23)+1;
const int M = 1e9+7;

void solve();

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(15);
	int t; cin >> t;
	irep(i, t) {
		cout << "Case #" << i << endl;
		solve();
	}
}

const int N = 1e5+5;

void solve()
{

