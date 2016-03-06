#include <iostream>
#include <string>
#include <matio.hpp>

int main()
{
	matio::Mat mat;

	int ret = mat.Open("datasets/small_v4_le.mat", matio::acc::MAT_ACC_RDONLY);
	std::cout << "Open ret: " << ret << std::endl;
	mat.Close();

	return 0;
}
