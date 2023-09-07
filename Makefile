CC = g++
CFLAGS = -Wall -g

main.exe: main.o gradeReportSystem.o 
	$(CC) $(CFLAGS) -o main.exe main.o gradeReportSystem.o 

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

gradeReportSystem.o: gradeReportSystem.cpp
	$(CC) $(CFLAGS) -c gradeReportSystem.cpp 

clean:
	rm -f *o main.exe *gch