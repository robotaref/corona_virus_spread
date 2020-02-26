//
// Created by Aref Ghodamai on 2/25/20.
//

#ifndef UNTITLED_PEOPLE_H
#define UNTITLED_PEOPLE_H

#include <vector>

using namespace std;

class people {
public:
    bool is_sick;
    bool is_out;
    int id;
    int start_day_of_sickness;

    vector<people *> neighbors;

    people(int id);

    void make_sick(int start_day);

    bool is_neighbor(int index);

    void add_neighbor(people *other);
};


#endif //UNTITLED_PEOPLE_H
