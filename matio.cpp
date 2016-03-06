#include "matio.hpp"
#include <matio.h>

#include <string>
#include <cstddef>

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

//Mat      *Mat_CreateVer(const char **matname,const char **hdr_str,
//                       enum mat_ft mat_file_ver)
//{
//
//}

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
	if(_mat != nullptr)
	{
		delete _mat;
		_mat = nullptr;
	}
}

Mat::Mat(const std::string& matname, const std::string& hdr_str, ft mat_file_ver)
{
	const char *temp_matname = matname.c_str();
	const char *temp_hdr_str = hdr_str.c_str();
	_mat = Mat_CreateVer(temp_matname,temp_hdr_str, convEnum(mat_file_ver));
}

int Mat::Open(const std::string& matname, acc mode)
{
	if(_mat == nullptr)
	{
		const char *temp_matname = matname.c_str();
		_mat = Mat_Open(temp_matname, convEnum(mode));
		return _mat == nullptr;
	}
	return 0;
}

int Mat::Close()
{
	if(_mat != nullptr)
	{
		return Mat_Close(_mat);
	}
	return 0;
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

int Mat::Rewind()
{
	if(_mat != nullptr)
	{
		return Mat_Rewind(_mat);
	}
	return 0;
}



/* MAT variable functions */
//MatVar  *Mat_VarCalloc(void)
//{
//
//}

MatVar::MatVar()
{
	//TODO constuct here
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


/*MatVar(std::string name,enum matio_classes class_type,
                      enum matio_types data_type,int rank,size_t *dims,
                      void *data,int opt)
{

}

MatVar  *Mat_VarCreateStruct(const char **name,int rank,size_t *dims,
                      const char ***fields,unsigned nfields)
{

}

int        Mat_VarDelete(Mat &_mat, const char **name)
{

}

MatVar  *Mat_VarDuplicate(const MatVar &in, int opt)
{

}

void       Mat_VarFree(MatVar &_matvar)
{

}
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

MatVar&  MatVar::GetCells(int *start,int *stride, int *edge)
{
	if(_matvar != nullptr)
	{
		matvar_t  **t = Mat_VarGetCells(_matvar,start,stride,edge); //TODO fix double pointer
		//return *(new MatVar(&t));;
	}
	return (*this);
}

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

unsigned   MatVar::GetNumberOfFields() const
{
	if(_matvar != nullptr)
	{
		return Mat_VarGetNumberOfFields(_matvar);
	}
	return 0;
}

int MatVar::AddStructField(const std::string& fieldname)
{
	if(_matvar != nullptr)
	{
		const char *temp_fieldname = fieldname.c_str();
		return Mat_VarAddStructField(_matvar, temp_fieldname);
	}
	return 0;
}

std::string MatVar::GetStructFieldnames() const
{
	if(_matvar != nullptr)
	{	//TODO
		//char * const * t = Mat_VarGetStructFieldnames(_matvar);
	}
	return "";
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

MatVar&  MatVar::GetStructField(const std::string& field_name, int opt,int index)
{
	if(_matvar != nullptr)
	{
		const char *temp_field_name = field_name.c_str();
		matvar_t  * t = Mat_VarGetStructFieldByName(_matvar, temp_field_name,index);
		return *(new MatVar(t));
	}
	return (*this);
}

//TODO add without copy
MatVar&  MatVar::GetStructs(int *start,int *stride,
		int *edge,int copy_fields)
{
	if(_matvar != nullptr)
	{
		matvar_t* t = Mat_VarGetStructs(_matvar,start,stride, edge,copy_fields);
		return *(new MatVar(t));
	}
	return (*this);
}

//TODO add without copy
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

//TODO move to Mat
MatVar&  MatVar::Read(Mat& _mat, const std::string& name)
{
	if(_matvar != nullptr)
	{
		const char *temp_name = name.c_str();

		//matvar_t* t = Mat_VarRead(&, temp_name);
		//return *(new MatVar(t));
	}
	return (*this);
}
//TODO move to Mat
int MatVar::ReadData(const Mat& _mat,MatVar &_matvar,void *data,
		int *start,int *stride,int *edge)
{
	return 0;
}

int MatVar::ReadDataAll(MatVar &_matvar)
{
	return 0;
}

//TODO move to dont use void pointer, use real types
int MatVar::ReadDataLinear(MatVar &_matvar,void *data, int start,int stride,int edge)
{
	return 0;
}

//MatVar  MatVar::ReadInfo( Mat &_mat, const char **name )
//{
//
//}

//MatVar  MatVar::ReadNext( Mat &_mat )
//{
//
//}

//MatVar  *Mat_VarReadNextInfo( Mat &_mat )
//{
//
//}

MatVar& MatVar::SetCell(int index,MatVar &cell)
{
	if(_matvar != nullptr)
	{
		//TODO how to send private pointer to Mat_VarSetCell?
		//matvar_t* t = Mat_VarSetCell(_matvar, index, &cell);
		//return *(new MatVar(t));
	}
	return (*this);
}

MatVar&   MatVar::SetStructFieldByIndex(size_t field_index,size_t index,MatVar &field)
{
	if(_matvar != nullptr)
	{
		//TODO how to send private pointer to Mat_VarSetCell?
		//matvar_t* t = Mat_VarSetStructFieldByIndex(_matvar, field_index,index,&field);
		//return *(new MatVar(t));
	}
	return (*this);
}

MatVar&   MatVar::SetStructFieldByName(const std::string& field_name,size_t index,MatVar &field)
{
	if(_matvar != nullptr)
	{
		const char *temp_field_name = field_name.c_str();
		//TODO how to send private pointer to Mat_VarSetCell?
		//matvar_t* t = Mat_VarSetStructFieldByName(_matvar,temp_field_name,index, &field);
		//return *(new MatVar(t));
	}
	return (*this);
}

//TODO move
int MatVar::Write(Mat &_mat,MatVar &_matvar, compression compress )
{

	//return Mat_VarWrite(_matvar,&field_name.c_str(),index, &field);

	return 0;
}

//TODO move
int MatVar::WriteInfo(Mat &_mat,MatVar &_matvar)
{
	//EXTERN int        Mat_VarWriteInfo(mat_t *_mat,matvar_t *_matvar);
	return 0;
}

int MatVar::WriteData(Mat &_mat,MatVar &_matvar,void *data,
		int *start,int *stride,int *edge)
{
	//EXTERN int        Mat_VarWriteData(mat_t *_mat,matvar_t *_matvar,void *data, int *start,int *stride,int *edge);

	return 0;
}


}//end namespace matio
