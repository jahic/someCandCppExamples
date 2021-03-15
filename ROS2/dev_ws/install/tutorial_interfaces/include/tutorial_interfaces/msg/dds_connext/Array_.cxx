

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Array_.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "Array_.h"

#include <new>

namespace tutorial_interfaces {
    namespace msg {
        namespace dds_ {

            /* ========================================================================= */
            const char *Array_TYPENAME = "tutorial_interfaces::msg::dds_::Array_";

            DDS_TypeCode* Array__get_typecode()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode Array__g_tc_member__sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(RTI_INT32_MAX,NULL);
                static DDS_TypeCode_Member Array__g_tc_members[1]=
                {

                    {
                        (char *)"member_",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode Array__g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"tutorial_interfaces::msg::dds_::Array_", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        Array__g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Array_*/

                if (is_initialized) {
                    return &Array__g_tc;
                }

                Array__g_tc_member__sequence._data._typeCode = (RTICdrTypeCode *)tutorial_interfaces::msg::dds_::Num__get_typecode();

                Array__g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& Array__g_tc_member__sequence;

                is_initialized = RTI_TRUE;

                return &Array__g_tc;
            }

            RTIBool Array__initialize(
                Array_* sample) {
                return tutorial_interfaces::msg::dds_::Array__initialize_ex(sample,RTI_TRUE,RTI_TRUE);
            }

            RTIBool Array__initialize_ex(
                Array_* sample,RTIBool allocatePointers, RTIBool allocateMemory)
            {

                struct DDS_TypeAllocationParams_t allocParams =
                DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

                allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
                allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

                return tutorial_interfaces::msg::dds_::Array__initialize_w_params(
                    sample,&allocParams);

            }

            RTIBool Array__initialize_w_params(
                Array_* sample, const struct DDS_TypeAllocationParams_t * allocParams)
            {

                void* buffer = NULL;
                if (buffer) {} /* To avoid warnings */

                if (sample == NULL) {
                    return RTI_FALSE;
                }
                if (allocParams == NULL) {
                    return RTI_FALSE;
                }

                if (allocParams->allocate_memory) {
                    tutorial_interfaces::msg::dds_::Num_Seq_initialize(&sample->member_ );
                    tutorial_interfaces::msg::dds_::Num_Seq_set_element_allocation_params(&sample->member_ ,allocParams);
                    tutorial_interfaces::msg::dds_::Num_Seq_set_absolute_maximum(&sample->member_ , RTI_INT32_MAX);
                    if (!tutorial_interfaces::msg::dds_::Num_Seq_set_maximum(&sample->member_, (0))) {
                        return RTI_FALSE;
                    }
                } else { 
                    tutorial_interfaces::msg::dds_::Num_Seq_set_length(&sample->member_, 0);
                }
                return RTI_TRUE;
            }

            void Array__finalize(
                Array_* sample)
            {

                tutorial_interfaces::msg::dds_::Array__finalize_ex(sample,RTI_TRUE);
            }

            void Array__finalize_ex(
                Array_* sample,RTIBool deletePointers)
            {
                struct DDS_TypeDeallocationParams_t deallocParams =
                DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

                if (sample==NULL) {
                    return;
                } 

                deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

                tutorial_interfaces::msg::dds_::Array__finalize_w_params(
                    sample,&deallocParams);
            }

            void Array__finalize_w_params(
                Array_* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
            {

                if (sample==NULL) {
                    return;
                }

                if (deallocParams == NULL) {
                    return;
                }

                tutorial_interfaces::msg::dds_::Num_Seq_set_element_deallocation_params(
                    &sample->member_,deallocParams);
                tutorial_interfaces::msg::dds_::Num_Seq_finalize(&sample->member_);

            }

            void Array__finalize_optional_members(
                Array_* sample, RTIBool deletePointers)
            {
                struct DDS_TypeDeallocationParams_t deallocParamsTmp =
                DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
                struct DDS_TypeDeallocationParams_t * deallocParams =
                &deallocParamsTmp;

                if (sample==NULL) {
                    return;
                } 
                if (deallocParams) {} /* To avoid warnings */

                deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
                deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

                {
                    DDS_UnsignedLong i, length;
                    length = tutorial_interfaces::msg::dds_::Num_Seq_get_length(
                        &sample->member_);

                    for (i = 0; i < length; i++) {
                        tutorial_interfaces::msg::dds_::Num__finalize_optional_members(
                            tutorial_interfaces::msg::dds_::Num_Seq_get_reference(
                                &sample->member_, i), deallocParams->delete_pointers);
                    }
                }  

            }

            RTIBool Array__copy(
                Array_* dst,
                const Array_* src)
            {
                try {

                    if (dst == NULL || src == NULL) {
                        return RTI_FALSE;
                    }

                    if (!tutorial_interfaces::msg::dds_::Num_Seq_copy(&dst->member_ ,
                    &src->member_ )) {
                        return RTI_FALSE;
                    }

                    return RTI_TRUE;

                } catch (std::bad_alloc&) {
                    return RTI_FALSE;
                }
            }

            /**
            * <<IMPLEMENTATION>>
            *
            * Defines:  TSeq, T
            *
            * Configure and implement 'Array_' sequence class.
            */
            #define T Array_
            #define TSeq Array_Seq

            #define T_initialize_w_params tutorial_interfaces::msg::dds_::Array__initialize_w_params

            #define T_finalize_w_params   tutorial_interfaces::msg::dds_::Array__finalize_w_params
            #define T_copy       tutorial_interfaces::msg::dds_::Array__copy

            #ifndef NDDS_STANDALONE_TYPE
            #include "dds_c/generic/dds_c_sequence_TSeq.gen"
            #include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
            #else
            #include "dds_c_sequence_TSeq.gen"
            #include "dds_cpp_sequence_TSeq.gen"
            #endif

            #undef T_copy
            #undef T_finalize_w_params

            #undef T_initialize_w_params

            #undef TSeq
            #undef T
        } /* namespace dds_  */
    } /* namespace msg  */
} /* namespace tutorial_interfaces  */

