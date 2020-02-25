//
// Created by Aref Ghodamai on 2/25/20.
//

#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

#include <vector>

class people;

using namespace std;

class people {
public:
    bool is_sick;
    int id;
    vector<people *> neighbors;

    people(int id);

    void add_neighbor(people *other);
};


#endif //UNTITLED_PEOPLE_H
