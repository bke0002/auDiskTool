//
// Created by Connor Jones on 7/8/15.
//

#ifndef AUDISKTOOL_REPORT_H
#define AUDISKTOOL_REPORT_H



#include <iostream>
class report {

    private:
        std::string fileName;
        std::string record;

    public:
        void printReport();
        void writeFile();
        void setFileName(std::string fileName){ report::fileName = fileName; }
        std::string getFileNAme() { return report::fileName; }
};
#endif //AUDISKTOOL_REPORT_H