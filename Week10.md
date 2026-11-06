# Discussion Problems Week 10

This recitation exercise consists of a single coding challenge, which can be broken up into parts and distributed among group members to work on them in parallel.  You will then put all the parts together to make a working program.

## Overview
This project uses object-oriented programming and polymorophism to create a small but extensible database representing people at a university such as Boston College.  You will use a virtual function to get appropriate type-specific behavior from instances of various closely related classes.  The project also illstrates an advanced technique, runtime type identification (RTTI), to identify instances of a single subclass while filtering out all instances of related classes — at runtime. This is a big project, for which time is short, so you will have to work efficiently.

The database represents various sets of people at a university.  Each one of them is a person.  Every person has a first name and a last name.  A person may be a student.  In addition to the basic attributes of first and last names, a student has a major.  But a person may be, instead, a professor.  A professor does not have a major, but does have a home department.  We can represent these conceptual relations as follows:

```
                   Person
                      |- first_name (std::string)
                      |- last_name (string)
   -------------------------------------------
   |                                         |
Student                                  Professor
   |-major (Department                        |- department (Department)
```
Department is an enumeration type.  You may start with a small  number of possible departments, e.g., COMPUTER_SCIENCE and MATHEMATICS.

Person offers two public functions: `get_full_name` and `to_string`, where the former returns a `std::string` of the first name concatenated with a space followed by the last name, and the latter simply calls the former.  But `to_string` is a virtual function, so that Student and Professor can override its behavior appropriately.  Please see the sample output below.

## Development Steps
1. Declare a `Person` type in `person.h` and implement the constructor, `get_full_name`, and `to_string` functions, as described above. You will also need a _virtual destructor_, whose body you can leave empty (since it does nothing). The need for a virtual destructor is explained further below. Write a throwaway `main` function to test it.  (Full group, 5 minutes.)
2. Create a `makefile` to use from now on in development.  Be sure to include both a normal build target (say, `university_db`) and a `clean` target. (Full group, 5 minutes.)
3. Split the group up for the next part.  One team writes a declaration and implementation of `Student` and the other of `Professor`.  Each of these inherits from `Person`.  A `Student` has a major, whereas a `Professor` has a department.  Their respective `to_string` overrides are suggested by the sample output below. (Teams, 10 minutes.)
4. File `people.h` contains the raw data from which to build the database.  First in this file, declare an enumeration type, `PersonType`, to distinguish the two kinds of people, `STUDENT` and `PROFESSOR`. Then declare a structure type, `Entry`, to represent a raw data entry, with fields for the first name, last name, person type (using the enumeration type), and department (using the Department enumeration type).  Then declare an array of (`const`) Entries, with entries for students and faculty members.  Include yourselves and your friends as students and as many professors as you can easily bring to mind.  (Whole group, 5 minutes.)
5. The group splits up again for two functions to be declared in file `main.cpp`, `main` and a helper function called `populate_db`.  (Teams, 10 minutes.)
  - `populate_db` takes a pointer-to-`Entry` (the start address of an array of `Entry` objects) and the  number of elements in the array and returns a pointer-to-pointer-to-`Person`, i.e., the start address of an array of addresses, each of which is the address of a distinct `Person` object. It allocates the array on the heap, and then populates it with the addresses of objects of type `Student` or `Professor` allocated on the heap. To do so, it iterates over the array of `Entry` objects whose start address is passed in, and, in a `switch` statement, checks the `person_type` field of each successive `Entry` object:  if it's a `STUDENT`, it creates a new `Student` object and puts its address into the array to be returned; if a `PROFESSOR`, a `Professor`.  (Include a `default` and handle it as a fatal error after printing an appropriate message.)
  - After it calls `populate_db` and gets the returned address of the start of an array — let's call it `people` — `main` iterates over `people` and calls `to_string` on each element.  Next, it iterates _again_ over the `people` array, this time filtering for `Student` objects only, and printing their full names out.  This part requires runtime type identification (RTTI), by means of the `typeid` operator.  The test for whether a `Person` object whose address is at hand is really a `Student` object looks like this: `if (typeid(* people[i]) == typeid(Student))` (and notice the dereference, since `people[i]` is the address of a `Person` object).

## Sample Output
```% ./university_db 
Grace Wagner is a student majoring in Computer Science.
Salamun Nuhin is a student majoring in Computer Science.
Zhejun Zhang is a student majoring in Computer Science.
Tyla Clemens is a student majoring in Computer Science.
Caden Parajuli is a student majoring in Mathematics.
Alexandra Magnusson is a student majoring in Mathematics.
Steven Roche is a student majoring in Mathematics.
Alexander Creiner is a professor in the Computer Science Department.
Sergio Alvarez is a professor in the Computer Science Department.
Amittai Aviram is a professor in the Computer Science Department.
Cristina Meier is a professor in the Computer Science Department.
Maira Marques Samary is a professor in the Computer Science Department.
Duncan Levear is a professor in the Computer Science Department.
Charles Wiseman is a professor in the Computer Science Department.
Jessica Finocchiaro is a professor in the Computer Science Department.
George Mohler is a professor in the Computer Science Department.
Students:
	Grace Wagner
	Salamun Nuhin
	Zhejun Zhang
	Tyla Clemens
	Caden Parajuli
	Alexandra Magnusson
	Steven Roche
% 
```

Next, 

