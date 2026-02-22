#include<iostream>
#include<vector>

using namespace std;

pair<int, int> find(vector<int>& vec, int query){
    int l = 0, r = vec.size() - 1;
    int loc_l = -1, loc_r = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(vec[mid] == query){
            loc_l = mid;
            r = mid - 1;
        }
        else if(vec[mid] > query){
            r = mid - 1;
        }
        else if(vec[mid] < query){
            l = mid + 1;
        }
    }
    l = 0, r = vec.size() - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(vec[mid] == query){
            loc_r = mid;
            l = mid + 1;
        }
        else if(vec[mid] < query){
            l = mid + 1;
        }
        else if(vec[mid] > query){
            r = mid - 1;
        }
    }
    if(loc_l == -1 || loc_r == -1)return {-1, -1};
    else{
        pair<int, int> ans;
        ans.first = loc_l;
        ans.second = loc_r;
        return ans;
    }
}
int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<int> vec(n, 0);
    for(int i=0; i<n; i++)scanf("%d", &vec[i]);
    for(int i=0; i<q; i++){
        int query;
        scanf("%d", &query);
        pair<int, int> ans = find(vec, query);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}