all: word_count ex-compile

word_count: word_count.c
		gcc -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include word_count.c -o word_count -lglib-2.0

ex-compile: ex-compile.c
		gcc -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include ex-compile.c -o ex-compile -lglib-2.0
