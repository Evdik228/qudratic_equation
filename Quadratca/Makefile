
FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat                    \
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy     \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op            \
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow            \
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn                           \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef              \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers                 \
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector             \
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla    \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr         

Compile: ./object/main.o ./object/users_interaction.o ./object/solve_square.o ./object/unit_tests.o ./object/work_vs_file.o ./object/utilits.o ./object/solution_generation.o
	g++ ./object/main.o ./object/users_interaction.o ./object/solve_square.o ./object/unit_tests.o ./object/work_vs_file.o ./object/utilits.o ./object/solution_generation.o $(FLAGS) -o app 
./object/main.o : src/main.cpp 
	g++ -c src/main.cpp -o ./object/main.o

./object/users_interaction.o : src/users_interaction.cpp include/users_interaction.h    
	g++ -c src/users_interaction.cpp -o ./object/users_interaction.o

./object/solve_square.o: src/solve_square.cpp include/solve_square.h
	g++ -c src/solve_square.cpp -o ./object/solve_square.o

./object/unit_tests.o : src/unit_tests.cpp include/unit_tests.h
	g++ -c src/unit_tests.cpp -o ./object/unit_tests.o

./object/work_vs_file.o: src/work_vs_file.cpp include/work_vs_file.h
	g++ -c src/work_vs_file.cpp  -o ./object/work_vs_file.o

./object/utilits.o: src/utilits.cpp include/utilits.h
	g++ -c src/utilits.cpp  -o ./object/utilits.o	

./object/solution_generation.o: src/solution_generation.cpp include/solution_generation.h
	g++ -c src/solution_generation.cpp -o ./object/solution_generation.o
clean:    
	rm ./object/*.o app
