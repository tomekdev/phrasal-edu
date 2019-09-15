#include <types.h>
#include <fstream>
#include <errno.h>
#include <string.h>
#include <string>
#include <memory.h>

bool loadconfig(char *cpath, MemObject<Category> &cats)
{
	std::fstream f;
	f.open(cpath, std::ios::in);
	if(f.good())
	{
		int cnt = 0;
		f.seekg(0, std::ios::end);
		int sz = f.tellg();
		f.seekg(0, std::ios::beg);
		int i = 0;
		while(!f.eof())
		{
			std::string buf;
			getline(f, buf);
			if(buf.length() > 0)
			{
				int a = 0;
				while(buf[a] == ' ' && a < buf.length())
					a++;
	
				if(buf[0] != '#')
				{
					cats.Resize(1);
					int b = 0;
					while(buf[a] != '#' && a < buf.length())
					{
						b++;
						a++;
					}
					a = 0;
					while(buf[a] != '/' && a < b)
						a++;
					cats[cats.size() - 1].en = new char[a + 1];
					strncpy(cats[cats.size() - 1].en, buf.substr(0, a).c_str(), a);
					cats[cats.size() - 1].en[a] = '\0';
					a++;
					int c = a;
					while(buf.substr(a, 2) != " =" && a < b)
						a++;
					cats[cats.size() - 1].pl = new char[a - c + 1];
					strncpy(cats[cats.size() - 1].pl, buf.substr(c, a - c).c_str(), a - c);
					cats[cats.size() - 1].pl[a - c] = '\0';
					a += 2; /* Skip " =" */
					while(buf[a] == ' ' && a < b)
						a++;
					c = a;
					while(a < b)
						a++;
					cats[cats.size() - 1].path = new char[a - c + 1];
					strncpy(cats[cats.size() - 1].path, buf.substr(c, a - c).c_str(), a - c);
					cats[cats.size() - 1].path[a - c] = '\0';
				}
			}
			i = f.tellg();
			cnt++;
		}
	}
	else
	{
		printf("Failed to open %s: %s\n", cpath, strerror(errno));
		return false;
	}
	return true;
}

Category::Category()
{
	en = NULL;
	pl = NULL;
	path = NULL;
//	subcategories = NULL;
//	num_subcategories = 0;
}

Category::~Category()
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
//	if(subcategories != NULL)
//	{
//		delete [] subcategories;
//		subcategories = NULL;
//	}
//	num_subcategories = 0;
}

bool Category::Load()
{
	if(!loadconfig(path, subcategories))
	{
		printf("Failed to load config for category %s | %s\n", en, pl);
		return false;
	}
	return true;
}
