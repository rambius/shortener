CPPFLAGS+=-Wall -I/usr/local/include
LDFLAGS+=-L/usr/local/lib -lsodium -lcunit

BINS=b64enc_main b64dec_main
TESTS=b64_test

.PHONY: all clean

all: ${BINS} 

test: ${TESTS}
	./b64_test

b64enc_main: b64enc.o b64enc_main.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

b64dec_main: b64dec.o b64dec_main.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

b64_test: b64enc.o b64dec.o b64_test.o
	${CC} ${LDFLAGS} ${.ALLSRC} -o ${.TARGET}

clean:
	rm -f ${BINS}
	rm -f ${TESTS}
	rm -f *.o
