
FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat                    \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy     \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op            \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow            \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn                           \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef              \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers                 \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector             \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla    \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr         

Compile: main.o users_interaction.o solve_square.o unit_tests.o work_vs_file.o utilits.o
	g++ main.o users_interaction.o solve_square.o unit_tests.o work_vs_file.o utilits.o $(FLAGS) -o app 
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
utilits.o: utilits.cpp utilits.h
	g++ -c utilits.cpp
clean:    
	rm *.o app
