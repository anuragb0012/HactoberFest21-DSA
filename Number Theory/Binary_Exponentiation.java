


//a^n
	private static long power(long a, long n) {
		long res = 1;
		while(n > 0) {
			if(n%2 == 0) {
				a*=a;
				n/=2;
			}
			else {
				res*=a;
				n--;
			}
		}
		return res;
	}
