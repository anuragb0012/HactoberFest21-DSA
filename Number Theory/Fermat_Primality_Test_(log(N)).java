public static boolean isPrime(long n)
    {
		int iteration = 5;
        /** base case **/
        if(n < 4)return n == 2 || n == 3;
        /** an even number other than 2 is composite **/
        if (n % 2 == 0)
            return false;
 
        Random rand = new Random();
        for (int i = 0; i < iteration; i++)
        {
            long r = Math.abs(rand.nextLong());            
            long a = 2 + r % (n-3);
            if (power(a, n - 1, n) != 1)
                return false;
        }
        return true;        
    }

	private static long power(long a, long n,long mod) {
		long res = 1;
		while(n > 0) {
			if((n&1) > 0) {
				res = multMod(res,a,mod);
			}
			n>>=1;
			a = multMod(a, a, mod);
		}
		return  (res%mod);
	}
	private static long multMod(long a, long b, long c) {
		long x = 0, y = a%c;
		while(b > 0) {
			if(b%2 == 1){
				x = (x+y)%c;
			}
			y = (y * 2L)%c;
			b/=2;
		}
		
		return x%c;
	}

	public static void main(String[] args) throws IOException {

		FastScanner sc = new FastScanner();
		int t = sc.nextInt();
		first: while (t-- != 0) {
			
			long n = sc.nextLong();
			if(isPrime(n)) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
			

		}

	}
