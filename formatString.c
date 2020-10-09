/**
 *  @file formatString
 * 
 *  Description:
 *  These procedures allow you to format a string, eliminating:
 *	1) spaces and non-graphic chars, present at the beginning of the string;
 * 	2) spaces and non-graphic chars, present at the end of the string;
 *	3) multiple spaces in the middle of the string (if there is a single space between 2 chars, it will not be deleted).
 *  The main procedure to call to format the string is formatString().
 * 
 *  @version 1
 *
 *  @date  05/08/2020
 *
 *  @author Gerardo Giannetta
 * 
 *  @warning it is not the intention of these procedures to eliminate non-graphic chars present in the middle of the string.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 150 // max dimension of the string of example

// the description is at the implementation
void deleteLeftChars(char * string, short index);
void deleteMultipleCentralSpaces(char * string, short index);
void deleteRightChars(char * string, short dimString);
void formatString(char * string);


int main(void) {

	char example[BUFFER] = "   ||     hello       World!       ||     ";

	/* Other examples: 
	 *   "ç£   hello world§°" --> "hello world"
	 *   "   ||     hello       World!       ||     " --> "|| hello World! ||"
	 *   "  °he£llo  " --> "he£llo" //this is correct according to the description
	*/

	printf("first string: %s\ndimension: %d chars\n\n", example, (int)strlen(example));

	formatString(example); // the main procedure

	printf("new string: %s\ndimension: %d chars\n\n", example, (int)strlen(example));

	return 0;
}


/**
 * The main procedure, this call the others 3 procedures to formatting the string
 * Library used:
 *  - string.h
 *  - ctype.h
 * 
 * @param[string]    string argument to format
 * 
 * @pre string != null
 * 
 * @post the same string but formatted
 */
void formatString(char * string) {

	short i = 0;
	short j = 0;

	deleteRightChars(string, strlen(string));

	while (string[i] != '\0') {

		if (isgraph(string[0]) == 0) {
			while (isgraph(string[j]) == 0) {
				j++;
			}
			deleteLeftChars(string, j);
		}

		if ((string[i] == ' ') && (string[i + 1] == ' ')) {
			deleteMultipleCentralSpaces(string, i);
		}

		i++;
	}
}



/**
 * Procedure to delete the right chars (at the end of string) that aren't graphic, 
 * for example: ç £ § ° and obviously the space char.
 * The procedure is recursive.
 * Library used:
 *  - string.h
 *  - ctype.h
 * 
 * @param[string]    string argument to format
 * @param[dimString] the dimesion of the string argument
 * 
 * @pre dimString > 0
 *      string != null
 * 
 * @post the same string without spaces or not graphic chars at the end of it
 */
void deleteRightChars(char * string, short dimString) {

	if (isgraph(string[dimString - 1]) == 0) {
		string[dimString - 1] = '\0';
		deleteRightChars(string, strlen(string));
	}
}



/**
 * Procedure to delete the left chars (at the beginning of string) that aren't graphic, 
 * for example: ç £ § ° and obviously the space char. 
 * 
 * @param[string] string argument to format
 * @param[index]  represents the end of the sequence of the not graphic chars
 * 
 * @pre string != null
 *      index >= 0
 * 
 * @post the same string without spaces or not graphic chars at the start of it
 */
void deleteLeftChars(char * string, short index) {

	short i = index;
	short j = 0;

	while (index > 0) {
		j++;
		index--;
	}
	while (string[i] != '\0') {
		string[i - j] = string[i];
		i++;
	}
	string[i - j] = '\0';
}



/**
 * Procedure to delete the space chars if there are 2 or more in the middle.
 * The procedure is recursive.
 * 
 * @warning if in the middle of string there are chars not graphic, these will not be delete,
 *          in fact the idea is not to modify the string itself, but to format it where needed.
 * 
 * @param[string] string argument to format
 * @param[index]  represents the end of the sequence of the space chars
 * 
 * @pre string != null
 *      index > 0
 * 
 * @post the same string without 2 or more space chars in the middle of it
 */
void deleteMultipleCentralSpaces(char * string, short index) {

	short i = index;
	short j = 0;

	while (string[i] == ' ') {
		string[i] = string[i + 1];
		i++;
	}
	while (string[i] != '\0') {
		string[i] = string[i + 1];
		i++;
	}

	while (string[j] != '\0') {
		if ((string[j] == ' ') && (string[j + 1] == ' ')) {
			deleteMultipleCentralSpaces(string, j);
		}
		j++;
	}
}