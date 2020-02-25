//
// Created by Aref Ghodamai on 2/25/20.
//

#ifndef UNTITLED_NETWORK_H
#define UNTITLED_NETWORK_H

#include <vector>
#include "people.h"

class network {
public:
    vector<people*> ppl;
    vector<people *> hash_map;

    network(int num_of_people, int num_of_neighbors);
    void add_neighbor(int i, int j);
};


#endif //UNTITLED_NETWORK_H
