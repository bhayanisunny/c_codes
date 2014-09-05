#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG_PRINT

int len; // keeping it global so it need not be passed where required

//--------------- HELPER FUNCTIONS - START ---------------//
/*
 * This function reverses all the characters from src string to dst string
 */
void reverseString(char *src, char *dst)
{
  int i=0;
  
  while(src[i] != '\0')
  {
    dst[len-i-1] = src[i++];
  }
}

/*
 * This function returns the total no. of words in a given strings
 */
int getCurWordLen(char *src, int pos)
{
  int cnt=0;

  while(src[pos++] != ' ')
  {
    cnt++;

    if(src[pos] == '\0')
      break;
  }
  
  if(cnt==0)
    cnt++;

#ifdef DEBUG_PRINT
  printf("word count=%d\n", cnt);
#endif // DEBUG_PRINT

  return cnt;
}

/*
 * This function reverses the characters of a given word
 */
void revCurWord(char *src, int pos, int wordlen)
{
  char tmp = src[pos];
  int i=0, j=0, loop = wordlen;

#ifdef DEBUG_PRINT
  printf("tmp=%c, pos[%d]=%c, len=%d\n\n", tmp, pos, rev[pos], wordlen);
#endif // DEBUG_PRINT

  i = pos + wordlen - 1;
  j = pos;

  while(loop != 1)
  {
    tmp = src[i];
    src[i--] = src[j];
    src[j++] = tmp;
    loop /= 2;
  }
}

/*
 * This function returns the total number of words in a given string
 */
int getNumWords(char *src)
{
  int cnt=0, i=0;

  while(src[i] != '\0')
  {
    if(src[i++] == ' ')
      cnt++;
  }

  return cnt+1;
}
//--------------- HELPER FUNCTIONS - END ---------------//

/*
 * This function reverses the order of words from the given string
 */
void reverse(char *str)
{
  int pos=0, noOfWords=0, wordLen=0;
  char *rev = (char *)calloc(len, 0);
  
  rev[len] = '\0'; // null terminate the string manually

  reverseString(str, rev);
#ifdef DEBUG_PRINT
  printf("%s,\n", rev);
  printf("=============================\n");
  printf("=============================\n\n");
#endif // DEBUG_PRINT

  noOfWords = getNumWords(rev);

#ifdef DEBUG_PRINT
  printf("noOfWords=%d\n", noOfWords);
#endif // DEBUG_PRINT

  while(noOfWords)
  {
    wordLen = getCurWordLen(rev, pos);
    // if wordLen == 1, then nothing is there to reverse the letters
    if(wordLen > 1)
    {
      revCurWord(rev, pos, wordLen);
    }
    pos += wordLen + 1;
    noOfWords--;
  }

  printf("Reversed String:\n%s, len=%d\n", rev, strlen(rev));
  printf("=============================\n");

  rev=NULL;
  free(rev);
}

int main(void)
{
  int i=0;
  char *str[3] = { "ABC DEF G HIJKL MN O P QRS",
                   "THE COW ATE THE GRASS",
                   "QUICK BROWN FOX JUMPED THE BIG WALL",
                };

  for(i=0; i<3; i++)
  {
    len = strlen(str[i]);

    printf("=============================\n");
    printf("Original String:\n%s, len=%d\n", str[i], strlen(str[i]));
    printf("=============================\n");

    reverse(str[i]);
  }
  return 0;
}
