#include <iostream>
#include <string>
#include <matio.hpp>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << argv[0] << " filename.mat" << std::endl;;
		return 1;
	}
	matio::Mat mat;

	int ret = mat.Open(argv[1], matio::acc::MAT_ACC_RDONLY);
	std::cout << "Open ret: " << ret << std::endl;
	mat.PrintVars();
	auto vars = mat.GetVarNames();
	for(auto& vv : vars)
	{
		std::cout << "mat.GetVarNames() : " << vv << std::endl;
	}
	std::cout << "Number of variables: " << mat.NumVars() << std::endl;

	std::cout << "Filename: " <<  mat.GetFilename() << std::endl;

	matio::MatVar& v = mat.Read(vars.front());

	std::cout << "x.GetSize(): " <<  v.GetSize() << std::endl;
	std::cout << "x.GetNumberOfFields() : " <<  v.GetNumberOfFields() << std::endl;

	auto filelds = v.GetStructFieldnames();
	for(auto& f : filelds)
	{
		std::cout << "x.GetStructFieldname() : " << f << std::endl;
	}
	mat.Close();

	return 0;
}
