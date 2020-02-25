//
// Created by Aref Ghodamai on 2/25/20.
//

#include "network.h"
#include <iostream>
#include <random>

using namespace std;

network::network(int num_of_people, int num_of_neighbors) {
    vector<people *> hash_map;
    for (int i = 0; i <= num_of_neighbors; i++) {
        this->ppl.push_back(new people(i));
    }

    for (int i = 0; i <= num_of_neighbors; i++) {
        for (int j = i + 1; j <= num_of_neighbors; j++) {
            this->add_neighbor(i, j);

        }
    }

//    for (int i = 3; i < num_of_people; i++) {
//        this->ppl.push_back(new people(i));
//
//        for (int j = 0; j < num_of_neighbors; j++) {
//            cout << "here: " << i << "\t";
//            cout << rand() % (int(ppl.size())) << endl;
//
//        }
//    }
}

void network::add_neighbor(int i, int j) {
    this->ppl[i]->add_neighbor(ppl[j]);
    this->ppl[j]->add_neighbor(ppl[i]);

}
