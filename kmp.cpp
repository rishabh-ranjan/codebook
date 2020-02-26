inline ll ch(char c) { return c-'a'; } // maps charset to 0-indexed ll's
const ll A = 26; // size of charset
 
// stores prefix function of s in pi
void calc_pi(const string &s, ll pi[]) {
	if (!sz(s)) return;
	pi[0] = 0;
	irep(i, sz(s)-1) {
		ll j = pi[i-1];
		for (; j > 0 && s[i] != s[j]; j = pi[j-1]) ;
		pi[i] = j ? j+1 : s[i] == s[j];
	}
}
 
// transition function for the kmp automaton
// tr = (sz(s)+1) * A array
void calc_tr(string &s, ll pi[], ll tr[][A])
{
	if (!sz(s)) return;
	rep(p, sz(s)+1)
		rep(c, 26) {
			ll j = p;
			for (; j > 0 && c != ch(s[j]); j = pi[j-1]) ;
			tr[p][c] = j ? j+1 : c == ch(s[j]);
		}
}

