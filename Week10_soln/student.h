/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#pragma once

#include <string>

#include "department.h"

#include "person.h"

class Student : public Person {

    public:

        Student(std::string first_name, std::string last_name, Department major);
        Department get_major();
        std::string to_string();

    private:

        Department major;
};
