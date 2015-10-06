#include <iostream>
#include <sstream>
#include "filesystem.h"

using namespace std;

const int MAXCOMMANDS = 8;
const int NUMAVAILABLECOMMANDS = 15;

string availableCommands[NUMAVAILABLECOMMANDS] = {
    "quit","format","ls","create","cat","save","read",
    "rm","copy","append","rename","mkdir","cd","pwd","help"
};

/* Takes usercommand from input and returns number of commands, commands are stored in strArr[] */
int parseCommandString(const string &userCommand, string strArr[]);
int findCommand(string &command);

/* Splits a filepath into multiple strings */
std::vector<string> split(const string &filePath, const char delim = '/');

string help();

int main(void) {

    string userCommand, commandArr[MAXCOMMANDS];
    string user = "user@DV1492";    // Change this if you want another user to be displayed
    string currentDir = "/";    // current directory, used for output

    bool bRun = true;
	int error;

	FileSystem drive;
	if(error = drive.Init() != 0)
		return error;


    do {
        cout << user << ":" << currentDir << "$ ";
        getline(cin, userCommand);

        int nrOfCommands = parseCommandString(userCommand, commandArr);
        if (nrOfCommands > 0) {

            int cIndex = findCommand(commandArr[0]);
            switch(cIndex) {

            case 0: // quit
                bRun = false;
                cout << "Exiting\n";
                break;
            case 1: // format
                // Call fileSystem.format()
                break;
            case 2: // ls
                cout << "Listing directory" << endl;
                // Call filesystem.ls()
                break;
            case 3: // create

                break;
            case 4: // cat

                break;
            case 5: // save

                break;
            case 6: // read

                break;
            case 7: // rm

                break;

            case 8: // copy

                break;

            case 9: // append

                break;

            case 10: // rename

                break;

            case 11: // mkdir

                break;

            case 12: // cd

                break;

            case 13: // pwd

                break;

            case 14: // help
                cout << help() << endl;
                break;

            default:
                cout << "Unknown command: " << commandArr[0] << endl;

            }
        }
    } while (bRun == true);

    return 0;
}

int parseCommandString(const string &userCommand, string strArr[]) {
    stringstream ssin(userCommand);
    int counter = 0;
    while (ssin.good() && counter < MAXCOMMANDS) {
        ssin >> strArr[counter];
        counter++;
    }
    if (strArr[0] == "") {
        counter = 0;
    }
    return counter;
}
int findCommand(string &command) {
    int index = -1;
    for (int i = 0; i < NUMAVAILABLECOMMANDS && index == -1; ++i) {
        if (command == availableCommands[i]) {
            index = i;
        }
    }
    return index;
}

std::vector<string> split(const string &filePath, const char delim) {
    vector<string> output;
    string cpy = filePath;

    size_t end = cpy.find_last_of(delim);
    if (cpy.length() > end+1) {
        output.push_back(cpy.substr(end+1, cpy.length()));
    }

    while (end != 0 && end!= std::string::npos) {

        cpy = cpy.substr(0, cpy.find_last_of('/'));
        //cout << cpy << endl;
        end = cpy.find_last_of(delim);
        output.push_back(cpy.substr(end+1, cpy.length()));

    }

    return output;
}

string help() {
    string helpStr;
    helpStr += "OSD Disk Tool .oO Help Screen Oo.\n";
    helpStr += "-----------------------------------------------------------------------------------\n" ;
    helpStr += "* quit:                             Quit OSD Disk Tool\n";
    helpStr += "* format;                           Formats disk\n";
    helpStr += "* ls     <path>:                    Lists contents of <path>.\n";
    helpStr += "* create <path>:                    Creates a file and stores contents in <path>\n";
    helpStr += "* cat    <path>:                    Dumps contents of <file>.\n";
    helpStr += "* save   <real-file>:               Saves disk to <real-file>\n";
    helpStr += "* read   <real-file>:               Reads <real-file> onto disk\n";
    helpStr += "* rm     <file>:                    Removes <file>\n";
    helpStr += "* copy   <source>    <destination>: Copy <source> to <destination>\n";
    helpStr += "* append <source>    <destination>: Appends contents of <source> to <destination>\n";
    helpStr += "* rename <old-file>  <new-file>:    Renames <old-file> to <new-file>\n";
    helpStr += "* mkdir  <directory>:               Creates a new directory called <directory>\n";
    helpStr += "* cd     <directory>:               Changes current working directory to <directory>\n";
    helpStr += "* pwd:                              Get current working directory\n";
    helpStr += "* help:                             Prints this help screen\n";
    return helpStr;
}
