# .PHONY: test

# CFLAGS=-I ../src -Wall -g -DSENTINEL

# test: test-rbtree
# 	./test-rbtree
# 	valgrind ./test-rbtree

# test-rbtree: test-rbtree.o ../src/rbtree.o

# ../src/rbtree.o:
# 	$(MAKE) -C ../src rbtree.o

# clean:
# 	rm -f test-rbtree *.o

.PHONY: test

CFLAGS=-I ../src -Wall -g -DSENTINEL
SRC=../src/rbtree.c
TEST=test/test-rbtree.c
OBJ=test-rbtree.o ../src/rbtree.o

test: test-rbtree
	./test-rbtree
	valgrind ./test-rbtree

test-rbtree: $(OBJ)
	gcc $(CFLAGS) -o test-rbtree $(OBJ)

../src/rbtree.o: ../src/rbtree.c
	gcc $(CFLAGS) -c $< -o $@

test-rbtree.o: $(TEST)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f test-rbtree *.o

