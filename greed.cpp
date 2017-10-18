/*Chido Nguyen
931506965
HW4 CS325 : Acitivty Scheduling
*/


//Structure to store our activity id and in formation 
struct Acts {
	int id;
	int s_time;
	int f_time;
};




//				Function : schedule_last_to_start
//Arguments: Container of activities objects
//Returns : optimal list of activity to maximize # in time frame
//Purpose: We will process a container of activities and determine which activities
//fit together the best to give us a list of max activities we can do using a Greedy method

void schedule_last_to_start(std::vector<*Acts> everything, std::vector<int> lists){
	
	int n = everything.size();
	lists.push_back(((everything[0]).id)); // assuming we have sorted container of activity
									// we pick the first item out right off the bat
	int idx=0;
	
	for(int i = 1; i < n ; i++){
		struct Acts cur = everything[i];
		struct Acts prev = everything[idx];
		if(cur.s_time >= prev.f_time){
			lists.push_back((everything[i]).id);
			idx= i;
		}
	}
}