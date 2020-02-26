#include "network.h"
#include <iostream>
#include <fstream>
using namespace std;

network::network(int num_of_people, int num_of_neighbors,int num_of_sicks,double spread_chance, int days_to_out) {
    this->days_to_out = days_to_out;
    this->spread_chance = spread_chance;
    for (int i = 0; i <= num_of_neighbors; i++) {
        this->ppl.push_back(new people(i));

    }

    for (int i = 0; i <= num_of_neighbors; i++) {
        for (int j = i + 1; j <= num_of_neighbors; j++) {
            this->add_neighbor(i, j);
        }
    }
    int k = 0;
    int init_s = 0;
    for (int i = num_of_neighbors + 1; i < num_of_people; i++) {
        this->ppl.push_back(new people(i));
        init_s = hash_map.size();
        for (int j = 0; j < num_of_neighbors; j++) {
            bool should_retry = true;
            while (should_retry) {
                k = rand() % init_s;
                int index = hash_map[k]->id;
                if (!ppl[i]->is_neighbor(index)) {
                    this->add_neighbor(i, index);
                    should_retry = false;
                }
            }
        }
    }

    for(int i=0 ; i< num_of_sicks;i++){
        int r = rand()% num_of_people;
        ppl[r]->make_sick(0);
    }

}

void network::passDay()
{
    this->day++;
    int s = int(this->ppl.size());
    for(int i= 0; i<s;i++){
        if(ppl[i]->is_sick && !ppl[i]->is_out){
            if(day - ppl[i]->start_day_of_sickness >= 14){
                ppl[i]->is_out=true;
            }
        }
    }

}

void network::add_neighbor(int i, int j) {
    this->ppl[i]->add_neighbor(ppl[j]);
    this->ppl[j]->add_neighbor(ppl[i]);
    this->hash_map.push_back(ppl[i]);
    this->hash_map.push_back(ppl[j]);
}

void network::write_hashmap(string address)
{
    cout<<"start"<<endl;
    ofstream outfile;
    outfile.open(address);
    for(int i=0;i<int(this->hash_map.size());i++){
        outfile<<hash_map[i]->id<<"\t";
    }
    outfile.close();
    cout<<"finish"<<endl;

}
