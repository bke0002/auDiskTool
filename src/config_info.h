//
// Created by Connor Jones on 7/8/15.
//

#ifndef AUDISKTOOL_CONFIG_INFO_H
#define AUDISKTOOL_CONFIG_INFO_H
#include <fstream>

//using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;


class config_info {
private:
    int interval;
    int count;
    int blk_read;
    int blk_reads;
    int kb_reads;
    int blk_write;
    int blk_writes;
    int kb_writes;
    bool config_updated;
    string reportName;

public:
    int getInterval() const { return interval; }

    void setInterval(int interval) {
        if(interval != getInterval())  {
            config_info::interval = interval;
            config_updated = true;
            std::cout << "The sampling interval has been changed to " << interval << " seconds.\n";
        } else {
            std::cout << "Interval is already " << interval << ".\n";
        }
    }

    int getCount() const { return count; }

    void setCount(int count) {
        if(count != getCount())  {
            config_info::count = count;
            config_updated = true;
            std::cout << "The number of records in each run has been changed to " << getCount() << ".\n";
        } else {
            std::cout << "The number of records generated in each run is already set to " << getCount() << ".\n";
        }
    }

    int getBlk_read() const { return blk_read; }

    void setBlk_read(int blk_read) {
        if(blk_read != getBlk_read())  {
            config_info::blk_read = blk_read;
            config_updated = true;
            std::cout << "print_blk_read has been changed to " << getBlk_read() << ".\n";
        } else {
            std::cout << "print_blk_read was " << getBlk_read() << "; the parameter remains unchanged to "
                             << getBlk_read() <<".\n";
        }
    }

    int getBlk_reads() const { return blk_reads; }

    void setBlk_reads(int blk_reads) {
        if(blk_reads != getBlk_reads())  {
            config_info::blk_reads = blk_reads;
            config_updated = true;
            std::cout << "print_blk_read/s has been changed to " << getBlk_reads() << ".\n";
        } else {
            std::cout << "print_blk_read/s was " << getBlk_reads() << "; the parameter remains unchanged to "
            << getBlk_reads() <<".\n";
        }
    }

    int getKb_reads() const { return kb_reads; }

    void setKb_reads(int kb_reads) {
        if(kb_reads != getKb_reads())  {
            config_info::kb_reads = kb_reads;
            config_updated = true;
            std::cout << "print_kb_reads has been changed to " << getKb_reads() << ".\n";
        } else {
            std::cout << "print_kb_reads was " << getKb_reads() << "; the parameter remains unchanged to "
            << getKb_reads() <<".\n";
        }
    }

    int getBlk_write() const { return blk_write; }

    void setBlk_write(int blk_write) {
        if(blk_write != getBlk_write())  {
            config_info::blk_write = blk_write;
            config_updated = true;
            std::cout << "print_blk_write has been changed to " << getBlk_write() << ".\n";
        } else {
            std::cout << "print_blk_write was " << getBlk_write() << "; the parameter remains unchanged to "
            << getBlk_write() <<".\n";
        }
    }

    int getBlk_writes() const { return blk_writes; }

    void setBlk_writes(int blk_writes) {
        if(blk_writes != getBlk_writes())  {
            config_info::blk_write = blk_writes;
            config_updated = true;
            std::cout << "print_blk_write/s has been changed to " << getBlk_writes() << ".\n";
        } else {
            std::cout << "print_blk_write/s was " << getBlk_writes() << "; the parameter remains unchanged to "
            << getBlk_writes() <<".\n";
        }
    }

    int getKb_writes() const { return kb_writes; }

    void setKb_writes(int kb_writes) {
        if(kb_writes != getKb_writes())  {
            config_info::kb_writes = kb_writes;
            config_updated = true;
            std::cout << "print_kb_write/s has been changed to " << getKb_writes() << ".\n";
        } else {
            std::cout << "print_kb_write/s was " << getKb_writes() << "; the parameter remains unchanged to "
            << getKb_writes() <<".\n";
        }
    }

    string getReportName(){ return reportName;}

    void setReportName(string name){
        //todo: need to account for taking in full path? It may actually just work as is though. Will test.
        string oldName = getReportName();
        config_info::reportName = name;
        cout << "The report file name is changed from '" << oldName << "' to '" << getReportName()
                << "'. \nYou can now type 'run' to generate new records to be saved in '"
                << getReportName() << "'. \nNote: '" << oldName << "' will not be deleted by audisktool.\n";
    }

    void printConfig(){
        cout << "Interval: " << getInterval() << endl;
        cout << "Count: " << getCount() << endl;
        cout << "Blk_read: " << getBlk_read() << endl;
        cout << "Blk_read/s: " << getBlk_reads() << endl;
        cout << "Kb_reads: " << getKb_reads() << endl;
        cout << "Blk_write: " << getBlk_write() << endl;
        cout << "Blk_write/s: " << getBlk_writes() << endl;
        cout << "Kb_write/s: " << getKb_writes() << endl;
        cout << "file name: " << getReportName() << endl << endl;
    }

    void save(){
        if(config_updated) {
            //save
            cout << "Saving configuration settings..\n";

            ofstream outStream("audisktool.conf"); //open file
            outStream << interval;
            outStream << " ";

            outStream << count;
            outStream << " ";

            outStream << blk_read;
            outStream << " ";

            outStream << blk_reads;
            outStream << " ";

            outStream << kb_reads;
            outStream << " ";

            outStream << blk_write;
            outStream << " ";

            outStream << blk_writes;
            outStream << " ";

            outStream << kb_writes;
            outStream << " ";

            outStream.close(); //close file
        }
        else {
            std::cout << "audisktool.conf has not been updated. There is no need to save the file.\n";
        }
    }

    config_info(){

        ifstream inStream("audisktool.conf");
        inStream >> interval;
        inStream >> count;
        inStream >> blk_read;
        inStream >> blk_reads;
        inStream >> kb_reads;
        inStream >> blk_write;
        inStream >> blk_writes;
        inStream >> kb_writes;

        inStream.close();

        reportName = "report.adt";
        config_updated = false;

        //todo: should we close inStream?

    }
};

#endif //AUDISKTOOL_CONFIG_INFO_H