/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include "student.h"

Student::Student(std::string first_name, std::string last_name, Department major) :
    Person(first_name, last_name),
    major(major)
{}

Department Student::get_major() {
    return major;
}

std::string Student::to_string() {
    return Person::to_string() + " is a student majoring in " +
        department_to_string(get_major()) + ".";
}

