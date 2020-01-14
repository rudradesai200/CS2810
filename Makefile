all : ./src/Main.cpp ./src/IITM.cpp ./src/BTech.cpp ./src/DualDegree.cpp ./src/Faculty.cpp
	g++ -o main ./src/Main.cpp ./src/IITM.cpp ./src/BTech.cpp ./src/DualDegree.cpp ./src/Faculty.cpp -std=c++11
