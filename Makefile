all:

	g++ main.cpp Road.cpp Vehicle.cpp -o main.out -std=c++11 -stdlib=libc++

	./main.out

test:
	g++ iniReader.cpp Road.cpp Vehicle.cpp -g -o test.out -std=c++11 -stdlib=libc++

x: 
	g++ x.cpp -g -o x.out -std=c++11 -stdlib=libc++
clean:
	rm Road.out Vehicle.out a.out