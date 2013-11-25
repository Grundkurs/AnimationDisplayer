#include <iostream>
#include "Program.h"


int main()
{

	Program program; 
	if (program.Initialize())
	{
		return program.Run();
	}
	return 1; 



}