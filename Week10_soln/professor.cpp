/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include "professor.h"

Professor::Professor(std::string first_name, std::string last_name, Department department) :
    Person(first_name, last_name),
    department(department)
{}

Department Professor::get_department() {
    return department;
}

std::string Professor::to_string() {
    return Person::to_string() + " is a professor in the " +
        department_to_string(get_department()) + " Department.";
}
