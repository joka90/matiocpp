#ifndef MATIO_HPP
#define MATIO_HPP

#include <string>
#include <map>
#include <vector>

//Forward declare the matio c types
struct _mat_t;
typedef struct _mat_t mat_t;
struct matvar_t;

namespace matio {

/** @defgroup MAT Matlab MAT File I/O Library */
/** @defgroup mat_util MAT File I/O Utility Functions */
/** @if mat_devman @defgroup mat_internal Internal Functions @endif */

/** @brief MAT file access types
 *
 * @ingroup MAT
 * MAT file access types
 */
enum class acc : char {
	MAT_ACC_RDONLY = 0,  /**< @brief Read only file access                */
			MAT_ACC_RDWR   = 1   /**< @brief Read/Write file access               */
};

/** @brief MAT file versions
 *
 * @ingroup MAT
 * MAT file versions
 */
//TODO change to correct type
enum class ft : int {
	MAT_FT_MAT73  = 0x0200,   /**< @brief Matlab version 7.3 file             */
			MAT_FT_MAT5   = 0x0100,   /**< @brief Matlab version 5 file               */
			MAT_FT_MAT4   = 0x0010,   /**< @brief Matlab version 4 file               */
			MAT_FT_UNDEFINED =   0    /**< @brief Undefined version                   */
};

/** @brief Matlab data types
 *
 * @ingroup MAT
 * Matlab data types
 */
enum class types : char {
	MAT_T_UNKNOWN    =  0,    /**< @brief UNKNOWN data type                    */
			MAT_T_INT8       =  1,    /**< @brief 8-bit signed integer data type      */
			MAT_T_UINT8      =  2,    /**< @brief 8-bit unsigned integer data type    */
			MAT_T_INT16      =  3,    /**< @brief 16-bit signed integer data type     */
			MAT_T_UINT16     =  4,    /**< @brief 16-bit unsigned integer data type   */
			MAT_T_INT32      =  5,    /**< @brief 32-bit signed integer data type     */
			MAT_T_UINT32     =  6,    /**< @brief 32-bit unsigned integer data type   */
			MAT_T_SINGLE     =  7,    /**< @brief IEEE 754 single precision data type */
			MAT_T_DOUBLE     =  9,    /**< @brief IEEE 754 double precision data type */
			MAT_T_INT64      = 12,    /**< @brief 64-bit signed integer data type     */
			MAT_T_UINT64     = 13,    /**< @brief 64-bit unsigned integer data type   */
			MAT_T_MATRIX     = 14,    /**< @brief matrix data type                    */
			MAT_T_COMPRESSED = 15,    /**< @brief compressed data type                */
			MAT_T_UTF8       = 16,    /**< @brief 8-bit unicode text data type        */
			MAT_T_UTF16      = 17,    /**< @brief 16-bit unicode text data type       */
			MAT_T_UTF32      = 18,    /**< @brief 32-bit unicode text data type       */

			MAT_T_STRING     = 20,    /**< @brief String data type                    */
			MAT_T_CELL       = 21,    /**< @brief Cell array data type                */
			MAT_T_STRUCT     = 22,    /**< @brief Structure data type                 */
			MAT_T_ARRAY      = 23,    /**< @brief Array data type                     */
			MAT_T_FUNCTION   = 24     /**< @brief Function data type                  */
};

/** @brief Matlab variable classes
 *
 * @ingroup MAT
 * Matlab variable classes
 */
enum class classes : char {
	MAT_C_EMPTY    =  0, /**< @brief Empty array                           */
			MAT_C_CELL     =  1, /**< @brief Matlab cell array class               */
			MAT_C_STRUCT   =  2, /**< @brief Matlab structure class                */
			MAT_C_OBJECT   =  3, /**< @brief Matlab object class                   */
			MAT_C_CHAR     =  4, /**< @brief Matlab character array class          */
			MAT_C_SPARSE   =  5, /**< @brief Matlab sparse array class             */
			MAT_C_DOUBLE   =  6, /**< @brief Matlab double-precision class         */
			MAT_C_SINGLE   =  7, /**< @brief Matlab single-precision class         */
			MAT_C_INT8     =  8, /**< @brief Matlab signed 8-bit integer class     */
			MAT_C_UINT8    =  9, /**< @brief Matlab unsigned 8-bit integer class   */
			MAT_C_INT16    = 10, /**< @brief Matlab signed 16-bit integer class    */
			MAT_C_UINT16   = 11, /**< @brief Matlab unsigned 16-bit integer class  */
			MAT_C_INT32    = 12, /**< @brief Matlab signed 32-bit integer class    */
			MAT_C_UINT32   = 13, /**< @brief Matlab unsigned 32-bit integer class  */
			MAT_C_INT64    = 14, /**< @brief Matlab signed 64-bit integer class    */
			MAT_C_UINT64   = 15, /**< @brief Matlab unsigned 64-bit integer class  */
			MAT_C_FUNCTION = 16  /**< @brief Matlab function class                 */
};

/** @brief Matlab array flags
 *
 * @ingroup MAT
 * Matlab array flags
 */
//TODO change to correct 
enum class flags : int {
	MAT_F_COMPLEX        = 0x0800, /**< @brief Complex bit flag */
			MAT_F_GLOBAL         = 0x0400, /**< @brief Global bit flag */
			MAT_F_LOGICAL        = 0x0200, /**< @brief Logical bit flag */
			MAT_F_DONT_COPY_DATA = 0x0001  /**< Don't copy data, use keep the pointer */
};

/** @brief MAT file compression options
 *
 * This option is only used on version 5 MAT files
 * @ingroup MAT
 */
enum class compression : char {
	MAT_COMPRESSION_NONE = 0,   /**< @brief No compression */
			MAT_COMPRESSION_ZLIB = 1    /**< @brief zlib compression */
};

/** @brief matio lookup type
 *
 * @ingroup MAT
 * matio lookup type
 */
enum class lookup : char {
	MAT_BY_NAME  = 1, /**< Lookup by name */
			MAT_BY_INDEX = 2  /**< Lookup by index */
};


/* Library function */
//EXTERN void Mat_GetLibraryVersion(int *major,int *minor,int *release);

/*     io.c         */
//EXTERN char  *strdup_vprintf(const char *format, va_list ap);
//EXTERN char  *strdup_printf(const char *format, ...);
//EXTERN int    Mat_SetVerbose( int verb, int s );
//EXTERN int    Mat_SetDebug( int d );
//EXTERN void   Mat_Critical( const char *format, ... );
//EXTERN MATIO_NORETURN void Mat_Error( const char *format, ... ) MATIO_NORETURNATTR;
//EXTERN void   Mat_Help( const char *helpstr[] );
//EXTERN int    Mat_LogInit( const char *progname );
//EXTERN int    Mat_LogClose(void);
//EXTERN int    Mat_LogInitFunc(const char *prog_name,
//                    void (*log_func)(int log_level, char *message) );
//EXTERN int    Mat_Message( const char *format, ... );
//EXTERN int    Mat_DebugMessage( int level, const char *format, ... );
//EXTERN int    Mat_VerbMessage( int level, const char *format, ... );
//EXTERN void   Mat_Warning( const char *format, ... );
//EXTERN size_t Mat_SizeOf(enum matio_types data_type);
//EXTERN size_t Mat_SizeOfClass(int class_type);

//Forward declare MatVar
class MatVar;

class Mat {
public:
	static void GetLibraryVersion(int *major,int *minor,int *release);

	Mat();
	Mat(const Mat&);
	~Mat();
	Mat(const std::string& matname, ft mat_file_ver);
	Mat(const std::string& matname, const std::string& hdr_str, ft mat_file_ver);
	bool Open(const std::string& matname, acc mode);
	void PrintVars() const;
	std::vector<std::string> GetVarNames() const;
	size_t NumVars() const;
	bool   Close();
	std::string GetFilename();
	ft GetVersion();
	MatVar&  Read(const std::string& name);
	MatVar&  ReadInfo(const std::string& name);
	bool Delete(const std::string& name);
	bool Write(MatVar &_matvar, compression compress);
	bool WriteInfo(MatVar &_matvar);
	bool WriteData(MatVar &_matvar, void *data, int *start, int *stride, int *edge);
private:
	mat_t  *_mat;
	std::map<std::string, matvar_t *> _vars;
};

/* MAT variable functions */
class MatVar {
	friend class Mat; // Mat is a friend of MatVar
public:
	MatVar();
	MatVar(matvar_t * _matvar);
	~MatVar();
	MatVar(std::string name, classes class_type, types data_type, int rank, size_t *dims, void *data, flags opt);
	MatVar(std::string name, int rank, size_t *dims, const char **fields, unsigned nfields);
	MatVar(const MatVar &in);
	MatVar&  GetCell(int index);
	MatVar&  GetCells(int *start, int *stride, int *edge);
	MatVar&  GetCellsLinear(int start, int stride, int edge);
	size_t   GetSize() const;
	size_t   GetNumberOfFields() const;
	bool     AddStructField(const std::string& fieldname);
	std::vector<std::string> GetStructFieldnames() const;
	MatVar&  GetStructFieldByIndex(size_t field_index, size_t index);
	MatVar&  GetStructFieldByName(const std::string& field_name, size_t index);
	MatVar&  GetStructField(size_t name_or_index, int opt, int index);
	MatVar&  GetStructField(const std::string& name_or_index, int opt, int index);

	MatVar&  GetStructs(int *start,int *stride, int *edge,int copy_fields);
	MatVar&  GetStructsLinear(int start,int stride, int edge,int copy_fields);
	void     Print(int printdata );
	bool     ReadDataAll();
	MatVar&  SetCell(int index,MatVar &cell);
	MatVar&  SetStructFieldByIndex(size_t field_index, size_t index, MatVar &field);
	MatVar&  SetStructFieldByName(const std::string& field_name, size_t index, MatVar &field);
private:

	matvar_t * _matvar;

};

}//end namespace matio
#endif
