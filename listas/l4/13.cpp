#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

// sort list by decreasing w/t
bool compare(ii a, ii b){
    return a.second * 1.0 / a.first > b.second * 1.0 / b.first; 
}

int main(){
    // pair of (time, weight) of the job
    vector<ii> jobs {
        ii(1, 10), ii(2,8), ii(3,10), ii(4,6), ii(2,3), ii(1,1), ii (10,1)
    };

    sort(jobs.begin(), jobs.end(), compare);

    int acc_time = jobs[0].first;
    int sum = acc_time * jobs[0].second;

    for(int i=1;i<jobs.size();i++){
        acc_time += jobs[i].first;
        sum += (jobs[i].second * acc_time);
    }

    printf("Weighted sum: %d\n", sum);

    return 0;
}
