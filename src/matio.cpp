#include "matio.hpp"
#include <matio.h>

#include <string>
#include <cstddef>
#include <iostream>

namespace {

::mat_acc convEnum(matio::acc in){
	if(in == matio::acc::MAT_ACC_RDONLY){ return mat_acc::MAT_ACC_RDONLY;
	}else if(in == matio::acc::MAT_ACC_RDWR){ return mat_acc::MAT_ACC_RDWR;
	}else{
		//should not get here TODO throw
		return mat_acc::MAT_ACC_RDONLY;
	}
}

::mat_ft convEnum(matio::ft in){
	if(in == matio::ft::MAT_FT_MAT73){ return mat_ft::MAT_FT_MAT73;
	}else if(in == matio::ft::MAT_FT_MAT5){ return mat_ft::MAT_FT_MAT5;
	}else if(in == matio::ft::MAT_FT_MAT4){ return mat_ft::MAT_FT_MAT4;
	}else if(in == matio::ft::MAT_FT_UNDEFINED){ return mat_ft::MAT_FT_UNDEFINED;
	}else{
		//should not get here TODO throw
		return mat_ft::MAT_FT_MAT73;
	}
}

::matio_types convEnum(matio::types in){
	if(in == matio::types::MAT_T_UNKNOWN){ return matio_types::MAT_T_UNKNOWN;
	}else if(in == matio::types::MAT_T_INT8){ return matio_types::MAT_T_INT8;
	}else if(in == matio::types::MAT_T_UINT8){ return matio_types::MAT_T_UINT8;
	}else if(in == matio::types::MAT_T_INT16){ return matio_types::MAT_T_INT16;
	}else if(in == matio::types::MAT_T_UINT16){ return matio_types::MAT_T_UINT16;
	}else if(in == matio::types::MAT_T_INT32){ return matio_types::MAT_T_INT32;
	}else if(in == matio::types::MAT_T_UINT32){ return matio_types::MAT_T_UINT32;
	}else if(in == matio::types::MAT_T_SINGLE){ return matio_types::MAT_T_SINGLE;
	}else if(in == matio::types::MAT_T_DOUBLE){ return matio_types::MAT_T_DOUBLE;
	}else if(in == matio::types::MAT_T_INT64){ return matio_types::MAT_T_INT64;
	}else if(in == matio::types::MAT_T_UINT64){ return matio_types::MAT_T_UINT64;
	}else if(in == matio::types::MAT_T_MATRIX){ return matio_types::MAT_T_MATRIX;
	}else if(in == matio::types::MAT_T_COMPRESSED){ return matio_types::MAT_T_COMPRESSED;
	}else if(in == matio::types::MAT_T_UTF8){ return matio_types::MAT_T_UTF8;
	}else if(in == matio::types::MAT_T_UTF16){ return matio_types::MAT_T_UTF16;
	}else if(in == matio::types::MAT_T_UTF32){ return matio_types::MAT_T_UTF32;
	}else if(in == matio::types::MAT_T_STRING){ return matio_types::MAT_T_STRING;
	}else if(in == matio::types::MAT_T_CELL){ return matio_types::MAT_T_CELL;
	}else if(in == matio::types::MAT_T_STRUCT){ return matio_types::MAT_T_STRUCT;
	}else if(in == matio::types::MAT_T_ARRAY){ return matio_types::MAT_T_ARRAY;
	}else if(in == matio::types::MAT_T_FUNCTION){ return matio_types::MAT_T_FUNCTION;
	}else{
		//should not get here TODO throw
		return matio_types::MAT_T_UNKNOWN;
	}
}

::matio_classes convEnum(matio::classes in){
	if(in == matio::classes::MAT_C_EMPTY){ return matio_classes::MAT_C_EMPTY;
	}else if(in == matio::classes::MAT_C_CELL){ return matio_classes::MAT_C_CELL;
	}else if(in == matio::classes::MAT_C_STRUCT){ return matio_classes::MAT_C_STRUCT;
	}else if(in == matio::classes::MAT_C_OBJECT){ return matio_classes::MAT_C_OBJECT;
	}else if(in == matio::classes::MAT_C_CHAR){ return matio_classes::MAT_C_CHAR;
	}else if(in == matio::classes::MAT_C_SPARSE){ return matio_classes::MAT_C_SPARSE;
	}else if(in == matio::classes::MAT_C_DOUBLE){ return matio_classes::MAT_C_DOUBLE;
	}else if(in == matio::classes::MAT_C_SINGLE){ return matio_classes::MAT_C_SINGLE;
	}else if(in == matio::classes::MAT_C_INT8){ return matio_classes::MAT_C_INT8;
	}else if(in == matio::classes::MAT_C_UINT8){ return matio_classes::MAT_C_UINT8;
	}else if(in == matio::classes::MAT_C_INT16){ return matio_classes::MAT_C_INT16;
	}else if(in == matio::classes::MAT_C_UINT16){ return matio_classes::MAT_C_UINT16;
	}else if(in == matio::classes::MAT_C_INT32){ return matio_classes::MAT_C_INT32;
	}else if(in == matio::classes::MAT_C_UINT32){ return matio_classes::MAT_C_UINT32;
	}else if(in == matio::classes::MAT_C_INT64){ return matio_classes::MAT_C_INT64;
	}else if(in == matio::classes::MAT_C_UINT64){ return matio_classes::MAT_C_UINT64;
	}else if(in == matio::classes::MAT_C_FUNCTION){ return matio_classes::MAT_C_FUNCTION;
	}else{
		//should not get here TODO throw
		return matio_classes::MAT_C_EMPTY;
	}
}

::matio_flags convEnum(matio::flags in){
	if(in == matio::flags::MAT_F_COMPLEX){ return matio_flags::MAT_F_COMPLEX;
	}else if(in == matio::flags::MAT_F_GLOBAL){ return matio_flags::MAT_F_GLOBAL;
	}else if(in == matio::flags::MAT_F_LOGICAL){ return matio_flags::MAT_F_LOGICAL;
	}else if(in == matio::flags::MAT_F_DONT_COPY_DATA){ return matio_flags::MAT_F_DONT_COPY_DATA;
	}else{
		//should not get here TODO throw
		return matio_flags::MAT_F_COMPLEX;
	}
}

::matio_compression convEnum(matio::compression in){
	if(in == matio::compression::MAT_COMPRESSION_NONE){ return matio_compression::MAT_COMPRESSION_NONE;
	}else if(in == matio::compression::MAT_COMPRESSION_ZLIB){ return matio_compression::MAT_COMPRESSION_ZLIB;
	}else{
		//should not get here TODO throw
		return matio_compression::MAT_COMPRESSION_NONE;
	}
}

//:: convEnum(matio::lookup in){
//    if(in == matio::lookup::MAT_BY_NAME){ return ::MAT_BY_NAME;
//    }else if(in == matio::lookup::MAT_BY_INDEX){ return ::MAT_BY_INDEX;
//    }else{
//        //should not get here TODO throw
//        return ::MAT_BY_NAME;
//    }
//}

matio::acc mat_acc_convEnum(::mat_acc in){
	if(in == ::mat_acc::MAT_ACC_RDONLY){ return matio::acc::MAT_ACC_RDONLY;
	}else if(in == ::mat_acc::MAT_ACC_RDWR){ return matio::acc::MAT_ACC_RDWR;
	}else{
		//should not get here TODO throw
		return matio::acc::MAT_ACC_RDONLY;
	}
}

matio::ft mat_ft_convEnum(::mat_ft in){
	if(in == ::mat_ft::MAT_FT_MAT73){ return matio::ft::MAT_FT_MAT73;
	}else if(in == ::mat_ft::MAT_FT_MAT5){ return matio::ft::MAT_FT_MAT5;
	}else if(in == ::mat_ft::MAT_FT_MAT4){ return matio::ft::MAT_FT_MAT4;
	}else if(in == ::mat_ft::MAT_FT_UNDEFINED){ return matio::ft::MAT_FT_UNDEFINED;
	}else{
		//should not get here TODO throw
		return matio::ft::MAT_FT_MAT73;
	}
}

matio::types matio_types_convEnum(::matio_types in){
	if(in == ::matio_types::MAT_T_UNKNOWN){ return matio::types::MAT_T_UNKNOWN;
	}else if(in == ::matio_types::MAT_T_INT8){ return matio::types::MAT_T_INT8;
	}else if(in == ::matio_types::MAT_T_UINT8){ return matio::types::MAT_T_UINT8;
	}else if(in == ::matio_types::MAT_T_INT16){ return matio::types::MAT_T_INT16;
	}else if(in == ::matio_types::MAT_T_UINT16){ return matio::types::MAT_T_UINT16;
	}else if(in == ::matio_types::MAT_T_INT32){ return matio::types::MAT_T_INT32;
	}else if(in == ::matio_types::MAT_T_UINT32){ return matio::types::MAT_T_UINT32;
	}else if(in == ::matio_types::MAT_T_SINGLE){ return matio::types::MAT_T_SINGLE;
	}else if(in == ::matio_types::MAT_T_DOUBLE){ return matio::types::MAT_T_DOUBLE;
	}else if(in == ::matio_types::MAT_T_INT64){ return matio::types::MAT_T_INT64;
	}else if(in == ::matio_types::MAT_T_UINT64){ return matio::types::MAT_T_UINT64;
	}else if(in == ::matio_types::MAT_T_MATRIX){ return matio::types::MAT_T_MATRIX;
	}else if(in == ::matio_types::MAT_T_COMPRESSED){ return matio::types::MAT_T_COMPRESSED;
	}else if(in == ::matio_types::MAT_T_UTF8){ return matio::types::MAT_T_UTF8;
	}else if(in == ::matio_types::MAT_T_UTF16){ return matio::types::MAT_T_UTF16;
	}else if(in == ::matio_types::MAT_T_UTF32){ return matio::types::MAT_T_UTF32;
	}else if(in == ::matio_types::MAT_T_STRING){ return matio::types::MAT_T_STRING;
	}else if(in == ::matio_types::MAT_T_CELL){ return matio::types::MAT_T_CELL;
	}else if(in == ::matio_types::MAT_T_STRUCT){ return matio::types::MAT_T_STRUCT;
	}else if(in == ::matio_types::MAT_T_ARRAY){ return matio::types::MAT_T_ARRAY;
	}else if(in == ::matio_types::MAT_T_FUNCTION){ return matio::types::MAT_T_FUNCTION;
	}else{
		//should not get here TODO throw
		return matio::types::MAT_T_UNKNOWN;
	}
}

matio::classes matio_classes_convEnum(::matio_classes in){
	if(in == ::matio_classes::MAT_C_EMPTY){ return matio::classes::MAT_C_EMPTY;
	}else if(in == ::matio_classes::MAT_C_CELL){ return matio::classes::MAT_C_CELL;
	}else if(in == ::matio_classes::MAT_C_STRUCT){ return matio::classes::MAT_C_STRUCT;
	}else if(in == ::matio_classes::MAT_C_OBJECT){ return matio::classes::MAT_C_OBJECT;
	}else if(in == ::matio_classes::MAT_C_CHAR){ return matio::classes::MAT_C_CHAR;
	}else if(in == ::matio_classes::MAT_C_SPARSE){ return matio::classes::MAT_C_SPARSE;
	}else if(in == ::matio_classes::MAT_C_DOUBLE){ return matio::classes::MAT_C_DOUBLE;
	}else if(in == ::matio_classes::MAT_C_SINGLE){ return matio::classes::MAT_C_SINGLE;
	}else if(in == ::matio_classes::MAT_C_INT8){ return matio::classes::MAT_C_INT8;
	}else if(in == ::matio_classes::MAT_C_UINT8){ return matio::classes::MAT_C_UINT8;
	}else if(in == ::matio_classes::MAT_C_INT16){ return matio::classes::MAT_C_INT16;
	}else if(in == ::matio_classes::MAT_C_UINT16){ return matio::classes::MAT_C_UINT16;
	}else if(in == ::matio_classes::MAT_C_INT32){ return matio::classes::MAT_C_INT32;
	}else if(in == ::matio_classes::MAT_C_UINT32){ return matio::classes::MAT_C_UINT32;
	}else if(in == ::matio_classes::MAT_C_INT64){ return matio::classes::MAT_C_INT64;
	}else if(in == ::matio_classes::MAT_C_UINT64){ return matio::classes::MAT_C_UINT64;
	}else if(in == ::matio_classes::MAT_C_FUNCTION){ return matio::classes::MAT_C_FUNCTION;
	}else{
		//should not get here TODO throw
		return matio::classes::MAT_C_EMPTY;
	}
}

matio::flags matio_flags_convEnum(::matio_flags in){
	if(in == ::matio_flags::MAT_F_COMPLEX){ return matio::flags::MAT_F_COMPLEX;
	}else if(in == ::matio_flags::MAT_F_GLOBAL){ return matio::flags::MAT_F_GLOBAL;
	}else if(in == ::matio_flags::MAT_F_LOGICAL){ return matio::flags::MAT_F_LOGICAL;
	}else if(in == ::matio_flags::MAT_F_DONT_COPY_DATA){ return matio::flags::MAT_F_DONT_COPY_DATA;
	}else{
		//should not get here TODO throw
		return matio::flags::MAT_F_COMPLEX;
	}
}

matio::compression matio_compression_convEnum(::matio_compression in){
	if(in == ::matio_compression::MAT_COMPRESSION_NONE){ return matio::compression::MAT_COMPRESSION_NONE;
	}else if(in == ::matio_compression::MAT_COMPRESSION_ZLIB){ return matio::compression::MAT_COMPRESSION_ZLIB;
	}else{
		//should not get here TODO throw
		return matio::compression::MAT_COMPRESSION_NONE;
	}
}

//matio::lookup _convEnum(:: in){
//    if(in == ::::MAT_BY_NAME){ return matio::lookup::MAT_BY_NAME;
//    }else if(in == ::::MAT_BY_INDEX){ return matio::lookup::MAT_BY_INDEX;
//    }else{
//        //should not get here TODO throw
//        return matio::lookup::MAT_BY_NAME;
//    }
//}



}// namespace

namespace matio {

void Mat::GetLibraryVersion(int *major,int *minor,int *release)
{
	Mat_GetLibraryVersion(major, minor, release);
}

Mat::Mat()
: _mat(nullptr)
{

}

Mat::Mat(const Mat& t)
: _mat(nullptr)
{
	//TODO copy constructor
}

Mat::~Mat()
{
	for(auto& var: _vars)
	{
		if(var.second != nullptr)
		{
			Mat_VarFree(var.second);
			var.second=nullptr;
		}
	}
	_vars.clear();

	if(_mat != nullptr)
	{
		Mat_Close(_mat);
		_mat = nullptr;
	}
}

Mat::Mat(const std::string& matname, ft mat_file_ver)
{
	const char *temp_matname = matname.c_str();
	const char *temp_hdr_str = NULL;
	_mat = Mat_CreateVer(temp_matname,temp_hdr_str, convEnum(mat_file_ver));
}

Mat::Mat(const std::string& matname, const std::string& hdr_str, ft mat_file_ver)
{
	const char *temp_matname = matname.c_str();
	const char *temp_hdr_str = hdr_str.c_str();
	_mat = Mat_CreateVer(temp_matname,temp_hdr_str, convEnum(mat_file_ver));
}

bool Mat::Open(const std::string& matname, acc mode)
{
	if(_mat == nullptr)
	{
		const char *temp_matname = matname.c_str();
		mat_t* t = Mat_Open(temp_matname, convEnum(mode));
		if(t == NULL)
		{
			return false;
		}
		_mat = t;

		matvar_t * matvar;
		do{
			matvar = Mat_VarReadNextInfo(_mat);
			if(matvar != NULL)
			{
				std::string name = matvar->name;
				_vars[name]=matvar;
			}
		}while(NULL != matvar);
		Mat_Rewind(_mat);
		return _mat != nullptr;
	}
	return false;
}

void Mat::PrintVars() const
{
	for(auto& var: _vars)
	{
		std::cout << var.first << std::endl;
	}
}

std::vector<std::string> Mat::GetVarNames() const
{
	std::vector<std::string> fields;
	for(auto& var: _vars)
	{
		if(var.second != nullptr)
		{
			fields.push_back(var.first);
		}
	}
	return fields;
}

size_t Mat::NumVars() const
{
	return _vars.size();
}

bool Mat::Close()
{
	if(_mat != nullptr)
	{
		for(auto& var: _vars)
		{
			if(var.second != nullptr)
			{
				Mat_VarFree(var.second);
				var.second=nullptr;
			}
		}
		_vars.clear();
		Mat_Close(_mat);
		_mat = nullptr;
		return true;//return true if passed
	}
	return false;
}

std::string Mat::GetFilename()
{
	if(_mat != nullptr)
	{
		return std::string(Mat_GetFilename(_mat));
	}
	return "";
}

ft Mat::GetVersion()
{
	if(_mat != nullptr)
	{
		return mat_ft_convEnum(Mat_GetVersion(_mat));
	}
	return ft::MAT_FT_UNDEFINED;
}

MatVar&  Mat::Read(const std::string& name)
{
	if(_mat != nullptr)
	{
		matvar_t* t;
		auto it = _vars.find(name);
		if (it != _vars.end())
		{
			t=it->second;
			if(t != nullptr)
			{
				Mat_VarReadDataAll(_mat,t);
				return *(new MatVar(t));
			}
		}
	}
	return *(new MatVar());
}

bool Mat::Write(MatVar &_matvar, compression compress)
{
	if(_mat != nullptr && _matvar._matvar != nullptr)
	{
		std::string name = _matvar._matvar->name;
		_vars[name]=_matvar._matvar;

		return 0 == Mat_VarWrite(_mat,_matvar._matvar, convEnum(compress));
	}
	return false;
}

bool Mat::WriteInfo(MatVar &_matvar)
{
	if(_mat != nullptr && _matvar._matvar != nullptr)
	{
		return 0 == Mat_VarWriteInfo(_mat,_matvar._matvar);
	}
	return false;
}

bool Mat::WriteData(MatVar &_matvar,void *data, int *start,int *stride,int *edge)
{
	if(_mat != nullptr && _matvar._matvar != nullptr)
	{
		std::string name = _matvar._matvar->name;
		_vars[name]=_matvar._matvar;

		return 0 == Mat_VarWriteData(_mat,_matvar._matvar, data, start, stride, edge);
	}
	return false;
}

MatVar&  Mat::ReadInfo(const std::string& name)
{
	if(_mat != nullptr)
	{
		matvar_t* t;
		auto it = _vars.find(name);
		if (it != _vars.end())
		{
			t=it->second;
			if(t != nullptr)
			{
				return *(new MatVar(t));
			}
		}
	}
	return *(new MatVar());
}

bool Mat::Delete(const std::string& name)
{
	if(_mat != nullptr)
	{
		//matvar_t* t;
		auto it = _vars.find(name);
		if (it != _vars.end())
		{
			//t=it->second;
			const char *temp_name = name.c_str();
			int ret = Mat_VarDelete(_mat, temp_name);
			if(ret == 0)
			{
				_vars.erase(it);
				return true;
			}
		}
	}
	return false;
}

MatVar::MatVar()
{
	// Construct here
	_matvar = Mat_VarCalloc();
}

MatVar::MatVar(matvar_t  *t)
:_matvar(t)
{

}


MatVar::~MatVar()
{
	if(_matvar != nullptr)
	{
		//delete _matvar;
		Mat_VarFree(_matvar);
		_matvar = nullptr;
	}
}

/** @brief Creates a MAT Variable with the given name and (optionally) data
 *
 * Creates a MAT variable that can be written to a Matlab MAT file with the
 * given name, data type, dimensions and data.  Rank should always be 2 or more.
 * i.e. Scalar values would have rank=2 and dims[2] = {1,1}.  Data type is
 * one of the MAT_T types.  MAT adds MAT_T_STRUCT and MAT_T_CELL to create
 * Structures and Cell Arrays respectively.  For MAT_T_STRUCT, data should be a
 * NULL terminated array of matvar_t * variables (i.e. for a 3x2 structure with
 * 10 fields, there should be 61 matvar_t * variables where the last one is
 * NULL).  For cell arrays, the NULL termination isn't necessary.  So to create
 * a cell array of size 3x2, data would be the address of an array of 6
 * matvar_t * variables.
 *
 * EXAMPLE:
 *   To create a struct of size 3x2 with 3 fields:
 * @code
 *     int rank=2, dims[2] = {3,2}, nfields = 3;
 *     matvar_t **vars;
 *
 *     vars = malloc((3*2*nfields+1)*sizeof(matvar_t *));
 *     vars[0]             = Mat_VarCreate(...);
 *        :
 *     vars[3*2*nfields-1] = Mat_VarCreate(...);
 *     vars[3*2*nfields]   = NULL;
 * @endcode
 *
 * EXAMPLE:
 *   To create a cell array of size 3x2:
 * @code
 *     int rank=2, dims[2] = {3,2};
 *     matvar_t **vars;
 *
 *     vars = malloc(3*2*sizeof(matvar_t *));
 *     vars[0]             = Mat_VarCreate(...);
 *        :
 *     vars[5] = Mat_VarCreate(...);
 * @endcode
 *
 * @ingroup MAT
 * @param name Name of the variable to create
 * @param class_type class type of the variable in Matlab(one of the mx Classes)
 * @param data_type data type of the variable (one of the MAT_T_ Types)
 * @param rank Rank of the variable
 * @param dims array of dimensions of the variable of size rank
 * @param data pointer to the data
 * @param opt 0, or bitwise or of the following options:
 * - MAT_F_DONT_COPY_DATA to just use the pointer to the data and not copy the
 *       data itself. Note that the pointer should not be freed until you are
 *       done with the mat variable.  The Mat_VarFree function will NOT free
 *       data that was created with MAT_F_DONT_COPY_DATA, so free it yourself.
 * - MAT_F_COMPLEX to specify that the data is complex.  The data variable
 *       should be a pointer to a mat_complex_split_t type.
 * - MAT_F_GLOBAL to assign the variable as a global variable
 * - MAT_F_LOGICAL to specify that it is a logical variable
 * @return A MAT variable that can be written to a file or otherwise used
 */
MatVar::MatVar(std::string name, classes class_type, types data_type, int rank, size_t *dims, void *data, flags opt)
{
	const char *temp_fieldname = name.c_str();
	_matvar=Mat_VarCreate(temp_fieldname, convEnum(class_type),
			convEnum(data_type), rank, dims,
			data, convEnum(opt));
}

/** @brief Creates a structure MATLAB variable with the given name and fields
 *
 * @ingroup MAT
 * @param name Name of the structure variable to create
 * @param rank Rank of the variable
 * @param dims array of dimensions of the variable of size rank
 * @param fields Array of @c nfields fieldnames
 * @param nfields Number of fields in the structure
 * @return Pointer to the new structure MATLAB variable on success, NULL on error
 */
MatVar::MatVar(std::string name, int rank, size_t *dims, const char **fields, unsigned nfields)
{
	const char *temp_fieldname = name.c_str();
	_matvar=Mat_VarCreateStruct(temp_fieldname, rank, dims, fields, nfields);
}

MatVar::MatVar(const MatVar &in)
:_matvar(Mat_VarDuplicate(in._matvar,1))//1 to do a deep copy
{

}

MatVar& MatVar::operator=(const MatVar& in)
{
  // This gracefully handles self assignment
  matvar_t* tmp = in._matvar;// No corruption if this line threw an exception
  if(_matvar != nullptr)
  {
	  //Mat_VarFree(_matvar);
  }
  _matvar = tmp;
  return *this;
}

/** @brief Returns a pointer to the Cell array at a specific index
 *
 * Returns a Reference to the Cell Array Field at the given 1-relative index.
 * MAT file must be a version 5 matlab file.
 * @ingroup MAT
 * @param index linear index of cell to return
 * @return Reference to the Cell Array Field on success, empty object on fail.
 */
MatVar&  MatVar::GetCell(int index)
{
	if(_matvar != nullptr)
	{
		matvar_t  *t = Mat_VarGetCell(_matvar,index);
		return *(new MatVar(t));;
	}
	return (*this);
}

/** @brief Indexes a cell array
 *
 * Finds cells of a cell array given a start, stride, and edge for each.
 * dimension.  The cells are placed in a pointer array.  The cells should not
 * be freed, but the array of pointers should be.  If copies are needed,
 * use Mat_VarDuplicate on each cell.
 *
 * Note that this function is limited to structure arrays with a rank less than
 * 10.
 *
 * @ingroup MAT
 * @param start vector of length rank with 0-relative starting coordinates for
 *              each dimension.
 * @param stride vector of length rank with strides for each dimension.
 * @param edge vector of length rank with the number of elements to read in
 *              each dimension.
 * @returns Reference to the Cell Array Field on success, empty object on fail.
 */
MatVar&  MatVar::GetCells(int *start,int *stride, int *edge)
{
	if(_matvar != nullptr)
	{
		matvar_t  **t = Mat_VarGetCells(_matvar,start,stride,edge); //TODO fix double pointer
		//return *(new MatVar(t));
	}
	return (*this);
}

/** @brief Indexes a cell array
 *
 * Finds cells of a cell array given a linear indexed start, stride, and edge.
 * The cells are placed in a pointer array.  The cells themself should not
 * be freed as they are part of the original cell array, but the pointer array
 * should be.  If copies are needed, use Mat_VarDuplicate on each of the cells.
 * MAT file version must be 5.
 * @ingroup MAT
 * @param start starting index
 * @param stride stride
 * @param edge Number of cells to get
 * @returns an array of pointers to the cells
 */
MatVar&  MatVar::GetCellsLinear(int start,int stride, int edge)
{
	if(_matvar != nullptr)
	{
		matvar_t  **t = Mat_VarGetCellsLinear(_matvar,start,stride, edge); //TODO fix double pointer
		//return *(new MatVar(t));;
	}
	return (*this);
}

size_t MatVar::GetSize() const
{
	if(_matvar != nullptr)
	{
		return Mat_VarGetSize(_matvar);
	}
	return 0;
}

size_t MatVar::GetNumberOfFields() const
{
	if(_matvar != nullptr)
	{
		return Mat_VarGetNumberOfFields(_matvar);
	}
	return 0;
}

bool MatVar::AddStructField(const std::string& fieldname)
{
	if(_matvar != nullptr)
	{
		const char *temp_fieldname = fieldname.c_str();
		return 0 == Mat_VarAddStructField(_matvar, temp_fieldname);
	}
	return false;
}

std::vector<std::string> MatVar::GetStructFieldnames() const
{
	std::vector<std::string> fields;
	if(_matvar != nullptr)
	{
		size_t s =  Mat_VarGetNumberOfFields(_matvar);
		char * const * f = Mat_VarGetStructFieldnames(_matvar);
		for(size_t i = 0; i < s; i++)
		{
			fields.push_back(std::string(f[i]));
		}
	}
	return fields;
}

MatVar& MatVar::GetStructFieldByIndex(size_t field_index, size_t index)
{
	if(_matvar != nullptr)
	{
		matvar_t  * t = Mat_VarGetStructFieldByIndex(_matvar, field_index,index);
		return *(new MatVar(t));
	}
	return (*this);
}

MatVar&  MatVar::GetStructFieldByName(const std::string& field_name, size_t index)
{
	if(_matvar != nullptr)
	{
		const char *temp_field_name = field_name.c_str();
		matvar_t  * t = Mat_VarGetStructFieldByName(_matvar, temp_field_name, index);
		return *(new MatVar(t));
	}
	return (*this);
}

MatVar&  MatVar::GetStructField(size_t name_or_index, int opt, int index)
{
	if(_matvar != nullptr)
	{
		matvar_t  * t = Mat_VarGetStructFieldByIndex(_matvar, opt, index);
		return *(new MatVar(t));
	}
	return (*this);
}

MatVar&  MatVar::GetStructField(const std::string& field_name, int opt, int index)
{
	if(_matvar != nullptr)
	{
		const char *temp_field_name = field_name.c_str();
		matvar_t  * t = Mat_VarGetStructFieldByName(_matvar, temp_field_name,index);
		return *(new MatVar(t));
	}
	return (*this);
}

MatVar&  MatVar::GetStructs(int *start, int *stride, int *edge, int copy_fields)
{
	if(_matvar != nullptr)
	{
		matvar_t* t = Mat_VarGetStructs(_matvar,start,stride, edge,copy_fields);
		return *(new MatVar(t));
	}
	return (*this);
}

MatVar&  MatVar::GetStructsLinear(int start, int stride, int edge, int copy_fields)
{
	if(_matvar != nullptr)
	{
		matvar_t* t = Mat_VarGetStructsLinear(_matvar, start, stride, edge, copy_fields);
		return *(new MatVar(t));
	}
	return (*this);
}

void MatVar::Print(int printdata)
{
	if(_matvar != nullptr)
	{
		Mat_VarPrint(_matvar, printdata);
	}
}

bool MatVar::ReadDataAll()
{
	//TODO if imitate read for some reason
	return false;
}

MatVar& MatVar::SetCell(int index, MatVar &cell)
{
	if(_matvar != nullptr)
	{
		Mat_VarSetCell(_matvar, index, cell._matvar);
	}
	//Return our self, so it's possible to dot several times.
	return (*this);
}

MatVar& MatVar::SetStructFieldByIndex(size_t field_index, size_t index, MatVar &field)
{
	if(_matvar != nullptr)
	{
		Mat_VarSetStructFieldByIndex(_matvar, field_index, index, (field._matvar));
	}
	//Return our self, so it's possible to dot several times.
	return (*this);
}

MatVar& MatVar::SetStructFieldByName(const std::string& field_name, size_t index, MatVar &field)
{
	if(_matvar != nullptr)
	{
		const char * temp_field_name = field_name.c_str();
		Mat_VarSetStructFieldByName(_matvar, temp_field_name, index, (field._matvar));
	}
	//Return our self, so it's possible to dot several times.
	return (*this);
}


}//end namespace matio
