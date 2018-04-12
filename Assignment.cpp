/**
 * File: Assignment.cpp
 * Author: Keegan Donley
 * Date Updated: 4/11/18
 * ----------------------------------------
 * Author contact: kd@keegandonley.com
 * Author website: https://www.keegandonley.com
 *
 * This file contains the implementations of the Assignment class.
 * This class handles running the program and collecting feedback for each
 * student. The Assignment should be initialized with a metadata set that has
 * been already generated. 
 **/

#include <string>
#include <iostream>
#include "AssignmentMeta.hpp"
#include "Assignment.hpp"
#include "Student.hpp"
#include "colors.h" // Note that on the Windows branch, all color defines are only placeholders.

/**
 * Constructor. An Assignment object is initialized with an assignment metadata object
 * 
 * @param data - aMeta * - The assignment metadata object.
 **/
Assignment::Assignment(aMeta * data) {
    assignmentData = data;
}



/**
 * This function prints the assignment information. As it currently stands, this is 
 * only the assignment metadata for the assignment being currently graded.
 **/
void Assignment::printAssignmentInfo() {
    assignmentData -> printClassMeta();
}



/**
 * This function iterates through each student in the vector and prints out the 
 * data for that student.
 * */
void Assignment::printStudentInfo() {
    for (std::vector<Student *>::iterator it = students.begin(); it != students.end(); ++it)
        (*it) -> printStudent(assignmentData);
}



/**
 * This function adds a student to the vector of students currently being graded.
 *
 * @param myStudent - student * - a student object representing a name as well as 
 * 				  the feedback for that student.
 *
 * @returns - bool - always returns true
 **/
bool Assignment::addStudent(Student * myStudent) {
    students.push_back(myStudent);
    return true;
}



/**
 * This function handles processing one student at a time. Additionally, this is where the 
 * keywords are read in from the input file. 
 *
 * @param meta - aMeta * - An assignment metadata object
 *
 * @returns - bool - always returns true
 **/
bool Assignment::readStudents(aMeta * meta) {
    keyWord * keys = new keyWord();
    keys -> readKeys();

    std::string fname;
    char linit;
    std::cout << BLUE << "Enter the student's first name and last initial (quit to end): " << ENDCOLORS;
    std::cin >> fname;

    while (fname != "quit") {
        std::cin >> linit;
        Student * myStudent = new Student(fname, linit);
        myStudent -> runGrading(keys, meta);
        addStudent(myStudent);
        myStudent -> printStudent(meta);
        myStudent -> writeStudentToFile(meta);
        // meta -> outPutFinishedMessage();
        std::cout << BLUE << "Enter the student's first name and last initial (quit to end): " << ENDCOLORS;
        std::cin >> fname;
    }
    remove("currentClass.txt");

    return true;
}

