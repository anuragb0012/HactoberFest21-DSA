// Topological Sort
	public class TopoSort {

		private static ArrayList<Integer>[] adj;
		private static int[] in;
		static ArrayList<Integer> toposort = new ArrayList<Integer>();

		private static void kahn(int n) {
			Queue<Integer> q = new LinkedList<Integer>();
			for(int i=1; i<=n; i++) {
				if(in[i] == 0)
					q.add(i);
			}
			while(!q.isEmpty()) {
				int curr = q.poll();
				toposort.add(curr);
				for(int child : adj[curr]) {
					in[child]--;
					if(in[child] == 0)
						q.add(child);
				}
			}
		}

		public static void main(String[] args) throws IOException {

			Scanner sc = new Scanner();
			int n = sc.nextInt();
			adj = new ArrayList[n+1];
			for(int i=1; i<=n; i++)adj[i] = new ArrayList<Integer>();
			in = new int[n+1];
			int m = sc.nextInt();
			for(int i=1; i<=m; i++) {
				int a = sc.nextInt(),b = sc.nextInt();
				adj[a].add(b);
				in[b]++;
			}
			kahn(n);
			System.out.println(toposort);
		}
	}
