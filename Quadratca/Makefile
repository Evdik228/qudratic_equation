
Compile: main.o users_interaction.o solve_square.o unit_tests.o work_vs_file.o
	g++ main.o users_interaction.o solve_square.o unit_tests.o work_vs_file.o -o app
main.o : main.cpp 
	g++ -c main.cpp          
users_interaction.o : users_interaction.cpp users_interaction.h    
	g++ -c users_interaction.cpp  
solve_square.o: solve_square.cpp solve_square.h
	g++ -c solve_square.cpp  
unit_tests.o : unit_tests.cpp unit_tests.h
	g++ -c unit_tests.cpp 
work_vs_file.o: work_vs_file.cpp work_vs_file.h
	g++ -c work_vs_file.cpp
