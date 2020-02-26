//
// Created by Aref Ghodamai on 2/25/20.
//

#ifndef UNTITLED_NETWORK_H
#define UNTITLED_NETWORK_H

#include <vector>
#include <string>
#include "people.h"

class network {
public:
    int day = 0;
    vector<people*> ppl;
    vector<people *> hash_map;
    double spread_chance;
    int days_to_out;
    network(int num_of_people, int num_of_neighbors, int num_of_sicks, double spread_chance,int days_to_out);
    void passDay();
    void add_neighbor(int i, int j);
    void write_hashmap(string address);
};



#endif //UNTITLED_NETWORK_H
