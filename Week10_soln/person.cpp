/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include "person.h"

Person::Person(std::string first_name, std::string last_name) :
    first_name(first_name), last_name(last_name)
{}

Person::~Person()
{}

std::string Person::get_full_name() {
    return first_name + " " + last_name;
}

std::string Person::to_string() {
    return get_full_name();
}
