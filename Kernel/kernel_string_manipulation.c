#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>

void test_strsep(){
//Strsep is non-reentrant, but this is fine for local variables which are not shared between kernel threads
//strsep is in memory editing, edits the first parameter by changing first delimiter char to '\0' and then pointing the pointer to the char after.
	char *tok = temp, *end = temp;
	while (tok != NULL) {
		//strsep finds first instance of delimiter, changes it to null char. Then makes end point to the next token.
		strsep(&end, ",");
		//puts(tok);
		//use current tok
		
		//update tok 
		tok = end;
	}
}

int main()
{
	void test_strsep();
}