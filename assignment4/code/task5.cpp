#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>
#include <iterator>
#include <experimental/iterator>

using namespace std;

vector<string> maximal_cq;

vector<int> uni(vector<int> r, int i){

    vector<int> l;
    l.push_back(i);
    vector<int> tmp;
    set_union(r.begin(), r.end(), l.begin(), l.end(), back_inserter(tmp));
    return tmp;
}
vector<int> intersection(vector<int> p,
                                      vector<vector<int>> g, int i){
    vector<int> v3;


    for(int m=0; m<g[i].size(); m++) {


        set_intersection(p.begin(), p.end(),
                         g[i].begin(), g[i].end(),
                         back_inserter(v3));


    }
    return v3;
}

void BK_algorithm(vector<vector<int>> g, vector<int> r, vector<int> p, vector<int> x) {

    vector<int> r_1;
    vector<int> p_1;
    vector<int> x_1;


    if (p.empty() and x.empty()) {
        ostringstream ss;
        copy(r.begin(), prev(r.end()), ostream_iterator<int>(ss, ", "));
        ss << r.back();
        string s = "{" +ss.str() + "}";
        maximal_cq.push_back(s);

    } else {
        for (int i: p) {
            r_1 = uni(r, i);
            p_1 = intersection(p, g, i);
            x_1 = intersection(x, g, i);

            BK_algorithm(g, r_1, p_1, x_1);
            


        }
    }
}

int main(int argc, const char* argv[]) {

    //taking input in a 2d vector//
    string sa, sb;


    vector<vector<string>> main_matrix_str;

    vector<string> k;


    while (getline(cin, sa) && !sa.empty()) {


        sb = "";
        k.clear();
        for (int j = 0; j < sa.size(); j++) {

            if (sa[j] == ' ') {
                k.push_back(sb);
                sb = "";
            } else {
                sb = sb + sa[j];
            }
        }

        k.push_back(sb);
        main_matrix_str.push_back(k);


    }
    vector<vector<double>> main_matrix;

    for (int i = 0; i < main_matrix_str.size(); i++) {
        vector<double> temp;
        for (int j = 0; j < main_matrix_str[i].size(); j++) {
            double num = stod(main_matrix_str[i][j]);
            temp.push_back(num);

        }
        main_matrix.push_back(temp);
    }





    vector<vector<int>> g;


    vector<int> tmp;


    for (int  i = 0; i < main_matrix.size(); i++)
    {
        for (int j = 0; j < main_matrix[j].size(); j++)
        {
            if(main_matrix[i][j]==1){
                tmp.push_back(j);
            }
        }
        g.push_back(tmp);
        tmp.clear();
    }

    vector<int> r;

    vector<int> p;
    for (int i=0; i < g.size(); i++) {
        p.push_back(i);
    }


    vector<int> x;



    BK_algorithm(g, r, p, x);
    for (int k = 0; k < maximal_cq.size(); ++k) {
        sort(maximal_cq.begin(), maximal_cq.end());
        maximal_cq.erase(unique(maximal_cq.begin(), maximal_cq.end()), maximal_cq.end());
        cout<<maximal_cq[k]<<endl;
    }

    return 0;
}
