 // all Substring HashCode in O(1) 
// precomputation int O(N LOG(N))
/*
abcdefg
2
0 1
ab = 63
0 2
abc = 2946
*/

static long mod = 1000000007;
	static int N = 1000001;
	static long dp[] = new long[N];
	static long inv[] = new long[N];
	
	
	static long power(long a , long n)
	{
		long result = 1;
	 
		while(n > 0)
		{
			if((n & 1) > 0) result = (result * a) % mod;
	 
			n >>= 1;
			a = (a * a) % mod;
		}
	 
		return result;
	}
	 
	 
	static void init(String input_string)
	{
		long p = 31;
		long p_power = 1;
		inv[0] = 1L;
		dp[0] = (input_string.charAt(0) - 'a' + 1);
	 
	 
		for(int i=1;i<input_string.length();i++)
		{
			char ch = input_string.charAt(i);
	 
			p_power = (p_power * p) % mod;
			inv[i] = power(p_power , mod - 2);
	 
			dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
		}
	}
	 
	static long getHash(String key)
	{
		long value = 0;
		long p = 31;
		long p_power = 1;
	 
		for(char ch : key.toCharArray())
		{
			value = (value + (ch - 'a' + 1)*p_power) % mod;
			p_power = (p_power * p) % mod;
		}
	 
		return value;
	}
	 
	static long substringHash(int L , int R)
	{
		long result = dp[R];
	 
		if(L > 0) result = (result - dp[L-1] + mod) % mod;
	 
		result = (result * inv[L]) % mod;
	 
		return result;
	}
	 
	
	public static void main(String[] args) {
		String pattern = sc.next();
		init(pattern);
		int q = sc.nextInt();
		while(q-- != 0) {
			int l = sc.nextInt(),r = sc.nextInt();
			System.out.println(pattern.substring(l,r+1)+" = "+substringHash(l, r));
		}
	}
	
