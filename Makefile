OBJS = main.o \
       memory.o \
       category.o \
       word.o
#       subcategory.o

CPPFLAGS = -g -Iinclude -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined
LDFLAGS = -g -fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined

phrasal-edu: $(OBJS)
	g++ -o phrasal-edu $(OBJS) $(CPPFLAGS) $(LDFLAGS)

all: phrasal-edu

clean:
	rm -rf $(OBJS) phrasal-edu
