all:
	clear; g++ main.cpp database.cpp student.cpp -o Main

test:
	clear; g++ database.cpp student.cpp test.cpp -o Testing

clean:
	rm Main Testing
