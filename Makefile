CPPFLAGS+=-Wall -I/usr/local/include
LDFLAGS+=-L/usr/local/lib -lsodium -lcunit

BINS=b64enc_main b64dec_main b64hash_main
TESTS=tests

.PHONY: all clean

all: ${BINS} 

test: ${TESTS}
	./tests

b64enc_main: b64enc.o b64enc_main.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

b64dec_main: b64dec.o b64dec_main.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

b64hash_main: b64enc.o b64hash_main.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

tests: b64enc.o b64dec.o b64hash.o tests.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

clean:
	rm -f ${BINS}
	rm -f ${TESTS}
	rm -f *.o
