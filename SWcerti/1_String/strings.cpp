/* STRING SERIES
 * strcpy(), strcmp(), strlen()
 * 
 *
*/

#include <iostream>
using namespace std;

#define STR_MAX_SIZE 100

int _strlen(char* str) { // Simple string length function
    int len = 0;
    while (*(str++)) len++;
    return len;
}

void _strcpy(char* dest, char* src) { // Simple string copy function
    while (*(src)) *(dest++) = *(src++);
    *dest = '\0';
    return;
}

int _strcmp(char* str1, char* str2) { // Simple string compare function
    while (*(str1)) {
        if (*(str1) != *(str2)) {
            return *(str1) > *(str2) ? 1 : -1;
        }
        str1++; str2++;
    }
    return *(str2) == '\0' ? 0 : -1;
}

int main(void) {
	char str1[] = "Hi, we are systemguys! nice to meet you!";
    char str2[] = "Hi, we are systemguys! nice to meat you!";
    char str3[STR_MAX_SIZE] = { 0 };
    // _strlen test
    cout << "Size of str1 --> " << _strlen(str1) << endl; 
    cout << "Size of str2 --> " << _strlen(str2) << endl;
    // _strcpy test
    _strcpy(str3, str1);
    cout << str3 << endl;
    // _strcmp test
    cout << _strcmp(str1, str2) << endl;
	return 0;
}