#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

#define MAX_SIZE 100

#define STRCOPY_STR      "StrCopy"
#define STRCOMPARE_STR   "StrCompare"
#define STRGETLENGTH_STR "StrGetLength"
#define STRCONCAT_STR    "StrConcat"
#define STRSEARCH_STR    "StrSearch"

#define PRINT_RESULT(a) \
  (a) ? printf("Correct!\n") : printf("Wrong!\n")
/*------------------------------------------------------------------*/
void
TestStrCopy()
{
  const char str1[] = "test StrCopy";
  const char str2[] = 
    "test StrCopy with Null\0 Following character "
    "should not be printed";
  const char str_empty[] = "";

  char dest[MAX_SIZE];
  char answer[MAX_SIZE];
  char *res1, *res2;

  printf("===========================\n"
	 "Test StrCopy\n"
	 "===========================\n");

  /* Test1: Normal copy */
  printf("Test1:\n");
  res1 = StrCopy(dest, str1);
  res2 = strcpy(answer, str1);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test2: Copy the null-contained string */
  printf("\nTest2:\n");
  res1 = StrCopy(dest, str2);
  res2 = strcpy(answer, str2);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test3: Copy the empty string */
  printf("\nTest3:\n");
  res1 = StrCopy(dest, str_empty);
  res2 = strcpy(answer, str_empty);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  return;
}
/*------------------------------------------------------------------*/
void 
TestStrGetLength()
{
  const char str1[] = "12345678901234567890";
  const char str2[] = "12345678901234567890\0 1234567";
  const char str_empty[] = "";
  size_t res1, res2;

  printf("===========================\n"
	 "Test StrGetLength\n"
	 "===========================\n");

  /* Test1: Normal String */
  printf("Test1:\n");
  res1 = StrGetLength(str1);
  res2 = strlen(str1);
  
  PRINT_RESULT(res1 == res2);
  printf("Your     Answer: [%d]\n", (int)res1);
  printf("String.h Answer: [%d]\n", (int)res2);

  /* Test2: The null-contained string */
  printf("\nTest2:\n");
  res1 = StrGetLength(str2);
  res2 = strlen(str2);

  PRINT_RESULT(res1 == res2);
  printf("Your     Answer: [%d]\n", (int)res1);
  printf("String.h Answer: [%d]\n", (int)res2);

  /* Test3: Empty string */
  printf("\nTest3:\n");
  res1 = StrGetLength(str_empty);
  res2 = strlen(str_empty);

  PRINT_RESULT(res1 == res2);
  printf("Your     Answer: [%d]\n", (int)res1);
  printf("String.h Answer: [%d]\n", (int)res2);
}
/*-----------------------------------------------------------------*/
void
TestStrSearch()
{
  char str1[] = "test StrSearch StrStrStr";
  char str2[] = "StrSearch with Null\0 Following character "
    "should not be searched";
  char str_empty[] = "";

  char *res1, *res2;

  printf("===========================\n"
	 "Test StrSearch\n"
	 "===========================\n");

  /* Test1: Normal Haystack & Needle */
  printf("Test1:\n");  
  res1 = StrSearch(str1, "Str");
  res2 = strstr(str1, "Str");

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test2: Normal Haystack & Needle with space */
  printf("\nTest2:\n");    
  res1 = StrSearch(str2, " with");
  res2 = strstr(str2, " with");

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test3: Normal Haystack with Null & Needle (after NULL) */
  printf("\nTest3:\n");    
  res1 = StrSearch(str2, "should");
  res2 = strstr(str2, "should");

  PRINT_RESULT((res1 == NULL) && (res2 == NULL));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test4: Normal Haystack with Null & Needle (no answer) */
  printf("\nTest4:\n");    
  res1 = StrSearch(str1, "should");
  res2 = strstr(str1, "should");

  PRINT_RESULT((res1 == NULL) && (res2 == NULL));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2); 

  /* Test5: Normal Haystack with Null & Needle (empty string) */
  printf("\nTest5:\n");    
  res1 = StrSearch(str2, str_empty);
  res2 = strstr(str2, str_empty);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2); 

  return;
}
/*------------------------------------------------------------------*/
void
TestStrCompare()
{
  char str[] = "TestCompare";
  char case_str[] = "testcompare";
  int res1, res2;
  
  printf("===========================\n"
	 "Test StrCompare\n"
	 "===========================\n");
  
  /* Test1: same length, same string */
  printf("Test1:\n");
  res1 = StrCompare(str, "TestCompare");
  res2 = strcmp(str, "TestCompare");

  PRINT_RESULT((res1 * res2 < 0) || (res1 == 0 && res2 == 0));
  printf("Your     Answer: [%d]\n", res1);
  printf("String.h Answer: [%d]\n", res2);
 
  /* Test2: same length, check case-sensitive */
  printf("\nTest2:\n");
  res1 = StrCompare(case_str, "TestCompare");
  res2 = strcmp(case_str, "TestCompare");

  PRINT_RESULT((res1 * res2 > 0) || (res1 == 0 && res2 == 0));
  printf("Your     Answer: [%d]\n", res1);
  printf("String.h Answer: [%d]\n", res2);

  /* Test3: different length  */
  printf("\nTest3:\n");
  res1 = StrCompare(str, "Test");
  res2 = strcmp(str, "Test");

  PRINT_RESULT((res1 * res2 > 0) || (res1 == 0 && res2 == 0));
  printf("Your     Answer: [%d]\n", res1);
  printf("String.h Answer: [%d]\n", res2);
  
  /* Test4: different length  */
  printf("\nTest4:\n");
  res1 = StrCompare(str, "TestCompareLong");
  res2 = strcmp(str, "TestCompareLong");

  PRINT_RESULT((res1 * res2 > 0) || (res1 == 0 && res2 == 0));
  printf("Your     Answer: [%d]\n", res1);
  printf("String.h Answer: [%d]\n", res2);

  /* Test5: empty string  */
  printf("\nTest5:\n");
  res1 = StrCompare(str, "");
  res2 = strcmp(str, "");

  PRINT_RESULT((res1 * res2 > 0) || (res1 == 0 && res2 == 0));
  printf("Your     Answer: [%d]\n", res1);
  printf("String.h Answer: [%d]\n", res2);
  
  return;
}
/*------------------------------------------------------------------*/
void 
TestStrConcat()
{
  char str1[] = "test StrConcat";
  char str2[] = 
    "test StrConcat with Null\0 Following character "
    "should not be added";
  char str_empty[] = "";

  char dest1[MAX_SIZE] = "Previous dest: ";
  char dest2[MAX_SIZE] = "Previous dest: "; 
  char dest3[MAX_SIZE] = "Previous dest: ";
  char dest4[MAX_SIZE] = "";
  char answer1[MAX_SIZE] = "Previous dest: ";
  char answer2[MAX_SIZE] = "Previous dest: ";
  char answer3[MAX_SIZE] = "Previous dest: ";
  char answer4[MAX_SIZE] = "";
  char *res1, *res2;

  printf("===========================\n"
	 "Test StrConcat\n"
	 "===========================\n");

  /* Test1: Normal concatenation */
  printf("Test1:\n");
  res1 = StrConcat(dest1, str1);
  res2 = strcat(answer1, str1);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test2: Concatenating the null-contained string */
  printf("\nTest2:\n");
  res1 = StrConcat(dest2, str2);
  res2 = strcat(answer2, str2);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test3: Cocatenating the empty string to normal string*/
  printf("\nTest3:\n");
  res1 = StrConcat(dest3, str_empty);
  res2 = strcat(answer3, str_empty);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  /* Test4: Cocatenating the normal string to empty string*/
  printf("\nTest4:\n");
  res1 = StrConcat(dest4, str1);
  res2 = strcat(answer4, str1);

  PRINT_RESULT((strcmp(res1, res2) == 0));
  printf("Your     Answer: [%s]\n", res1);
  printf("String.h Answer: [%s]\n", res2);

  return;
}
/*------------------------------------------------------------------*/
/* PrintUsage()
   print out the usage of the test client                           */
/*------------------------------------------------------------------*/
void 
PrintUsage(char* argv0) 
{
  printf("Test Client Usage:\n");
  printf("%s [StrGetLength|StrCopy|StrCompare|StrSearch|StrConcat|"
	 "\n", 
	 argv0);
}
/*------------------------------------------------------------------*/
int 
main(int argc, char *argv[])
{
  if (argc != 2) {
    PrintUsage(argv[0]);
    return (EXIT_FAILURE);
  }
  
  if (strcmp(argv[1], STRCOPY_STR) == 0)
      TestStrCopy();

  if (strcmp(argv[1], STRGETLENGTH_STR) == 0)
    TestStrGetLength();

  if (strcmp(argv[1], STRSEARCH_STR) == 0)
    TestStrSearch();

  if (strcmp(argv[1], STRCOMPARE_STR) == 0)
    TestStrCompare();

  if (strcmp(argv[1], STRCONCAT_STR) == 0)
    TestStrConcat();

  return 0;
  
}
