/*
 * Author: Amittai Aviram - aviram@bc.edu
 */

#include "department.h"

enum PersonType { STUDENT, PROFESSOR };

struct Entry {
    const char * first_name;
    const char * last_name;
    const PersonType person_type;
    const Department department;
};

const Entry records[] = {
    {"Grace", "Wagner", STUDENT, COMPUTER_SCIENCE},
    {"Salamun", "Nuhin", STUDENT, COMPUTER_SCIENCE},
    {"Zhejun", "Zhang", STUDENT, COMPUTER_SCIENCE},
    {"Tyla", "Clemens", STUDENT, COMPUTER_SCIENCE},
    {"Caden", "Parajuli", STUDENT, MATHEMATICS},
    {"Alexandra", "Magnusson", STUDENT, MATHEMATICS},
    {"Steven", "Roche", STUDENT, MATHEMATICS}, 
    {"Alexander", "Creiner", PROFESSOR, COMPUTER_SCIENCE},
    {"Sergio", "Alvarez", PROFESSOR, COMPUTER_SCIENCE},
    {"Amittai", "Aviram", PROFESSOR, COMPUTER_SCIENCE},
    {"Cristina", "Meier", PROFESSOR, COMPUTER_SCIENCE},
    {"Maira", "Marques Samary", PROFESSOR, COMPUTER_SCIENCE},
    {"Duncan", "Levear", PROFESSOR, COMPUTER_SCIENCE},
    {"Charles", "Wiseman", PROFESSOR, COMPUTER_SCIENCE},
    {"Jessica", "Finocchiaro", PROFESSOR, COMPUTER_SCIENCE},
    {"George", "Mohler", PROFESSOR, COMPUTER_SCIENCE}
};

