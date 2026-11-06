/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include <string>

#include "department.h"

std::string department_to_string(Department department) {
    std::string department_names[] = {
        "AADS",
        "Art",
        "Art History",
        "Astronomy",
        "Biology",
        "Classics",
        "Chemistry",
        "Computer Science",
        "Earth Science",
        "Economics",
        "Geography",
        "History",
        "Languages",
        "Linguistics",
        "Mathematics",
        "Philosophy",
        "Physics",
        "Religion",
        "Political Science",
        "Sociology",
        "Statistics",
        "Theater",
        "Theology"
    };
    return department_names[department];
};


