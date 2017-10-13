#include <bits/stdc++.h>

using namespace std;

bool is_sub(vector<string> a, vector<string> b){
	int tama = (int) a.size();
	int tamb = (int) b.size();
	int i=0, j=0, counter=0;
	while(i<tama && j<tamb){
		if(a[i] == b[j]){
			counter++;
			i+=1;
			j+=1;			
		}else{
			j+=1;
		}
	}
	return counter == tama;
}


int main(){
	vector<string> a = {"buy Amazon", "buy Eagle", "buy Google"};
	vector<string> b = {"buy Amazon", "a", "b", "buy Eagle", "b", "buy Google"};
	vector<string> c = {"a", "b"};
	vector<string> d = {"f", "g", "h"};

	bool issubab = is_sub(a, b);
	bool issubcd = is_sub(c, d);
	printf("vector A is subsequence of vector B: %s\n", issubab? "Yes" :  "No");
	printf("vector C is subsequence of vector D: %s\n", issubcd? "Yes" :  "No");
	
	return 0;	
}
