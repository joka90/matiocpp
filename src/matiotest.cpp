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
		mat.Read(vv).Print(0);
	}
	std::cout << "Number of variables: " << mat.NumVars() << std::endl;

	std::cout << "Filename: " <<  mat.GetFilename() << std::endl;

	matio::MatVar& v = mat.Read("var50");

	std::cout << "x.GetSize(): " <<  v.GetSize() << std::endl;
	std::cout << "x.GetNumberOfFields() : " <<  v.GetNumberOfFields() << std::endl;

	auto filelds = v.GetStructFieldnames();
	for(auto& f : filelds)
	{
		std::cout << "x.GetStructFieldname() : " << f << std::endl;
	}
	mat.Close();
	double v1d[] = {234.4,234.323,456.45,432.002};
	size_t r = 4;
	matio::MatVar v1("v1", matio::classes::MAT_C_DOUBLE, matio::types::MAT_T_DOUBLE, 4, &r, v1d, matio::flags::MAT_F_GLOBAL);

	//matio::Mat mat2("new.mat",matio::ft::MAT_FT_MAT4);
	//mat2.Open("new.mat",matio::acc::MAT_ACC_RDWR);
	//mat2.Write(v1,matio::compression::MAT_COMPRESSION_NONE);
	//mat2.Close();
	//TODO
	//const char fil[][]={'hej', 'hopp', 'gummi'};
	//matio::MatVar v2("v2", 3, &r, fil, 3);

	return 0;
}
