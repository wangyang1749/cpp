# this make file
#main.exe:main.cpp
#	@g++ main.cpp -o main.exe

#main:main.cpp
#	g++ *.cpp -o main.exe

objs=main.o add.o
$(objs):%.o:%.cpp
	g++ -c ${CFLAGS} $< -o$@