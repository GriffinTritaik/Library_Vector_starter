#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes_usr/fileIO.h"
using namespace std;

bool readFileIntoVector(ifstream &file) {
	bool retValue = true;

	std::string line;
	std::string token;

	return retValue;
}

void processLine(std::string &myString){
    std::stringstream ss(myString);
    std::string token;

}
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	if (!readFileIntoVector(myFile)){
		return NO_BOOKS_IN_LIBRARY;
	}

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}


	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}


	return SUCCESS;
}


