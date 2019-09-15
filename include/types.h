#ifndef _TYPES_H_
#define _TYPES_H_

#define DATA_DIR "data/"

#include <memory.h>

#if 0
class Word {
	public:
		char *en; /* English translation of a word */
		char **pl; /* Polish translation(s) of a word */
		int num_pl;
		Word();
		virtual ~Word();
};

class SubCategory {
	public:
		char *en; /* English translation */
		char *pl; /* Polish translation */
		char *path; /* Path to corresponding wordlist */
		Word *words;
		int num_words;
		SubCategory();
		virtual ~SubCategory();
};
#endif
class SubCategory {
	public:
		char *en; /* English translation */
		char *pl; /* Polish translation */
		char *path; /* Path to subcategory config file */
		
};

class Category {
	public:
		char *en; /* English translation */
		char *pl; /* Polish translation */
		char *path; /* Path to category config file */
//		SubCategory *subcategories;
//		int num_subcategories;
		MemObject<Category> subcategories;
		Category();
		bool Load();
		~Category();
};

class Word {
	public:
		char *en;
		char **pl;
		int n_pl;
		Word();
		~Word();
};

bool loadconfig(char *cpath, MemObject<Category> &cats);
bool loadwords(char *cpath, MemObject<Word> &w);

#endif /* _TYPES_H_ */
