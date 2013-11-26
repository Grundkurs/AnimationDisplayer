#include <iostream>
#include "Program.h"


int main()
{

	Program program; 

	if (program.Startup())	
		{
		return program.Run();
		}
	return 1; 



}