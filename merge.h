#ifndef MERGE_H
#define MERGE_H
#include <vector>
// our merge sort algo from week 1
struct Acts {
	int id;
	int s_time;
	int f_time;
};

void MergeSort(std::vector<Acts*> *Array, int first_value, int last_value);
void Merge(std::vector<Acts*> *Arr, int low, int mid, int high);


#endif

