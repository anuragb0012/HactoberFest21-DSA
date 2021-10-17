
  private static long gcd(long a, long b) {
		
		if(b == 0)
			return a;
		return gcd(b,a%b);
		
	}
  private static int gcd(int a, int b) {
		
		if(b == 0)
			return a;
		return gcd(b,a%b);
		
	}
