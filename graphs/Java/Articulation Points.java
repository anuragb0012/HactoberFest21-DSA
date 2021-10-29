	
// Find the Articulation Points of a graph

	/*
	 		---- In main Function ----
	 for(int i=1; i<=n; i++) {
			if(vis[i] == 0)dfs(i,-1);
		}
		System.out.println(AP);
		
	 */
	
	
	private static ArrayList<Integer>[] adj;
	private static int n,timer;
	private static int[] vis,in,low;
	static HashSet<Integer> AP = new HashSet<Integer>();

	private static void dfs(int node, int par) {
		vis[node] = 1;
		in[node] = low[node] = timer;
		timer++;
		int child_cnt = 0;
		
		for(int child : adj[node]) {
			
			if(par == child)continue;
			
			if(vis[child] == 1) {
				// back edge
				low[node] = Math.min(low[node], in[child]);
			}
			else {
				// forward edge
				dfs(child, node);
				child_cnt++;
				low[node] = Math.min(low[node], low[child]);

				if(in[node] <= low[child] && par != -1)AP.add(node);
			}
		}
		if(par == -1 && child_cnt > 1)AP.add(node);
		
	}
	
