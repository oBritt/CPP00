

#include <string>
#include <iostream>



int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int e = 0; str[e]; e++)
			{
				str[e] = toupper(str[e]);
			}
			std::cout << str;
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}