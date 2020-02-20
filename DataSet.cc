#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "DataSet.hh"

DataSet::DataSet(const std::string &fileName) {
    std::ifstream inFile;

    inFile.open(fileName);
    if (!inFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

   /* std::string name;
    while (std::getline(inFile, name)) {
        std::cout << name << std::endl;
    }*/

    std::string line;
    std::vector<std::string> v;

    while(std::getline(inFile, line)){
        if (line.empty()){
            break;
        }
        v.push_back(line);
    }

    std::vector<std::string>::iterator it;

    std::string temp;
    int found;
    int index = 0;
    for (it = v.begin(); it != v.end(); it++){
        std::stringstream ss = std::stringstream(*it);
        while (!ss.eof()) {

            /* extracting word by word from stream */
            ss >> temp;

            /* Checking the given word is integer or not */
            if (std::stringstream(temp) >> found)
                if (index == 0) {

                }
                std::cout << found << " ";

            /* To save from space at the end of string */
            temp = "";
        }
    }


    inFile.close();
}
