/**
 * File: AssignmentMeta.cpp
 * Author: Keegan Donley
 * Date Updated: 4/12/18
 * ----------------------------------------
 * Author contact: kd@keegandonley.com
 * Author website: https://www.keegandonley.com
 *
 * This file contains the implementations of the AssignmentMeta class.
 * This class handles storing and managing metadata for each asignment. 
 * For example, the class name, assignment points, and solution information
 * among a few other things.
 **/

#include <iostream>
#include <string>
#include <fstream>
#include "AssignmentMeta.hpp"
#include "colors.h"

/**
 * Constructor.
 * 
 * totalScore - The maximum score for the assignment. Initializes to 0.
 * assignmentName - The name (or number) of the assignment. Initializes to "".
 * classLetters - The identifier for the class (CS, CTE, CIS, etc). Initializes to "CS"
 * classNumber - The course identifier (2a, 110, 242, etc). Initializes to "".
 **/
aMeta::aMeta() {
    totalScore = 0;
    assignmentName = "";
    classLetters = "CS";
    classNumber = "";
}



/**
 * Constructor.
 * 
 * @param score - int - The maximum score for the assignment. Initializes to 0.
 * @param assignmentName - std::string - The name (or number) of the assignment. Initializes to "".
 * @param classLetters - std::string - The identifier for the class (CS, CTE, CIS, etc). Initializes to "CS"
 * @param classNumber - std::string - The course identifier (2a, 110, 242, etc). Initializes to "".
 * @param password - std::string - The password to access the solution.
 **/
aMeta::aMeta(int score, std::string name, std::string letters, std::string number, std::string password) {
    totalScore = score;
    assignmentName = name;
    classLetters = letters;
    classNumber = number;
    solutionPWD = password;
}



/**
 * This function prints out the assignment metadata as needed. 
 **/
void aMeta::printClassMeta() {
    std::cout << GREEN << "\n-- Assignment metadata --------------------------------------" << std::endl;
    std::cout << "Class name: " << classLetters << classNumber << std::endl;
    std::cout << "Current assignment: " << assignmentName << std::endl;
    std::cout << "Assignment points: " << totalScore << std::endl;
    std::cout << "\nCompletion Message:\n";
    outPutFinishedMessage();
    std::cout << "-------------------------------------------------------------\n" << ENDCOLORS << std::endl;
}



/**
 * This function gets the maximum score for the assignment.
 * 
 * @returns int - the maximum score for the assignment.
 **/
int aMeta::getTotalScore() {
    return totalScore;
}



/**
 * This function gets the assignment name.
 * 
 * @returns std::string - the assignment name.
 **/
std::string aMeta::getAName() {
    return assignmentName;
}



/**
 * This function outputs the URL, username, and the password
 **/
void aMeta::outPutFinishedMessage() {
    std::cout << initialMessage << std::endl;
    std::cout << "URL: " << patternMatchURL() << std::endl;
    std::cout << "Username: " << "a" + assignmentName << std::endl;
    std::cout << "Password: " << solutionPWD << std::endl;
}



/**
 * This function gets the assignment identifier in the following format:
 * <letters><number>_assignment<assignment_name>
 * For example, for CS 10 assignment 1: CS10_assignment1
 * 
 * @returns std::string - the assignment identifier
 **/
std::string aMeta::getAssignmentIdentifier() {
    return classLetters + classNumber + "_assignment" + assignmentName;
}



/**
 * This function reads in the pattern for auto-generating solution URLS.
 * The pattern is stored in config.txt in the following format:
 *      http://daveteaches.com/%classNum%/s%assignment%/s%assignment%.shtml
 * 
 * Each parameter enclosed in %% will be replaced by the appropriate value.
 * For CS 10 assignment 1, the generated URL will be 
 *      http://daveteaches.com/10/s1/s1.shtml
 * 
 * The configuration can be modified to suit other URL schemes - but use caution when editing
 * the file config.txt. There is no error handling or recovery in case errors are introduced.
 * 
 * TODO: Mapping needs to support more parameters so that the URL config can be used for 
         more complex schemes. Currently, the only two parameters that can be auto-filled are
         classNum and assignment.
 * 
 * @returns std::string - the expanded and filled-in URL corresponding to the
 *                        pattern in 'config.txt'
 **/
std::string aMeta::patternMatchURL() {
    std::string pattern;
    std::string result = "";
    std::string key = "";
    std::ifstream infile;
    infile.open ("config.txt");
    std::getline(infile, pattern);
    for (unsigned long i = 0; i < pattern.size(); i++) {
        // If the character isn't a key delimiter add it
        if (pattern[i] != '%') {
            result = result + pattern[i];
        }
        // We are looking at a delimiter (%)
        else {
            i++; // increment past the delimiter
            key = ""; // reset the key - we are about to read it
            while (pattern[i] != '%') { // until the next delimiter, build the key
                key = key + pattern[i];
                i++;
            }
            // The key is done, now we use it to store the value
            if (key == "classNum")
                result = result + classNumber;
            else if (key == "assignment")
                result = result + assignmentName;
            // TODO: Needs to support more parameters so that the URL config can be used for 
            //       more complex schemes

            // Now, we are looking at a delimiter, so the loop increments one past it.
        }
    }
    return result;

}
