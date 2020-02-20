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
                Library *li = new Library(index_library);

                int i = 0;
                while (!ss.eof()) {
                    ss >> temp;
                    if (std::stringstream(temp) >> found) {
                        if (i == 1) {
                            li->signUpTime = found;
                        } else if (i == 2)
                            li->nbScanPerDay = found;
                    }
                    i++;
                }
                it++;


                while (!ss.eof()) {
                    ss >> temp;
                    if (std::stringstream(temp) >> found) {
                        li->books.push_back(this->books[found]);
                    }
                }

                this->libraries.push_back(li);
                index_library++;
            }
            /* To save from space at the end of string */
            temp = "";
        }
        index++;
    }


    inFile.close();
}
