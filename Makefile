all: test split

test:
	clang dt.c test.c -o test -lopencv_core -lopencv_highgui -lopencv_imgproc -lm

split:
	clang++ split.cc -o split -lopencv_core -lopencv_highgui -lopencv_imgproc

clean:
	rm test split
