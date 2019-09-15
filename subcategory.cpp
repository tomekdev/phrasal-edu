#include <types.h>
#include <string.h>

SubCategory::SubCategory()
{
	en = NULL;
	pl = NULL;
	path = NULL;
	words = NULL;
	num_words = 0;
}

SubCategory::~SubCategory()
{
	if(en != NULL)
	{
		delete [] en;
		en = NULL;
	}
	if(pl != NULL)
	{
		delete [] pl;
		pl = NULL;
	}
	if(path != NULL)
	{
		delete [] path;
		path = NULL;
	}
	if(words != NULL)
	{
		for(int i = 0; i < num_words; i++)
		{
			delete [] words;
		}
		words = NULL;
		num_words = 0;
	}
}