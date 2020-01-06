#include <cstring>
#include <cctype>

using namespace std;

void encode(const char *surname, char *soundex);

int compare(const char *one, const char *two);

int count(const char *surname, const char *sentence);

int encode_letter(char letter);