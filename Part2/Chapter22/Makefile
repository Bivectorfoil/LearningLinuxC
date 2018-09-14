all: main

main: main.o stack.o maze.o
	gcc $^ -o $@

.PHONY: clean

clean:
	-rm main *.o

sources = main.c stack.c maze.c

include $(sources:.c=.d)

%.d: %.c
		set -e; rm -f $@; \
				$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
				sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
				rm -f $@.$$$$
