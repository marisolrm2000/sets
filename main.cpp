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
    map<string, string> wordmap;
    string last="";
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++){
        wordmap[last]=*it;
        last = *it;
    }
    ofstream mapfile(filename+"_map.txt");
    for (map<string,string>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it){
        //cout << it->first<<' ' << it->second<<endl;
        mapfile << it->first<< ", " << it->second<<endl;

    }
    cout << endl;

    //part4
    string state = "";
    for(int i = 0; i < 100; i++){
      cout << wordmap[state] << " ";
      state = wordmap[state];
    }
    cout << endl;
       
}