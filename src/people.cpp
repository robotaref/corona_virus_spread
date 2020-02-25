//
// Created by Aref Ghodamai on 2/25/20.
//

#include "people.h"

people::people(int id) {
    this->id = id;
}

void people::add_neighbor(people *other) {
    this->neighbors.push_back(other);
}
