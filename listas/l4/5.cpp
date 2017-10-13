#include <bits/stdc++.h>

using namespace std;

// This solution assumes the vector of houses will contain 
// the positions of them in ascending order from east to west.

vector<int> places_stations(vector<int> houses){
	vector<int> places_of_stations;
	for(int i=0; i<(int)houses.size(); i++){
		if(!i){
			places_of_stations.insert(places_of_stations.begin(), houses[i]+4);
			continue;
		}
		if(abs(places_of_stations[0] - houses[i]) <= 4){
			continue;
		}else{
			places_of_stations.insert(places_of_stations.begin(), houses[i]+4);
		} 
	}
	return places_of_stations;
}

int main(){
	vector<int> houses = {43, 44, 45, 50, 52, 60};
	vector<int> stations = places_stations(houses);
	for(int i=0; i<(int)stations.size(); i++) printf("Station at %d\n", stations[i]);
	return 0;	
}
