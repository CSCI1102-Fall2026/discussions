/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#pragma once

#include <string>

class Person {

    public:

        Person(std::string first_name, std::string last_name);
        virtual ~Person();
        std::string get_full_name();
        virtual std::string to_string();

    private:

        std::string first_name;
        std::string last_name;
};
