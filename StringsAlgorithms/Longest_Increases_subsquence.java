int n = sc.nextInt();
    int arr[] = new int[n+1];
        int LongestDecressingSubsequence[] = new int[n+1];
        Arrays.fill(LongestDecressingSubsequence, 1);
        int LongestIncresesSubsequence[] = new int[n+1];
        Arrays.fill(LongestIncresesSubsequence, 1);
        for (int j = 0 ; j  < n ; j++) {
            for (int i = 0 ; i < j ; i++) {
                if (nums[i] < nums[j]) {
                    LongestIncresesSubsequence[j] = Math.max(LongestIncresesSubsequence[i] + 1, LongestIncresesSubsequence[j]);
                }
            }
        }
        System.out.println(Arrays.toString(LongestIncresesSubsequence));
        for (int j = n-1 ; j  > 0 ; j--) {
            for (int i = n-1 ; i > j ; i--) {
                if (nums[i] < nums[j]) {
                    LongestDecressingSubsequence[j] = Math.max(LongestDecressingSubsequence[i] + 1, LongestDecressingSubsequence[j]);
                }
            }
        }
        System.out.println(Arrays.toString(LongestDecressingSubsequence));
