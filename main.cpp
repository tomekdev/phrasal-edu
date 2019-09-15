#include <iostream>
#include <stdio.h>
#include <fstream>
#include <types.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <memory.h>

#if 0
int main()
{
	MemObject<Category> categories;
	char *conf_path = new char[strlen(DATA_DIR) + strlen("config")];
	strcpy(conf_path, DATA_DIR);
	strcpy(&conf_path[strlen(DATA_DIR)], "config");
	if(!loadconfig(conf_path, categories))
	{
		delete [] conf_path;
		return -1;
	}
	/* Select unit */
	printf("Wybierz rozdzial:\n");
	for(int i = 0; i < categories.size(); i++)
	{
		printf("%d. %s | %s\n", i + 1, categories[i].en, categories[i].pl);
	}
	int selection = 0;
	printf("Wybór: ");
	std::cin >> selection;
	if(selection < 1 || selection > categories.size())
	{
		printf("Selection error\n");
		return -1;
	}
	if(!categories[selection - 1].Load())
	{
		printf("Fatal error\n");
	}
	delete [] conf_path;

return 0;
}
#endif

int main()
{
	MemObject<Category> categories;
	char *conf_path = new char[strlen(DATA_DIR) + strlen("config") + 1];
	strcpy(conf_path, DATA_DIR);
	strcpy(&conf_path[strlen(DATA_DIR)], "config");
	if(!loadconfig(conf_path, categories))
	{
		printf("Failed to load %s\n", conf_path);
		return -1;
	}
	printf("Wybierz rozdzial: \n");
	for(int i = 0; i < categories.size(); i++)
	{
		printf("%d. %s | %s\n", i + 1, categories[i].en, categories[i].pl);
	}
	printf(">>> ");
	int selection = 0;
	std::cin >> selection;
	if(selection < 1 || selection > categories.size())
	{
		printf("Bad selection\n");
	}
	if(!categories[selection - 1].Load())
	{
		printf("Failed to load\n");
	}
	else
	{
		/* Select subcategory */
		printf("Wybierz podkategorie:\n");
		for(int i = 0; i < categories[selection - 1].subcategories.size(); i++)
		{
			printf("%d. %s | %s\n", i + 1, categories[selection - 1].subcategories[i].en, categories[selection - 1].subcategories[i].pl);
		}
		printf("%d. ==---> Wszystkie podkategorie\n", categories[selection - 1].subcategories.size() + 1);
		printf(">>> ");
		int oldselection = selection;
		selection = 0;
		std::cin >> selection;
		bool all_subcats = false;
		if(selection < 1 || selection > categories[oldselection - 1].subcategories[selection - 1].size() + 1)
		{
			printf("Bad selection\n");
		}
		else
		{
			if(selection == categories[oldeselection - 1].subcategories[selection - 1].size() + 1)
			{
				/* Use all subcategories */
				all_subcats = true;
				/* Load all words */
				MemObject<Word> words;
				for(int i = 0; i < categories[selection - 1].subcategories.size(); i++)
				{
					loadwords(categories[selection - 1].subcategories[i].path, &words);
				}
			}
		}
	}
	delete [] conf_path;
return 0;
}
