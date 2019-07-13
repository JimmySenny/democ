CC = gcc
FLAG = -g -Wall

bin/tst_mysql:
	$(CC) -o $@ src/tst_mysqlconnect.c -I/usr/lib/mysqlclient/include -L/usr/lib/mysqlclient/lib -lmysqlclient	

clean:
	rm -f bin/*
