
  // Don't forget to init() in main method
	static long mod = (int) (1000000007);
	static int N = 100000;
	static long fact[] = new long[N];
	static long invfact[] = new long[N];
	static int power(long a,long n,long p){
		long result = 1;
		while (n > 0) {
			if ((n & 1) > 0)
				result = a * result % p;
			a = a * a % p;
			n >>= 1;
		}
		return (int) result;
	}
	static void init(){
		long p=mod;
		fact[0]=1;
		int i;
		for(i=1;i<N;i++){
			fact[i]=i*fact[i-1]%p;
		}
		i--;
		invfact[i]=power(fact[i],p-2,p);
		for(i--;i>=0;i--){
			invfact[i]=invfact[i+1]*(i+1)%p;
		}
	}
	static int ncr(int n,int r){
		if(r > n || n < 0 || r < 0)return 0;
		return (int) ((int) (fact[n]*invfact[r]%mod*invfact[n-r]%mod)%mod);
	}
