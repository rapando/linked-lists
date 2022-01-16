# compile and run the linked list project
# to compile:
#	make
# to clean up
#	make clean

TARGET=linked-lists
all: compile run clean

compile:
	gcc -o $(TARGET)  main.c linked-lists.c

run:
	./$(TARGET)

clean:
	rm $(TARGET)	

