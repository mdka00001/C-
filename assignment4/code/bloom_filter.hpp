#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <cstdint>  // uint64_t

#include <bitset>
#include <math.h>

#include "murmurhash.hpp"

template <typename Key>
struct BloomHash {
    std::size_t operator()(Key key, unsigned int seed) const {
        // implement using murmur3_32

        return murmur3_32(reinterpret_cast<uint8_t*>(&key), sizeof(key) ,seed);
    }
};

template <typename Key, unsigned int m, typename Hash = BloomHash<Key>>
class BloomFilter {
public:
    explicit BloomFilter(unsigned int num_hashes){

        this->k_ = num_hashes;

    }

    BloomFilter(std::initializer_list<Key> init, unsigned int num_hashes){

        this->k_ = num_hashes;
        for (Key i=0; i<init.size(); i++) {
            insert(i);
        }

    }

    template <typename It>
    BloomFilter(It first, It last, unsigned int num_hashes){

        this->k_ = num_hashes;

        for (auto i = first; i != last ; i++) {

            insert(*i);

        }
    }

    bool insert(const Key& key){
        for(auto i=0; i< this->k_; i++){
            Hash h;
            int k=h(key,i)%this->data_.size();
            if(this->data_[k]==0){
                this->data_[k]=1;
                return true;
            }
            else{
                continue;
            }
        }
    }

    bool contains(const Key& key) const{
        for (auto i=0; i<this->k_; i++){
            Hash h;
            int k=h(key,i)%this->data_.size();
            if(this->data_[k]==0){
                return false;
            }


        }
        return true;
    }

    uint64_t approx_size() const;

    template <typename It>
    double false_positive_rate(It positive_begin, It positive_end,
                               It negative_begin, It negative_end) const{

        unsigned long TP, FP, TN, FN, ratio;


        for (auto i = positive_begin; i != positive_end; ++i) {

            if(contains(*i)){
                TP++;
            }

            else{
                FP++;
            }

        }

        for (auto i = negative_begin; i != negative_end; ++i) {

            if(!contains(*i)){
                TN++;
            }
            else{
                FN++;
            }

        }
        ratio=FP/(FP+TN);

        return ratio;

    }

    double space_ratio(uint64_t num_elements){
    }

private:
    std::bitset<m> data_;
    unsigned int k_;
};

#endif  // BLOOM_FILTER_HPP
