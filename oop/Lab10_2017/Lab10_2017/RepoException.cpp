#include <string>
#include <iostream>

#include "RepoException.h"

using std::string;
using std::iostream;

RepoException::RepoException(const string& ms) : mesaj{ ms } {}

const string RepoException::getMesaj() const {
	return "\n" + mesaj + "\n";
}