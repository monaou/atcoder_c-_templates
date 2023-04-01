int a[MAX_N];
int n,k;

bool dfs(int i, int sum){
    if(i==n)return sum==k;
    if(dfs(i+1,sum))return true;
    if(dfs(i+1,sum+a[i]))return true;
    return false;
}
void solve(){
    if(dfs(0,0))print("Yes");
}

int N,M;
char　field[MAX_N][MAX_M+1];

void dfs(int x, int y){
    field[x][y]=='.';
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx;int ny=y+dy;
            if(0<=nx && nx < N && 0<=ny && ny < M && field[nx][ny]=='W')dfs(nx,ny);
        }
    }
}
void solve(){
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j]=='W'){
                dfs[i][j];
                res++;
            }
        }
    }
    printf("%d\n",res);
}

#include <iostream>
using namespace std;

int H, W, A, B, ans = 0;
void dfs(int i, int bit, int A, int B){
    if(i == H * W) return (void)ans++;
    if(bit & 1 << i) return dfs(i + 1, bit, A, B);
    if(B) dfs(i + 1, bit | 1 << i, A, B - 1);
    if(A){
        if(i % W != W - 1 && ~bit & 1 << (i + 1)) dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
        if(i + W < H * W) dfs(i + 1, bit | 1 << i | 1 << (i + W), A - 1, B);
    }
}
int main(){
    cin >> H >> W >> A >> B;
    dfs(0, 0, A, B);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, Q;
int A[11]{};
int a[50], b[50], c[50], d[50];
int ans = 0;
void dfs(int n) {
    if (n == N) {
        int sum = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = min(A[n], M); i <= M; i++) {
        A[n + 1] = i;
        dfs(n + 1);
    }
}
int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    A[0] = 1;
    dfs(0);
    cout << ans << "\n";
    return 0;
}
//M^N
#include <bits/stdc++.h>
using namespace std;

const int M = 2;
void dfs(vector<int> &A) {
    // 終端条件 --- 10 重ループまで回したら処理して打ち切り
    if (A.size() == 10) {
        for (int i = 0; i < 10; ++i) cout << A[i];
        cout << endl;
        return;
    }

    for (int v = 0; v < M; ++v) {
        A.push_back(v);
        dfs(A);
        A.pop_back(); // これが結構ポイント
    }
}

int main() {
    vector<int> A;
    dfs(A);
}