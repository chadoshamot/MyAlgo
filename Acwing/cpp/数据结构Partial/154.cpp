#include<iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)scanf("%d", &a[i]);
    int head = 0, tail = -1;
    for(int i=0; i<n; i++){
        int start = i - k + 1;
        while(head <= tail && q[head] < start)head++;
        while(head <= tail && a[q[tail]] >= a[i]){
            tail--;
        }
        tail++;
        q[tail] = i;
        if(i >= k - 1)printf("%d ", a[q[head]]);
    }

    printf("\n");
    head = 0, tail = -1;
    for(int i=0; i<n; i++){
        int start = i - k + 1;
        while(head <= tail && q[head] < start)head++;
        while(head <= tail && a[q[tail]] < a[i])tail--;
        tail++;
        q[tail] = i;
        if(i >= k - 1)printf("%d ", a[q[head]]);
    }

    return 0;
}