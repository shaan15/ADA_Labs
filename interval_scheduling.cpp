#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct interval{
	int start;
	int finish;
};

struct sort_finish{
	bool operator()(interval i, interval j){
	return(i.finish < i.finish);
	}
};



void schedule(int n, interval arr[]){
	sort(arr,arr+n,sort_finish());
	int i,j;

	printf("(%d,%d) ", arr[i].start, arr[i].finish);	
	for(j=1;j<n;j++){
		if(arr[j].start >= arr[i].finish){
			printf("(%d,%d)", arr[j].start, arr[j].finish);
			i=j;
		}
	}
}

int main(){
	interval arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
	
	schedule(6,arr);

}