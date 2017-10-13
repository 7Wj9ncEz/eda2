#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

bool compare(ii a, ii b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main(){
    // pair of (supercomputer time, pc time) of the jobs
    vector<ii> jobs {
        //ii(3,4), ii(9,3), ii(1,2), ii(10, 10), ii(2,5), ii(1,3)
        ii(3,4),ii(1,3),ii(2,5)
    };

    // sort the jobs by decreasing supercomputer time
    sort(jobs.begin(), jobs.end(), compare);

    int finish_time = jobs[0].first;
    int pc_time = jobs[0].second;

    for(int i=1;i<(int)jobs.size();i++){
        // always add supercomputer time
        finish_time += jobs[i].first;

        // decrease each pc time with time spent by the last job
        pc_time = max(0, pc_time - jobs[i-1].second);

        // get maximum between previous and current pc_time
        pc_time = max(pc_time, jobs[i].second);
    }

    finish_time += pc_time;

    printf("Finish time: %d\n", finish_time);

    return 0;
}
