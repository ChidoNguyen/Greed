/*Chido Nguyen
931506965
HW4 CS325 : Acitivty Scheduling
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include "merge.h"

using std::cin;
using std::cout;
using std::endl;


//Structure to store our activity id and in formation declared in merge.h
/*struct Acts {
	int id;
	int s_time;
	int f_time;
};*/




//				Function : schedule_last_to_start
//Arguments: Container of activities objects
//Returns : optimal list of activity to maximize # in time frame
//Purpose: We will process a container of activities and determine which activities
//fit together the best to give us a list of max activities we can do using a Greedy method

void schedule_last_to_start(std::vector<Acts*> &everything, std::vector<int> &lists){
	
	int n = everything.size();
	lists.push_back((*(everything[0])).id); // assuming we have sorted container of activity
									// we pick the first item out right off the bat
	int idx=0;
	
	for(int i = 1; i < n ; i++){
		struct Acts cur = *everything[i];
		struct Acts prev = *everything[idx];
		if(cur.f_time <= prev.s_time){
			lists.push_back((*everything[i]).id);
			idx= i;
		}
	}
}

void PRINT_ME(std::vector<int> &contain) {
	while (!(contain.empty())) {
		cout << contain.back() <<"	";
		contain.pop_back();
	}
	cout << endl;
}


int main() {
	std::vector<Acts*> testing;
	std::vector<int> lists;
	std::fstream inpt;
	inpt.open("act.txt");
	std::string holdit;
	int set_count = 0;


//https://stackoverflow.com/questions/36705943/string-stream-in-c-to-parse-string-of-words-numbers
	while (!inpt.eof()) {
		int act_num;
		int tmp;
		std::getline(inpt, holdit);
		std::stringstream splice(holdit);
		splice >> act_num;

		for (int i = 0; i < act_num; i++) {
			struct Acts *to_add;
			to_add = new struct Acts;
			std::getline(inpt, holdit);
			std::stringstream splice(holdit);
			splice >> tmp;
			(*to_add).id = tmp;
			splice >> tmp;
			(*to_add).s_time = tmp;
			splice >> tmp;
			(*to_add).f_time = tmp;
			testing.push_back(to_add);
			
		}
		set_count++;
		MergeSort(&testing, 0, testing.size() - 1); // sort our activites
		schedule_last_to_start(testing, lists); // schedule it algorithm
		cout << "Set " << set_count << endl;
		cout << "Number of activities selected = " << lists.size() << endl;
		PRINT_ME(lists);
		//clean up prior to next loop//
		while (!(testing.empty())) {
			delete testing.back();
			testing.pop_back();
		}
		lists.clear();
		act_num = 0;
		tmp = 0;
	
	}


	inpt.close();
	return 0;
}