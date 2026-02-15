#include<iostream>
#include<vector>

using namespace std;

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}
void quickSort(vector<int>& q, int l, int r){
    if(l >= r)return;
    int x = q[(l + r + 1) / 2];
    int i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)swap(q[i], q[j]);
    }
    quickSort(q, l, i - 1);
    quickSort(q, i, r);
}
// int quickChoose(vector<int>& q, int l, int r, int k){
//     if(r == l && k == 1)return q[r];
//     int id = (l + r + 1) / 2;
//     int x = q[id];
//     int loc = quickSort(q, l, r, x);
//     if(loc == k)return x;
//     else if(loc < k){
//         return quickChoose(q, loc + 1, r, k - loc);
//     }
//     else if(loc > k){
//         return quickChoose(q, l, loc - 1, k);
//     }
// }

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> q(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &q[i]);
    quickSort(q, 0, q.size() - 1);
    int ans = q[k - 1];
    printf("%d", ans);
    return 0;
}