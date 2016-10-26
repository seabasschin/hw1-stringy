#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Sebastian Dittgen
int mystrlen(char str[]) {
	int len = 0;
	while(*str) {
		len ++;
		*str++;
	}
	return len;
}

char* mystrcpy(char *dest, char *src){
	char *start = dest;
	while (*src != 0){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return start;
}

char * mystrncpy( char *dest, char *src, int n) {
  char *start = dest;
  while (n && *src) {
    *dest = *src;
    src++;
    dest++;
    n--;
  }
  return start;
}

char * mystrcat( char *dest, char *src ) {
  char *start = dest;
  dest += mystrlen(dest);
  mystrncpy(dest, src, mystrlen(src));
  return start;
}

char mystrcmp( char *s1, char *s2 ) {
  while (*s1 || *s2) {
    if (*s1 < *s2) {
      return -1;
    }
    if (*s1 > *s2) {
      return 1;
    }
    s1++; s2++;
  }
  return 0;
}

char * mystrchr( char *s, char c ) {
  while (*s != c) {
    if ( !*s ) { return NULL; }
    s++;
  }
  return s;
}

char * mystrstr(char *s, char *substr){
	while (*s) {
		char *startstr = s;
		char *tst = substr;
		while (*s == *tst && *s && *tst){
			s++;
			tst++;
		}
		if (*tst == 0)
		    return startstr;	  
		    s = startstr+1;
		}
	return NULL;
}


int main() {
	char s1[] = "sebastian";
	char s2[] = "bas";

	printf("s1 = 'sebastian'\n");
	printf("s2 = 'bas'\n\n");


	printf("s1 len should be 9. mystrlen says: %d \n", mystrlen(s2));

	printf("mystrcpy s1 to s2 %s \n", mystrcpy(s1, s2));
	char s3[] = "sebastian";
	char s4[] = "bas";
	printf("mystrncpy s1 and s2 (should be babastian):%s \n\n", mystrncpy(s3, s4, 2));
	char s5[128] = "sebastian";
	char s6[128] = "bas";
	printf("mystrcat s1 and s2 (should be sebastianbas: %s \n\n", mystrcat(s5, s6));
	char s7[128] = "sebastian";
	char s8[128] = "bas";
	printf("mystrcmp s1 and s2 (should be 1):%d \n\n", mystrcmp(s7, s8));
	char s9[128] = "sebastian";
	char a = 'a';
	printf("mystrchr s1 and 'a' (should be 'astian'): %s \n\n", mystrchr(s9,a));
	char s10[128] = "sebastian";
	char s11[128] = "bas";
	printf("mystrstr s1 and s2 (should be 'bastian'): %s \n\n", mystrstr(s10,s11));
	return 0;


}