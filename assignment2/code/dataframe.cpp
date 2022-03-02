#include "dataframe.hpp"
#include <vector>
//Also consider the code in utils.hpp may come in handy (does not have to be used)
using namespace std;
Dataframe::Dataframe() = default;

template<typename T>
void Dataframe::add_column(const std::vector<T> &col_values) {
    this->data.push_back(col_values);

}





void Dataframe::set_colnames(const std::vector<std::string> &cnames) {
    for (int i=0; i<cnames.size(); i++){
        this->colnames.push_back(cnames[i]);
    }

}

void Dataframe::set_rownames(const std::vector<std::string> &rnames) {
    for (int i=0; i<rnames.size(); i++){
        this->rownames.push_back(rnames[i]);
    }

}


bool Dataframe::has_rownames() const {
    if(this->rownames.size()>0){
        return true;
    }
    return false;
}

bool Dataframe::has_colnames() const {
    if(this->colnames.size()>0){
        return true;
    }
    return false;
}

std::size_t Dataframe::nrows() const {
    return this->rownames.size();
}

std::size_t Dataframe::ncols() const {
    return this->colnames.size();
}

const std::vector<std::string> &Dataframe::get_rownames() const {
    for (int i=0; i< this->rownames.size(); i++){
        return reinterpret_cast<const std::vector<std::basic_string<char>> &>(this->rownames[i]);
    }
}

const std::vector<std::string> &Dataframe::get_colnames() const {
    for (int i=0; i< this->colnames.size(); i++){
        return reinterpret_cast<const std::vector<std::basic_string<char>> &>(this->colnames[i]);
    }
}


template<typename T>
T Dataframe::get(const size_t i, const size_t j) const {

    Dataframe x=*this;
    for(int a=0; a< x.ncols(); a++){
        for(int b=0; x.nrows(); b++){
            if(a==i and b==j){
                return &x;
            }

        }
    }
}

template<typename T>
T Dataframe::get(const std::string &r, const std::string &c) const {
    Dataframe x=*this;
    for(int a=0; a< x.ncols(); a++){
        for(int b=0; x.nrows(); b++){
            if(x.colnames[a]==r and x.rownames[b]==c){
                return &x;
            }

        }
    }
}


void Dataframe::clear_rownames() {
    this->rownames.erase(this->rownames.begin(),this->rownames.end());
}

void Dataframe::clear_colnames() {
    this->colnames.erase(this->colnames.begin(),this->colnames.end());
}

void Dataframe::remove_column(const size_t i) {

    for(auto&p : this->data){
        p.erase(p.begin()+i);
    }

    this->colnames.erase(colnames.begin()+i);
}

void Dataframe::swap_columns(const size_t i, const size_t j) {
    list<vector<ColType>>::iterator it = this->data.begin();
    for(int x=0; x<i; x++){
        it++;
    }
    vector<ColType>x= *it;


    list<vector<ColType>>::iterator it1 = this->data.begin();
    for(int x=0; x<j; x++){
        it1++;
    }
    vector<ColType>y= *it1;

    for(auto&p : this->data){
        p.erase(p.begin()+j);
    }
    std::list<vector<ColType>>::iterator it3;
    it3=this->data.begin();
    ++it3;
    this->data.insert(it3,i,y);
    this->data.insert(it3,j,x);

    for(auto&p : this->data){
        p.erase(p.begin()+(i+1));
    }
    for(auto&p : this->data){
        p.erase(p.begin()+(j+1));
    }

    for(auto&p : this->data){
        for(auto&p : this->data){

        }
    }


        }











