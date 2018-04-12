/**
 * File: AssignmentMeta.hpp
 * Author: Keegan Donley
 * Date Updated: 4/12/18
 * ----------------------------------------
 * Author contact: kd@keegandonley.com
 * Author website: https://www.keegandonley.com
 *
 * This file contains the aMeta class.
 * This class handles storing and managing metadata for each asignment. 
 * For example, the class name, assignment points, and solution information
 * among a few other things.
 * 
 Private data members:
 * 	int totalScore - The maximum points available for the assignment
 * 	std::string assignmentName - The name (or number) of the assignment
 *  std::string classNumber - The class number (or name in some cases)
 *  std::string classLetters - The letters representing the course 
 *                             (i.e. CS, CIS, EECS, etc)
 * std::string initialMessage - The message that is deplayed initially before the 
 *                              assignment solution information. Value contains:
 *                              "Good work on this assignment. Here is the information to view
 *                              the solution. Please do not share it with anyone else."
 * 
 *                              TODO: Read in this value from a config file as well.
 * 
 * std::string solutionPWD - The password to access the solution file.
 **/

#include <string>

#ifndef __AMETA_DEF
#define __AMETA_DEF

class aMeta {
public:
    aMeta();
    aMeta(int, std::string, std::string, std::string, std::string);
    void printClassMeta();
    int getTotalScore();
    std::string getAName();
    void outPutFinishedMessage();
    std::string getAssignmentIdentifier();
private:
    int totalScore;
    std::string assignmentName;
    std::string classNumber;
    std::string classLetters;
    std::string initialMessage = "Good work on this assignment. Here is the information to view\nthe solution. Please do not share it with anyone else.";
    std::string solutionPWD;
    std::string patternMatchURL();
};
#endif
