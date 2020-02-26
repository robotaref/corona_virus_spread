#include "src/network.h"
#include <iostream>
#include "src/people.h"

using namespace std;

int main() {
    int num_of_people = 1000;
    int num_of_neighbors = 5;
    int num_of_sicks = 10;
    double spread_chance = .15;
    int days_to_out = 14;
    network net(num_of_people, num_of_neighbors, num_of_sicks, spread_chance, days_to_out);
    net.write_hashmap("hash_map.txt");
//    net.pass_day()
    return 0;
}
