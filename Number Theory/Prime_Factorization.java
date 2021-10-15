 private static void primefact(int n) {

		for (int i = 2; i * i <= n; i++) {
    
			if (n % i == 0) {
				int count = 0;
				while (n % i == 0) {
					count++;
					n /= i;
				}
				System.out.println(i + "^" + count);
			}
		}
		if (n > 1)
			System.out.println(n + "^1");
      

	}
