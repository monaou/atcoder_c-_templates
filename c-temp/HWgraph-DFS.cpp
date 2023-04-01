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