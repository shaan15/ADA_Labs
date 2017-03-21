#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef struct node{
	long int data;
	long int dist;
	long int p;
	long int wt;
	int check;
	struct node *next;
	// bool operator<(const struct node *b) const{
	// 	return dist < b->dist;
	// }
}NODE;
struct compare{
	bool operator()(const NODE *a, const NODE *b) const{
		return a->dist > b->dist;
	}
};
NODE *v[MAX];
// priority_queue<NODE *, vector<NODE *>, compare> h;
vector <NODE *> h;
// void dec_key(struct node *x){
// 	long int i = x->h;
// 	while (i>1 && v[i/2]->key > v[i]->key){
// 		struct node *temp = v[i/2];
// 		v[i/2] = v[i];
// 		v[i/2]->h = i/2;
// 		v[i]=temp;
// 		v[i]->h=i;
// 		i = i/2;
// 	}

// }
int main(void){
	long int n,m,i,st,en;
	scanf("%ld", &n);
	scanf("%ld", &m);
	for (i=1; i<=n; i++){
		v[i] = (NODE *)malloc(sizeof(NODE));
		v[i]->data = i;
		v[i]->dist = LONG_MAX;
		v[i]->check = -1;
		// v[i]->dist = i;
		v[i]->wt = -1;
		v[i]->p = -1;
		v[i]->next = NULL;
		h.push_back(v[i]);
	}
	for (i=1; i<=m; i++){
		long int e1, e2, w;
		scanf("%ld", &e1);
		scanf("%ld", &e2);
		scanf("%ld", &w);
		// NODE *ptr = (NODE *)malloc(sizeof(NODE));
		// ptr->data = e1;
		// ptr->dist = -1;
		// ptr->p = -1;
		// ptr->wt = w;
		// ptr->next = v[e2]->next; 
		// v[e2]->next = ptr;
		NODE *ptr2 = (NODE *)malloc(sizeof(NODE));
		ptr2->data = e2;
		ptr2->dist = -1;
		ptr2->wt = w;
		ptr2->p = -1;
		ptr2->next = v[e1]->next;
		v[e1]->next = ptr2;
	}
	scanf("%ld %ld", &st, &en);

	
	v[st]->dist = 0; 
	make_heap(h.begin(), h.end(), compare());
	// printf("here\n");
	// v[1]->dist = 10;
	while ( !h.empty() ){
		NODE *q = h.front();
		NODE *ptr = q->next;
		pop_heap(h.begin(), h.end());
		h.pop_back();
		while (ptr != NULL){
			if (v[ptr->data]->dist > (q->dist + ptr->wt)){
				v[ptr->data]->check = 0;
				v[ptr->data]->dist = q->dist + ptr->wt;
				v[ptr->data]->p = q->data;
			}
			ptr = ptr->next;
		}
		make_heap(h.begin(), h.end(), compare());
		// if (v[])
	}
	
	// printf("%ld\n", h.front()->data);
	return 0;

}