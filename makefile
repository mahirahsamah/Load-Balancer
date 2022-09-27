
output: main.o classes.o loadbalancer.o
	g++ main.o classes.o loadbalancer.o -o output

main.o: main.cpp
	g++ -std=c++17 -Wall -Werror -g -pedantic -Weffc++ -c main.cpp

classes.o: classes.cpp
	g++ -std=c++17 -Wall -Werror -g -pedantic -Weffc++ -c classes.cpp

loadbalancer.o: loadbalancer.cpp
	g++ -std=c++17 -Wall -Werror -g -pedantic -Weffc++ -c loadbalancer.cpp

clean:
	rm *.o output