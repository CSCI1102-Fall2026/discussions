/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#pragma once

#include <string>

#include "department.h"

#include "person.h"

class Professor : public Person {

    public:

        Professor(std::string first_name, std::string last_name, Department department);
        Department get_department();
        std::string to_string();

    private:

        Department department;
};
