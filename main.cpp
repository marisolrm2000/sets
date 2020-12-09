#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;
int main(int argc, char *argv[])
{
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    ofstream setfile(filename+"_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        //cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    cout << endl;
    
    //part 2
    ofstream vectorfile(filename+"_vector.txt");
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        vectorfile << ' ' << *it;
    }

    //part 3
    map<string, vector<string> > wordmap;
    string state = "";
    for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
      wordmap[state].push_back(*it);
      state = *it;
    }
    //ofstream mapfile(filename+"_map.txt");
    //for (map<string,string>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it){
    //    //cout << it->first<<' ' << it->second<<endl;
    //    mapfile << it->first<< ", " << it->second<<endl;
    //}
    cout << endl;

    //part4
    srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
    state = "";
    for (int i = 0; i < 100; i++) {
      int ind = rand() % wordmap[state].size();
      cout << wordmap[state][ind] << " ";
      state = wordmap[state][ind];
    }
    cout << endl;
}