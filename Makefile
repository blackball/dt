all: test

test:
	clang -g -O3 dt.c test.c -o test -lopencv_core -lopencv_highgui -lopencv_imgproc -lm

clean:
	rm test
