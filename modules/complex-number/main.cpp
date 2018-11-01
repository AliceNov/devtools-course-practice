#include "mpi.h"
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int *matrix = nullptr, *tarray = nullptr;
	int ProcNum, ProcRank;
	int N = 0, M = 0; 
	int *result = nullptr; 	
	MPI_Status status;
	double times;
	int k = 0, l = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);


	if (ProcRank == 0) 
	{
		/*if (argc < 3)
		{
			cout << "Enter Matrix Sizes\n N:" << endl;
			cin >> N;
			cout << "M:" << endl;
			cin >> M;
		}
		else
		{
			N = atoi(argv[1]);
			M = atoi(argv[2]);
		}*/

		N = atoi(argv[1]);
		M = atoi(argv[2]);

		matrix = new int[N*M];
		srand(time(0));
		for (int i = 0; i<N*M; i++)
			matrix[i] = rand() % 10;

		result = new int[M];
		for (int i = 0; i < M; i++)
			result[i] = 0;

		tarray = new int[N*M];
		int h = 0;
		for (int j = 0; j < M; j++)
			for (int i = j; i < N*M; i+=M)
			{
				tarray[h] = matrix[i];
				h++;
			}
	}

	
	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (ProcRank == 0)
	{
		

		k = M / ProcNum; //количество строк для каждого процесса
		l = M % ProcNum; //оставшееся количество, первому процессу

		for (int i = 1; i< ProcNum; i++)
			MPI_Send(tarray + (i)*k*N, k*N, MPI_INT, i, i, MPI_COMM_WORLD);
	}

	times = MPI_Wtime();

	
	if (ProcRank != 0)
	{
		k = M / ProcNum;
		int *tmp = new int[N*k];
		int *res = new int[k];
		int sum;

		MPI_Recv(tmp, N*k, MPI_INT, 0, ProcRank, MPI_COMM_WORLD, &status);

		for (int i = 0; i < k; i++)
		{
			sum = 0;
			for (int j = 0; j < N; j++)
				sum += tmp[j + N*i];
			res[i] = sum;
		}
		MPI_Send(res, k, MPI_INT, 0, ProcRank, MPI_COMM_WORLD);
		delete tmp;
		delete res;
	}
	else
	{
		int sum;
		for (int i = 0; i < k; i++)
		{
			sum = 0;
			for (int j = 0; j<N; j++)
				sum += tarray[j + i*N];
			result[i] = sum;
		}

		if (l != 0)
		{
			for (int i = 0; i < l; i++)
			{
				sum = 0;
				for (int j = 0; j < N; j++)
					sum += tarray[k*ProcNum*N + j + i*N];
				result[i + k*ProcNum] = sum;
			}
		}
	}

	printf("Time of Proc # %d is  %.10f\n", ProcRank, MPI_Wtime() - times);

	if (ProcRank == 0)
	{
		for (int i = 1; i< ProcNum; i++)
		{
			MPI_Recv(result + i*k, k, MPI_INT, MPI_ANY_SOURCE, i, MPI_COMM_WORLD, &status);
		}
		printf(" Matrix %dx%d \n", N, M);
		printf("----------------------------------------\n");
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<M; j++)
			{
				printf("%d ", matrix[i*M + j]);
			}
			printf("\n");
		}

		for (int j = 1; j <= M; j++)
		{
			printf("Sum of %d row: %d\n", j, result[j-1]);
		}

	}

	if (matrix != nullptr)
		delete matrix;
	if (tarray != nullptr)
		delete tarray;
	if (result != nullptr)
		delete result;

	MPI_Finalize();
	return 0;
}