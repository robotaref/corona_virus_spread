//
// Created by Aref Ghodamai on 2/25/20.
//

#include "network.h"
#include <iostream>

using namespace std;

network::network(int num_of_people, int num_of_neighbors) {

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

}

void network::add_neighbor(int i, int j) {
    this->ppl[i]->add_neighbor(ppl[j]);
    this->ppl[j]->add_neighbor(ppl[i]);
    this->hash_map.push_back(ppl[i]);
    this->hash_map.push_back(ppl[j]);
}
