
output: main.o classes.o loadbalancer.o
	g++ main.o classes.o loadbalancer.o -o output

main.o: main.cpp
	g++ -std=c++17 -c main.cpp

classes.o: classes.cpp classes.h
	g++ -std=c++17 -c classes.cpp 

loadbalancer.o: loadbalancer.cpp loadbalancer.h
	g++ -std=c++17 -c loadbalancer.cpp

clean:
	rm *.o output