private static ArrayList<Integer> lis;

	public static int[] generatePrimes(int n) {
		    boolean[] prime = new boolean[n + 1];
		    Arrays.fill(prime, 2, n + 1, true);
		    for (int i = 2; i * i <= n; i++)
		      if (prime[i])
		        for (int j = i * i; j <= n; j += i)
		          prime[j] = false;
		    int[] primes = new int[n + 1];
		    int cnt = 0;
		    for (int i = 0; i < prime.length; i++)
		      if (prime[i])
		        primes[cnt++] = i;

		    return Arrays.copyOf(primes, cnt);
		  }
	
	private static void init(int l, int r) {
		if(l == 1)l++;
		int maxN = r-l+1;
		int arr[] = new int[maxN];
		for(int p : lis) {
			if(p*p <= r) {
				int i = (l/p)*p;
				if(i<l)i+=p;
				for(;i<=r; i+=p) {
					if(i!=p)arr[i-l] = 1;
				}
			}
		}
		for(int i=0; i<maxN;i++)
			if(arr[i] == 0) {
				System.out.println(l+i);
			}
		
	}
	 
	 public static void main(String[] args) {
		 
		 int arr[] = generatePrimes(100001);
		 lis = new ArrayList<Integer>();
		 for(int e : arr)lis.add(e);
		 Scanner sc = new Scanner(System.in);
		 int t = sc.nextInt();
		 while(t-- != 0) {
			 int l = sc.nextInt(),r = sc.nextInt();
			 init(l,r);
			 System.out.println();
		 }
		 
		
	}
