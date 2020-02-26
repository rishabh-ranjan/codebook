int ceil_sqrt(ll x)
{
	ll lo = 0;
	ll hi = INT_MAX;
	while (lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		if (mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return (int)lo;
}

int floor_sqrt(ll x)
{
	ll lo = 0;
	ll hi = INT_MAX;
	while (lo < hi)
	{
		ll mid = lo + (hi-lo+1)/2;
		if (mid * mid <= x)
			lo = mid;
		else
			hi = mid - 1;
	}
	return (int)lo;
}
