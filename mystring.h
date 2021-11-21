/*

Work 08: If you like it then you should've put a string on it

Oct 5, 2021
Due: Friday 10/07 10:00am
GitHub Submission Link: git@github.com:mks65/08_string.git

    First, acquaint yourself with the basic string functions: strlen, strcpy, strcat, strncat and strncpy. You can look at the man pages for each if you are unclear as to their uses. I encourage you to play around with each so you are comfortable with how to use them.
    Then write your own versions of the following:
    Required (use the function headers I provide, they may differ from the standard headers).
        strlen [ int mystrlen( char *s ) ]
        strcpy/strncpy (choose one) [ char * mystrcpy( char *dest, char *source ) char * mystrncpy( char *dest, char *source, int n) ]
        strcat/strncat (choose one) [ char * mystrcat( char *dest, char *source ) char * mystrncat( char *dest, char *source, int n) ]
        strcmp [ int mystrcmp( char *s1, char *s2 ) ]
            Your version does not need to return the same exact value as the system version, as long as it returns -, + or 0 when it should.
        strchr [ char * mystrchr( char *s, char c ) ]
    You must test every function you write, you will not get full credit for an untested functions.
    You do not need to write 7 functions, only 5, but you need to write 1 of the “n” versions. (So if you do strcpy then you have to do strncat)
    Your program should consist of:
        the main.c file that I have prepared for you, available in the dwsource github repo
        a .c/.h pair of files for your string functions.
        a makefile
    Extra functions:
        The other strn/str version of the functions you wrote above
        strstr [ char * mystrstr( char *s1, char * s2 ) ]
        mysplit [ char * mysplit(char *s, char d) ]
            This is not quite a built in string function, but similar to strsep.
            This function should go through s, replacing each instance of c with a NULL byte.
            While you’re testing this one, contemplate: Why is this useful?

    When you test your functions, run them alongside the regular ones so you can see if they behave the same way or not. Remember you should call them something other than the regular names.

    Here’s an example of what your code might look like when run:

      start strings:
      s1: []
      s2: [hello]
      s3: [goodbye]

      Testing strlen(s2):
      [standard]:     5
      [mine]:         5

      Testing strcpy(s1, s2):
      [standard]:     [hello]
      [mine]:         [hello]

      Testing strncpy(s1, s3, 3):
      [standard]:     [goolo]
      [mine]:         [goolo]

      Testing strcat(s1, s3):
      [standard]:     [goologoodbye]
      [mine]:         [goologoodbye]

      Testing strncat(s1, s2, 3):
      [standard]:     [goologoodbyehel]
      [mine]:         [goologoodbyehel]

      Testing strchr(s1, 'l'):
      [standard]:     [0x7ffeee8698c3]
      [mine]:         [0x7ffeee8698c3]

      Testing strchr(s1, 0):
      [standard]:     [0x7ffeee8698cf]
      [mine]:         [0x7ffeee8698cf]

      Testing strchr(s1, 'z'):
      [standard]:     [0x0]
      [mine]:         [0x0]

      Testing strcmp
              Comparting ab to abc:
                      [standard]:     [-1]
                      [mine]:         [-99]
              Comparting abc to ab:
                      [standard]:     [1]
                      [mine]:         [99]
              Comparting abc to abc:
                      [standard]:     [0]
                      [mine]:         [0]


*/

#include <stdio.h>
#include <string.h>

int mystrlen(char *s) {
	char *t = s;
	int mylength = 0;;
	while (*t != '\0') {
		mylength += 1;
		t++;
	}
	return mylength;
}
char * mystrncpy(char *dest, char *source, int n) {
	int source_length = mystrlen(source);
	int dest_length = mystrlen(dest);
	for (int i = 0; i < n; i++) {
		if (dest[i] == 0) break;
		dest[i] == source[i];
	}
	if (n < dest_length) {
		for (int j = n; j < dest_length; j++) dest[j] == '\0';
	}
	return dest;
}
char * mystrcat(char *dest, char *source) {
	int source_length = mystrlen(source);
	int dest_length = mystrlen(dest);
	int final_length = source_length + dest_length;
	// char my_final[final_length];
	for (int j = dest_length; j < final_length; j++) dest[j] = source[j - (dest_length - 2)];
	return dest;
}
int mystrcmp(char *s1, char *s2) {
	int sone_length = mystrlen(s1);
	int stwo_length = mystrlen(s2);
	if (sone_length < stwo_length) return -1;
	if (sone_length == stwo_length) return 0;
	if (sone_length > stwo_length) return 1;
}
char * mystrchr(char *s, char c) {
	int string_length = mystrlen(s);
	for (int k = 0; k <= string_length; k++) {
		if (s[k] == c) return &(s[k]);
		// if ((k == string_length) && (s[k] == '\0')) return s[k];
	}
	return NULL;
}

