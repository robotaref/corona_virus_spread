//
// Created by Aref Ghodamai on 2/25/20.
//

#include "people.h"

people::people(int id) {
    this->id = id;
}

void people::make_sick(int start_day)
{
    this->is_out = false;
    this->is_sick = true;
    this->start_day_of_sickness = start_day;
}

void people::add_neighbor(people *other) {
    this->neighbors.push_back(other);
}


bool people::is_neighbor(int index) {
    for(int i = 0; i<int(this->neighbors.size());i++){
        if(index== this->neighbors[i]->id)
            return true;
    }
    return false;
}
