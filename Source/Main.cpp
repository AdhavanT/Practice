#include "common.h"
#include <iostream>
 
extern const activetest_func active_test;

int main()
{

	active_test();

	LARGE_INTEGER cpu_frequency;
	QueryPerformanceFrequency(&cpu_frequency);
	f64 cpu_frequency_inv = 1 / (f64)cpu_frequency.QuadPart;

	uint32 length = ATP::testtype_registry->no_of_testtypes;
	ATP::TestType *front = ATP::testtype_registry->front;

	for (uint32 i = 0; i < length; i++)
	{
		if (front->type == ATP::MULTI)
		{
			std::cout << "MULTI TEST->" << front->name << ":\n";
			uint32 no_tests = front->tests.size;
			for (uint32 j = 0; j < no_tests; j++)
			{
				std::cout << "	index(" << j+1 << "): " << front->tests.front[j].test_run_cycles << " cycles [" << (f64)front->tests.front[j].test_run_cycles * cpu_frequency_inv * 1000 << "ms]\n";
			}
		}
		else
		{
			std::cout << "TEST->" << front->name <<" : "<<front->info.test_run_cycles<< " cycles [" << (f64)front->info.test_run_cycles * cpu_frequency_inv * 1000 << "ms]\n";
		}
		front++;
	}

}


