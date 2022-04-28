All: ompmatrix cmatrix avxmatrix

test_matrix.o: ./test_matrix.c
	$(CC) -g -c -O3 -o $@ $^

cmatrix: test_matrix.o ./matrix_impl.c
	$(CC) $(CFLAGS) -g -c -O3 -o matrix_impl.o matrix_impl.c
	$(CC) $(CFLAGS) -g -o cmatrix matrix_impl.o test_matrix.o

ompmatrix: test_matrix.o ./omp_matrix.c
	$(CC) $(CFLAGS) -g -c -O3 -fopenmp -o omp_matrix.o omp_matrix.c
	$(CC) $(CFLAGS) -g -fopenmp -o ompmatrix omp_matrix.o test_matrix.o

avxmatrix: test_matrix.o ./avxmatrix.c
	$(CC) $(CFLAGS) -march=native -g -c -O3 -o avxmatrix.o ./avxmatrix.c
	$(CC) $(CFLAGS) -g -march=native -o avxmatrix avxmatrix.o test_matrix.o

.PHONY: clean

clean:
	rm *.o cmatrix ompmatrix avxmatrix
