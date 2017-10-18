#include "merge.h"



void MergeSort(std::vector<Acts*> *Array, int first_value, int last_value) {

	if (first_value < last_value) {
		int midway = floor((first_value + last_value) / 2);
		MergeSort(Array, first_value, midway);
		MergeSort(Array, midway + 1, last_value);
		Merge(Array, first_value, midway, last_value);

	}

};

void Merge(std::vector<Acts*> *Arr, int low, int mid, int high) {


	int idx1 = mid - low + 1;
	int idx2 = high - mid;

	std::vector<Acts*> Left(idx1);
	std::vector<Acts*> Right(idx2);

	for (int i = 0; i < idx1; i++) {
		Left[i] = (*Arr)[low + i];
	}
	for (int x = 0; x < idx2; x++) {
		Right[x] = (*Arr)[mid + 1 + x];
	}
	int R_idx = 0;
	int L_idx = 0;
	int Merge_idx = low;

	while (L_idx < idx1 && R_idx < idx2) {
		if ((*Left[L_idx]).s_time >= (*Right[R_idx]).s_time) {
			(*Arr)[Merge_idx] = Left[L_idx];
			L_idx++;
		}
		else {
			(*Arr)[Merge_idx] = Right[R_idx];
			R_idx++;
		}
		Merge_idx++;
	}
	while (L_idx < idx1) {
		(*Arr)[Merge_idx] = Left[L_idx];
		L_idx++;
		Merge_idx++;
	}

	while (R_idx < idx2) {
		(*Arr)[Merge_idx] = Right[R_idx];
		R_idx++;
		Merge_idx++;
	}
};