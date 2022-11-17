#include <stdio.h>

#include "trie.h"

int t1();
int t2();
int t3();
int t4();
int t5();
int t6();
int t7();
int t8();
int t9();
int t10();

int main()
{
	t1();
	t2();
	t3();
	t4();
	t5();
	t6();	
	t7();	
	t8();
	t9();	
	t10();	
	
	return 0;
}


int t1()
{
	trie_ty *trie = create();
	
	destroy(trie);
}

int t2()
{
	trie_ty *trie = create();
	
	add(trie, "test2");
	
	destroy(trie);
}

int t3()
{
	trie_ty *trie = create();
	
	int is_empty = 0;
	
	is_empty = isEmpty(trie);
	
	printf("is empty, expect true, get: %d \n", is_empty);
	
	add(trie, "test3");
	
	is_empty = isEmpty(trie);
	
	printf("is empty, expect false, get: %d \n", is_empty);
	
	destroy(trie);
}

int t4()
{
	trie_ty *trie = create();
	
	int is_present = 0;
	
	const char *str = "test4";
	
	is_present = isPresent(trie, str);
	
	printf("is present, expect false, get: %d \n", is_present);
	
	add(trie, str);
	
	is_present = isPresent(trie, str);
	
	printf("is present, expect true, get: %d \n", is_present);
	
	destroy(trie);
}

int t5()
{
	trie_ty *trie = create();
	
	const char *str1 = "test5";
	const char *str2 = "advrvr";
	const char *str3 = "adeff";
	const char *str4 = "teee";
	
	add(trie, str1);
	add(trie, str2);
	add(trie, str3);
	add(trie, str4);
	
	printf("is present, expect true, get: %d \n",isPresent(trie, str1));
	printf("is present, expect true, get: %d \n",isPresent(trie, str2));
	printf("is present, expect true, get: %d \n",isPresent(trie, str3));
	printf("is present, expect true, get: %d \n",isPresent(trie, str4));
	
	printf("is present, expect false, get: %d \n",isPresent(trie, "na"));
	printf("is present, expect false, get: %d \n",isPresent(trie, "te"));		
	printf("is present, expect false, get: %d \n",isPresent(trie, "ade"));
	printf("is present, expect false, get: %d \n",isPresent(trie, "lolo"));
	
	destroy(trie);
}

int t6()
{
	trie_ty *trie = create();
	
	const char *str1 = "test5";
	const char *str2 = "advrvr";
	const char *str3 = "adeff";
	const char *str4 = "teee";
	
	add(trie, str1);
	add(trie, str2);
	add(trie, str3);
	add(trie, str4);
	
	printf("is present, expect true, get: %d \n",isPresent(trie, str1));
	printf("is present, expect true, get: %d \n",isPresent(trie, str2));
	printf("is present, expect true, get: %d \n",isPresent(trie, str3));
	printf("is present, expect true, get: %d \n",isPresent(trie, str4));
	
	remove_str(trie, str1);
	
	printf("is present, expect false, get: %d \n",isPresent(trie, str1));
	printf("is present, expect true, get: %d \n",isPresent(trie, str2));
	
	remove_str(trie, str2);
	remove_str(trie, str3);
	remove_str(trie, str4);
	
	printf("is present, expect false, get: %d \n",isPresent(trie, str2));
	printf("is present, expect false, get: %d \n",isPresent(trie, str3));
	printf("is present, expect false, get: %d \n",isPresent(trie, str4));
	
	
	destroy(trie);
}

int t7()
{

}

int t8()
{

}

int t9()
{

}

int t10()
{

}


