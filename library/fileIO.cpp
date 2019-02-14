#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../includes_usr/fileIO.h"
#include "../includes_usr/constants.h"
#include "../includes_usr/datastructures.h"
using namespace std;



/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();

	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	string token;

	while (getline(myFile, line)){
		book toAdd;

		stringstream ss(line);
		getline(ss, token, ',');
		toAdd.book_id = std::stoi(token);
		getline(ss, token, ',');
		toAdd.title = token;
		getline(ss, token, ',');
		toAdd.author = token;
		getline(ss, token, ',');
		toAdd.state = IN;
		getline(ss, token);
		toAdd.loaned_to_patron_id = std::stoi(token);

		books.push_back(toAdd);
	}

	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}

	myFile.close();
	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	ofstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	if (books.empty()){
		return NO_BOOKS_IN_LIBRARY;
	}

	for (int i = 0; i < books.size(); i++){
		myFile << books[i].book_id << "," << books[i].title << "," <<
				books[i].author << "," << books[i].state << "," <<
				books[i].loaned_to_patron_id << endl;
	}

	myFile.close();
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	patrons.clear();

	ifstream myFile;
	myFile.open(filename);
	if (!myFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	string line;
	string token;

	while (getline(myFile, line)){
		patron toAdd;

		stringstream ss(line);
		getline(ss, token, ',');
		toAdd.patron_id = std::stoi(token);
		getline(ss, token, ',');
		toAdd.name = token;
		getline(ss, token);
		toAdd.number_books_checked_out = std::stoi(token);

		patrons.push_back(toAdd);
	}

	if (patrons.empty()){
		return NO_BOOKS_IN_LIBRARY;
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


