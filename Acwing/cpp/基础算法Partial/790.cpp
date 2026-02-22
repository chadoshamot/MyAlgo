#include<iostream>
#include<vector>

using namespace std;

int main(){
    double n;
    scanf("%lf", &n);
    double l = -10000;
    int flag = 0;
    if(n < 0){
        n = -n;
        flag = 1;
    }
    double r = 10000;
    while(r - l > 1e-8){
        //在初始l和r的时候，直接取大范围，不要先固定在l=0和r = n之间
        //这是因为对绝对值小于1的数，其立方根的绝对值大于这个数的绝对值
        double mid = (r + l) / 2;
        //cout << "mid == " << mid << endl;
        if(mid * mid * mid >= n){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    if(flag)printf("-");
    printf("%.6lf", l);
    return 0;
}