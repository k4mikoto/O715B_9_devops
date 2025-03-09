#include "input.h"

#define S_OK (0)
#define E_FAIL (-1)


/* ************************************************
	simple test cases for the library functions 
   ************************************************
*/

bool run_tests(){
  string validstring = "2";
  string negstring = "-1";
  string invalidstring = "word";
  
  bool valid = isNumeric(validstring);
  bool neg = isNumeric(negstring);
  bool invalid = isNumeric(invalidstring);
  
  if (valid && !neg && !invalid) return true;
  else return false;
}

int main()
{
	bool result;
	
	printf("Running Example tests .. \n");
	result = run_tests();

	if (result) {
		printf ("tests passed.\n");
		return S_OK;}
	else {
		printf ("tests failed.\n");
		return E_FAIL;}

}
