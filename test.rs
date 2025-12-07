impl Solution {
    pub fn max_k_divisible_components(n: i32, edges: Vec<Vec<i32>>, values: Vec<i32>, k: i32) -> i32 {
        let n_usize = n as usize;

        let mut g = vec![vec![]; n_usize];

        for e in edges.iter()
        {
            let u = e[0] as usize;
            let v = e[1] as usize;
            g[u].push(v);
            g[v].push(u);
        }

        let mut ans = 0;

        fn dfs(
            u:usize,
            fa:usize,
            values:&Vec<i32>,
            k:i64,
            g:&Vec<Vec<usize>>,
            ans:&mut i32,
        ) -> i64
        {
            let mut sum:i64 = values[u].into();

            for &v in g[u].iter()
            {
                if v == fa{
                    continue;
                }

                sum += dfs(v,u,values,k,g,ans);
            }
            if sum % k == 0{
                *ans+=1;
                return 0;
            }

            return sum;
        }

        dfs(0, usize::MAX, &values, k as i64, &g, &mut ans);
        
        return ans
    }
}