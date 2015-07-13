//
// Created by Connor Jones on 7/8/15.
//

#ifndef AUDISKTOOL_REPORT_H
#define AUDISKTOOL_REPORT_H
using std::ifstream;
using std::ofstream;


//#include <iostream>
class report {

    private:
        std::string fileName;
        std::string record;
        config_info configInfo;

    public:
        void printReport(){
            //todo: need to catch exception where file can't be opened
            string file = "\"" + fileName + "\"";
            cout << "file name: "  << file << endl << endl;
//            ifstream inStream(fileName);
//            inStream.close();
        };

        void writeFile();

        std::string getFileNAme() { return report::fileName; } //todo: necessary?

        report(config_info configInfo) {
            report::configInfo = configInfo;
            report::fileName = configInfo.getReportName();
        }
};
#endif //AUDISKTOOL_REPORT_H