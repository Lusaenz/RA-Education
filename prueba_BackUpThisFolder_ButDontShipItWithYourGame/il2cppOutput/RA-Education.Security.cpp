#include "pch-cpp.hpp"





template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
struct HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D;
struct SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9;
struct String_t;
struct StringBuilder_t;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t2BAC58CA52B68B6D0ED9843AF302C61381BE165C;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____4EB76342DE17DF5A380D77C217C4C38C5BE968A99EF1B3CE09E344FE11110B73_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____CEF83CB53250D2FF71A6CDB9903F37114AFAF258A1C411B4FC4391D01D8CAF6A_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_t295AE25EC159B05A3A10BFEF973CB1AA74DC29A6 
{
};
struct U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8  : public RuntimeObject
{
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	int32_t ___m_codePage;
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem;
	bool ___m_deserializedFromEverett;
	bool ___m_isReadOnly;
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback;
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback;
};
struct HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D  : public RuntimeObject
{
	bool ____disposed;
	int32_t ___HashSizeValue;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___HashValue;
	int32_t ___State;
};
struct PasswordHasher_t802317E55C8296F4C1DF0B52AC0BA0730EFFAFC1  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t2BAC58CA52B68B6D0ED9843AF302C61381BE165C  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9  : public HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D
{
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D20_tBE2B12036C00105CABEB737558CC16C4F4261D2D 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D20_tBE2B12036C00105CABEB737558CC16C4F4261D2D__padding[20];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D54_t1884722196F7B44E94BB4FFA7BCF064CF4FA323B 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D54_t1884722196F7B44E94BB4FFA7BCF064CF4FA323B__padding[54];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_com
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 
{
	intptr_t ___value;
};
struct StringComparison_tE14A55CCFA001A5AC85D754179BF2888F45CC94D 
{
	int32_t ___value__;
};
struct U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8_StaticFields
{
	__StaticArrayInitTypeSizeU3D20_tBE2B12036C00105CABEB737558CC16C4F4261D2D ___4EB76342DE17DF5A380D77C217C4C38C5BE968A99EF1B3CE09E344FE11110B73;
	__StaticArrayInitTypeSizeU3D54_t1884722196F7B44E94BB4FFA7BCF064CF4FA323B ___CEF83CB53250D2FF71A6CDB9903F37114AFAF258A1C411B4FC4391D01D8CAF6A;
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding;
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings;
	RuntimeObject* ___s_InternalSyncObject;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* SHA256_Create_m41FBBA07C26677E1028E44E3530AC1BA17D26BBC (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* HashAlgorithm_ComputeHash_mC9CD24714D75A8D61F12509BF952A26347FF22FB (HashAlgorithm_t299ECE61BBF4582B1F75734D43A96DDEC9B2004D* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_buffer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5 (StringBuilder_t* __this, int32_t ___0_capacity, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310 (uint8_t* __this, String_t* ___0_format, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PasswordHasher_IsSha256Hash_m600F0F642139FE5CB95A29F5ADEE159B9C3E08BA (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* PasswordHasher_HashPassword_m8D7550D8D1D22CC1D739F0755FCCAEB8CEC4AD4D (String_t* ___0_password, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_Equals_mCC34895D0DB2AD440C9D8767032215BC86B5C48B (String_t* ___0_a, String_t* ___1_b, int32_t ___2_comparisonType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 104828
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* PasswordHasher_HashPassword_m8D7550D8D1D22CC1D739F0755FCCAEB8CEC4AD4D (String_t* ___0_password, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringBuilder_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260);
		s_Il2CppMethodInitialized = true;
	}
	SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* V_0 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_2 = NULL;
	StringBuilder_t* V_3 = NULL;
	int32_t V_4 = 0;
	String_t* V_5 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:15>
		String_t* L_0 = ___0_password;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:17>
		String_t* L_1 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_defaults.string_class))->___Empty;
		return L_1;
	}

IL_0009:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:20>
		SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* L_2;
		L_2 = SHA256_Create_m41FBBA07C26677E1028E44E3530AC1BA17D26BBC(NULL);
		V_0 = L_2;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0063:
			{
				{
					SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* L_3 = V_0;
					if (!L_3)
					{
						goto IL_006c;
					}
				}
				{
					SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* L_4 = V_0;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_006c:
				{
					return;
				}
			}
		});
		try
		{
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:22>
				Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_5;
				L_5 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
				String_t* L_6 = ___0_password;
				NullCheck(L_5);
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7;
				L_7 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(17, L_5, L_6);
				V_1 = L_7;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:23>
				SHA256_t6FEDD761EE6301127DAAF13320E8FD63296837F9* L_8 = V_0;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_1;
				NullCheck(L_8);
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10;
				L_10 = HashAlgorithm_ComputeHash_mC9CD24714D75A8D61F12509BF952A26347FF22FB(L_8, L_9, NULL);
				V_2 = L_10;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:25>
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = V_2;
				NullCheck(L_11);
				StringBuilder_t* L_12 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
				StringBuilder__ctor_m2619CA8D2C3476DF1A302D9D941498BB1C6164C5(L_12, ((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_11)->max_length)), 2)), NULL);
				V_3 = L_12;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:26>
				V_4 = 0;
				goto IL_0052_1;
			}

IL_0033_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:28>
				StringBuilder_t* L_13 = V_3;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14 = V_2;
				int32_t L_15 = V_4;
				NullCheck(L_14);
				String_t* L_16;
				L_16 = Byte_ToString_m793A41EEEB7B422F6FE658E99D2F7683F59EE310(((L_14)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_15))), _stringLiteral65A0F9B64ACE7C859A284EA54B1190CBF83E1260, NULL);
				NullCheck(L_13);
				StringBuilder_t* L_17;
				L_17 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_13, L_16, NULL);
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:26>
				int32_t L_18 = V_4;
				V_4 = ((int32_t)il2cpp_codegen_add(L_18, 1));
			}

IL_0052_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:26>
				int32_t L_19 = V_4;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_20 = V_2;
				NullCheck(L_20);
				if ((((int32_t)L_19) < ((int32_t)((int32_t)(((RuntimeArray*)L_20)->max_length)))))
				{
					goto IL_0033_1;
				}
			}
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:31>
				StringBuilder_t* L_21 = V_3;
				NullCheck(L_21);
				String_t* L_22;
				L_22 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_21);
				V_5 = L_22;
				goto IL_006d;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:33>
		String_t* L_23 = V_5;
		return L_23;
	}
}
// Method Definition Index: 104829
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PasswordHasher_IsSha256Hash_m600F0F642139FE5CB95A29F5ADEE159B9C3E08BA (String_t* ___0_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	Il2CppChar V_1 = 0x0;
	int32_t G_B12_0 = 0;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:40>
		String_t* L_0 = ___0_value;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (L_1)
		{
			goto IL_0012;
		}
	}
	{
		String_t* L_2 = ___0_value;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_2, NULL);
		if ((((int32_t)L_3) == ((int32_t)((int32_t)64))))
		{
			goto IL_0014;
		}
	}

IL_0012:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:42>
		return (bool)0;
	}

IL_0014:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:45>
		V_0 = 0;
		goto IL_004f;
	}

IL_0018:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:47>
		String_t* L_4 = ___0_value;
		int32_t L_5 = V_0;
		NullCheck(L_4);
		Il2CppChar L_6;
		L_6 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_4, L_5, NULL);
		V_1 = L_6;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:48>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:49>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:50>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:51>
		Il2CppChar L_7 = V_1;
		if ((((int32_t)L_7) < ((int32_t)((int32_t)48))))
		{
			goto IL_002a;
		}
	}
	{
		Il2CppChar L_8 = V_1;
		if ((((int32_t)L_8) <= ((int32_t)((int32_t)57))))
		{
			goto IL_0046;
		}
	}

IL_002a:
	{
		Il2CppChar L_9 = V_1;
		if ((((int32_t)L_9) < ((int32_t)((int32_t)97))))
		{
			goto IL_0034;
		}
	}
	{
		Il2CppChar L_10 = V_1;
		if ((((int32_t)L_10) <= ((int32_t)((int32_t)102))))
		{
			goto IL_0046;
		}
	}

IL_0034:
	{
		Il2CppChar L_11 = V_1;
		if ((((int32_t)L_11) < ((int32_t)((int32_t)65))))
		{
			goto IL_0043;
		}
	}
	{
		Il2CppChar L_12 = V_1;
		G_B12_0 = ((((int32_t)((((int32_t)L_12) > ((int32_t)((int32_t)70)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_0047;
	}

IL_0043:
	{
		G_B12_0 = 0;
		goto IL_0047;
	}

IL_0046:
	{
		G_B12_0 = 1;
	}

IL_0047:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:53>
		if (G_B12_0)
		{
			goto IL_004b;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:55>
		return (bool)0;
	}

IL_004b:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:45>
		int32_t L_13 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_004f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:45>
		int32_t L_14 = V_0;
		String_t* L_15 = ___0_value;
		NullCheck(L_15);
		int32_t L_16;
		L_16 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_15, NULL);
		if ((((int32_t)L_14) < ((int32_t)L_16)))
		{
			goto IL_0018;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:59>
		return (bool)1;
	}
}
// Method Definition Index: 104830
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PasswordHasher_VerifyPassword_m56F77F7A11DCC0907E238E5717817644E38811FB (String_t* ___0_inputPassword, String_t* ___1_storedPassword, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:67>
		String_t* L_0 = ___1_storedPassword;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (!L_1)
		{
			goto IL_000a;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:69>
		return (bool)0;
	}

IL_000a:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:72>
		String_t* L_2 = ___1_storedPassword;
		bool L_3;
		L_3 = PasswordHasher_IsSha256Hash_m600F0F642139FE5CB95A29F5ADEE159B9C3E08BA(L_2, NULL);
		if (!L_3)
		{
			goto IL_0020;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:74>
		String_t* L_4 = ___0_inputPassword;
		String_t* L_5;
		L_5 = PasswordHasher_HashPassword_m8D7550D8D1D22CC1D739F0755FCCAEB8CEC4AD4D(L_4, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:75>
		String_t* L_6 = ___1_storedPassword;
		bool L_7;
		L_7 = String_Equals_mCC34895D0DB2AD440C9D8767032215BC86B5C48B(L_5, L_6, 5, NULL);
		return L_7;
	}

IL_0020:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/Scrips/Core/Security/PasswordHasher.cs:79>
		String_t* L_8 = ___0_inputPassword;
		String_t* L_9 = ___1_storedPassword;
		bool L_10;
		L_10 = String_Equals_mCC34895D0DB2AD440C9D8767032215BC86B5C48B(L_8, L_9, 4, NULL);
		return L_10;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 104831
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52 UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_m3586773A47F762CCBBD47684AB9DAFBEAE010A1C (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____4EB76342DE17DF5A380D77C217C4C38C5BE968A99EF1B3CE09E344FE11110B73_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____CEF83CB53250D2FF71A6CDB9903F37114AFAF258A1C411B4FC4391D01D8CAF6A_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)54));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____CEF83CB53250D2FF71A6CDB9903F37114AFAF258A1C411B4FC4391D01D8CAF6A_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)20));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tE09EC111BE5BC78FC1EB0F422C779E199B4875C8____4EB76342DE17DF5A380D77C217C4C38C5BE968A99EF1B3CE09E344FE11110B73_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = 1;
		(&V_0)->___TotalTypes = 1;
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52 L_6 = V_0;
		return L_6;
	}
}
// Method Definition Index: 104832
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_m3B7B42059062C725187EEAE83464998CFF27A176 (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t2BAC58CA52B68B6D0ED9843AF302C61381BE165C* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_pinvoke(const MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52& unmarshaled, MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_pinvoke_back(const MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_pinvoke& marshaled, MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_pinvoke_cleanup(MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_com(const MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52& unmarshaled, MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_com_back(const MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_com& marshaled, MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52& unmarshaled)
{
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, il2cpp_defaults.byte_class, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshal_com_cleanup(MonoScriptData_t129DA1E3B96146BD7E1A15182E2C6463B23BBB52_marshaled_com& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 705
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength;
		return L_0;
	}
}
