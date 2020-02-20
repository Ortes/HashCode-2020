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
        int index_book = 0;
        int index_library = 0;
        while (!ss.eof()) {



            if (index == 0) {

            } else if (index == 1) {

                /* extracting word by word from stream */
                ss >> temp;
                if (std::stringstream(temp) >> found) {
                    Book *book = new Book(index_book, found);
                    this->books.push_back(book);
                    index_book++;
                }
            } else {

                for (int i = 0; i < 2; i++) {
                    Library *li = new Library(index_book, found);
                    /* extracting word by word from stream */
                    ss >> temp;
                    if (std::stringstream(temp) >> found) {

                        this->books.push_back(book);
                        index_book++;
                    }
                }
            }
            /* To save from space at the end of string */
            temp = "";
        }
        index++;
    }


    inFile.close();
}
