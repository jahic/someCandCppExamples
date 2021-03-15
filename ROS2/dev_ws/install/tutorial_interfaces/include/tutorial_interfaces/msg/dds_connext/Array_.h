

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Array_.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Array__778908762_h
#define Array__778908762_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "tutorial_interfaces/msg/dds_connext/Num_.h"
namespace tutorial_interfaces {
    namespace msg {
        namespace dds_ {

            extern const char *Array_TYPENAME;

            struct Array_Seq;
            #ifndef NDDS_STANDALONE_TYPE
            class Array_TypeSupport;
            class Array_DataWriter;
            class Array_DataReader;
            #endif

            class Array_ 
            {
              public:
                typedef struct Array_Seq Seq;
                #ifndef NDDS_STANDALONE_TYPE
                typedef Array_TypeSupport TypeSupport;
                typedef Array_DataWriter DataWriter;
                typedef Array_DataReader DataReader;
                #endif

                tutorial_interfaces::msg::dds_::Num_Seq  member_ ;

            };
            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
            /* If the code is building on Windows, start exporting symbols.
            */
            #undef NDDSUSERDllExport
            #define NDDSUSERDllExport __declspec(dllexport)
            #endif

            NDDSUSERDllExport DDS_TypeCode* Array__get_typecode(void); /* Type code */

            DDS_SEQUENCE(Array_Seq, Array_);

            NDDSUSERDllExport
            RTIBool Array__initialize(
                Array_* self);

            NDDSUSERDllExport
            RTIBool Array__initialize_ex(
                Array_* self,RTIBool allocatePointers,RTIBool allocateMemory);

            NDDSUSERDllExport
            RTIBool Array__initialize_w_params(
                Array_* self,
                const struct DDS_TypeAllocationParams_t * allocParams);  

            NDDSUSERDllExport
            void Array__finalize(
                Array_* self);

            NDDSUSERDllExport
            void Array__finalize_ex(
                Array_* self,RTIBool deletePointers);

            NDDSUSERDllExport
            void Array__finalize_w_params(
                Array_* self,
                const struct DDS_TypeDeallocationParams_t * deallocParams);

            NDDSUSERDllExport
            void Array__finalize_optional_members(
                Array_* self, RTIBool deletePointers);  

            NDDSUSERDllExport
            RTIBool Array__copy(
                Array_* dst,
                const Array_* src);

            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
            /* If the code is building on Windows, stop exporting symbols.
            */
            #undef NDDSUSERDllExport
            #define NDDSUSERDllExport
            #endif
        } /* namespace dds_  */
    } /* namespace msg  */
} /* namespace tutorial_interfaces  */

#endif /* Array_ */

