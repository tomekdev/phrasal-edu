#include <types.h>
#include <string.h>
#include <fstream>

Word::Word()
{
	en = NULL;
	pl = NULL;
	n_pl = 0;
}

Word::~Word()
{
	if(en != NULL)
	{
		delete [] en;
		en = NULL;
	}
	if(pl != NULL)
	{
		for(int i = 0; i < n_pl; i++)
		{
			delete [] pl[i];
		}
		pl = NULL;
		n_pl = 0;
	}
}

bool loadwords(char *cpath, MemObject<Word> &w)
{
	std::fstream f;
	f.open(cpath, std::ios::in);
	if(!f.good())
	{
		printf("Failed to open %s: %s\n", cpath, strerror(errno));
		return false;
	}
	while(!f.eof())
	{
		std::string buf;
		getline(f, buf);
		int a = 0;
		while(buf[a] != '#' && a < buf.length())
			a++;
		if(a == buf.length())
		{
			/* Not a comment */
			a = 0;
			while(buf[a] != '=' && a < buf.length())
				a++;
			/* Remove spaces */
			while(buf[a] == ' ' && a > 0)
				a--;
			w.Resize(1);
			w[w.size() - 1].en = new char[a + 1];
			strncpy(w.[w.size() - 1].en, buf.substr(0, a), a);
			w[w.size() - 1].en[a] = '\0';
			/* Skip spaces */
			while(buf[a] == ' ' && a > 0)
				a++;
			/* Skip '=' */
			a++;
			/* Skip spaces */
			while(buf[a] == ' ' && a > 0)
				a++;
			int b = a;
			/* Read until end of line */
			while(a < buf.length())
			{
				if(buf[a] == '/')
				{
					/* Reallocate */
					char **temp = w[w.size() - 1].pl;
					w[w.size() - 1].pl = 
				a++;
			}

		}
	}
}
