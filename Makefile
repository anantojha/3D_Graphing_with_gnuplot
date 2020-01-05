LIBS = -lstdc++

OBJS = main.o Linear_Regression.o 

all:	$(OBJS)
	g++ -o main $(OBJS) $(-LIBS)

main.o:		main.cc Linear_Regression.h 
		g++ -c main.cc

Linear_Regression.o:	Linear_Regression.cc Linear_Regression.h
			g++ -c Linear_Regression.cc

clean: 
	rm -f $(OBJS) main
