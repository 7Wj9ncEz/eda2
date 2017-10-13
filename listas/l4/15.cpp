#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

bool compare(ii a, ii b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    vector <ii> intervals {
        ii(1,3), ii(3,4), ii(2,5), ii(9, 11), ii(4,6), ii(6, 10), ii(4,8), ii(7,10)
    };

    // sort the intevals by smallest beginning and ending
    sort(intervals.begin(), intervals.end(), compare);

    vector<ii> commitee;

    for(int i=0;i<intervals.size();i++){
        cout << "cur: " << i << endl;
        ii cur = intervals[i];
        ii to_insert = ii(-1, -1);
        int j = i + 1;

        for(; j < intervals.size(); j++){
            cout << "    intersect " << j << endl;
            ii curj = intervals[j];

            if(curj.first < cur.second)
                to_insert = curj;
            else
                break;
        }

        commitee.push_back(to_insert);

        i = j;
    }

    cout << "Commitee: ";
    for(auto c : commitee){
        printf("[%d, %d] ", c.first, c.second);
    }
    printf("\n");

    return 0;
}
