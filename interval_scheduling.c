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

typedef interval interval;

bool ftime_compare(interval i, interval j){
	return(i.finish < i.finish);
}

void schedule(interval *arr, int n){
	sort(arr,arr+n,ftime_compare);
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
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	schedule(arr,n);

}