#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1 << 18], B[1 << 18];
bool used[1 << 18];
vector<int> G[1 << 18];vector<int> H[1 << 18];
vector<int> I;
long long cnts = 0;

void dfs(int pos) {
	used[pos] = true;
	for (int i : G[pos]) {
		if (used[i] == false) dfs(i);
	}
	I.push_back(pos);
}

void dfs2(int pos) {
	used[pos] = true;
	cnts++;
	for (int i : H[pos]) {
		if (used[i] == false) dfs2(i);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		H[B[i]].push_back(A[i]);
	}
	// Step #2. First DFS
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) dfs(i);
	}
	// Step #3. Second DFS
	long long Answer = 0;
	reverse(I.begin(), I.end());
	for (int i = 1; i <= N; i++) used[i] = false;
	for (int i : I) {
		if (used[i] == true) continue;
		cnts = 0;
		dfs2(i);
		Answer += cnts * (cnts - 1LL) / 2LL;
	}
	// Step #4. Output The Answer!
	cout << Answer << endl;
}

#include <atcoder/scc>
#include <cstdio>

using namespace std;
using namespace atcoder;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    scc_graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g.add_edge(u, v);
    }

    auto scc = g.scc();

    printf("%d\n", int(scc.size()));
    for (auto v : scc) {
        printf("%d", int(v.size()));
        for (int x : v) {
            printf(" %d", x);
        }
        printf("\n");
    }

    return 0;
}
