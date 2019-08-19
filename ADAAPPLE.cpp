        #include <bits/stdc++.h>
        #define MAXN 300400
        using namespace std;
         
        int n,m;
         
        bool col[MAXN];
         
        vector<int> edges[MAXN];
        int l, r;
         
        int par[MAXN][20], h[MAXN];
         
        int LCA(int l, int r) {
        	if(h[l] > h[r])
        		swap(l, r);
        	for(int i = 19; i > -1; --i) {
        		if(h[par[r][i]] >= h[l])
        			r = par[r][i];
        	}
        	if(l == r)
        		return l;
         
        	for(int i = 19; i > -1; --i)
        		if(par[l][i] != par[r][i]) {
        			l = par[l][i];
        			r = par[r][i];
        		}
        	return par[l][0];
        }
         
        bool used[MAXN];
         
        int label_l[MAXN];
        int label_r[MAXN];
        int cnt = 0;
         
        int col_so_far[MAXN];
         
        void dfs(int v, int cur_h, int cur_white) {
        	if(col[v])
        		cur_white++;
         
        	label_l[v] = ++cnt;
        	label_r[v] = label_l[v];
        	col_so_far[label_l[v]] = cur_white;
         
        	used[v] = true;
        	h[v] = cur_h;
         
        	for(auto& nei : edges[v])
        	if(!used[nei]) {
        		par[nei][0] = v;
        		dfs(nei, cur_h + 1, cur_white);
        		label_r[v] = max(label_r[v], label_r[nei]);
        	}
        }
        
        int cnt_s[4*MAXN], upd[4*MAXN];
        
        void build(int l, int r, int v) {
        	if(l == r) {
        		cnt_s[v] = col_so_far[l];
        		return;
        	}
        	int mid = (l+r)>>1;
        	build(l, mid, v*2);
        	build(mid+1, r, v*2+1);
        	cnt_s[v] = cnt_s[v*2]+cnt_s[v*2+1];
        }
         
        void update(int l, int r, int v, int lll, int rrr, int delta) {
        	if(lll<= l && rrr >= r) {
        		upd[v] += delta;
        		cnt_s[v] += (l-r+1)*delta;
        		return;
        	}
        	int mid = (l + r) >> 1;
         
        	cnt_s[v*2] += upd[v]*(mid-l+1);
        	cnt_s[v*2+1] += upd[v]*(r-mid);
        	upd[v*2]+=upd[v];
        	upd[v*2+1]+=upd[v];
        	upd[v] = 0;
         
        	if(lll <= mid)
        		update(l, mid, v*2, lll, rrr, delta);
        	if(rrr > mid)
        		update(mid + 1, r, v*2+1, lll, rrr, delta);
        	cnt_s[v] = cnt_s[v*2] + cnt_s[v*2+1];
        }
         
        int get(int l, int r, int v, int lll) {
        	if(l == r) {
        		return cnt_s[v];
        	}
        	int mid = (l + r) >> 1;
        	cnt_s[v*2] += upd[v]*(mid-l+1);
        	cnt_s[v*2+1] += upd[v]*(r-mid);
        	upd[v*2]+=upd[v];
        	upd[v*2+1]+=upd[v];
        	upd[v] = 0;
         
        	if(lll <= mid)
        		return get(l, mid, v*2, lll);
        	return get(mid + 1, r, v*2+1, lll);
        }
        int type;
        int main() {
        	std::ios::sync_with_stdio(false);
        	cin.tie(0);
        	cin>>n>>m;
        	char ch;
        	for(int i = 0; i < n; ++i) {
        		cin>>ch;
        		if(ch == '0')
        			col[i] = false;
        		else
        			col[i] = true;
        	}
        	
        	for(int i = 1; i < n; ++i) {
        		cin>>l>>r;
        		edges[l].push_back(r);
        		edges[r].push_back(l);	
        	}
         
        	par[0][0] = 0;
        	dfs(0, 0, 0);
         
        	for(int i = 1; i < 20; ++i)
        	for(int j = 0; j < n; ++j)
        		par[j][i] = par[par[j][i-1]][i-1];
         
        	build(1, n, 1);
         
        	for(int i = 0; i < m; ++i) {
        		cin>>type;
        		if(type == 0) {
        			cin>>l;
        			if(col[l]) {
        				col[l] = false;
        				update(1, n, 1, label_l[l], label_r[l], -1);
        			} else {
        				col[l] = true;
        				update(1, n, 1, label_l[l], label_r[l], 1);
        			}
        		} else {
        			cin>>l>>r;
        			int lca = LCA(l, r);
        			int cur_white = get(1, n, 1, label_l[l]) + get(1, n, 1, label_l[r]) - 2*get(1, n, 1, label_l[lca]);
        			if(col[lca])
        			    cur_white++;        			
        			int cur_cnt = h[l] + h[r] - 2 * h[lca] + 1;
        			if(cur_white == 0 || cur_white == cur_cnt)
        				cout<<"YES"<<endl;
        			else
        				cout<<"NO"<<endl;
        		}
        	}
        	
        	return 0;
        }  
