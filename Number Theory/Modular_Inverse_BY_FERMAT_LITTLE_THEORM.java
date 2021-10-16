//	a^n % mod
	private static long power(long a, long n,long mod) {
		long res = 1;
		while(n > 0) {
			if(n%2 == 0) {
				a = (a%mod * a%mod)%mod;
				n/=2;
			}
			else {
				res = (res%mod * a%mod)%mod;
				n--;
			}
		}
		return res%mod;
	}
	
	// Inverse Of a Number
	private static long ModInverse(long a, long mod) {
		
		return power(a, mod-2,mod);
	}


	public static void main(String[] args) {
		
		int a = 3;
		int mod = 11;
		int inverse = ModInverse(a,mod);
		System.out.println(a+"^-1("+mod+")"+" = "+inverse);

	}
