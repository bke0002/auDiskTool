#include <iostream>
#include "config_info.h"
#include "report.h"
#include "commandline_version2.cpp"

using namespace std;

//declaring functions
void launch();
void printHelp();

// global variables
command inputCommand;


const string VERSION = "1.0.0";


config_info configInfo;
report report1(configInfo);

int main() {

    report1.printReport();
    launch();


    return 0;
}

void launch(){

    cout << "auDiskTool, VERSION " << VERSION << ". Type 'help' to find more about commands.\n\n";

    while(1) {

        input_command(inputCommand);
        string type = inputCommand.type;
        string flag = inputCommand.flag;
        string value = inputCommand.value;

        if(type == "run" && flag == ""){
            cout << "run the program.\n";
        }

        else if(type == "set") {

            if(flag == "report") {
                configInfo.setReportName(value);
//                cout << "report name updated to: " << configInfo.getReportName() << endl;
            }

            else if (flag == "interval" || flag == "count") {
                //convert value to int
                //todo: need catch in case value is not a number. Error is currently thrown and program exits
                int value = stoi(inputCommand.value);

                if (value < 1) {
                    cout << "Please enter a valid command.\n";
                }
                else if (flag == "interval") {
                    cout << "Execute setInterval(" << value << ") method.\n";
                    configInfo.setInterval(value);
                }
                else if (flag == "count") {
                    cout << "Execute setCount(" << value << ") method.\n";
                }
            }
            else if(flag == "blk_read"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_read(" << value << ") method.\n";
                    configInfo.setBlk_read(value);
                }
            }
            else if(flag == "blk_read/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_reads(" << value << ") method.\n";
                    configInfo.setBlk_reads(value);
                }
            }
            else if(flag == "kb_read/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setKb_reads(" << value << ") method.\n";
                    configInfo.setKb_reads(value);
                }
            }
            else if(flag == "blk_write"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_write(" << value << ") method.\n";
                    configInfo.setBlk_write(value);
                }
            }
            else if(flag == "blk_write/s"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setBlk_writes(" << value << ") method.\n";
                    configInfo.setBlk_writes(value);
                }
            }
            else if(flag == "kb_write"){
                //convert value to int
                int value = stoi(inputCommand.value);

                if(value != 0 && value != 1) {
                    cout << "Please enter a valid input for value.\n";
                }
                else {
                    cout << "Execute setKb_write(" << value << ") method.\n";
                    configInfo.setKb_writes(value);
                }
            }
            else {
                cout << "Please enter a valid command. Type 'help' to see commands.\n";
            }
        }
        else if(type == "print"){

            if(flag == "conf"){
                configInfo.printConfig();
            }

            else if(flag == "report"){
                cout << "Execute printReport() method\n";
                //todo: insert report command
            }

            else {
                cout << "Please enter a valid command. Type 'help' to see commands.\n";
            }
        }
        else if(type == "exit"){
            //todo: move to Tool class
            cout << "Determining if config settings have been updated..\n";
            configInfo.save();
            cout << "Exiting..\n";
            exit(0);
        }

        else if(type == "help"){
            //todo: move to Tool class
            printHelp();
        }

        else if(type == "save") {
            configInfo.save();
        }
        else {
            cout << "Please enter a valid command. Type 'help' to see commands.\n";
        }

    } // End while loop

}


void printHelp(){ //todo: move to Tool class
    cout << "run - run the monitoring tool.\n"
            "set interval [value] – set sampling period to [value]\n"
            "set count [value] – set the number of records to [value]\n"
            "set report [name] – set report file name to [name]\n"
            "set blk_read [0|1] – set print_blk_read to 0 or 1\n"
            "set blk_read/s [0|1] – set print_blk_read/s to 0 or 1\n"
            "set kb_read/s [0|1] – set print_kb_read/s to 0 or 1\n"
            "set blk_write [0|1] – set print_blk_write to 0 or 1\n"
            "set blk_write/s [0|1] – set print_blk_write/s to 0 or 1\n"
            "set kb_write [0|1] – set print_kb_write to 0 or 1\n"
            "print conf – display all the parameters\n"
            "print report – open and display the report file\n"
            "save – the configuration file audisktool.conf is updated\n"
            "exit – exit the tool.\n\n";
}