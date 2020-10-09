@file formatString

Description:
These procedures allow you to format a string, eliminating:
1) spaces and non-graphic chars, present at the beginning of the string;
2) spaces and non-graphic chars, present at the end of the string;
3) multiple spaces in the middle of the string (if there is a single space between 2 chars, it will not be deleted).
The main procedure to call to format the string is formatString().

@version 1

@warning it is not the intention of these procedures to eliminate non-graphic chars present in the middle of the string.
