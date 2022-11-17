#ifndef __TRIE_H__
#define __TRIE_H__

typedef struct trie trie_ty;


trie_ty* create();

void destroy(trie_ty* trie);

int add(trie_ty* trie, const char* str);

int remove_str(trie_ty* trie, const char* str);

int isPresent(const trie_ty* trie, const char* str);

size_t count(const trie_ty* trie);

int isEmpty(const trie_ty* trie);



#endif
