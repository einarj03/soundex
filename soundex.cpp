#include "soundex.h"
using namespace std;

void encode(const char *surname, char *soundex) {
    soundex[0] = toupper(surname[0]);
    int soundex_index = 1;
    int cur_num;
    int prev_num = 0;
    for  (int i = 1; i < strlen(surname) && soundex_index < 4; ++i) {
        cur_num = encode_letter(toupper(surname[i]));
        if (cur_num != 0 && cur_num != -1 && cur_num != prev_num)
            soundex[soundex_index++] = cur_num + '0';
        
        prev_num = cur_num;
    }

    for (int i = soundex_index; i < 4; ++i)
        soundex[i] = '0';

    soundex[4] = '\0';
}

int compare(const char *one, const char *two) {
    if (!strcmp(one, two))
        return 1;

    return 0;
}

int count(const char *surname, const char *sentence) {
    char surname_soundex[5];
    encode(surname, surname_soundex);

    char word[30];
    int word_i = 0;
    char word_soundex[5];
    int count = 0;
    
    for (int sentence_i = 0; sentence_i < strlen(sentence);  ++sentence_i) {
        if (isalpha(sentence[sentence_i])) {
            word[word_i] = sentence[sentence_i];
            ++word_i;
        } else {
            word[word_i]= '\0';
            encode(word, word_soundex);
            count += compare(surname_soundex, word_soundex);
            strcpy(word, "");
            word_i = 0;
        }
    }

    return count;
}

int encode_letter(char letter) {
    switch (letter) {
        case 'B':
        case 'F':
        case 'P':
        case 'V': return 1;
        case 'C':
        case 'G':
        case 'J':
        case 'K':
        case 'Q':
        case 'S':
        case 'X':
        case 'Z': return 2;
        case 'D':
        case 'T': return 3;
        case 'L': return 4;
        case 'M': 
        case 'N': return 5;
        case 'R': return 6;
        default: return -1;
    }
}

