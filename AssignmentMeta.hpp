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

private:
    int totalScore;
    std::string assignmentName;
    std::string classNumber;
    std::string classLetters;
    std::string initialMessage = "Good work on this assignment. Here is the information to view the solution. Please do not share it with anyone else.";
    std::string baseURL = "http://daveteaches.com/";
    std::string solutionPWD;


};
#endif
