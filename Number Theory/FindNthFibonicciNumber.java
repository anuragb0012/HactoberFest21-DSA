private static final int Mod = (int) (10e9+7);
	private static long[] arr;
	private static long[][] I,T;
	
	private static void multiply(long[][] A, long[][] B, int dim) {
		
		long res[][] = new long[dim+1][dim+1];
		for(int i=1; i<=dim; i++) {
			for(int j=1;j<=dim; j++) {
				
				res[i][j]=0;
				for(int k=1; k<=dim; k++)
					res[i][j] = ((res[i][j]) + (A[i][k] * B[k][j]))%Mod;
				
			}
		}
		
		// copy in  A Matrix
		for(int i=1; i<=dim; i++)
			for(int j = 1; j<=dim; j++)
				A[i][j]=res[i][j]%Mod;
		
		
		
	}
	
	private static long getFib(long n) {

		if(n <= 2)return arr[(int) n];
		I[1][1] = I[2][2] = 1;
		I[1][2] = I[2][1] = 0;
		T[1][1] = 0;
		T[1][2] = T[2][1] = T[2][2] = 1;
		
		n--;
		
		while(n > 0) {
			if(n%2 == 0) {
				multiply(T,T,2);
				n/=2;
			}
			else {
				multiply(I,T,2);
				n--;
			}
//			System.out.println("---------I-------");
//			printMatrix(I, 2);
//			System.out.println("---------T-------");
//			printMatrix(T, 2);
		}
		
		long Fn = (arr[1]*I[1][1]+ arr[2]*I[2][1])%Mod;
		
		return Fn;
	}
private static void printMatrix(long[][] A, int dim) {
		
		for(int i =1; i<=dim; i++) {
			for(int j=1; j<=dim; j++)
				System.out.print(A[i][j]+" ");
			System.out.println();
		}
	}
	public static void main(String[] args) {
		
		
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		while(t-- != 0) {
			arr = new long[3];
			I = new long[3][3];
			T = new long[3][3];
			
			 arr[1] = sc.nextLong();
			 arr[2] = sc.nextLong();
			 long n = sc.nextInt()+1;
			 long ans = getFib(n);
			 System.out.println(ans);
		}

	}

	
	
	
