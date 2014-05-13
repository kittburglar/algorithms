#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;



struct adjvert{
	int currvert;
	vector<int> neighbours;
};

struct treevert{
	int u;
	int v;
};

vector<adjvert> adjlist;
vector<int> status;
vector<int> num;
vector<treevert> treetable;
vector<treevert> timetable;
int entry;
int ex;
int dumbstyle;
void printadjvert(struct adjvert adj){
	cout << adj.currvert << " ";
	cout << "Neighbours are:" << endl;
	for(int a = 0; a < adj.neighbours.size(); a++){
		cout << adj.neighbours[a] << " ";
	}
	return;
}

int timer = 0;
void dfs_visit(int v, int cnum){
	//cout << "the vertex " << adjlist[v].currvert << " entry is: " << entry  << " exit is: " << ex << endl;
	entry = timer;
	timetable[v].u = entry;
status[v] = 1;
	num[v] = cnum;
//cout 	 //timer++;
		for(int m = 0; m  < (adjlist[v].neighbours).size(); m++){
		//timer++;
		//cout << (adjlist[v].neighbours)[m] << endl;
			if(status[(adjlist[v].neighbours)[m]] == 0){ //here
				timer++;
				//cout << "the vertex u is: " << adjlist[v].currvert << " the vertex v is : " << (adjlist[v].neighbours)[m] << endl;
				treevert tree_edge;
				//tree_edge.u = adjlist[v].currvert;
				tree_edge.u = adjlist[v].currvert;
				tree_edge.v = (adjlist[v].neighbours)[m]; 
				treetable.push_back(tree_edge);
				//cout << "we are about to recuse on with index " << (adjlist[v].neighbours)[m] - 1 << " this is vertex: "<< (adjlist[v].neighbours)[m]  << endl;
				//timer++;
				ex = timer;
				//timetable[v].u = entry;
				timetable[v].v =  ex;
				//cout << "the vertex " << adjlist[v].currvert << " entry is: " << entry  << " exit is: " << ex << endl;
				dfs_visit((adjlist[v].neighbours)[m], cnum);  //here
				//cout << "entry is: " << entry  << " exit is: " << ex << endl;
				//cout << "DFS gives :"<< adjlist[v].currvert  << endl;
			}
		
	}	
	status[v] = 2;
		
	//}
	//cout << "DFS gives :"<< adjlist[v].currvert  << endl;
return;


}

//int timer = 0;
void dfs_visit2(int v, int cnum){
        //cout << "the vertex " << adjlist[v].currvert << " entry is: " << entry  << " exit is: " << ex << endl;
        entry = timer;
        timetable[v].u = entry;
status[v] = 1;
        num[v] = cnum;
//cout   //timer++;
                for(int m = 0; m  < (adjlist[v].neighbours).size(); m++){
                //timer++;
                //cout << (adjlist[v].neighbours)[m] << endl;
                        if(status[(adjlist[v].neighbours)[m]-1] == 0){ //here
                                timer++;
                                //cout << "the vertex u is: " << adjlist[v].currvert << " the vertex v is : " << (adjlist[v].neighbours)[m] << endl;
                                treevert tree_edge;
                                //tree_edge.u = adjlist[v].currvert;
                                tree_edge.u = adjlist[v].currvert;
                                tree_edge.v = (adjlist[v].neighbours)[m];
                                treetable.push_back(tree_edge);
                                //cout << "we are about to recuse on with index " << (adjlist[v].neighbours)[m] - 1 << " this is vertex: "<< (adjlist[v].neighbours)[m]  << endl;
                                //timer++;
                                ex = timer;
                                //timetable[v].u = entry;
                                timetable[v].v =  ex;
                                //cout << "the vertex " << adjlist[v].currvert << " entry is: " << entry  << " exit is: " << ex << endl;
                                dfs_visit2((adjlist[v].neighbours)[m]-1, cnum);  //here
                                //cout << "entry is: " << entry  << " exit is: " << ex << endl;
                                //cout << "DFS gives :"<< adjlist[v].currvert  << endl;
                        }
                
        }       
        status[v] = 2;

        //}
        //cout << "DFS gives :"<< adjlist[v].currvert  << endl;
return;


}
void edgetype(int vertu, int vertv){
	for(int n = 0; n < adjlist.size();n++){
        	if(vertu == adjlist[n].currvert){
			//cout << "we got a match on :" << vertu << endl;
			for(int b = 0; b < adjlist[n].neighbours.size(); b++){
				if(vertv == adjlist[n].neighbours[b]){
					break;
				}
				//cout << adjlist[n].currvert << endl;
				else if((b == adjlist[n].neighbours.size()-1) && (vertv != adjlist[n].neighbours[b])){
					//cout << adjlist[n].currvert << endl;
					cout << vertu << " " << vertv << " no-such-edge" << endl;
					return;
				}
			}
			//cout << vertu << " " << vertv << " no-such-edge" << endl;
		}
                //	cout << vertu << " " << vertv << " no-such-edge" << endl;

        	//cout << vertu << " " << vertv << " no-such-edge" << endl;      
	}
	//cout << vertu << " " << vertv << " no-such-edge" << endl;


	for(int i = 0; i < treetable.size() ;i++){
//		cout << vertu << " " << treetable[i].u << endl;
		if(vertu == treetable[i].u){
			// tree-edge
//			cout << vertv << " " << treetable[i].v << endl;
			if(vertv == treetable[i].v){
				cout << vertu << " " << vertv << " tree-edge" << endl;
			return;
			}
		}
	}
		if((timetable[vertu].u != 0)&&(timetable[vertu].v == 0)){
			cout << vertu << " " << vertv << " back-edge" << endl;
			return;
		}
		if(timetable[vertu].u < timetable[vertv].v){
			cout << vertu << " " << vertv << " forward-edge" << endl;
			return;
		}
		cout << vertu << " " << vertv << " cross-edge" << endl;
		return;
	
	
}
/*
void vertex_init(vertex* v){
	v->status = 0;
	v->num = 0;
}
I*/
int main(){
//read input before space
	string input;
	getline(cin, input);
	while(input != ""){
		//we split the line into string tokens
		string buf;
		stringstream ss(input);
		vector<string> tokens;
		//cout << input << endl;
		getline(cin,input);
		while (ss >> buf){
			tokens.push_back(buf);	
		}
		/*
		std::cout << "myvector contains:";
		for (unsigned i=0; i<tokens.size(); i++)
                	std::cout << ' ' << tokens[i];
       		std::cout << '\n';
        	return 0;
		*/
		struct adjvert curr;
		//first
		curr.currvert = atoi(tokens[0].c_str());
		if(curr.currvert == 0){
		cout << "dumbsryle was set" << endl;	
		int dumbstyle = 1;
		}
		//rest
		//sort((curr.neighbours).begin(),(curr.neighbours).end());
		for (unsigned i=2; i<tokens.size(); i++){
        	//sort((curr.neighbours).begin(),(curr.neighbours).end());        
	      (curr.neighbours).push_back(atoi(tokens[i].c_str()));		
		//sort((curr.neighbours).begin(),(curr.neighbours).end())
		//SORT THE NEIGHBOUR ARRAY`
		//sort((curr.neighbours).begin(),(curr.neighbours).end());
		}
		sort((curr.neighbours).begin(),(curr.neighbours).end());
		adjlist.push_back(curr);
		
	}
	//cout << "Adjacency list is" << endl;
	/*
	for(int b = 0; b < adjlist.size(); b++){
		printadjvert(adjlist[b]);
		cout << endl;
	}
	*/
	//cout << "adj size is: " << adjlist.size() << endl;
	for(int s = 0; s < adjlist.size(); s++){
		status.push_back(0);
		num.push_back(0);
		struct treevert t;
		t.u = 0;
		t.v = 0;
		timetable.push_back(t);
	}
	/*
	cout << "TimeTable looks like.." << endl;
	for (unsigned f=0; f<timetable.size(); f++)
                        cout  << timetable[f].u << ' ' << timetable[f].v << endl;
	*/
	int cnum = 0;
	for(int b = 0; b < adjlist.size(); b++){
        
	//	cout << status[b];
	//	cout << num[b] <<endl;;
        //        cout << endl;
        //int cnum = 0;
		if (status[b] == 0){
			//panic("FUCK");
			if(dumbstyle == 1)
			dfs_visit(b,cnum);
			else
			dfs_visit2(b,cnum);
			//cout << timer << endl;
			cnum = cnum + 1;
		}
	}
	/*I
	cout << "TimeTable looks like.." << endl;
        for (unsigned f=0; f<timetable.size(); f++)
                        cout  << timetable[f].u << ' ' << timetable[f].v << endl;
	*/
	//cout << timer << endl;
	//cout << "the vertex " << adjlist[cnum].currvert+1 << " entry is: " << entry  << " exit is: " << ex << endl;
	//for (unsigned i=0; i<treet able.size(); i++)
        //                cout << ' ' << treetable[i].u << ' ' << treetable[i].v << endl;;
	//cout << "the vertex " << adjlist[v].currvert << " entry is: " << entry  << " exit is: " << ex << endl;
//ss.str("");
	//strng input2;
	getline(cin,input);
	//read output before space
	while(input != ""){
	
	//we split the line into string tokens
                string buf2;
                stringstream ss2(input);
                vector<string> tokens2;
                //cout << input2 << endl;
                getline(cin,input);
                while (ss2 >> buf2){
                        tokens2.push_back(buf2);
                }
                //cout << "we are here" << endl;
		/*
                std::cout << "myvector contains:";
                for (unsigned i=0; i<tokens.size(); i++)
                        std::cout << ' ' << tokens[i];
                std::cout << '\n';
                return 0;
                */
                struct adjvert curr;
                //first
                //curr.currvert = atoi(tokens2[0].c_str());
                //rest
                //sort((curr.neighbours).begin(),(curr.neighbours).end());
                //for (unsigned z=0; z<tokens2.size(); z++){
                
		//cout << tokens2[0] << ' ' << tokens2[1] << endl;;
		edgetype(atoi(tokens2[0].c_str()),atoi(tokens2[1].c_str()));
		//sort((curr.neighbours).begin(),(curr.neighbours).end());        
        //      (curr.neighbours).push_back(atoi(tokens2[i].c_str()));
                //sort((curr.neighbours).begin(),(curr.neighbours).end())
                //SORT THE NEIGHBOUR ARRAY`
                //sort((curr.neighbours).begin(),(curr.neighbours).end());
               // }
	}
	return 0;
}
