/**
 * File: Assignment.hpp
 * Author: Keegan Donley
 * Date Updated: 4/11/18
 * ----------------------------------------
 * Author contact: kd@keegandonley.com
 * Author website: https://www.keegandonley.com
 *
 * This file contains the Assignment class.
 * This class handles running the program and collecting feedback for each
 * student. The Assignment should be initialized with a metadata set that has
 * been already generated.
 *
 * Private data members:
 * 	aMeta * assignmentData - the assignment metadata as defined by aMeta.
 * 	vector<Student *> students - a vector containing all the students and their
 * 					data for the current grading session.
 **/

#include <string>
#include <vector>

#include "AssignmentMeta.hpp"
#include "Student.hpp"
#include "keyWord.hpp"


#ifndef __A_DEF
#define __A_DEF

class Assignment {
public:
    Assignment(aMeta * data);
    void printAssignmentInfo();
    void printStudentInfo();
    bool addStudent(Student * studentInfo);
    bool readStudents(aMeta * meta);

private:
    aMeta * assignmentData;
    std::vector<Student *> students;
};

#endif
