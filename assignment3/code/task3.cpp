#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <cctype>
using namespace std;

//struct to create objects of seq_name, k_mers and counts for each k_mers
struct Contig{
    string seq_name;
    map<string, int> d;
    vector<string> k_mer;
};

//function to count the number of k_mers
string nth_element(string s, long n, long k){
    string result="";
        for (int i = 0; i < s.length(); i++) {

            if (((i+1) % n) != 0) {
                result += s[i];


            }

        }
        result= result.substr(0, k);
        if(result.length()==k){
            return result;
        }
        else{
            return "";
        }



}
int main(int argc, char* argv[]) {
    if(argc>3){
        
        //taking fasta input in to a data frame
    vector<vector<string>> main_matrix;
    vector<vector<string>> seq_id;
    vector<string> temp;
    vector<string> temp2;
    map<string, string> t;
    long k = atoi(argv[2]);

    int n = atoi(argv[3]);
    int n_0 = n - 1;


    std::ifstream input(argv[1]);
    if (!input.good()) {
        return 0;
    }
    std::string file, id, sequence;

    while (std::getline(input, file)) {

        if (file.empty())
            continue;

        if (file[0] == '>') {

            if (!id.empty()) {
                temp2.push_back(id);
                temp.push_back(sequence);
                seq_id.push_back(temp2);
                main_matrix.push_back(temp);
                temp.clear();
                temp2.clear();
            }

            id = file.substr(1);
            sequence.clear();

        } else {
            sequence += file;
        }
    }

    if (!id.empty()) {
        temp2.push_back(id);

        temp.push_back(sequence);
        seq_id.push_back(temp2);
        main_matrix.push_back(temp);
            temp.clear();
            temp2.clear();
        }
        
    //transforming all lowercase into uppercase
        for (int i = 0; i < main_matrix.size(); i++) {
            for (int j = 0; j < main_matrix[i].size(); j++) {
                transform(main_matrix[i][j].begin(), main_matrix[i][j].end(), main_matrix[i][j].begin(), ::toupper);
            }
        }
    //checking for unwanted elements to eliminate non-dna sequence
    vector<string> unwanted{"B", "D", "E", "F", "H", "I", "J", "K", "L", "M",
                            "N", "O", "P", "Q", "R", "S", "V", "W", "X", "Y",
                            "Z"};
        
        //creating a map of header and sequence
        map<string, string> first;

        for (int i = 0; i < main_matrix.size(); i++) {
            for (int j = 0; j < main_matrix[i].size(); j++) {
                for (int m = 0; m < unwanted.size(); m++) {
                    if(main_matrix[i][j].find(unwanted[m])!=string::npos){
                        main_matrix[i][j]="";
                        first[seq_id[i][j]] = main_matrix[i][j];
                        cerr<<seq_id[i][j]<<endl;}
                    else{
                        first[seq_id[i][j]] = main_matrix[i][j];}

                    }

                }
            }

        

        //creating a vector of struct Contig
        vector<Contig *> v;

        map<string, string>::iterator it;
        for (it = first.begin(); it != first.end(); ++it) {
            
            //tmp is an instance of type Contig
            Contig tmp;
            
            //storing header into the object
            tmp.seq_name = it->first;
            for (int j = 0; j < it->second.length(); j++) {


                //generating all possible k-mers and storing into the Contig object
                while ( it->second.length()!= 0) {
                    string pre = nth_element(it->second, n+1, k);
                    tmp.k_mer.push_back(pre);
                    it->second.erase(it->second.begin() + 0);
                }

            }
            
            //eliminating the k_mers of length not equal to k
            for (int i = 0; i < tmp.k_mer.size(); i++) {
                if (tmp.k_mer[i].length() != k) {
                    tmp.k_mer.erase(tmp.k_mer.begin() + i);
                }


            }
            
            //lexicographically sorting the k_mers
            sort(tmp.k_mer.begin(), tmp.k_mer.end());
            
            //counting the k_mers
            map<string, int> duplicate;
            for (string i: tmp.k_mer) {
                if(i.length()!=0)
                ++duplicate[i];
            }
            Contig *c = new Contig;
            c->k_mer = tmp.k_mer;
            c->seq_name = tmp.seq_name;
            c->d = duplicate;
            v.push_back(c);


        }

        //output results
        for (int i = 0; i < v.size(); i++) {
            cout<< v[i]->seq_name << endl;
            map<string, int>::iterator it_2;
            if (!v[i]->k_mer.empty()) {
                for (it_2 = v[i]->d.begin(); it_2 != v[i]->d.end(); ++it_2) {
                    cout << it_2->first << " " << it_2->second << endl;
                }
            }
            cout << endl;

        }
        }


        return 0;
    }

