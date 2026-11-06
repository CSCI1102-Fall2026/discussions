/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "department.h"
#include "people.h"
#include "professor.h"
#include "student.h"

Person ** populate_db(const Entry * entries, int num_entries) {
    Person ** people = new Person *[num_entries];
    for (int i = 0; i < num_entries; ++i) {
        switch (entries[i].person_type) {
            case STUDENT:
                people[i] = new Student(entries[i].first_name,
                        entries[i].last_name, entries[i].department);
                break;
            case PROFESSOR:
                people[i] = new Professor(entries[i].first_name,
                        entries[i].last_name, entries[i].department);
                break;
            default:
                std::cerr << "Unsupported person type: " <<
                    entries[i].person_type << std::endl;
        }
    }
    return people;
}

int main() {
    int num_people = sizeof(records) / sizeof(records[0]);
    Person ** people = populate_db(records, num_people);
    for (int i = 0; i < num_people; ++i) {
        std::cout << people[i]->to_string() << std::endl;
    }
    std::cout << "Students:" << std::endl;
    for (int i = 0; i < num_people; ++i) {
        if (typeid(* people[i]) == typeid(Student)) {
            std::cout << "\t" << ((Student *)people[i])->get_full_name() << std::endl;
        }
    }

    for (int i = 0; i < num_people; ++i) {
        delete people[i];
    }

    delete[] people;

    return EXIT_SUCCESS;
}

