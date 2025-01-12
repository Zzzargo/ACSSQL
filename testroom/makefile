.PHONY: build clean
build:
	gcc -Wall -Wextra -g ../src/task1.c testing_task1.c -o test -lm
	gcc -Wall -Wextra -g ../src/task1.c ../src/task2.c -o test2 -lm
debug-task2-t9s:
	./test2 ../tests/db/small.db < ../tests/input/test9.in > debug/debug.small.test9.out
task2-t9s:
	./test2 ../tests/db/small.db < ../tests/input/test9.in
r-task2-t9s:
	./test2 ../tests/db/small.db < ../tests/input/test9.in > ../tests/output/small.test9.out
diff-task2-t9s:
	diff ../tests/output/small.test9.out ../tests/ref/small.test9.ref
r-task2-t9b:
	./test2 ../tests/db/big.db < ../tests/input/test9.in > ../tests/output/big.test9.out
diff-task2-t9b:
	diff ../tests/output/big.test9.out ../tests/ref/big.test9.ref
r-task2-t10s:
	./test2 ../tests/db/small.db < ../tests/input/test10.in > ../tests/output/small.test10.out
diff-task2-t10s:
	diff ../tests/output/small.test10.out ../tests/ref/small.test10.ref
r-task2-t10b:
	./test2 ../tests/db/big.db < ../tests/input/test10.in > ../tests/output/big.test10.out
diff-task2-t10b:
	diff ../tests/output/big.test10.out ../tests/ref/big.test10.ref
task2-t10s:
	./test2 ../tests/db/small.db < ../tests/input/test10.in
clean:
	rm test
	rm test2