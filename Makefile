CXX = g++

main: Game.o Character.o MyStack.o driver.cpp
	$(CXX) $(CXXFLAGS) Character.o Game.o  MyStack.o driver.cpp -o main

Game.o: Game.cpp Game.h Character.o
	$(CXX) $(CXXFLAGS) -c Game.cpp

MyStack.o: MyStack.cpp MyStack.h
	$(CXX) -c MyStack.cpp

Character.o: Character.cpp Character.h
	$(CXX) $(CXXFLAGS) -c Character.cpp

run:
	./main

run1:
	./proj5 proj5_books.txt

val1:
	valgrind ./proj5 proj5_books.txt

clean:
	rm *~
	rm *.o

test1:
	make Tqueue_test
	./Tqueue_test
