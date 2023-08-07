all: compile link 

compile:
	g++ -Isfml/include -c src/Main.cpp src/App.cpp src/City.cpp src/Province.cpp src/Map.cpp

link:
	g++ Main.o App.o Map.o Province.o City.o -o app