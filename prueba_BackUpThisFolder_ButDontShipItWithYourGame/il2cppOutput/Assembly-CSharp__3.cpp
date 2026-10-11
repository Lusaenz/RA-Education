#include "pch-cpp.hpp"





template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3
{
	typedef void (*Action)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};
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
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
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
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct Comparison_1_tE977BBB4F0CF77771298A262B86AF2AD31187146;
struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
struct Dictionary_2_tA348003A3C1CEFB3096E9D2A0BC7F1AC8EC4F710;
struct Dictionary_2_t7EE155547BF85C4842B48F5187C809B9BD49A286;
struct Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00;
struct Func_2_tACBF5A1656250800CE861707354491F0611F6624;
struct Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0;
struct Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF;
struct IEnumerable_1_t0FFF98899BD0CCBA938282533A74665546B11C2D;
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
struct IEnumerable_1_t349E66EC5F09B881A8E52EE40A1AB9EC60E08E44;
struct IEnumerable_1_tBEA6C219B3D53413B77067120604E18CF109DAB1;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_tC97D118E4BF4DED562658508050671CE052C65B9;
struct List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828;
struct List_1_t76F9611073289221FD689EB9CF04C021C23B2186;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct BindingU5BU5D_t2A94383B4742A53987FF83B6CF5943B683970DED;
struct IndexedColumnU5BU5D_t8587AF19BB7D441ABF744911119AE9E3ABEDD0A4;
struct ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960;
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA;
struct AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F;
struct BaseTableQuery_t28D9E3082475EF8E0FC7E8F87FA0174C247BED7D;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
struct CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C;
struct ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4;
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
struct Delegate_t;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5;
struct IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct IFormatProvider_tC202922D43BFF3525109ABF3FB79625F5646AB52;
struct IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2;
struct IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F;
struct MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MemberInfo_t;
struct MethodBase_t;
struct MethodInfo_t;
struct NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5;
struct NotNullConstraintViolationException_t879E7832BFBEBCFCE0B1902526231D755FA83456;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6;
struct PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1;
struct PropertyInfo_t;
struct Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8;
struct SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF;
struct SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4;
struct SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664;
struct SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct Stopwatch_tA188A210449E22C07053A7D3014DD182C7369043;
struct String_t;
struct TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534;
struct TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966;
struct Type_t;
struct UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826;
struct Binding_t846C16F3FF76025D82F878E8E00A5894741580FD;
struct U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81;
struct U3CU3Ec__DisplayClass105_0_t8E67D00FCA72EDFB9CAB00662760929AAAA2F274;
struct U3CU3Ec__DisplayClass106_0_tCCA41F62B5EA6FC5618E0CC020ADB2165A043E97;
struct U3CU3Ec__DisplayClass95_0_t60206737D176DC76F28DCB8EC7DF4E6C06EE5D8A;
struct U3CU3Ec__DisplayClass96_0_t527EA7B759880603FA94E43D3EFF38F94C04DC91;
struct U3CU3Ec__DisplayClass97_0_t7DD496E8120D85C5BD65C1D718EBC656A5139846;
struct ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2;
struct TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1;
struct TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F;
struct U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A;
struct U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96;
struct U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278;
struct Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671;

IL2CPP_EXTERN_C RuntimeClass* Binding_t846C16F3FF76025D82F878E8E00A5894741580FD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Guid_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t76F9611073289221FD689EB9CF04C021C23B2186_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tC97D118E4BF4DED562658508050671CE052C65B9_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Result_tBCF6FD0B3965B1AB3130BD1B60A6B937FCD8EED4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral087915F54405AD1B7F0E6ADFE8D41FB99BBC5929;
IL2CPP_EXTERN_C String_t* _stringLiteral0B1AA9B29EF545DBB7671B2694E3D4F830F07300;
IL2CPP_EXTERN_C String_t* _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745;
IL2CPP_EXTERN_C String_t* _stringLiteral2BE7531317059E346E68D5E40F607A6DDDB9FA57;
IL2CPP_EXTERN_C String_t* _stringLiteral3A0F6D9DBC0488BBFF8777F70B454F11D38CAC5F;
IL2CPP_EXTERN_C String_t* _stringLiteral4B2E822D33FB5518E457261FE7AAFA1B172FDF65;
IL2CPP_EXTERN_C String_t* _stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C;
IL2CPP_EXTERN_C String_t* _stringLiteral6791FD228A8829A89802587131C38934CF0E3A9D;
IL2CPP_EXTERN_C String_t* _stringLiteral738F291E53E97C08DAE378C71EF70A60E31AE900;
IL2CPP_EXTERN_C String_t* _stringLiteral77B57D428E28530AC6DF109E9E5436339E1F7152;
IL2CPP_EXTERN_C String_t* _stringLiteral7EF9629485339439117D5EB2BD0095D32B266B7B;
IL2CPP_EXTERN_C String_t* _stringLiteral7F129804295CEE0C04CDF4D55A11D7A4ED8A692A;
IL2CPP_EXTERN_C String_t* _stringLiteral80E7F4E6C02B03699F008F88CF100C4A58F4B1CD;
IL2CPP_EXTERN_C String_t* _stringLiteral83E8CA1BC21F4B77911E28ADCD695A986FAAD8F8;
IL2CPP_EXTERN_C String_t* _stringLiteralA1604BA2DF7A8D273C546D03C05252552111513B;
IL2CPP_EXTERN_C String_t* _stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9;
IL2CPP_EXTERN_C String_t* _stringLiteralB0A1C47352664275E2D7F477FA4C62FC016B575F;
IL2CPP_EXTERN_C String_t* _stringLiteralB3F14BF976EFD974E34846B742502C802FABAE9D;
IL2CPP_EXTERN_C String_t* _stringLiteralBFF9324A7A4DB3E1D645999C8B9E2DA54472D42C;
IL2CPP_EXTERN_C String_t* _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
IL2CPP_EXTERN_C String_t* _stringLiteralC314B19DDFC8FCE377B4A8712813CBE720521F28;
IL2CPP_EXTERN_C String_t* _stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677;
IL2CPP_EXTERN_C String_t* _stringLiteralD635CA0E4F85CB7F26A62468F86B37AEADB9D184;
IL2CPP_EXTERN_C String_t* _stringLiteralD7764DAE340A30DF12CAC1D83DBBA792E904A118;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralDBB6EBD9AA582506BA733281AF7A5F5E65A624F1;
IL2CPP_EXTERN_C String_t* _stringLiteralE237EC436581AFB5F89F4E57554E10B20D85C41D;
IL2CPP_EXTERN_C String_t* _stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29;
IL2CPP_EXTERN_C String_t* _stringLiteralE7650EB4C8EF6F4B045B8E8747677ECDDEF6AA10;
IL2CPP_EXTERN_C String_t* _stringLiteralED45F4AF48C69346087C97D466BF405E270AABE2;
IL2CPP_EXTERN_C String_t* _stringLiteralF3AFDFF8CF4EECA2CEFFAA76CE1B231800822441;
IL2CPP_EXTERN_C String_t* _stringLiteralF57B369204E09200EF1244FE1DC17C91C4CE8B44;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Any_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m6325CE9602A98DA4A975472F98C7910DDE3717FF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Any_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_m437EBE80131A4CD77D4F0924E3E375284C8A074A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Cast_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_mC71EC946C5A6FCA3956E91CEFEA6AC53497D8F39_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Count_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m57CC70E85C42987C231D56F3D4CA940C9D6EE660_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerable_Where_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m42628461F47BB2F46D2F0ED015117BCB0A5965EC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m51B7F6D3686AE2542AB3B31697069DA12D259BA4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m7BF2A509F39D61CA112B7EAD8999D35EE56D6C8F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_ToArray_m27A3A30821E452F09439851819E7DA5612C828E3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mA5F09B5DB35D0EDC340F75E2C9CFB2AE65C81F0F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mE9E8FCA661D879A24A1C832D63E9254F4375EA0D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_mEFA76239AAE09EB0C4E66AB1ED13E2A8C60EAFC2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Orm_SqlType_mDCE7980C3A660660D6700F7A4413F090E19959AE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PreparedSqlLiteInsertCommand_ExecuteNonQuery_mB3C230E1C516704102397C40F4755B5B814C621E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SQLiteCommand_ExecuteNonQuery_m9E1C1980946214E8C0CB50EC26828EC428435F5B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SQLiteCommand_ReadCol_mC92CB5B68FD045C70567CB31BA216D163E211E03_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3CCreateInsertCommandU3Eb__38_0_m88101F47F990EFC0C85013F09E4E590C2994CEC6_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3CCreateInsertCommandU3Eb__38_1_m9B9E8F68B952A79B9B6AB52EBA05A8B5B489A931_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec_U3Cget_InsertColumnsU3Eb__30_0_mC65BE356215F8AC4CC235F9BE4C98C4534B8B937_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec__DisplayClass33_0_U3CFindColumnWithPropertyNameU3Eb__0_mEF298136BF9EE46A93578AF27D572E44CE85D73B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* U3CU3Ec__DisplayClass34_0_U3CFindColumnU3Eb__0_mFB0F28EB947998D4BE1413D0F0FE9341698AF0E0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Guid_t_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_0_0_0_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tC97D118E4BF4DED562658508050671CE052C65B9  : public RuntimeObject
{
	BindingU5BU5D_t2A94383B4742A53987FF83B6CF5943B683970DED* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828  : public RuntimeObject
{
	IndexedColumnU5BU5D_t8587AF19BB7D441ABF744911119AE9E3ABEDD0A4* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t76F9611073289221FD689EB9CF04C021C23B2186  : public RuntimeObject
{
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA  : public RuntimeObject
{
};
struct Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA  : public RuntimeObject
{
};
struct BaseTableQuery_t28D9E3082475EF8E0FC7E8F87FA0174C247BED7D  : public RuntimeObject
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
struct MemberInfo_t  : public RuntimeObject
{
};
struct Orm_t0CB9CD2E590819A2FF7A7318E4430A7908DBE8B1  : public RuntimeObject
{
};
struct SQLite3_t901F4323097756296B4D20225DDB1659EFA9ABEC  : public RuntimeObject
{
};
struct SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF  : public RuntimeObject
{
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ____conn;
	List_1_tC97D118E4BF4DED562658508050671CE052C65B9* ____bindings;
	String_t* ___U3CCommandTextU3Ek__BackingField;
};
struct SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664  : public RuntimeObject
{
	String_t* ___U3CConnectionStringU3Ek__BackingField;
	String_t* ___U3CDatabasePathU3Ek__BackingField;
	bool ___U3CStoreDateTimeAsTicksU3Ek__BackingField;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966  : public RuntimeObject
{
	Type_t* ___U3CMappedTypeU3Ek__BackingField;
	String_t* ___U3CTableNameU3Ek__BackingField;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ___U3CColumnsU3Ek__BackingField;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___U3CPKU3Ek__BackingField;
	String_t* ___U3CGetByPrimaryKeySqlU3Ek__BackingField;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ____autoPk;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ____insertColumns;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ____insertOrReplaceColumns;
	bool ___U3CHasAutoIncPKU3Ek__BackingField;
	PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* ____insertCommand;
	String_t* ____insertCommandExtra;
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
struct Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826  : public RuntimeObject
{
	String_t* ___U3CColumnNameU3Ek__BackingField;
	bool ___U3CAscendingU3Ek__BackingField;
};
struct Binding_t846C16F3FF76025D82F878E8E00A5894741580FD  : public RuntimeObject
{
	String_t* ___U3CNameU3Ek__BackingField;
	RuntimeObject* ___U3CValueU3Ek__BackingField;
	int32_t ___U3CIndexU3Ek__BackingField;
};
struct U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81  : public RuntimeObject
{
};
struct U3CU3Ec__DisplayClass105_0_t8E67D00FCA72EDFB9CAB00662760929AAAA2F274  : public RuntimeObject
{
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___pk;
	RuntimeObject* ___obj;
};
struct U3CU3Ec__DisplayClass106_0_tCCA41F62B5EA6FC5618E0CC020ADB2165A043E97  : public RuntimeObject
{
	RuntimeObject* ___objects;
	int32_t ___c;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___U3CU3E4__this;
};
struct U3CU3Ec__DisplayClass95_0_t60206737D176DC76F28DCB8EC7DF4E6C06EE5D8A  : public RuntimeObject
{
	RuntimeObject* ___objects;
	int32_t ___c;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___U3CU3E4__this;
};
struct U3CU3Ec__DisplayClass96_0_t527EA7B759880603FA94E43D3EFF38F94C04DC91  : public RuntimeObject
{
	RuntimeObject* ___objects;
	int32_t ___c;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___U3CU3E4__this;
	String_t* ___extra;
};
struct U3CU3Ec__DisplayClass97_0_t7DD496E8120D85C5BD65C1D718EBC656A5139846  : public RuntimeObject
{
	RuntimeObject* ___objects;
	int32_t ___c;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___U3CU3E4__this;
	Type_t* ___objType;
};
struct ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2  : public RuntimeObject
{
	String_t* ___U3CNameU3Ek__BackingField;
	int32_t ___U3CnotnullU3Ek__BackingField;
};
struct U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A  : public RuntimeObject
{
};
struct U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96  : public RuntimeObject
{
	String_t* ___propertyName;
};
struct U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278  : public RuntimeObject
{
	String_t* ___columnName;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 
{
	List_1_tC97D118E4BF4DED562658508050671CE052C65B9* ____list;
	int32_t ____index;
	int32_t ____version;
	Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* ____current;
};
struct Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 
{
	bool ___hasValue;
	int32_t ___value;
};
struct AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
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
struct CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	String_t* ___U3CValueU3Ek__BackingField;
};
struct ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	String_t* ___U3CNameU3Ek__BackingField;
};
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D 
{
	uint64_t ____dateData;
};
struct Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___flags;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___flags_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___hi_OffsetPadding[4];
			int32_t ___hi;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___hi_OffsetPadding_forAlignmentOnly[4];
			int32_t ___hi_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___lo_OffsetPadding[8];
			int32_t ___lo;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___lo_OffsetPadding_forAlignmentOnly[8];
			int32_t ___lo_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___mid_OffsetPadding[12];
			int32_t ___mid;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___mid_OffsetPadding_forAlignmentOnly[12];
			int32_t ___mid_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___ulomidLE_OffsetPadding[8];
			uint64_t ___ulomidLE;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___ulomidLE_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___ulomidLE_forAlignmentOnly;
		};
	};
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
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
struct Guid_t 
{
	int32_t ____a;
	int16_t ____b;
	int16_t ____c;
	uint8_t ____d;
	uint8_t ____e;
	uint8_t ____f;
	uint8_t ____g;
	uint8_t ____h;
	uint8_t ____i;
	uint8_t ____j;
	uint8_t ____k;
};
struct IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
};
struct IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	String_t* ___U3CNameU3Ek__BackingField;
	int32_t ___U3COrderU3Ek__BackingField;
	bool ___U3CUniqueU3Ek__BackingField;
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	int32_t ___U3CValueU3Ek__BackingField;
};
struct MethodBase_t  : public MemberInfo_t
{
};
struct NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
};
struct PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
};
struct PropertyInfo_t  : public MemberInfo_t
{
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534  : public Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA
{
	String_t* ___U3CNameU3Ek__BackingField;
};
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A 
{
	int64_t ____ticks;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
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
struct __StaticArrayInitTypeSizeU3D4168_t4A2B51FA14D1CC57DE5F866BDBF4EA49AEC25063 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D4168_t4A2B51FA14D1CC57DE5F866BDBF4EA49AEC25063__padding[4168];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D5735_t4C1A02E18F3351BFB5B6B94994AEAFB9CC2BC798 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D5735_t4C1A02E18F3351BFB5B6B94994AEAFB9CC2BC798__padding[5735];
	};
};
#pragma pack(pop, tp)
struct IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8 
{
	String_t* ___IndexName;
	String_t* ___TableName;
	bool ___Unique;
	List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828* ___Columns;
};
struct IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_pinvoke
{
	char* ___IndexName;
	char* ___TableName;
	int32_t ___Unique;
	List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828* ___Columns;
};
struct IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_com
{
	Il2CppChar* ___IndexName;
	Il2CppChar* ___TableName;
	int32_t ___Unique;
	List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828* ___Columns;
};
struct IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813 
{
	int32_t ___Order;
	String_t* ___ColumnName;
};
struct IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_pinvoke
{
	int32_t ___Order;
	char* ___ColumnName;
};
struct IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_com
{
	int32_t ___Order;
	Il2CppChar* ___ColumnName;
};
struct BindingFlags_t5DC2835E4AE9C1862B3AD172EF35B6A5F4F1812C 
{
	int32_t ___value__;
};
struct CreateFlags_tB46BB63DEE074BD99459B52E7B3CE3FBAB44211E 
{
	int32_t ___value__;
};
struct DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 
{
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ____dateTime;
	int16_t ____offsetMinutes;
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct MethodInfo_t  : public MethodBase_t
{
};
struct PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6  : public RuntimeObject
{
	bool ___U3CInitializedU3Ek__BackingField;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___U3CConnectionU3Ek__BackingField;
	String_t* ___U3CCommandTextU3Ek__BackingField;
	intptr_t ___U3CStatementU3Ek__BackingField;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4  : public RuntimeObject
{
	bool ____open;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ____busyTimeout;
	Dictionary_2_t7EE155547BF85C4842B48F5187C809B9BD49A286* ____mappings;
	Dictionary_2_t7EE155547BF85C4842B48F5187C809B9BD49A286* ____tables;
	Stopwatch_tA188A210449E22C07053A7D3014DD182C7369043* ____sw;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ____elapsed;
	int32_t ____transactionDepth;
	Random_t79716069EDE67D1D7734F60AE402D0CA3FB6B4C8* ____rand;
	intptr_t ___U3CHandleU3Ek__BackingField;
	String_t* ___U3CDatabasePathU3Ek__BackingField;
	bool ___U3CTraceU3Ek__BackingField;
	bool ___U3CTimeExecutionU3Ek__BackingField;
	TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* ___TraceEvent;
	TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* ___TimeExecutionEvent;
	bool ___U3CStoreDateTimeAsTicksU3Ek__BackingField;
};
struct StringComparison_tE14A55CCFA001A5AC85D754179BF2888F45CC94D 
{
	int32_t ___value__;
};
struct UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089  : public IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F
{
};
struct ColType_t028877A03D2134405D3E6DD38C264743DAE3E42F 
{
	int32_t ___value__;
};
struct ConfigOption_tC75676CB0CDB61DB524CC4FB4E3178EF431A2348 
{
	int32_t ___value__;
};
struct ExtendedResult_tDEB6B6B7BB84CB70AF70D9C7E3392C8208A11D17 
{
	int32_t ___value__;
};
struct Result_tBCF6FD0B3965B1AB3130BD1B60A6B937FCD8EED4 
{
	int32_t ___value__;
};
struct Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671  : public RuntimeObject
{
	PropertyInfo_t* ____prop;
	String_t* ___U3CNameU3Ek__BackingField;
	Type_t* ___U3CColumnTypeU3Ek__BackingField;
	String_t* ___U3CCollationU3Ek__BackingField;
	bool ___U3CIsAutoIncU3Ek__BackingField;
	bool ___U3CIsAutoGuidU3Ek__BackingField;
	bool ___U3CIsPKU3Ek__BackingField;
	RuntimeObject* ___U3CIndicesU3Ek__BackingField;
	bool ___U3CIsNullableU3Ek__BackingField;
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___U3CMaxStringLengthU3Ek__BackingField;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE  : public Exception_t
{
	int32_t ___U3CResultU3Ek__BackingField;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0  : public MulticastDelegate_t
{
};
struct Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF  : public MulticastDelegate_t
{
};
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};
struct NotNullConstraintViolationException_t879E7832BFBEBCFCE0B1902526231D755FA83456  : public SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE
{
	RuntimeObject* ___U3CColumnsU3Ek__BackingField;
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1  : public MulticastDelegate_t
{
};
struct TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F  : public MulticastDelegate_t
{
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct List_1_tC97D118E4BF4DED562658508050671CE052C65B9_StaticFields
{
	BindingU5BU5D_t2A94383B4742A53987FF83B6CF5943B683970DED* ___s_emptyArray;
};
struct List_1_t2BE6BF2F224712DFD6F90AF9B4BAF64099401828_StaticFields
{
	IndexedColumnU5BU5D_t8587AF19BB7D441ABF744911119AE9E3ABEDD0A4* ___s_emptyArray;
};
struct List_1_t76F9611073289221FD689EB9CF04C021C23B2186_StaticFields
{
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_t0F5473E849A5A5185A9F4C5246F0C32816C49FCA_StaticFields
{
	__StaticArrayInitTypeSizeU3D4168_t4A2B51FA14D1CC57DE5F866BDBF4EA49AEC25063 ___36914ED5F25FB0F633A16C660B960D3D186175290FE9A381326B49090ED40541;
	__StaticArrayInitTypeSizeU3D5735_t4C1A02E18F3351BFB5B6B94994AEAFB9CC2BC798 ___50BA0B676B4079D89AE0E048B927D95AEDBEC58E46B2E31E4141650B7FCF4CC2;
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
struct SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields
{
	intptr_t ___NegativePointer;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_StaticFields
{
	U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* ___U3CU3E9;
	Comparison_1_tE977BBB4F0CF77771298A262B86AF2AD31187146* ___U3CU3E9__60_1;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* ___U3CU3E9__105_2;
};
struct U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields
{
	U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* ___U3CU3E9;
	Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* ___U3CU3E9__30_0;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* ___U3CU3E9__38_0;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* ___U3CU3E9__38_1;
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
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_StaticFields
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth365;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth366;
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MinValue;
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MaxValue;
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___UnixEpoch;
};
struct Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_StaticFields
{
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___Zero;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___One;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___MinusOne;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___MaxValue;
	Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F ___MinValue;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray;
};
struct Guid_t_StaticFields
{
	Guid_t ___Empty;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_StaticFields
{
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___Zero;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MaxValue;
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MinValue;
};
struct DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_StaticFields
{
	DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 ___MinValue;
	DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 ___MaxValue;
	DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 ___UnixEpoch;
};
struct PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_StaticFields
{
	intptr_t ___NullStatement;
};
struct SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4_StaticFields
{
	intptr_t ___NullHandle;
	Dictionary_2_tA348003A3C1CEFB3096E9D2A0BC7F1AC8EC4F710* ___syncObjects;
	bool ____preserveDuringLinkMagic;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960  : public RuntimeArray
{
	ALIGN_FIELD (8) Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* m_Items[1];

	inline Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7  : public RuntimeArray
{
	ALIGN_FIELD (8) PropertyInfo_t* m_Items[1];

	inline PropertyInfo_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline PropertyInfo_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, PropertyInfo_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline PropertyInfo_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline PropertyInfo_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, PropertyInfo_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76  : public RuntimeArray
{
	ALIGN_FIELD (8) IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* m_Items[1];

	inline IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* List_1_ToArray_mD7E4F8E7C11C3C67CB5739FCC0A6E86106A6291F_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared (Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Where_TisRuntimeObject_m5DAF16724887B42DDBBF391C7F375749E8AA4AD7_gshared (RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Enumerable_ToArray_TisRuntimeObject_mA54265C2C8A0864929ECD300B75E4952D553D17D_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_FirstOrDefault_TisRuntimeObject_mFACC750E4D7AF7B43F5B866C84F613B3ECC41994_gshared (RuntimeObject* ___0_source, Func_2_tE1F0D41563EE092E5E5540B061449FDE88F1DC00* ___1_predicate, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerable_Any_TisRuntimeObject_m67CFBD544CF1D1C0C7E7457FDBDB81649DE26847_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Enumerable_Count_TisRuntimeObject_mA9FCB8ECCFE8FABC5AA2F8D46F82ACD52279930B_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Func_2__ctor_m7F8A01C0B02BC1D4063F4EB1E817F7A48562A398_gshared (Func_2_tACBF5A1656250800CE861707354491F0611F6624* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Select_TisRuntimeObject_TisRuntimeObject_m67C538A5EBF57C4844107A8EF25DB2CAAFBAF8FB_gshared (RuntimeObject* ___0_source, Func_2_tACBF5A1656250800CE861707354491F0611F6624* ___1_selector, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_gshared (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Enumerable_Cast_TisRuntimeObject_m21250FA47CFF08469ACE158D6FA4E1FE11837D29_gshared (RuntimeObject* ___0_source, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703_gshared (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;

IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* ColumnInfo_get_Name_m58406BCC746124ACF825EC2F71A33EC51EA787E2_inline (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m313E56F7E0112B6C9ED9C8E4FEA00A3A5D5C4E80 (U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Column_GetValue_mC41975E43F1AAF075BC3B67C1BADF8B4B7DEB0EF (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLiteConnection_Update_m56A254715412DE09139E61F8AEF503FDEC1E5212 (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLiteConnection_Insert_mB63605D430E8D23EC2BA531AE12220491EFB09CD (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLiteConnection_Insert_mE3483091067DEF6AADCB8DAFAA2C4D3C4AB84C3F (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, RuntimeObject* ___0_obj, String_t* ___1_extra, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLiteConnection_Insert_m27C8D61DF252C83AF70E8DAF37713A5F5140DAAC (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, RuntimeObject* ___0_obj, Type_t* ___1_objType, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_ConnectionString_m86572BCB05C4F3AB9ADB3847FAECFB4B55A97876_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_StoreDateTimeAsTicks_mE61C0DD29C9985A25FBCDEBF7BF43389C5E69C23_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_DatabasePath_mE625A3627858ECFC73B7F530C066CE3C83716BC0_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2 (Attribute_tFDA8EFEFB0711976D22474794576DAF28F7440AA* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableAttribute_set_Name_m1BE9470AE2BA2E3BAD9694E4E1B78E19E8212984_inline (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ColumnAttribute_set_Name_mE3122C2539DE916052E72CC9E7971B96234FE023_inline (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IndexedAttribute_set_Name_mC9D9DA8C0FD3BD0CFC098D113AD0C38863EAC898_inline (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IndexedAttribute_set_Order_mBB0C74DD1D10DBBBA79A98C9798E3000312E3C57_inline (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute__ctor_m536933E83B03CE758EFBEE9F11E4B537DE1E75D6 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute__ctor_mF5A696DB87387DF433EA71AB7F7DD8739BAAC26A (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, String_t* ___0_name, int32_t ___1_order, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void MaxLengthAttribute_set_Value_m769CB0382163AFC0547A8237C646995EFA1EBC29_inline (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void CollationAttribute_set_Value_m879958EE7A8C28BEE1D60FF7F57DF65736377F0A_inline (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_MappedType_mD0220B466756EA9D6E96E80B7DABDC5136638832_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Type_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
inline RuntimeObject* Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_gshared)(___0_source, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* TableMapping_get_MappedType_mEFC30D7C1A5CA7FE335BD3EA01B759170A16B6FA_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* TableAttribute_get_Name_m28941E0E3D074B4D9AC32C13886B62B9678EB7C1_inline (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_TableName_m74BB32CC2B1F03EB818461E7B8B7608E443D05A5_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) ;
inline void List_1__ctor_mE9E8FCA661D879A24A1C832D63E9254F4375EA0D (List_1_t76F9611073289221FD689EB9CF04C021C23B2186* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t76F9611073289221FD689EB9CF04C021C23B2186*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column__ctor_m8C177984EBE01667C7E935F00904E889933F18B9 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, PropertyInfo_t* ___0_prop, int32_t ___1_createFlags, const RuntimeMethod* method) ;
inline void List_1_Add_m7BF2A509F39D61CA112B7EAD8999D35EE56D6C8F_inline (List_1_t76F9611073289221FD689EB9CF04C021C23B2186* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t76F9611073289221FD689EB9CF04C021C23B2186*, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
inline ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* List_1_ToArray_m27A3A30821E452F09439851819E7DA5612C828E3 (List_1_t76F9611073289221FD689EB9CF04C021C23B2186* __this, const RuntimeMethod* method)
{
	return ((  ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* (*) (List_1_t76F9611073289221FD689EB9CF04C021C23B2186*, const RuntimeMethod*))List_1_ToArray_mD7E4F8E7C11C3C67CB5739FCC0A6E86106A6291F_gshared)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_Columns_mB809C3C4C606ABECA6A7C39817E85C49E0580871_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_PK_m65E0749BAD788A1FE4087774C2EB2DE22E2DD6F7_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_HasAutoIncPK_m11254701AD04373CFD39137AB076C7735E6F1FF0_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* TableMapping_get_PK_m60262F211F1A2F9C31183BBD63849106D0D2A76E_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_GetByPrimaryKeySql_m2E681BF7B6CC67FDF742C2F8FC721A23C28A8215_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Convert_ChangeType_m2AA053891B5D1BD5CA7689B72EE5ADC95CD3E14B (RuntimeObject* ___0_value, Type_t* ___1_conversionType, RuntimeObject* ___2_provider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_SetValue_m2C03ECE0FF590C829C366FEC3BB3007D1804266E (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_obj, RuntimeObject* ___1_val, const RuntimeMethod* method) ;
inline void Func_2__ctor_m7A4C94ED93BA348E3167A682E87E59364CAFA3D3 (Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_m13C0A7F33154D861E2A041B52E88461832DA1697_gshared)(__this, ___0_object, ___1_method, method);
}
inline RuntimeObject* Enumerable_Where_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m42628461F47BB2F46D2F0ED015117BCB0A5965EC (RuntimeObject* ___0_source, Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* ___1_predicate, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*, const RuntimeMethod*))Enumerable_Where_TisRuntimeObject_m5DAF16724887B42DDBBF391C7F375749E8AA4AD7_gshared)(___0_source, ___1_predicate, method);
}
inline ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_ToArray_TisRuntimeObject_mA54265C2C8A0864929ECD300B75E4952D553D17D_gshared)(___0_source, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass33_0__ctor_m6F38599845F7D4E3276601029322FA31C0665A45 (U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* __this, const RuntimeMethod* method) ;
inline Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF (RuntimeObject* ___0_source, Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* ___1_predicate, const RuntimeMethod* method)
{
	return ((  Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* (*) (RuntimeObject*, Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*, const RuntimeMethod*))Enumerable_FirstOrDefault_TisRuntimeObject_mFACC750E4D7AF7B43F5B866C84F613B3ECC41994_gshared)(___0_source, ___1_predicate, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass34_0__ctor_mC801859216DF994C8CC531ABE5F96D3ED1B322E5 (U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* TableMapping_CreateInsertCommand_mD08CD90FEE995D8FBD71DD35E3E192D4A9308BAE (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, String_t* ___1_extra, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_Dispose_mCA54621740609D3A5DC1952524DFCB280474E8C7 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_InsertColumns_mD397D5E0041FCB77305768E1F09F667CBC8F8195 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
inline bool Enumerable_Any_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m6325CE9602A98DA4A975472F98C7910DDE3717FF (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_Any_TisRuntimeObject_m67CFBD544CF1D1C0C7E7457FDBDB81649DE26847_gshared)(___0_source, method);
}
inline int32_t Enumerable_Count_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m57CC70E85C42987C231D56F3D4CA940C9D6EE660 (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  int32_t (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_Count_TisRuntimeObject_mA9FCB8ECCFE8FABC5AA2F8D46F82ACD52279930B_gshared)(___0_source, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t String_Compare_mB21E4512DAFACE027D2DD3FE75DD6E69CE315009 (String_t* ___0_strA, String_t* ___1_strB, int32_t ___2_comparisonType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_InsertOrReplaceColumns_m475DA34A95A499529056F13599F15A580F187377 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) ;
inline void Func_2__ctor_m0B92B23BC9DF6F76137D05B5B9ED715E2C576C95 (Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method)
{
	((  void (*) (Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF*, RuntimeObject*, intptr_t, const RuntimeMethod*))Func_2__ctor_m7F8A01C0B02BC1D4063F4EB1E817F7A48562A398_gshared)(__this, ___0_object, ___1_method, method);
}
inline RuntimeObject* Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF (RuntimeObject* ___0_source, Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* ___1_selector, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF*, const RuntimeMethod*))Enumerable_Select_TisRuntimeObject_TisRuntimeObject_m67C538A5EBF57C4844107A8EF25DB2CAAFBAF8FB_gshared)(___0_source, ___1_selector, method);
}
inline StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194 (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_ToArray_TisRuntimeObject_mA54265C2C8A0864929ECD300B75E4952D553D17D_gshared)(___0_source, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD (String_t* ___0_separator, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_m918500C1EFB475181349A79989BB79BB36102894 (String_t* ___0_format, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_args, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand__ctor_mAC78E6F9CAB8A87FD6340F01B89E74B2303A439D (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_CommandText_mF815B54C9CC7655C4EFD985B018A7F2BCB801D25_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* ColumnAttribute_get_Name_m77A6DCA8A8508839AAF308D8A8FAFB0AE02E56B6_inline (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Name_mD882DC58740CE81E425CB2A31F3DCA0F0E50894D_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Nullable_GetUnderlyingType_mA8FA7F61D3B8E56EB4E40378020FD2854838BDF8 (Type_t* ___0_nullableType, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_ColumnType_m7CC823907CE0417707286D87E8B09356F56B3684_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Type_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Orm_Collation_mDB9DE76216C8D86506F69A62B055D575FA8AC1B6 (MemberInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Collation_m38950A7B621B26E1445DD71BA8EB25310A9625E2_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsPK_mBF1730A4E7ED323706C717DFBC85CE53C37275AC (MemberInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsPK_mF1E6B6A586CB5A6C00E2AC6E9BB2C6B431F1BC2C_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsAutoInc_m126F84B8548B4EFF57C48A1C31AC1E17748F3185 (MemberInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC (Type_t* ___0_left, Type_t* ___1_right, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsAutoGuid_mCC042141DA8E2AC6540F48E80C5A56F8E4A9BD3A_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsAutoGuid_m57F6E41749A0EA41B0045EAAEA737420D91BFDD6_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsAutoInc_mB5E9C07D162A67B47AA22CAD5377FA88FB539957_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Orm_GetIndices_m4296DBD5B13F476E7DB224DFB73E510E0DD9D750 (MemberInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Indices_m3CE76E6C2C8921D734C9A02DEBE747C2F46675A7_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Column_get_Indices_m7031A7B3593A288E9B314065A906D1358FF0580E_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
inline bool Enumerable_Any_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_m437EBE80131A4CD77D4F0924E3E375284C8A074A (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  bool (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_Any_TisRuntimeObject_m67CFBD544CF1D1C0C7E7457FDBDB81649DE26847_gshared)(___0_source, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075 (String_t* __this, String_t* ___0_value, int32_t ___1_comparisonType, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsMarkedNotNull_m2555E838D4C3CB82B522556F01B44449E6368CF0 (MemberInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsNullable_mFFD923C501D7848B8DC14A9B40FB52D729DF8305_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 Orm_MaxStringLength_m6EB8E9A029C0454AA62C8B9FA1B61022A9CDC698 (PropertyInfo_t* ___0_p, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_MaxStringLength_mDFCF47180CF9CB10CFEF5532AF58957C487C4FA1_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MethodInfo_t* PropertyInfo_GetGetMethod_mE0D6C0811D404DD977B53E68C0D36BA8CB889F74 (PropertyInfo_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MethodBase_Invoke_mEEF3218648F111A8C338001A7804091A0747C826 (MethodBase_t* __this, RuntimeObject* ___0_obj, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___1_parameters, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mC12E53D77D3E4A11ABAAB6191DFDA2079F7E4075 (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Column_get_PropertyName_mA027B508D4E518B622B97A7AE61B26DDAB5185A4 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Orm_SqlType_mDCE7980C3A660660D6700F7A4413F090E19959AE (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_p, bool ___1_storeDateTimeAsTicks, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_values, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsNullable_mBA3EFE8EE8CEB4F11EA0AE63AE30E8E27BF3DF7F_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Column_get_Collation_mFCB25D7DEC4A917028AD1119B960797354754FE4_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m093934F71A9B351911EE46311674ED463B180006 (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, String_t* ___3_str3, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 Column_get_MaxStringLength_mAAA93C02B5F68450E5EC2E9106BF6EDBEE367FD1_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) ;
inline bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*, const RuntimeMethod*))Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline)(__this, method);
}
inline int32_t Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*, const RuntimeMethod*))Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* CollationAttribute_get_Value_m8BBDF28DFA2375F6E36CD0CA758954F6E261DC4D_inline (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, const RuntimeMethod* method) ;
inline RuntimeObject* Enumerable_Cast_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_mC71EC946C5A6FCA3956E91CEFEA6AC53497D8F39 (RuntimeObject* ___0_source, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (RuntimeObject*, const RuntimeMethod*))Enumerable_Cast_TisRuntimeObject_m21250FA47CFF08469ACE158D6FA4E1FE11837D29_gshared)(___0_source, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t MaxLengthAttribute_get_Value_m41D0EE4D437B205AAAA56902DB7EFC0176397851_inline (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, const RuntimeMethod* method) ;
inline void Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703 (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, int32_t ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28*, int32_t, const RuntimeMethod*))Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703_gshared)(__this, ___0_value, method);
}
inline void List_1__ctor_mA5F09B5DB35D0EDC340F75E2C9CFB2AE65C81F0F (List_1_tC97D118E4BF4DED562658508050671CE052C65B9* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC97D118E4BF4DED562658508050671CE052C65B9*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteCommand_set_CommandText_mE6FE06C0BEFC9971431441AB6A99E7DDFD0F5203_inline (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool SQLiteConnection_get_Trace_mFF9F2DB848A04CF036DD487904E7DF71837855E2_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteConnection_InvokeTrace_mC117DE5AF32471170B169B09E3D991B952427E49 (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SQLiteConnection_get_SyncObject_mE82D7F8069DEC72A0CDC7119C14222C6D665FED5 (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Monitor_Exit_m05B2CF037E2214B3208198C282490A2A475653FA (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Monitor_Enter_m3CDB589DA1300B513D55FDCFB52B63E879794149 (RuntimeObject* ___0_obj, bool* ___1_lockTaken, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLiteCommand_Prepare_mA2043FB66DB03F52E32B297539A6CE6B11896015 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Step_m47764101C949500F2E1E61DDAF4BCC215C342950 (intptr_t ___0_stmt, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_Finalize_mBB9D4342B1DBFB4D31F6840B8CC48EC596343900 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, intptr_t ___0_stmt, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Changes_m0CA6C84B391B75B9B89D5115175F51D4B81BCEAC (intptr_t ___0_db, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5 (intptr_t ___0_db, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920 (int32_t ___0_r, String_t* ___1_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ExtendedErrCode_mE53EAE79412B17719370EA83EF845896409E4E68 (intptr_t ___0_db, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NotNullConstraintViolationException_t879E7832BFBEBCFCE0B1902526231D755FA83456* NotNullConstraintViolationException_New_mCBE6743A22BAE37F13BC97069BD90D5A197E9128 (int32_t ___0_r, String_t* ___1_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Binding__ctor_m13CB4B80C3F97D812D6E871A671E2EADC50DDEDB (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Name_m6605B567612DDFD3FA9FC4557DD0F03ABE7698F8_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Value_m63DB4E8880807D0480D3ED195430FE33717FBAD0_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
inline void List_1_Add_m51B7F6D3686AE2542AB3B31697069DA12D259BA4_inline (List_1_tC97D118E4BF4DED562658508050671CE052C65B9* __this, Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC97D118E4BF4DED562658508050671CE052C65B9*, Binding_t846C16F3FF76025D82F878E8E00A5894741580FD*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_Bind_mCA6324D7AC057A0934CB8FFA830AD6946E08456E (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, String_t* ___0_name, RuntimeObject* ___1_val, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_mEFA76239AAE09EB0C4E66AB1ED13E2A8C60EAFC2_inline (List_1_tC97D118E4BF4DED562658508050671CE052C65B9* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tC97D118E4BF4DED562658508050671CE052C65B9*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* SQLiteCommand_get_CommandText_mC5B929462D924D4197466FFF1EFBA48B06A6EE12_inline (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) ;
inline Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F (List_1_tC97D118E4BF4DED562658508050671CE052C65B9* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 (*) (List_1_tC97D118E4BF4DED562658508050671CE052C65B9*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_inline (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702* __this, const RuntimeMethod* method)
{
	return ((  Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* (*) (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Binding_get_Value_mC2E67931562F6A62D66038EBEA50BA9395C77785_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344 (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2 (intptr_t ___0_db, String_t* ___1_query, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_BindAll_m611A3B2A51B3D4F0FC695575AC92570671DCE270 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, intptr_t ___0_stmt, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Finalize_m109856BC23FA51D5AE62948F98C9381A9EA08CAC (intptr_t ___0_stmt, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Binding_get_Name_m36460244708DECF7462EC96985049395A01BEE4F_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindParameterIndex_m7E9EAA9E6291ADD9991140E8B9DD82A3AEBCA572 (intptr_t ___0_stmt, String_t* ___1_name, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Index_mD5F67E97A91ED368AF1055F65734E8FA474C3AB1_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Binding_get_Index_m5456E8E974EFC63C021CCF2AD8FC8036E8AA2C91_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool SQLiteConnection_get_StoreDateTimeAsTicks_m4F0D2FE9AD61981FA554273C956E335B1C1F9929_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB (intptr_t ___0_stmt, int32_t ___1_index, RuntimeObject* ___2_value, bool ___3_storeDateTimeAsTicks, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindNull_m9C7AB23E02A0AF38C0ECEE46561509A7BD54862F (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3 (intptr_t ___0_stmt, int32_t ___1_index, int32_t ___2_val, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindText_mEDC93F5CA420D62CE61DC2624453A3C76670056A (intptr_t ___0_stmt, int32_t ___1_index, String_t* ___2_val, int32_t ___3_n, intptr_t ___4_free, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Convert_ToInt32_m9FEA65DB96264479B5268014F10754787382D297 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t Convert_ToInt64_mB980D7B1AB7B7071D416EE892C2B736D712BE1B5 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E (intptr_t ___0_stmt, int32_t ___1_index, int64_t ___2_val, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Convert_ToDouble_m86FF4F837721833186E883102C056A35F0860EB0 (RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindDouble_mEDD937BE65B3E374F9AFCDA8D482F9F1292C4290 (intptr_t ___0_stmt, int32_t ___1_index, double ___2_val, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* DateTime_ToString_m6963A84785C320DA776C9FCFFEDAF26C8F1A8D78 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, String_t* ___0_format, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t DateTimeOffset_get_UtcTicks_mADA0A7B073B9AD2DC81ABC3343382567119D4705 (DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindBlob_mECFD37EFD7AE1CE6A7B5A63D630CC1E15CF1206A (intptr_t ___0_stmt, int32_t ___1_index, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___2_val, int32_t ___3_n, intptr_t ___4_free, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Guid_ToString_m2BFFD5FA726E03FA707AAFCCF065896C46D5290C (Guid_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLite3_ColumnString_mC7495ED684AF170F31724D26EF5BB4EBA78E0E94 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double SQLite3_ColumnDouble_mE4F9CDF44BEF62E61DB8EDB332865923E7B17A7B (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TimeSpan__ctor_m061B122FA11D2063FE751C1F1D019DF1C8B10B1F_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, int64_t ___0_ticks, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, int64_t ___0_ticks, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D DateTime_Parse_m2DE2BF8FC3E6A6FB695ACE7A2D39A812D1D806DB (String_t* ___0_s, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DateTimeOffset__ctor_m81DCBFF0B9D7029AD6B8B80EA4CB8846387DFB9A (DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4* __this, int64_t ___0_ticks, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_offset, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F Decimal_op_Explicit_mC97457D67812EF62FBEC4E9C07E5DCFACAA1FE66 (double ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* SQLite3_ColumnByteArray_m09025DD6AB983E61366EFCB4F1500F7EA24CEC5E (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Guid__ctor_mAE66BA1C43B4194F4F7991E2E30370E36CBBF830 (Guid_t* __this, String_t* ___0_g, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IntPtr__ctor_m20A566609A091311C734617C699E61F545250AC7 (intptr_t* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Connection_mCCBE4206E6F940C3762DDF7EC4E7C75174145E23_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* PreparedSqlLiteInsertCommand_get_CommandText_m1774FAC339AF3EE7649470C4F02912EFED8E9214_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PreparedSqlLiteInsertCommand_get_Initialized_mCA24A887ADAD977158DC4E161DC05D6A0041703B_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Statement_mC87A23AD8B6856E34DC7B2020EA0188AFA737D07_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, intptr_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Initialized_mEE003DDBDE4E99119A83428683D170BBB556ADAB_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E (intptr_t ___0_stmt, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_Dispose_m520FE32389F4CCEFB755F387EEDD744E73B3CC6D (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, bool ___0_disposing, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65 (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Prepare2_m5531D11AAAEFE4C51DB0CF750D4D073930A58019 (intptr_t ___0_db, String_t* ___1_sql, int32_t ___2_numBytes, intptr_t* ___3_stmt, intptr_t ___4_pzTail, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_Errmsg_m6FE2B877839224BC999C20A5D835A6B1103EBD2A (intptr_t ___0_db, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Marshal_PtrToStringUni_mA30F3D8587F2E51F70DF5F30A3C2910CBDAB6F20 (intptr_t ___0_ptr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnName16Internal_m296D10EEB4C133C71292AD9AD27E6032C9E5D760 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnText16_m17C0B6B852576E3369DBF3C8C8F1BA3D7C002254 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnBytes_m79D6917064332E241C14666AC5E17E07782A554B (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnBlob_mB0E992DF4C8C119993796A69B160153D91688D35 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77 (intptr_t ___0_source, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_destination, int32_t ___2_startIndex, int32_t ___3_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Il2CppChar String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3 (String_t* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_open(char*, intptr_t*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_open_v2(char*, intptr_t*, int32_t, intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_open16(Il2CppChar*, intptr_t*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_enable_load_extension(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_close(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_initialize();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_shutdown();
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_config(int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_win32_set_directory(uint32_t, Il2CppChar*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_busy_timeout(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_changes(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_prepare_v2(intptr_t, char*, int32_t, intptr_t*, intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_step(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_reset(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_finalize(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int64_t CDECL sqlite3_last_insert_rowid(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_errmsg16(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_parameter_index(intptr_t, char*);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_null(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_int(intptr_t, int32_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_int64(intptr_t, int32_t, int64_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_double(intptr_t, int32_t, double);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_text16(intptr_t, int32_t, Il2CppChar*, int32_t, intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_bind_blob(intptr_t, int32_t, uint8_t*, int32_t, intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_column_count(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_column_name(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_column_name16(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_column_type(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_column_int(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int64_t CDECL sqlite3_column_int64(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C double CDECL sqlite3_column_double(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_column_text(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_column_text16(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C intptr_t CDECL sqlite3_column_blob(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_column_bytes(intptr_t, int32_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_extended_errcode(intptr_t);
#endif
#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
IL2CPP_EXTERN_C int32_t CDECL sqlite3_libversion_number();
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_Multicast(TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* currentDelegate = reinterpret_cast<TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_message, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_OpenInst(TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, const RuntimeMethod* method)
{
	NullCheck(___0_message);
	typedef void (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_message, method);
}
void TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_OpenStatic(TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_message, method);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F (TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(char*);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	char* ____0_message_marshaled = NULL;
	____0_message_marshaled = il2cpp_codegen_marshal_string(___0_message);

	il2cppPInvokeFunc(____0_message_marshaled);

	il2cpp_codegen_marshal_free(____0_message_marshaled);
	____0_message_marshaled = NULL;

}
// Method Definition Index: 87921
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TraceHandler__ctor_mB5AD602EF2E69BA74DA2B3231271A978628B2CE4 (TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		bool isOpen = parameterCount == 0;
		if (isOpen)
		{
			__this->___invoke_impl = (intptr_t)&TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl = __this->___method_ptr;
			__this->___method_code = (intptr_t)__this->___m_target;
		}
	}
	__this->___extra_arg = (intptr_t)&TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316_Multicast;
}
// Method Definition Index: 87922
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TraceHandler_Invoke_m8E86FA4E2BD373DEECB483F6D9414BDA8467D316 (TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_message, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 87923
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TraceHandler_BeginInvoke_m79AF874B596A36E880B2AA5E1151F7119EC88157 (TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, String_t* ___0_message, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	void *__d_args[2] = {0};
	__d_args[0] = ___0_message;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// Method Definition Index: 87924
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TraceHandler_EndInvoke_m65DF6EDB5346805320752D78FE5B0594B62711B0 (TraceHandler_t6ECA6402D80AC2B4F22437E2509F5695B5270E0F* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977_Multicast(TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* currentDelegate = reinterpret_cast<TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl)((Il2CppObject*)currentDelegate->___method_code, ___0_executionTime, ___1_totalExecutionTime, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method));
	}
}
void TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977_OpenInst(TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_executionTime, ___1_totalExecutionTime, method);
}
void TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977_OpenStatic(TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr)(___0_executionTime, ___1_totalExecutionTime, method);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1 (TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	il2cppPInvokeFunc(___0_executionTime, ___1_totalExecutionTime);

}
// Method Definition Index: 87925
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimeExecutionHandler__ctor_m4B1EBC347B6CB67A35A4B3FB27048E9E55D4B3FA (TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr = (intptr_t)il2cpp_codegen_get_method_pointer((RuntimeMethod*)___1_method);
	__this->___method = ___1_method;
	__this->___m_target = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (isOpen)
			__this->___invoke_impl = (intptr_t)&TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977_OpenStatic;
		else
			{
				__this->___invoke_impl = __this->___method_ptr;
				__this->___method_code = (intptr_t)__this->___m_target;
			}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl = __this->___method_ptr;
		__this->___method_code = (intptr_t)__this->___m_target;
	}
	__this->___extra_arg = (intptr_t)&TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977_Multicast;
}
// Method Definition Index: 87926
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimeExecutionHandler_Invoke_m850DD21DF5D0F96F054397CA0DE3399C46C88977 (TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_executionTime, ___1_totalExecutionTime, reinterpret_cast<RuntimeMethod*>(__this->___method));
}
// Method Definition Index: 87927
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* TimeExecutionHandler_BeginInvoke_m58F1992D8E71C4390C1D82B5C2F6666E9325DCC3 (TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___0_executionTime, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___1_totalExecutionTime, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___2_callback, RuntimeObject* ___3_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[3] = {0};
	__d_args[0] = Box(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var, &___0_executionTime);
	__d_args[1] = Box(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var, &___1_totalExecutionTime);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___2_callback, (RuntimeObject*)___3_object);
}
// Method Definition Index: 87928
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TimeExecutionHandler_EndInvoke_m4ECC9C0308AFCDBC005E27480D7F69590FA6CB87 (TimeExecutionHandler_t9D72C644BA49F80C9F8F861BB8C4D82F4659AEE1* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_pinvoke(const IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813& unmarshaled, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_pinvoke& marshaled)
{
	marshaled.___Order = unmarshaled.___Order;
	marshaled.___ColumnName = il2cpp_codegen_marshal_string(unmarshaled.___ColumnName);
}
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_pinvoke_back(const IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_pinvoke& marshaled, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813& unmarshaled)
{
	int32_t unmarshaledOrder_temp_0 = 0;
	unmarshaledOrder_temp_0 = marshaled.___Order;
	unmarshaled.___Order = unmarshaledOrder_temp_0;
	unmarshaled.___ColumnName = il2cpp_codegen_marshal_string_result(marshaled.___ColumnName);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___ColumnName), (void*)il2cpp_codegen_marshal_string_result(marshaled.___ColumnName));
}
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_pinvoke_cleanup(IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_marshal_free(marshaled.___ColumnName);
	marshaled.___ColumnName = NULL;
}
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_com(const IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813& unmarshaled, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_com& marshaled)
{
	marshaled.___Order = unmarshaled.___Order;
	marshaled.___ColumnName = il2cpp_codegen_marshal_bstring(unmarshaled.___ColumnName);
}
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_com_back(const IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_com& marshaled, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813& unmarshaled)
{
	int32_t unmarshaledOrder_temp_0 = 0;
	unmarshaledOrder_temp_0 = marshaled.___Order;
	unmarshaled.___Order = unmarshaledOrder_temp_0;
	unmarshaled.___ColumnName = il2cpp_codegen_marshal_bstring_result(marshaled.___ColumnName);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___ColumnName), (void*)il2cpp_codegen_marshal_bstring_result(marshaled.___ColumnName));
}
IL2CPP_EXTERN_C void IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshal_com_cleanup(IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813_marshaled_com& marshaled)
{
	il2cpp_codegen_marshal_free_bstring(marshaled.___ColumnName);
	marshaled.___ColumnName = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_pinvoke(const IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8& unmarshaled, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_pinvoke& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___ColumnsException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___ColumnsException, NULL);
}
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_pinvoke_back(const IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_pinvoke& marshaled, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___ColumnsException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___ColumnsException, NULL);
}
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_pinvoke_cleanup(IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_com(const IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8& unmarshaled, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_com& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___ColumnsException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___ColumnsException, NULL);
}
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_com_back(const IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_com& marshaled, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___ColumnsException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s'.", IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8____Columns_FieldInfo_var, IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___ColumnsException, NULL);
}
IL2CPP_EXTERN_C void IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshal_com_cleanup(IndexInfo_t130EB73FEDB0A44572B2EAE47B93D8012DD4CAD8_marshaled_com& marshaled)
{
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 87929
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ColumnInfo_get_Name_m58406BCC746124ACF825EC2F71A33EC51EA787E2 (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:563>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87930
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ColumnInfo_set_Name_mEAB01B2C4036920F552D161024D39EA8ABEC4E30 (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:563>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87931
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t ColumnInfo_get_notnull_m9235EC7BCF9972BE205E6DBDDD779F5D9F57793E (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:568>
		int32_t L_0 = __this->___U3CnotnullU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87932
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ColumnInfo_set_notnull_m8F12A793A394E9CC6C60DC0C801B206B997C4320 (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:568>
		int32_t L_0 = ___0_value;
		__this->___U3CnotnullU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87933
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ColumnInfo_ToString_m0B6AAD03107CA9A6F833FD859BC952844596A73B (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:576>
		String_t* L_0;
		L_0 = ColumnInfo_get_Name_m58406BCC746124ACF825EC2F71A33EC51EA787E2_inline(__this, NULL);
		return L_0;
	}
}
// Method Definition Index: 87934
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ColumnInfo__ctor_mBC11D4A3290354C03D77431E67ABDD6653799516 (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 87935
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_mB93FF7EEAFA85240352AD7F57D4DA2A9C13590D8 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* L_0 = (U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81*)il2cpp_codegen_object_new(U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_il2cpp_TypeInfo_var);
		U3CU3Ec__ctor_m313E56F7E0112B6C9ED9C8E4FEA00A3A5D5C4E80(L_0, NULL);
		((U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_il2cpp_TypeInfo_var))->___U3CU3E9 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81_il2cpp_TypeInfo_var))->___U3CU3E9), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87936
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_m313E56F7E0112B6C9ED9C8E4FEA00A3A5D5C4E80 (U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87937
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t U3CU3Ec_U3CCreateTableU3Eb__60_1_m3F48E90E5E0CE5941E5D1896D9C0D6440C62B139 (U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* __this, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813 ___0_lhs, IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813 ___1_rhs, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:466>
		IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813 L_0 = ___0_lhs;
		int32_t L_1 = L_0.___Order;
		IndexedColumn_tA7D07048558F90E3A50CD8558495ABDC1AA9F813 L_2 = ___1_rhs;
		int32_t L_3 = L_2.___Order;
		return ((int32_t)il2cpp_codegen_subtract(L_1, L_3));
	}
}
// Method Definition Index: 87938
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* U3CU3Ec_U3CUpdateU3Eb__105_2_mA2CB6A7DAAD2ECE5C417869FFF2652D2379A1B6C (U3CU3Ec_t3003A0284D9289722D32F9D0189CACFC3CF56B81* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral087915F54405AD1B7F0E6ADFE8D41FB99BBC5929);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1437>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(L_0, NULL);
		String_t* L_2;
		L_2 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677, L_1, _stringLiteral087915F54405AD1B7F0E6ADFE8D41FB99BBC5929, NULL);
		return L_2;
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
// Method Definition Index: 87939
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass105_0__ctor_mFA3AF3418D81955B1925B5A11011D8330BC73426 (U3CU3Ec__DisplayClass105_0_t8E67D00FCA72EDFB9CAB00662760929AAAA2F274* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87940
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec__DisplayClass105_0_U3CUpdateU3Eb__0_m9B8590A6566FDA98D2730B17A5E79D4CDCBA0EB6 (U3CU3Ec__DisplayClass105_0_t8E67D00FCA72EDFB9CAB00662760929AAAA2F274* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_p, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1430>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_p;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_1 = __this->___pk;
		return (bool)((((int32_t)((((RuntimeObject*)(Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671*)L_0) == ((RuntimeObject*)(Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671*)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 87941
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* U3CU3Ec__DisplayClass105_0_U3CUpdateU3Eb__1_m93B1377F565A7DEECE77B4E10C2D25DFD66DABD8 (U3CU3Ec__DisplayClass105_0_t8E67D00FCA72EDFB9CAB00662760929AAAA2F274* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1433>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		RuntimeObject* L_1 = __this->___obj;
		NullCheck(L_0);
		RuntimeObject* L_2;
		L_2 = Column_GetValue_mC41975E43F1AAF075BC3B67C1BADF8B4B7DEB0EF(L_0, L_1, NULL);
		return L_2;
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
// Method Definition Index: 87942
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass106_0__ctor_mDC49846B1FB1F2C29A65448AE311F0D9B50F0256 (U3CU3Ec__DisplayClass106_0_tCCA41F62B5EA6FC5618E0CC020ADB2165A043E97* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87943
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass106_0_U3CUpdateAllU3Eb__0_m619957A15739A6DE1D4D53156221EEFEE5D5011B (U3CU3Ec__DisplayClass106_0_tCCA41F62B5EA6FC5618E0CC020ADB2165A043E97* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1467>
		RuntimeObject* L_0 = __this->___objects;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0038:
			{
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_0048;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_0048:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_002e_1;
			}

IL_000e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1467>
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = L_6;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1468>
				int32_t L_7 = __this->___c;
				SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_8 = __this->___U3CU3E4__this;
				RuntimeObject* L_9 = V_1;
				NullCheck(L_8);
				int32_t L_10;
				L_10 = SQLiteConnection_Update_m56A254715412DE09139E61F8AEF503FDEC1E5212(L_8, L_9, NULL);
				__this->___c = ((int32_t)il2cpp_codegen_add(L_7, L_10));
			}

IL_002e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1467>
				RuntimeObject* L_11 = V_0;
				NullCheck(L_11);
				bool L_12;
				L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_11);
				if (L_12)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_0049;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0049:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1470>
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
// Method Definition Index: 87944
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass95_0__ctor_m175301C3C2F61E851B1E1689A82C28F12A3F801F (U3CU3Ec__DisplayClass95_0_t60206737D176DC76F28DCB8EC7DF4E6C06EE5D8A* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87945
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass95_0_U3CInsertAllU3Eb__0_m1C426B4058363C24150D1167440BC7D06D54E563 (U3CU3Ec__DisplayClass95_0_t60206737D176DC76F28DCB8EC7DF4E6C06EE5D8A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1138>
		RuntimeObject* L_0 = __this->___objects;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0038:
			{
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_0048;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_0048:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_002e_1;
			}

IL_000e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1138>
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = L_6;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1139>
				int32_t L_7 = __this->___c;
				SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_8 = __this->___U3CU3E4__this;
				RuntimeObject* L_9 = V_1;
				NullCheck(L_8);
				int32_t L_10;
				L_10 = SQLiteConnection_Insert_mB63605D430E8D23EC2BA531AE12220491EFB09CD(L_8, L_9, NULL);
				__this->___c = ((int32_t)il2cpp_codegen_add(L_7, L_10));
			}

IL_002e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1138>
				RuntimeObject* L_11 = V_0;
				NullCheck(L_11);
				bool L_12;
				L_12 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_11);
				if (L_12)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_0049;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0049:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1141>
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
// Method Definition Index: 87946
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass96_0__ctor_m945A63A7A70654D3F0270FBBF7C9992A6D4A89F4 (U3CU3Ec__DisplayClass96_0_t527EA7B759880603FA94E43D3EFF38F94C04DC91* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87947
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass96_0_U3CInsertAllU3Eb__0_mC82BF8711EBC5CF454AE2DA81AB28E71964801DB (U3CU3Ec__DisplayClass96_0_t527EA7B759880603FA94E43D3EFF38F94C04DC91* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1161>
		RuntimeObject* L_0 = __this->___objects;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_003e:
			{
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_004e;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_004e:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0034_1;
			}

IL_000e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1161>
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = L_6;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1162>
				int32_t L_7 = __this->___c;
				SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_8 = __this->___U3CU3E4__this;
				RuntimeObject* L_9 = V_1;
				String_t* L_10 = __this->___extra;
				NullCheck(L_8);
				int32_t L_11;
				L_11 = SQLiteConnection_Insert_mE3483091067DEF6AADCB8DAFAA2C4D3C4AB84C3F(L_8, L_9, L_10, NULL);
				__this->___c = ((int32_t)il2cpp_codegen_add(L_7, L_11));
			}

IL_0034_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1161>
				RuntimeObject* L_12 = V_0;
				NullCheck(L_12);
				bool L_13;
				L_13 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_12);
				if (L_13)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_004f;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_004f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1164>
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
// Method Definition Index: 87948
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass97_0__ctor_m211A9713964056959F85ADDB01B686417AE00C98 (U3CU3Ec__DisplayClass97_0_t7DD496E8120D85C5BD65C1D718EBC656A5139846* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 87949
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass97_0_U3CInsertAllU3Eb__0_mB6AADEDB828DE54812679E3B2080B28F149045D8 (U3CU3Ec__DisplayClass97_0_t7DD496E8120D85C5BD65C1D718EBC656A5139846* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1184>
		RuntimeObject* L_0 = __this->___objects;
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_003e:
			{
				{
					RuntimeObject* L_2 = V_0;
					V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var));
					RuntimeObject* L_3 = V_2;
					if (!L_3)
					{
						goto IL_004e;
					}
				}
				{
					RuntimeObject* L_4 = V_2;
					NullCheck(L_4);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_4);
				}

IL_004e:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0034_1;
			}

IL_000e_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1184>
				RuntimeObject* L_5 = V_0;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_5);
				V_1 = L_6;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1185>
				int32_t L_7 = __this->___c;
				SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_8 = __this->___U3CU3E4__this;
				RuntimeObject* L_9 = V_1;
				Type_t* L_10 = __this->___objType;
				NullCheck(L_8);
				int32_t L_11;
				L_11 = SQLiteConnection_Insert_m27C8D61DF252C83AF70E8DAF37713A5F5140DAAC(L_8, L_9, L_10, NULL);
				__this->___c = ((int32_t)il2cpp_codegen_add(L_7, L_11));
			}

IL_0034_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1184>
				RuntimeObject* L_12 = V_0;
				NullCheck(L_12);
				bool L_13;
				L_13 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_12);
				if (L_13)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_004f;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_004f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1187>
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
// Method Definition Index: 87950
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLiteConnectionString_get_ConnectionString_m2EA2380E5D4DFE0202BA63DC16075E330925BC6B (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1579>
		String_t* L_0 = __this->___U3CConnectionStringU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87951
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_ConnectionString_m86572BCB05C4F3AB9ADB3847FAECFB4B55A97876 (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1579>
		String_t* L_0 = ___0_value;
		__this->___U3CConnectionStringU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CConnectionStringU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87952
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLiteConnectionString_get_DatabasePath_m2D747D91AD882B1B0AFD68D6C6D27CA8741560C3 (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1580>
		String_t* L_0 = __this->___U3CDatabasePathU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87953
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_DatabasePath_mE625A3627858ECFC73B7F530C066CE3C83716BC0 (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1580>
		String_t* L_0 = ___0_value;
		__this->___U3CDatabasePathU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CDatabasePathU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87954
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool SQLiteConnectionString_get_StoreDateTimeAsTicks_m7AEE221792DEC2B3BC981FDEE516B58E2410CE9D (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1581>
		bool L_0 = __this->___U3CStoreDateTimeAsTicksU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87955
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_StoreDateTimeAsTicks_mE61C0DD29C9985A25FBCDEBF7BF43389C5E69C23 (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1581>
		bool L_0 = ___0_value;
		__this->___U3CStoreDateTimeAsTicksU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87956
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteConnectionString__ctor_m6F801F49429561BA08DF50ED0963E55A09ECF740 (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_databasePath, bool ___1_storeDateTimeAsTicks, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1587>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1589>
		String_t* L_0 = ___0_databasePath;
		SQLiteConnectionString_set_ConnectionString_m86572BCB05C4F3AB9ADB3847FAECFB4B55A97876_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1590>
		bool L_1 = ___1_storeDateTimeAsTicks;
		SQLiteConnectionString_set_StoreDateTimeAsTicks_mE61C0DD29C9985A25FBCDEBF7BF43389C5E69C23_inline(__this, L_1, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1595>
		String_t* L_2 = ___0_databasePath;
		SQLiteConnectionString_set_DatabasePath_mE625A3627858ECFC73B7F530C066CE3C83716BC0_inline(__this, L_2, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1597>
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
// Method Definition Index: 87957
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TableAttribute_get_Name_m28941E0E3D074B4D9AC32C13886B62B9678EB7C1 (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1603>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87958
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableAttribute_set_Name_m1BE9470AE2BA2E3BAD9694E4E1B78E19E8212984 (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1603>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87959
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableAttribute__ctor_m7F0937483FE57EAFC6551F053052D3884C894DA4 (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1605>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1607>
		String_t* L_0 = ___0_name;
		TableAttribute_set_Name_m1BE9470AE2BA2E3BAD9694E4E1B78E19E8212984_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1608>
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
// Method Definition Index: 87960
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ColumnAttribute_get_Name_m77A6DCA8A8508839AAF308D8A8FAFB0AE02E56B6 (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1614>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87961
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ColumnAttribute_set_Name_mE3122C2539DE916052E72CC9E7971B96234FE023 (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1614>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87962
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ColumnAttribute__ctor_m8F096173B17D0873E1F18AEB03159F1AC70D6D73 (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1616>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1618>
		String_t* L_0 = ___0_name;
		ColumnAttribute_set_Name_mE3122C2539DE916052E72CC9E7971B96234FE023_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1619>
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
// Method Definition Index: 87963
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PrimaryKeyAttribute__ctor_m1B5ABDB6CFD05EE382AE4FECBC285A685A322FCE (PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1* __this, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
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
// Method Definition Index: 87964
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AutoIncrementAttribute__ctor_mD3B084DE7A762DCB582705486B57A39F1CFDFC38 (AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F* __this, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
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
// Method Definition Index: 87965
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* IndexedAttribute_get_Name_m0502FBE35D490AD806F760DBBBCD7BD6EF916267 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1635>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87966
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute_set_Name_mC9D9DA8C0FD3BD0CFC098D113AD0C38863EAC898 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1635>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87967
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IndexedAttribute_get_Order_m629769800888BE772C43501B9C7C82B62804A85B (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1636>
		int32_t L_0 = __this->___U3COrderU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87968
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute_set_Order_mBB0C74DD1D10DBBBA79A98C9798E3000312E3C57 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1636>
		int32_t L_0 = ___0_value;
		__this->___U3COrderU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87969
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IndexedAttribute_get_Unique_m25A846BC2B302CA9A0376B11618C700AA1727034 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1637>
		bool L_0 = __this->___U3CUniqueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87970
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute_set_Unique_m30827EC5B7FCDF41A08A91BE3DBB9D809690B031 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1637>
		bool L_0 = ___0_value;
		__this->___U3CUniqueU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87971
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute__ctor_m536933E83B03CE758EFBEE9F11E4B537DE1E75D6 (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1639>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1641>
		return;
	}
}
// Method Definition Index: 87972
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexedAttribute__ctor_mF5A696DB87387DF433EA71AB7F7DD8739BAAC26A (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, String_t* ___0_name, int32_t ___1_order, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1643>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1645>
		String_t* L_0 = ___0_name;
		IndexedAttribute_set_Name_mC9D9DA8C0FD3BD0CFC098D113AD0C38863EAC898_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1646>
		int32_t L_1 = ___1_order;
		IndexedAttribute_set_Order_mBB0C74DD1D10DBBBA79A98C9798E3000312E3C57_inline(__this, L_1, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1647>
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
// Method Definition Index: 87973
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IgnoreAttribute__ctor_mF4FF4FF58C8107CE9A844DEEE162D2CE37258AC7 (IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2* __this, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
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
// Method Definition Index: 87974
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool UniqueAttribute_get_Unique_m9C26295FB4E84575B879D5489109E85F8F7EE785 (UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1659>
		return (bool)1;
	}
}
// Method Definition Index: 87975
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniqueAttribute_set_Unique_m1F08B2771DCA98A680A5753B5A63420F0D081DFD (UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1660>
		return;
	}
}
// Method Definition Index: 87976
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniqueAttribute__ctor_mCDAB270D9BDBE539F1DE0D8CE2527E94ECB34068 (UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1663>
		IndexedAttribute__ctor_m536933E83B03CE758EFBEE9F11E4B537DE1E75D6(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1665>
		return;
	}
}
// Method Definition Index: 87977
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UniqueAttribute__ctor_mA53BC4F63B71FABD52A2B01665505E3EC57D598B (UniqueAttribute_t07585A11D474DA2B91085A538967C34503D33089* __this, String_t* ___0_name, int32_t ___1_order, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1667>
		String_t* L_0 = ___0_name;
		int32_t L_1 = ___1_order;
		IndexedAttribute__ctor_mF5A696DB87387DF433EA71AB7F7DD8739BAAC26A(__this, L_0, L_1, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1669>
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
// Method Definition Index: 87978
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t MaxLengthAttribute_get_Value_m41D0EE4D437B205AAAA56902DB7EFC0176397851 (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1675>
		int32_t L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87979
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MaxLengthAttribute_set_Value_m769CB0382163AFC0547A8237C646995EFA1EBC29 (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1675>
		int32_t L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87980
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MaxLengthAttribute__ctor_mE4E0A4268B04BC5A66A380D893411D7D78514FD1 (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, int32_t ___0_length, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1677>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1679>
		int32_t L_0 = ___0_length;
		MaxLengthAttribute_set_Value_m769CB0382163AFC0547A8237C646995EFA1EBC29_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1680>
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
// Method Definition Index: 87981
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* CollationAttribute_get_Value_m8BBDF28DFA2375F6E36CD0CA758954F6E261DC4D (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1686>
		String_t* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87982
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CollationAttribute_set_Value_m879958EE7A8C28BEE1D60FF7F57DF65736377F0A (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1686>
		String_t* L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CValueU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87983
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CollationAttribute__ctor_m74171777F23B90780F7779918B268060020CF7C9 (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, String_t* ___0_collation, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1688>
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1690>
		String_t* L_0 = ___0_collation;
		CollationAttribute_set_Value_m879958EE7A8C28BEE1D60FF7F57DF65736377F0A_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1691>
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
// Method Definition Index: 87984
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotNullAttribute__ctor_m44569D9884F78B44899997D60465826DF8837527 (NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5* __this, const RuntimeMethod* method) 
{
	{
		Attribute__ctor_m79ED1BF1EE36D1E417BA89A0D9F91F8AAD8D19E2(__this, NULL);
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
// Method Definition Index: 87985
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* TableMapping_get_MappedType_mEFC30D7C1A5CA7FE335BD3EA01B759170A16B6FA (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1701>
		Type_t* L_0 = __this->___U3CMappedTypeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87986
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_MappedType_mD0220B466756EA9D6E96E80B7DABDC5136638832 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1701>
		Type_t* L_0 = ___0_value;
		__this->___U3CMappedTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMappedTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87987
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1703>
		String_t* L_0 = __this->___U3CTableNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87988
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_TableName_m74BB32CC2B1F03EB818461E7B8B7608E443D05A5 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1703>
		String_t* L_0 = ___0_value;
		__this->___U3CTableNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CTableNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87989
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1705>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = __this->___U3CColumnsU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87990
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_Columns_mB809C3C4C606ABECA6A7C39817E85C49E0580871 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1705>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = ___0_value;
		__this->___U3CColumnsU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CColumnsU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87991
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* TableMapping_get_PK_m60262F211F1A2F9C31183BBD63849106D0D2A76E (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1707>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = __this->___U3CPKU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87992
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_PK_m65E0749BAD788A1FE4087774C2EB2DE22E2DD6F7 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1707>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_value;
		__this->___U3CPKU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPKU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87993
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* TableMapping_get_GetByPrimaryKeySql_m6F97EEA5C4CE0564FA1C4DA9C81CCFD85CD4CEF5 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1709>
		String_t* L_0 = __this->___U3CGetByPrimaryKeySqlU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87994
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_GetByPrimaryKeySql_m2E681BF7B6CC67FDF742C2F8FC721A23C28A8215 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1709>
		String_t* L_0 = ___0_value;
		__this->___U3CGetByPrimaryKeySqlU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CGetByPrimaryKeySqlU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87995
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping__ctor_m0906A126548666E53A39E4599DD45B87A7B0A622 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Type_t* ___0_type, int32_t ___1_createFlags, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m7BF2A509F39D61CA112B7EAD8999D35EE56D6C8F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_ToArray_m27A3A30821E452F09439851819E7DA5612C828E3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mE9E8FCA661D879A24A1C832D63E9254F4375EA0D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t76F9611073289221FD689EB9CF04C021C23B2186_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B1AA9B29EF545DBB7671B2694E3D4F830F07300);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF57B369204E09200EF1244FE1DC17C91C4CE8B44);
		s_Il2CppMethodInitialized = true;
	}
	TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* V_0 = NULL;
	List_1_t76F9611073289221FD689EB9CF04C021C23B2186* V_1 = NULL;
	PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7* V_2 = NULL;
	int32_t V_3 = 0;
	PropertyInfo_t* V_4 = NULL;
	bool V_5 = false;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* V_6 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* V_7 = NULL;
	TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* G_B2_0 = NULL;
	TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* G_B3_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1715>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1717>
		Type_t* L_0 = ___0_type;
		TableMapping_set_MappedType_mD0220B466756EA9D6E96E80B7DABDC5136638832_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1723>
		Type_t* L_1 = ___0_type;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		NullCheck(L_1);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4;
		L_4 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_1, L_3, (bool)1);
		RuntimeObject* L_5;
		L_5 = Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD((RuntimeObject*)L_4, Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_RuntimeMethod_var);
		V_0 = ((TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534*)CastclassClass((RuntimeObject*)L_5, TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534_il2cpp_TypeInfo_var));
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1726>
		TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* L_6 = V_0;
		if (L_6)
		{
			G_B2_0 = __this;
			goto IL_003a;
		}
		G_B1_0 = __this;
	}
	{
		Type_t* L_7;
		L_7 = TableMapping_get_MappedType_mEFC30D7C1A5CA7FE335BD3EA01B759170A16B6FA_inline(__this, NULL);
		NullCheck(L_7);
		String_t* L_8;
		L_8 = VirtualFuncInvoker0< String_t* >::Invoke(8, L_7);
		G_B3_0 = L_8;
		G_B3_1 = G_B1_0;
		goto IL_0040;
	}

IL_003a:
	{
		TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* L_9 = V_0;
		NullCheck(L_9);
		String_t* L_10;
		L_10 = TableAttribute_get_Name_m28941E0E3D074B4D9AC32C13886B62B9678EB7C1_inline(L_9, NULL);
		G_B3_0 = L_10;
		G_B3_1 = G_B2_0;
	}

IL_0040:
	{
		NullCheck(G_B3_1);
		TableMapping_set_TableName_m74BB32CC2B1F03EB818461E7B8B7608E443D05A5_inline(G_B3_1, G_B3_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1729>
		Type_t* L_11;
		L_11 = TableMapping_get_MappedType_mEFC30D7C1A5CA7FE335BD3EA01B759170A16B6FA_inline(__this, NULL);
		NullCheck(L_11);
		PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7* L_12;
		L_12 = VirtualFuncInvoker1< PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7*, int32_t >::Invoke(111, L_11, ((int32_t)8212));
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1735>
		List_1_t76F9611073289221FD689EB9CF04C021C23B2186* L_13 = (List_1_t76F9611073289221FD689EB9CF04C021C23B2186*)il2cpp_codegen_object_new(List_1_t76F9611073289221FD689EB9CF04C021C23B2186_il2cpp_TypeInfo_var);
		List_1__ctor_mE9E8FCA661D879A24A1C832D63E9254F4375EA0D(L_13, List_1__ctor_mE9E8FCA661D879A24A1C832D63E9254F4375EA0D_RuntimeMethod_var);
		V_1 = L_13;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1736>
		V_2 = L_12;
		V_3 = 0;
		goto IL_009c;
	}

IL_0060:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1736>
		PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7* L_14 = V_2;
		int32_t L_15 = V_3;
		NullCheck(L_14);
		int32_t L_16 = L_15;
		PropertyInfo_t* L_17 = (L_14)->GetAt(static_cast<il2cpp_array_size_t>(L_16));
		V_4 = L_17;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1738>
		PropertyInfo_t* L_18 = V_4;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (IgnoreAttribute_tA2AB36495CD8F5A5828E6F023AD78A693D0694A2_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		NullCheck(L_18);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_21;
		L_21 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_18, L_20, (bool)1);
		NullCheck(L_21);
		V_5 = (bool)((!(((uint32_t)(((RuntimeArray*)L_21)->max_length)) <= ((uint32_t)0)))? 1 : 0);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1742>
		PropertyInfo_t* L_22 = V_4;
		NullCheck(L_22);
		bool L_23;
		L_23 = VirtualFuncInvoker0< bool >::Invoke(19, L_22);
		if (!L_23)
		{
			goto IL_0098;
		}
	}
	{
		bool L_24 = V_5;
		if (L_24)
		{
			goto IL_0098;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1743>
		List_1_t76F9611073289221FD689EB9CF04C021C23B2186* L_25 = V_1;
		PropertyInfo_t* L_26 = V_4;
		int32_t L_27 = ___1_createFlags;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_28 = (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671*)il2cpp_codegen_object_new(Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671_il2cpp_TypeInfo_var);
		Column__ctor_m8C177984EBE01667C7E935F00904E889933F18B9(L_28, L_26, L_27, NULL);
		NullCheck(L_25);
		List_1_Add_m7BF2A509F39D61CA112B7EAD8999D35EE56D6C8F_inline(L_25, L_28, List_1_Add_m7BF2A509F39D61CA112B7EAD8999D35EE56D6C8F_RuntimeMethod_var);
	}

IL_0098:
	{
		int32_t L_29 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_29, 1));
	}

IL_009c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1736>
		int32_t L_30 = V_3;
		PropertyInfoU5BU5D_tD81C248B41D0C76207C42DB9C332DC79F490B1D7* L_31 = V_2;
		NullCheck(L_31);
		if ((((int32_t)L_30) < ((int32_t)((int32_t)(((RuntimeArray*)L_31)->max_length)))))
		{
			goto IL_0060;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1746>
		List_1_t76F9611073289221FD689EB9CF04C021C23B2186* L_32 = V_1;
		NullCheck(L_32);
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_33;
		L_33 = List_1_ToArray_m27A3A30821E452F09439851819E7DA5612C828E3(L_32, List_1_ToArray_m27A3A30821E452F09439851819E7DA5612C828E3_RuntimeMethod_var);
		TableMapping_set_Columns_mB809C3C4C606ABECA6A7C39817E85C49E0580871_inline(__this, L_33, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1747>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_34;
		L_34 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		V_6 = L_34;
		V_3 = 0;
		goto IL_00ef;
	}

IL_00ba:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1747>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_35 = V_6;
		int32_t L_36 = V_3;
		NullCheck(L_35);
		int32_t L_37 = L_36;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_38 = (L_35)->GetAt(static_cast<il2cpp_array_size_t>(L_37));
		V_7 = L_38;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1748>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_39 = V_7;
		NullCheck(L_39);
		bool L_40;
		L_40 = Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline(L_39, NULL);
		if (!L_40)
		{
			goto IL_00da;
		}
	}
	{
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_41 = V_7;
		NullCheck(L_41);
		bool L_42;
		L_42 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(L_41, NULL);
		if (!L_42)
		{
			goto IL_00da;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1749>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_43 = V_7;
		__this->____autoPk = L_43;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____autoPk), (void*)L_43);
	}

IL_00da:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1751>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_44 = V_7;
		NullCheck(L_44);
		bool L_45;
		L_45 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(L_44, NULL);
		if (!L_45)
		{
			goto IL_00eb;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1752>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_46 = V_7;
		TableMapping_set_PK_m65E0749BAD788A1FE4087774C2EB2DE22E2DD6F7_inline(__this, L_46, NULL);
	}

IL_00eb:
	{
		int32_t L_47 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_47, 1));
	}

IL_00ef:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1747>
		int32_t L_48 = V_3;
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_49 = V_6;
		NullCheck(L_49);
		if ((((int32_t)L_48) < ((int32_t)((int32_t)(((RuntimeArray*)L_49)->max_length)))))
		{
			goto IL_00ba;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1756>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_50 = __this->____autoPk;
		TableMapping_set_HasAutoIncPK_m11254701AD04373CFD39137AB076C7735E6F1FF0_inline(__this, (bool)((!(((RuntimeObject*)(Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671*)L_50) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0), NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1758>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_51;
		L_51 = TableMapping_get_PK_m60262F211F1A2F9C31183BBD63849106D0D2A76E_inline(__this, NULL);
		if (!L_51)
		{
			goto IL_012f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1759>
		String_t* L_52;
		L_52 = TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline(__this, NULL);
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_53;
		L_53 = TableMapping_get_PK_m60262F211F1A2F9C31183BBD63849106D0D2A76E_inline(__this, NULL);
		NullCheck(L_53);
		String_t* L_54;
		L_54 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(L_53, NULL);
		String_t* L_55;
		L_55 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral0B1AA9B29EF545DBB7671B2694E3D4F830F07300, L_52, L_54, NULL);
		TableMapping_set_GetByPrimaryKeySql_m2E681BF7B6CC67FDF742C2F8FC721A23C28A8215_inline(__this, L_55, NULL);
		return;
	}

IL_012f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1763>
		String_t* L_56;
		L_56 = TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline(__this, NULL);
		String_t* L_57;
		L_57 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteralF57B369204E09200EF1244FE1DC17C91C4CE8B44, L_56, NULL);
		TableMapping_set_GetByPrimaryKeySql_m2E681BF7B6CC67FDF742C2F8FC721A23C28A8215_inline(__this, L_57, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1765>
		return;
	}
}
// Method Definition Index: 87996
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool TableMapping_get_HasAutoIncPK_mA730845D302D410182560567262D34419FDBDA65 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1767>
		bool L_0 = __this->___U3CHasAutoIncPKU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87997
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_set_HasAutoIncPK_m11254701AD04373CFD39137AB076C7735E6F1FF0 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1767>
		bool L_0 = ___0_value;
		__this->___U3CHasAutoIncPKU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87998
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_SetAutoIncPK_mACCEE4F1548ACC3E6FCB24611E891BE9E03EB468 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, RuntimeObject* ___0_obj, int64_t ___1_id, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1771>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = __this->____autoPk;
		if (!L_0)
		{
			goto IL_002b;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1772>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_1 = __this->____autoPk;
		RuntimeObject* L_2 = ___0_obj;
		int64_t L_3 = ___1_id;
		int64_t L_4 = L_3;
		RuntimeObject* L_5 = Box(il2cpp_defaults.int64_class, &L_4);
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_6 = __this->____autoPk;
		NullCheck(L_6);
		Type_t* L_7;
		L_7 = Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39_inline(L_6, NULL);
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		RuntimeObject* L_8;
		L_8 = Convert_ChangeType_m2AA053891B5D1BD5CA7689B72EE5ADC95CD3E14B(L_5, L_7, (RuntimeObject*)NULL, NULL);
		NullCheck(L_1);
		Column_SetValue_m2C03ECE0FF590C829C366FEC3BB3007D1804266E(L_1, L_2, L_8, NULL);
	}

IL_002b:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1774>
		return;
	}
}
// Method Definition Index: 87999
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_InsertColumns_mD397D5E0041FCB77305768E1F09F667CBC8F8195 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Where_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m42628461F47BB2F46D2F0ED015117BCB0A5965EC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3Cget_InsertColumnsU3Eb__30_0_mC65BE356215F8AC4CC235F9BE4C98C4534B8B937_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* G_B3_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B3_1 = NULL;
	TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* G_B3_2 = NULL;
	Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* G_B2_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B2_1 = NULL;
	TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* G_B2_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1778>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = __this->____insertColumns;
		if (L_0)
		{
			goto IL_003d;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1779>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_1;
		L_1 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_2 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__30_0;
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_3 = L_2;
		if (L_3)
		{
			G_B3_0 = L_3;
			G_B3_1 = L_1;
			G_B3_2 = __this;
			goto IL_002e;
		}
		G_B2_0 = L_3;
		G_B2_1 = L_1;
		G_B2_2 = __this;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* L_4 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9;
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_5 = (Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*)il2cpp_codegen_object_new(Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		Func_2__ctor_m7A4C94ED93BA348E3167A682E87E59364CAFA3D3(L_5, L_4, (intptr_t)((void*)U3CU3Ec_U3Cget_InsertColumnsU3Eb__30_0_mC65BE356215F8AC4CC235F9BE4C98C4534B8B937_RuntimeMethod_var), NULL);
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_6 = L_5;
		((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__30_0 = L_6;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__30_0), (void*)L_6);
		G_B3_0 = L_6;
		G_B3_1 = G_B2_1;
		G_B3_2 = G_B2_2;
	}

IL_002e:
	{
		RuntimeObject* L_7;
		L_7 = Enumerable_Where_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m42628461F47BB2F46D2F0ED015117BCB0A5965EC((RuntimeObject*)G_B3_1, G_B3_0, Enumerable_Where_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m42628461F47BB2F46D2F0ED015117BCB0A5965EC_RuntimeMethod_var);
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_8;
		L_8 = Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D(L_7, Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D_RuntimeMethod_var);
		NullCheck(G_B3_2);
		G_B3_2->____insertColumns = L_8;
		Il2CppCodeGenWriteBarrier((void**)(&G_B3_2->____insertColumns), (void*)L_8);
	}

IL_003d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1781>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_9 = __this->____insertColumns;
		return L_9;
	}
}
// Method Definition Index: 88000
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_InsertOrReplaceColumns_m475DA34A95A499529056F13599F15A580F187377 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1787>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = __this->____insertOrReplaceColumns;
		if (L_0)
		{
			goto IL_0019;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1788>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_1;
		L_1 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_2;
		L_2 = Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D((RuntimeObject*)L_1, Enumerable_ToArray_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m149B3F63C2980C8A6FD61A3621AF4D8FCC34655D_RuntimeMethod_var);
		__this->____insertOrReplaceColumns = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertOrReplaceColumns), (void*)L_2);
	}

IL_0019:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1790>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_3 = __this->____insertOrReplaceColumns;
		return L_3;
	}
}
// Method Definition Index: 88001
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* TableMapping_FindColumnWithPropertyName_mF4C267C9812693ACA7A48F8FF035932693EFE9F7 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_propertyName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass33_0_U3CFindColumnWithPropertyNameU3Eb__0_mEF298136BF9EE46A93578AF27D572E44CE85D73B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* V_0 = NULL;
	{
		U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* L_0 = (U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96*)il2cpp_codegen_object_new(U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96_il2cpp_TypeInfo_var);
		U3CU3Ec__DisplayClass33_0__ctor_m6F38599845F7D4E3276601029322FA31C0665A45(L_0, NULL);
		V_0 = L_0;
		U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* L_1 = V_0;
		String_t* L_2 = ___0_propertyName;
		NullCheck(L_1);
		L_1->___propertyName = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___propertyName), (void*)L_2);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1796>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_3;
		L_3 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* L_4 = V_0;
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_5 = (Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*)il2cpp_codegen_object_new(Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		Func_2__ctor_m7A4C94ED93BA348E3167A682E87E59364CAFA3D3(L_5, L_4, (intptr_t)((void*)U3CU3Ec__DisplayClass33_0_U3CFindColumnWithPropertyNameU3Eb__0_mEF298136BF9EE46A93578AF27D572E44CE85D73B_RuntimeMethod_var), NULL);
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_6;
		L_6 = Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF((RuntimeObject*)L_3, L_5, Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF_RuntimeMethod_var);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1797>
		return L_6;
	}
}
// Method Definition Index: 88002
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* TableMapping_FindColumn_m5A402637E9E85B65364E7D124D8990966B249A5A (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_columnName, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass34_0_U3CFindColumnU3Eb__0_mFB0F28EB947998D4BE1413D0F0FE9341698AF0E0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* V_0 = NULL;
	{
		U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* L_0 = (U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278*)il2cpp_codegen_object_new(U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278_il2cpp_TypeInfo_var);
		U3CU3Ec__DisplayClass34_0__ctor_mC801859216DF994C8CC531ABE5F96D3ED1B322E5(L_0, NULL);
		V_0 = L_0;
		U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* L_1 = V_0;
		String_t* L_2 = ___0_columnName;
		NullCheck(L_1);
		L_1->___columnName = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&L_1->___columnName), (void*)L_2);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1802>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_3;
		L_3 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* L_4 = V_0;
		Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0* L_5 = (Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0*)il2cpp_codegen_object_new(Func_2_t0888294D314FCB3F6B77C82DE782085116AB55E0_il2cpp_TypeInfo_var);
		Func_2__ctor_m7A4C94ED93BA348E3167A682E87E59364CAFA3D3(L_5, L_4, (intptr_t)((void*)U3CU3Ec__DisplayClass34_0_U3CFindColumnU3Eb__0_mFB0F28EB947998D4BE1413D0F0FE9341698AF0E0_RuntimeMethod_var), NULL);
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_6;
		L_6 = Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF((RuntimeObject*)L_3, L_5, Enumerable_FirstOrDefault_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m1EFEE48E19323896E49631EB6B7CE6F197093ADF_RuntimeMethod_var);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1803>
		return L_6;
	}
}
// Method Definition Index: 88003
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* TableMapping_GetInsertCommand_mE2B7EAC929E051BB524A2F1E91E790E03368F385 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, String_t* ___1_extra, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1811>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_0 = __this->____insertCommand;
		if (L_0)
		{
			goto IL_001f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1812>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_1 = ___0_conn;
		String_t* L_2 = ___1_extra;
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_3;
		L_3 = TableMapping_CreateInsertCommand_mD08CD90FEE995D8FBD71DD35E3E192D4A9308BAE(__this, L_1, L_2, NULL);
		__this->____insertCommand = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertCommand), (void*)L_3);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1813>
		String_t* L_4 = ___1_extra;
		__this->____insertCommandExtra = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertCommandExtra), (void*)L_4);
		goto IL_004d;
	}

IL_001f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1815>
		String_t* L_5 = __this->____insertCommandExtra;
		String_t* L_6 = ___1_extra;
		bool L_7;
		L_7 = String_op_Inequality_m8C940F3CFC42866709D7CA931B3D77B4BE94BCB6(L_5, L_6, NULL);
		if (!L_7)
		{
			goto IL_004d;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1816>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_8 = __this->____insertCommand;
		NullCheck(L_8);
		PreparedSqlLiteInsertCommand_Dispose_mCA54621740609D3A5DC1952524DFCB280474E8C7(L_8, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1817>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_9 = ___0_conn;
		String_t* L_10 = ___1_extra;
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_11;
		L_11 = TableMapping_CreateInsertCommand_mD08CD90FEE995D8FBD71DD35E3E192D4A9308BAE(__this, L_9, L_10, NULL);
		__this->____insertCommand = L_11;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertCommand), (void*)L_11);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1818>
		String_t* L_12 = ___1_extra;
		__this->____insertCommandExtra = L_12;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertCommandExtra), (void*)L_12);
	}

IL_004d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1820>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_13 = __this->____insertCommand;
		return L_13;
	}
}
// Method Definition Index: 88004
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* TableMapping_CreateInsertCommand_mD08CD90FEE995D8FBD71DD35E3E192D4A9308BAE (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, String_t* ___1_extra, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Any_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m6325CE9602A98DA4A975472F98C7910DDE3717FF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Count_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m57CC70E85C42987C231D56F3D4CA940C9D6EE660_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3CCreateInsertCommandU3Eb__38_0_m88101F47F990EFC0C85013F09E4E590C2994CEC6_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_U3CCreateInsertCommandU3Eb__38_1_m9B9E8F68B952A79B9B6AB52EBA05A8B5B489A931_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7EF9629485339439117D5EB2BD0095D32B266B7B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral80E7F4E6C02B03699F008F88CF100C4A58F4B1CD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3AFDFF8CF4EECA2CEFFAA76CE1B231800822441);
		s_Il2CppMethodInitialized = true;
	}
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* V_0 = NULL;
	String_t* V_1 = NULL;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* G_B8_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B8_1 = NULL;
	String_t* G_B8_2 = NULL;
	int32_t G_B8_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B8_4 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B8_5 = NULL;
	String_t* G_B8_6 = NULL;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* G_B7_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B7_1 = NULL;
	String_t* G_B7_2 = NULL;
	int32_t G_B7_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B7_4 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B7_5 = NULL;
	String_t* G_B7_6 = NULL;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* G_B10_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B10_1 = NULL;
	String_t* G_B10_2 = NULL;
	int32_t G_B10_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B10_4 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B10_5 = NULL;
	String_t* G_B10_6 = NULL;
	Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* G_B9_0 = NULL;
	ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* G_B9_1 = NULL;
	String_t* G_B9_2 = NULL;
	int32_t G_B9_3 = 0;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B9_4 = NULL;
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* G_B9_5 = NULL;
	String_t* G_B9_6 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1825>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0;
		L_0 = TableMapping_get_InsertColumns_mD397D5E0041FCB77305768E1F09F667CBC8F8195(__this, NULL);
		V_0 = L_0;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1827>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_1 = V_0;
		bool L_2;
		L_2 = Enumerable_Any_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m6325CE9602A98DA4A975472F98C7910DDE3717FF((RuntimeObject*)L_1, Enumerable_Any_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m6325CE9602A98DA4A975472F98C7910DDE3717FF_RuntimeMethod_var);
		if (L_2)
		{
			goto IL_0043;
		}
	}
	{
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_3;
		L_3 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		int32_t L_4;
		L_4 = Enumerable_Count_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m57CC70E85C42987C231D56F3D4CA940C9D6EE660((RuntimeObject*)L_3, Enumerable_Count_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_m57CC70E85C42987C231D56F3D4CA940C9D6EE660_RuntimeMethod_var);
		if ((!(((uint32_t)L_4) == ((uint32_t)1))))
		{
			goto IL_0043;
		}
	}
	{
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_5;
		L_5 = TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline(__this, NULL);
		NullCheck(L_5);
		int32_t L_6 = 0;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(L_7);
		bool L_8;
		L_8 = Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline(L_7, NULL);
		if (!L_8)
		{
			goto IL_0043;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1829>
		String_t* L_9;
		L_9 = TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline(__this, NULL);
		String_t* L_10 = ___1_extra;
		String_t* L_11;
		L_11 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral7EF9629485339439117D5EB2BD0095D32B266B7B, L_9, L_10, NULL);
		V_1 = L_11;
		goto IL_00e7;
	}

IL_0043:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1833>
		String_t* L_12 = ___1_extra;
		int32_t L_13;
		L_13 = String_Compare_mB21E4512DAFACE027D2DD3FE75DD6E69CE315009(L_12, _stringLiteral80E7F4E6C02B03699F008F88CF100C4A58F4B1CD, 5, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1835>
		if (!((((int32_t)L_13) == ((int32_t)0))? 1 : 0))
		{
			goto IL_005b;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1836>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_14;
		L_14 = TableMapping_get_InsertOrReplaceColumns_m475DA34A95A499529056F13599F15A580F187377(__this, NULL);
		V_0 = L_14;
	}

IL_005b:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1839>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1840>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1841>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1842>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1843>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_15 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)4);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_16 = L_15;
		String_t* L_17;
		L_17 = TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline(__this, NULL);
		NullCheck(L_16);
		ArrayElementTypeCheck (L_16, L_17);
		(L_16)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)L_17);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_18 = L_16;
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_19 = V_0;
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_20 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_0;
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_21 = L_20;
		if (L_21)
		{
			G_B8_0 = L_21;
			G_B8_1 = L_19;
			G_B8_2 = _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
			G_B8_3 = 1;
			G_B8_4 = L_18;
			G_B8_5 = L_18;
			G_B8_6 = _stringLiteralF3AFDFF8CF4EECA2CEFFAA76CE1B231800822441;
			goto IL_0096;
		}
		G_B7_0 = L_21;
		G_B7_1 = L_19;
		G_B7_2 = _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
		G_B7_3 = 1;
		G_B7_4 = L_18;
		G_B7_5 = L_18;
		G_B7_6 = _stringLiteralF3AFDFF8CF4EECA2CEFFAA76CE1B231800822441;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* L_22 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9;
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_23 = (Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF*)il2cpp_codegen_object_new(Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF_il2cpp_TypeInfo_var);
		Func_2__ctor_m0B92B23BC9DF6F76137D05B5B9ED715E2C576C95(L_23, L_22, (intptr_t)((void*)U3CU3Ec_U3CCreateInsertCommandU3Eb__38_0_m88101F47F990EFC0C85013F09E4E590C2994CEC6_RuntimeMethod_var), NULL);
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_24 = L_23;
		((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_0 = L_24;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_0), (void*)L_24);
		G_B8_0 = L_24;
		G_B8_1 = G_B7_1;
		G_B8_2 = G_B7_2;
		G_B8_3 = G_B7_3;
		G_B8_4 = G_B7_4;
		G_B8_5 = G_B7_5;
		G_B8_6 = G_B7_6;
	}

IL_0096:
	{
		RuntimeObject* L_25;
		L_25 = Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF((RuntimeObject*)G_B8_1, G_B8_0, Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF_RuntimeMethod_var);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_26;
		L_26 = Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194(L_25, Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194_RuntimeMethod_var);
		String_t* L_27;
		L_27 = String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD(G_B8_2, L_26, NULL);
		NullCheck(G_B8_4);
		ArrayElementTypeCheck (G_B8_4, L_27);
		(G_B8_4)->SetAt(static_cast<il2cpp_array_size_t>(G_B8_3), (RuntimeObject*)L_27);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_28 = G_B8_5;
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_29 = V_0;
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_30 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_1;
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_31 = L_30;
		if (L_31)
		{
			G_B10_0 = L_31;
			G_B10_1 = L_29;
			G_B10_2 = _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
			G_B10_3 = 2;
			G_B10_4 = L_28;
			G_B10_5 = L_28;
			G_B10_6 = G_B8_6;
			goto IL_00cd;
		}
		G_B9_0 = L_31;
		G_B9_1 = L_29;
		G_B9_2 = _stringLiteralC18C9BB6DF0D5C60CE5A5D2D3D6111BEB6F8CCEB;
		G_B9_3 = 2;
		G_B9_4 = L_28;
		G_B9_5 = L_28;
		G_B9_6 = G_B8_6;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* L_32 = ((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9;
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_33 = (Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF*)il2cpp_codegen_object_new(Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF_il2cpp_TypeInfo_var);
		Func_2__ctor_m0B92B23BC9DF6F76137D05B5B9ED715E2C576C95(L_33, L_32, (intptr_t)((void*)U3CU3Ec_U3CCreateInsertCommandU3Eb__38_1_m9B9E8F68B952A79B9B6AB52EBA05A8B5B489A931_RuntimeMethod_var), NULL);
		Func_2_tC2C8F7DF19D51C9E5D238CD9FA2A496D0402AAAF* L_34 = L_33;
		((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_1 = L_34;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9__38_1), (void*)L_34);
		G_B10_0 = L_34;
		G_B10_1 = G_B9_1;
		G_B10_2 = G_B9_2;
		G_B10_3 = G_B9_3;
		G_B10_4 = G_B9_4;
		G_B10_5 = G_B9_5;
		G_B10_6 = G_B9_6;
	}

IL_00cd:
	{
		RuntimeObject* L_35;
		L_35 = Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF((RuntimeObject*)G_B10_1, G_B10_0, Enumerable_Select_TisColumn_t564DF88EC1682FE8BFF942CEA00230032EF3D671_TisString_t_mE4568176DBB3B39197A61EDC625575525BBB04FF_RuntimeMethod_var);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_36;
		L_36 = Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194(L_35, Enumerable_ToArray_TisString_t_m3B23EE2DD15B2996E7D2ECA6E74696DA892AA194_RuntimeMethod_var);
		String_t* L_37;
		L_37 = String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD(G_B10_2, L_36, NULL);
		NullCheck(G_B10_4);
		ArrayElementTypeCheck (G_B10_4, L_37);
		(G_B10_4)->SetAt(static_cast<il2cpp_array_size_t>(G_B10_3), (RuntimeObject*)L_37);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = G_B10_5;
		String_t* L_39 = ___1_extra;
		NullCheck(L_38);
		ArrayElementTypeCheck (L_38, L_39);
		(L_38)->SetAt(static_cast<il2cpp_array_size_t>(3), (RuntimeObject*)L_39);
		String_t* L_40;
		L_40 = String_Format_m918500C1EFB475181349A79989BB79BB36102894(G_B10_6, L_38, NULL);
		V_1 = L_40;
	}

IL_00e7:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1847>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_41 = ___0_conn;
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_42 = (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6*)il2cpp_codegen_object_new(PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var);
		PreparedSqlLiteInsertCommand__ctor_mAC78E6F9CAB8A87FD6340F01B89E74B2303A439D(L_42, L_41, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1848>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_43 = L_42;
		String_t* L_44 = V_1;
		NullCheck(L_43);
		PreparedSqlLiteInsertCommand_set_CommandText_mF815B54C9CC7655C4EFD985B018A7F2BCB801D25_inline(L_43, L_44, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1849>
		return L_43;
	}
}
// Method Definition Index: 88005
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TableMapping_Dispose_m7CB62DC02436FF13F3F28B49836AC0DDA437AFE1 (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1854>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_0 = __this->____insertCommand;
		if (!L_0)
		{
			goto IL_001a;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1855>
		PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* L_1 = __this->____insertCommand;
		NullCheck(L_1);
		PreparedSqlLiteInsertCommand_Dispose_mCA54621740609D3A5DC1952524DFCB280474E8C7(L_1, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1856>
		__this->____insertCommand = (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____insertCommand), (void*)(PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6*)NULL);
	}

IL_001a:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1858>
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
// Method Definition Index: 88006
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1864>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88007
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_Name_mD882DC58740CE81E425CB2A31F3DCA0F0E50894D (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1864>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88008
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Column_get_PropertyName_mA027B508D4E518B622B97A7AE61B26DDAB5185A4 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1866>
		PropertyInfo_t* L_0 = __this->____prop;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = VirtualFuncInvoker0< String_t* >::Invoke(8, L_0);
		return L_1;
	}
}
// Method Definition Index: 88009
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1868>
		Type_t* L_0 = __this->___U3CColumnTypeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88010
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_ColumnType_m7CC823907CE0417707286D87E8B09356F56B3684 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1868>
		Type_t* L_0 = ___0_value;
		__this->___U3CColumnTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CColumnTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88011
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Column_get_Collation_mFCB25D7DEC4A917028AD1119B960797354754FE4 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1870>
		String_t* L_0 = __this->___U3CCollationU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88012
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_Collation_m38950A7B621B26E1445DD71BA8EB25310A9625E2 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1870>
		String_t* L_0 = ___0_value;
		__this->___U3CCollationU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCollationU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88013
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1872>
		bool L_0 = __this->___U3CIsAutoIncU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88014
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_IsAutoInc_mB5E9C07D162A67B47AA22CAD5377FA88FB539957 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1872>
		bool L_0 = ___0_value;
		__this->___U3CIsAutoIncU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88015
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Column_get_IsAutoGuid_m57F6E41749A0EA41B0045EAAEA737420D91BFDD6 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1873>
		bool L_0 = __this->___U3CIsAutoGuidU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88016
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_IsAutoGuid_mCC042141DA8E2AC6540F48E80C5A56F8E4A9BD3A (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1873>
		bool L_0 = ___0_value;
		__this->___U3CIsAutoGuidU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88017
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1875>
		bool L_0 = __this->___U3CIsPKU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88018
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_IsPK_mF1E6B6A586CB5A6C00E2AC6E9BB2C6B431F1BC2C (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1875>
		bool L_0 = ___0_value;
		__this->___U3CIsPKU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88019
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Column_get_Indices_m7031A7B3593A288E9B314065A906D1358FF0580E (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1877>
		RuntimeObject* L_0 = __this->___U3CIndicesU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88020
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_Indices_m3CE76E6C2C8921D734C9A02DEBE747C2F46675A7 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1877>
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CIndicesU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CIndicesU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88021
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Column_get_IsNullable_mBA3EFE8EE8CEB4F11EA0AE63AE30E8E27BF3DF7F (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1879>
		bool L_0 = __this->___U3CIsNullableU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88022
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_IsNullable_mFFD923C501D7848B8DC14A9B40FB52D729DF8305 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1879>
		bool L_0 = ___0_value;
		__this->___U3CIsNullableU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88023
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 Column_get_MaxStringLength_mAAA93C02B5F68450E5EC2E9106BF6EDBEE367FD1 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1881>
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_0 = __this->___U3CMaxStringLengthU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88024
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_set_MaxStringLength_mDFCF47180CF9CB10CFEF5532AF58957C487C4FA1 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1881>
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_0 = ___0_value;
		__this->___U3CMaxStringLengthU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88025
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column__ctor_m8C177984EBE01667C7E935F00904E889933F18B9 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, PropertyInfo_t* ___0_prop, int32_t ___1_createFlags, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Any_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_m437EBE80131A4CD77D4F0924E3E375284C8A074A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Guid_t_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBFF9324A7A4DB3E1D645999C8B9E2DA54472D42C);
		s_Il2CppMethodInitialized = true;
	}
	ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* V_0 = NULL;
	bool V_1 = false;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B2_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B1_0 = NULL;
	String_t* G_B3_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B3_1 = NULL;
	Type_t* G_B5_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B5_1 = NULL;
	Type_t* G_B4_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B4_1 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B9_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B6_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B8_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B7_0 = NULL;
	int32_t G_B10_0 = 0;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B10_1 = NULL;
	int32_t G_B15_0 = 0;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B17_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B16_0 = NULL;
	int32_t G_B18_0 = 0;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B18_1 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B20_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B19_0 = NULL;
	int32_t G_B21_0 = 0;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B21_1 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B28_0 = NULL;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B27_0 = NULL;
	int32_t G_B29_0 = 0;
	Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* G_B29_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1883>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1885>
		PropertyInfo_t* L_0 = ___0_prop;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		RuntimeObject* L_4;
		L_4 = Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD((RuntimeObject*)L_3, Enumerable_FirstOrDefault_TisRuntimeObject_m7DE546C4F58329C905F662422736A44C50268ECD_RuntimeMethod_var);
		V_0 = ((ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4*)CastclassClass((RuntimeObject*)L_4, ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4_il2cpp_TypeInfo_var));
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1887>
		PropertyInfo_t* L_5 = ___0_prop;
		__this->____prop = L_5;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____prop), (void*)L_5);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1888>
		ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* L_6 = V_0;
		if (!L_6)
		{
			G_B2_0 = __this;
			goto IL_0035;
		}
		G_B1_0 = __this;
	}
	{
		ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* L_7 = V_0;
		NullCheck(L_7);
		String_t* L_8;
		L_8 = ColumnAttribute_get_Name_m77A6DCA8A8508839AAF308D8A8FAFB0AE02E56B6_inline(L_7, NULL);
		G_B3_0 = L_8;
		G_B3_1 = G_B1_0;
		goto IL_003b;
	}

IL_0035:
	{
		PropertyInfo_t* L_9 = ___0_prop;
		NullCheck(L_9);
		String_t* L_10;
		L_10 = VirtualFuncInvoker0< String_t* >::Invoke(8, L_9);
		G_B3_0 = L_10;
		G_B3_1 = G_B2_0;
	}

IL_003b:
	{
		NullCheck(G_B3_1);
		Column_set_Name_mD882DC58740CE81E425CB2A31F3DCA0F0E50894D_inline(G_B3_1, G_B3_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1890>
		PropertyInfo_t* L_11 = ___0_prop;
		NullCheck(L_11);
		Type_t* L_12;
		L_12 = VirtualFuncInvoker0< Type_t* >::Invoke(16, L_11);
		Type_t* L_13;
		L_13 = Nullable_GetUnderlyingType_mA8FA7F61D3B8E56EB4E40378020FD2854838BDF8(L_12, NULL);
		Type_t* L_14 = L_13;
		if (L_14)
		{
			G_B5_0 = L_14;
			G_B5_1 = __this;
			goto IL_0056;
		}
		G_B4_0 = L_14;
		G_B4_1 = __this;
	}
	{
		PropertyInfo_t* L_15 = ___0_prop;
		NullCheck(L_15);
		Type_t* L_16;
		L_16 = VirtualFuncInvoker0< Type_t* >::Invoke(16, L_15);
		G_B5_0 = L_16;
		G_B5_1 = G_B4_1;
	}

IL_0056:
	{
		NullCheck(G_B5_1);
		Column_set_ColumnType_m7CC823907CE0417707286D87E8B09356F56B3684_inline(G_B5_1, G_B5_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1891>
		PropertyInfo_t* L_17 = ___0_prop;
		String_t* L_18;
		L_18 = Orm_Collation_mDB9DE76216C8D86506F69A62B055D575FA8AC1B6(L_17, NULL);
		Column_set_Collation_m38950A7B621B26E1445DD71BA8EB25310A9625E2_inline(__this, L_18, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1893>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1894>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1895>
		PropertyInfo_t* L_19 = ___0_prop;
		bool L_20;
		L_20 = Orm_IsPK_mBF1730A4E7ED323706C717DFBC85CE53C37275AC(L_19, NULL);
		if (L_20)
		{
			G_B9_0 = __this;
			goto IL_008f;
		}
		G_B6_0 = __this;
	}
	{
		int32_t L_21 = ___1_createFlags;
		if ((!(((uint32_t)((int32_t)((int32_t)L_21&1))) == ((uint32_t)1))))
		{
			G_B8_0 = G_B6_0;
			goto IL_008c;
		}
		G_B7_0 = G_B6_0;
	}
	{
		PropertyInfo_t* L_22 = ___0_prop;
		NullCheck(L_22);
		String_t* L_23;
		L_23 = VirtualFuncInvoker0< String_t* >::Invoke(8, L_22);
		int32_t L_24;
		L_24 = String_Compare_mB21E4512DAFACE027D2DD3FE75DD6E69CE315009(L_23, _stringLiteralBFF9324A7A4DB3E1D645999C8B9E2DA54472D42C, 5, NULL);
		G_B10_0 = ((((int32_t)L_24) == ((int32_t)0))? 1 : 0);
		G_B10_1 = G_B7_0;
		goto IL_0090;
	}

IL_008c:
	{
		G_B10_0 = 0;
		G_B10_1 = G_B8_0;
		goto IL_0090;
	}

IL_008f:
	{
		G_B10_0 = 1;
		G_B10_1 = G_B9_0;
	}

IL_0090:
	{
		NullCheck(G_B10_1);
		Column_set_IsPK_mF1E6B6A586CB5A6C00E2AC6E9BB2C6B431F1BC2C_inline(G_B10_1, (bool)G_B10_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1897>
		PropertyInfo_t* L_25 = ___0_prop;
		bool L_26;
		L_26 = Orm_IsAutoInc_m126F84B8548B4EFF57C48A1C31AC1E17748F3185(L_25, NULL);
		if (L_26)
		{
			goto IL_00b0;
		}
	}
	{
		bool L_27;
		L_27 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(__this, NULL);
		if (!L_27)
		{
			goto IL_00ad;
		}
	}
	{
		int32_t L_28 = ___1_createFlags;
		G_B15_0 = ((((int32_t)((int32_t)((int32_t)L_28&4))) == ((int32_t)4))? 1 : 0);
		goto IL_00b1;
	}

IL_00ad:
	{
		G_B15_0 = 0;
		goto IL_00b1;
	}

IL_00b0:
	{
		G_B15_0 = 1;
	}

IL_00b1:
	{
		V_1 = (bool)G_B15_0;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1898>
		bool L_29 = V_1;
		if (!L_29)
		{
			G_B17_0 = __this;
			goto IL_00cd;
		}
		G_B16_0 = __this;
	}
	{
		Type_t* L_30;
		L_30 = Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39_inline(__this, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_31 = { reinterpret_cast<intptr_t> (Guid_t_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_32;
		L_32 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_31, NULL);
		bool L_33;
		L_33 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_30, L_32, NULL);
		G_B18_0 = ((int32_t)(L_33));
		G_B18_1 = G_B16_0;
		goto IL_00ce;
	}

IL_00cd:
	{
		G_B18_0 = 0;
		G_B18_1 = G_B17_0;
	}

IL_00ce:
	{
		NullCheck(G_B18_1);
		Column_set_IsAutoGuid_mCC042141DA8E2AC6540F48E80C5A56F8E4A9BD3A_inline(G_B18_1, (bool)G_B18_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1899>
		bool L_34 = V_1;
		if (!L_34)
		{
			G_B20_0 = __this;
			goto IL_00e2;
		}
		G_B19_0 = __this;
	}
	{
		bool L_35;
		L_35 = Column_get_IsAutoGuid_m57F6E41749A0EA41B0045EAAEA737420D91BFDD6_inline(__this, NULL);
		G_B21_0 = ((((int32_t)L_35) == ((int32_t)0))? 1 : 0);
		G_B21_1 = G_B19_0;
		goto IL_00e3;
	}

IL_00e2:
	{
		G_B21_0 = 0;
		G_B21_1 = G_B20_0;
	}

IL_00e3:
	{
		NullCheck(G_B21_1);
		Column_set_IsAutoInc_mB5E9C07D162A67B47AA22CAD5377FA88FB539957_inline(G_B21_1, (bool)G_B21_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1901>
		PropertyInfo_t* L_36 = ___0_prop;
		RuntimeObject* L_37;
		L_37 = Orm_GetIndices_m4296DBD5B13F476E7DB224DFB73E510E0DD9D750(L_36, NULL);
		Column_set_Indices_m3CE76E6C2C8921D734C9A02DEBE747C2F46675A7_inline(__this, L_37, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1902>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1903>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1904>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1905>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1906>
		RuntimeObject* L_38;
		L_38 = Column_get_Indices_m7031A7B3593A288E9B314065A906D1358FF0580E_inline(__this, NULL);
		bool L_39;
		L_39 = Enumerable_Any_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_m437EBE80131A4CD77D4F0924E3E375284C8A074A(L_38, Enumerable_Any_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_m437EBE80131A4CD77D4F0924E3E375284C8A074A_RuntimeMethod_var);
		if (L_39)
		{
			goto IL_0136;
		}
	}
	{
		bool L_40;
		L_40 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(__this, NULL);
		if (L_40)
		{
			goto IL_0136;
		}
	}
	{
		int32_t L_41 = ___1_createFlags;
		if ((!(((uint32_t)((int32_t)((int32_t)L_41&2))) == ((uint32_t)2))))
		{
			goto IL_0136;
		}
	}
	{
		String_t* L_42;
		L_42 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(__this, NULL);
		NullCheck(L_42);
		bool L_43;
		L_43 = String_EndsWith_m5E5D307CA6AEB7C08CE782B4693B19D07ADC9075(L_42, _stringLiteralBFF9324A7A4DB3E1D645999C8B9E2DA54472D42C, 5, NULL);
		if (!L_43)
		{
			goto IL_0136;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1908>
		IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76* L_44 = (IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76*)(IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76*)SZArrayNew(IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76_il2cpp_TypeInfo_var, (uint32_t)1);
		IndexedAttributeU5BU5D_tECC9B39A2DA79012572DCCC1AAABAD39250DBA76* L_45 = L_44;
		IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* L_46 = (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F*)il2cpp_codegen_object_new(IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_il2cpp_TypeInfo_var);
		IndexedAttribute__ctor_m536933E83B03CE758EFBEE9F11E4B537DE1E75D6(L_46, NULL);
		NullCheck(L_45);
		ArrayElementTypeCheck (L_45, L_46);
		(L_45)->SetAt(static_cast<il2cpp_array_size_t>(0), (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F*)L_46);
		Column_set_Indices_m3CE76E6C2C8921D734C9A02DEBE747C2F46675A7_inline(__this, (RuntimeObject*)L_45, NULL);
	}

IL_0136:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1910>
		bool L_47;
		L_47 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(__this, NULL);
		if (L_47)
		{
			G_B28_0 = __this;
			goto IL_014a;
		}
		G_B27_0 = __this;
	}
	{
		PropertyInfo_t* L_48 = ___0_prop;
		bool L_49;
		L_49 = Orm_IsMarkedNotNull_m2555E838D4C3CB82B522556F01B44449E6368CF0(L_48, NULL);
		G_B29_0 = ((((int32_t)L_49) == ((int32_t)0))? 1 : 0);
		G_B29_1 = G_B27_0;
		goto IL_014b;
	}

IL_014a:
	{
		G_B29_0 = 0;
		G_B29_1 = G_B28_0;
	}

IL_014b:
	{
		NullCheck(G_B29_1);
		Column_set_IsNullable_mFFD923C501D7848B8DC14A9B40FB52D729DF8305_inline(G_B29_1, (bool)G_B29_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1911>
		PropertyInfo_t* L_50 = ___0_prop;
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_51;
		L_51 = Orm_MaxStringLength_m6EB8E9A029C0454AA62C8B9FA1B61022A9CDC698(L_50, NULL);
		Column_set_MaxStringLength_mDFCF47180CF9CB10CFEF5532AF58957C487C4FA1_inline(__this, L_51, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1912>
		return;
	}
}
// Method Definition Index: 88026
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Column_SetValue_m2C03ECE0FF590C829C366FEC3BB3007D1804266E (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_obj, RuntimeObject* ___1_val, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1916>
		PropertyInfo_t* L_0 = __this->____prop;
		RuntimeObject* L_1 = ___0_obj;
		RuntimeObject* L_2 = ___1_val;
		NullCheck(L_0);
		VirtualActionInvoker3< RuntimeObject*, RuntimeObject*, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* >::Invoke(27, L_0, L_1, L_2, (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1917>
		return;
	}
}
// Method Definition Index: 88027
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Column_GetValue_mC41975E43F1AAF075BC3B67C1BADF8B4B7DEB0EF (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1921>
		PropertyInfo_t* L_0 = __this->____prop;
		NullCheck(L_0);
		MethodInfo_t* L_1;
		L_1 = PropertyInfo_GetGetMethod_mE0D6C0811D404DD977B53E68C0D36BA8CB889F74(L_0, NULL);
		RuntimeObject* L_2 = ___0_obj;
		NullCheck(L_1);
		RuntimeObject* L_3;
		L_3 = MethodBase_Invoke_mEEF3218648F111A8C338001A7804091A0747C826(L_1, L_2, (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)NULL, NULL);
		return L_3;
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
// Method Definition Index: 88028
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__cctor_m7A2152DD5B61C0A9D8DBF6215D0A008037F118EE (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* L_0 = (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A*)il2cpp_codegen_object_new(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var);
		U3CU3Ec__ctor_mC12E53D77D3E4A11ABAAB6191DFDA2079F7E4075(L_0, NULL);
		((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_StaticFields*)il2cpp_codegen_static_fields_for(U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A_il2cpp_TypeInfo_var))->___U3CU3E9), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88029
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__ctor_mC12E53D77D3E4A11ABAAB6191DFDA2079F7E4075 (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 88030
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec_U3Cget_InsertColumnsU3Eb__30_0_mC65BE356215F8AC4CC235F9BE4C98C4534B8B937 (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1779>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		NullCheck(L_0);
		bool L_1;
		L_1 = Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline(L_0, NULL);
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 88031
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* U3CU3Ec_U3CCreateInsertCommandU3Eb__38_0_m88101F47F990EFC0C85013F09E4E590C2994CEC6 (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1841>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(L_0, NULL);
		String_t* L_2;
		L_2 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677, L_1, _stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677, NULL);
		return L_2;
	}
}
// Method Definition Index: 88032
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* U3CU3Ec_U3CCreateInsertCommandU3Eb__38_1_m9B9E8F68B952A79B9B6AB52EBA05A8B5B489A931 (U3CU3Ec_tF8D922861A9A33A83BEA5B875685C233FE85C65A* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral738F291E53E97C08DAE378C71EF70A60E31AE900);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1843>
		return _stringLiteral738F291E53E97C08DAE378C71EF70A60E31AE900;
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
// Method Definition Index: 88033
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass33_0__ctor_m6F38599845F7D4E3276601029322FA31C0665A45 (U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 88034
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec__DisplayClass33_0_U3CFindColumnWithPropertyNameU3Eb__0_mEF298136BF9EE46A93578AF27D572E44CE85D73B (U3CU3Ec__DisplayClass33_0_t2F8E87B666FA82327E80E705F1377B388ABA9D96* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1796>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Column_get_PropertyName_mA027B508D4E518B622B97A7AE61B26DDAB5185A4(L_0, NULL);
		String_t* L_2 = __this->___propertyName;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_1, L_2, NULL);
		return L_3;
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
// Method Definition Index: 88035
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void U3CU3Ec__DisplayClass34_0__ctor_mC801859216DF994C8CC531ABE5F96D3ED1B322E5 (U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
// Method Definition Index: 88036
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool U3CU3Ec__DisplayClass34_0_U3CFindColumnU3Eb__0_mFB0F28EB947998D4BE1413D0F0FE9341698AF0E0 (U3CU3Ec__DisplayClass34_0_t02941BAB55DF62B19025E064B73697317229C278* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_c, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1802>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_c;
		NullCheck(L_0);
		String_t* L_1;
		L_1 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(L_0, NULL);
		String_t* L_2 = __this->___columnName;
		bool L_3;
		L_3 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_1, L_2, NULL);
		return L_3;
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
// Method Definition Index: 88037
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Orm_SqlDecl_m109EAD098868DD1BB57BB219504A2676D6BCAE84 (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_p, bool ___1_storeDateTimeAsTicks, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4B2E822D33FB5518E457261FE7AAFA1B172FDF65);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral77B57D428E28530AC6DF109E9E5436339E1F7152);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7F129804295CEE0C04CDF4D55A11D7A4ED8A692A);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral83E8CA1BC21F4B77911E28ADCD695A986FAAD8F8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC314B19DDFC8FCE377B4A8712813CBE720521F28);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1934>
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)5);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = L_0;
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralC62C64F00567C5368CAE37F4E64E1E82FF785677);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = L_1;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_3 = ___0_p;
		NullCheck(L_3);
		String_t* L_4;
		L_4 = Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline(L_3, NULL);
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(1), (String_t*)L_4);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_5 = L_2;
		NullCheck(L_5);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(2), (String_t*)_stringLiteral77B57D428E28530AC6DF109E9E5436339E1F7152);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = L_5;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_7 = ___0_p;
		bool L_8 = ___1_storeDateTimeAsTicks;
		String_t* L_9;
		L_9 = Orm_SqlType_mDCE7980C3A660660D6700F7A4413F090E19959AE(L_7, L_8, NULL);
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(3), (String_t*)L_9);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_10 = L_6;
		NullCheck(L_10);
		(L_10)->SetAt(static_cast<il2cpp_array_size_t>(4), (String_t*)_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		String_t* L_11;
		L_11 = String_Concat_m647EBF831F54B6DF7D5AFA5FD012CF4EE7571B6A(L_10, NULL);
		V_0 = L_11;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1936>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_12 = ___0_p;
		NullCheck(L_12);
		bool L_13;
		L_13 = Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline(L_12, NULL);
		if (!L_13)
		{
			goto IL_004b;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1937>
		String_t* L_14 = V_0;
		String_t* L_15;
		L_15 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_14, _stringLiteralC314B19DDFC8FCE377B4A8712813CBE720521F28, NULL);
		V_0 = L_15;
	}

IL_004b:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1939>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_16 = ___0_p;
		NullCheck(L_16);
		bool L_17;
		L_17 = Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline(L_16, NULL);
		if (!L_17)
		{
			goto IL_005f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1940>
		String_t* L_18 = V_0;
		String_t* L_19;
		L_19 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_18, _stringLiteral7F129804295CEE0C04CDF4D55A11D7A4ED8A692A, NULL);
		V_0 = L_19;
	}

IL_005f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1942>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_20 = ___0_p;
		NullCheck(L_20);
		bool L_21;
		L_21 = Column_get_IsNullable_mBA3EFE8EE8CEB4F11EA0AE63AE30E8E27BF3DF7F_inline(L_20, NULL);
		if (L_21)
		{
			goto IL_0073;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1943>
		String_t* L_22 = V_0;
		String_t* L_23;
		L_23 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_22, _stringLiteral4B2E822D33FB5518E457261FE7AAFA1B172FDF65, NULL);
		V_0 = L_23;
	}

IL_0073:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1945>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_24 = ___0_p;
		NullCheck(L_24);
		String_t* L_25;
		L_25 = Column_get_Collation_mFCB25D7DEC4A917028AD1119B960797354754FE4_inline(L_24, NULL);
		bool L_26;
		L_26 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_25, NULL);
		if (L_26)
		{
			goto IL_0097;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1946>
		String_t* L_27 = V_0;
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_28 = ___0_p;
		NullCheck(L_28);
		String_t* L_29;
		L_29 = Column_get_Collation_mFCB25D7DEC4A917028AD1119B960797354754FE4_inline(L_28, NULL);
		String_t* L_30;
		L_30 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(L_27, _stringLiteral83E8CA1BC21F4B77911E28ADCD695A986FAAD8F8, L_29, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745, NULL);
		V_0 = L_30;
	}

IL_0097:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1949>
		String_t* L_31 = V_0;
		return L_31;
	}
}
// Method Definition Index: 88038
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Orm_SqlType_mDCE7980C3A660660D6700F7A4413F090E19959AE (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_p, bool ___1_storeDateTimeAsTicks, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Guid_t_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2BE7531317059E346E68D5E40F607A6DDDB9FA57);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3A0F6D9DBC0488BBFF8777F70B454F11D38CAC5F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB0A1C47352664275E2D7F477FA4C62FC016B575F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB3F14BF976EFD974E34846B742502C802FABAE9D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD7764DAE340A30DF12CAC1D83DBBA792E904A118);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDBB6EBD9AA582506BA733281AF7A5F5E65A624F1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE7650EB4C8EF6F4B045B8E8747677ECDDEF6AA10);
		s_Il2CppMethodInitialized = true;
	}
	Type_t* V_0 = NULL;
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	Type_t* G_B34_0 = NULL;
	String_t* G_B34_1 = NULL;
	Type_t* G_B33_0 = NULL;
	String_t* G_B33_1 = NULL;
	String_t* G_B35_0 = NULL;
	String_t* G_B35_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1954>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_p;
		NullCheck(L_0);
		Type_t* L_1;
		L_1 = Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39_inline(L_0, NULL);
		V_0 = L_1;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1955>
		Type_t* L_2 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_3 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.boolean_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_4;
		L_4 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_3, NULL);
		bool L_5;
		L_5 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_2, L_4, NULL);
		if (L_5)
		{
			goto IL_0073;
		}
	}
	{
		Type_t* L_6 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_7 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.byte_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_8;
		L_8 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_7, NULL);
		bool L_9;
		L_9 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_6, L_8, NULL);
		if (L_9)
		{
			goto IL_0073;
		}
	}
	{
		Type_t* L_10 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_11 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.uint16_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_12;
		L_12 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_11, NULL);
		bool L_13;
		L_13 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_10, L_12, NULL);
		if (L_13)
		{
			goto IL_0073;
		}
	}
	{
		Type_t* L_14 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_15 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.sbyte_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_16;
		L_16 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_15, NULL);
		bool L_17;
		L_17 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_14, L_16, NULL);
		if (L_17)
		{
			goto IL_0073;
		}
	}
	{
		Type_t* L_18 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_19 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int16_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_20;
		L_20 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_19, NULL);
		bool L_21;
		L_21 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_18, L_20, NULL);
		if (L_21)
		{
			goto IL_0073;
		}
	}
	{
		Type_t* L_22 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_23 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int32_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_24;
		L_24 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_23, NULL);
		bool L_25;
		L_25 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_22, L_24, NULL);
		if (!L_25)
		{
			goto IL_0079;
		}
	}

IL_0073:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1956>
		return _stringLiteralB0A1C47352664275E2D7F477FA4C62FC016B575F;
	}

IL_0079:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1957>
		Type_t* L_26 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_27 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.uint32_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_28;
		L_28 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_27, NULL);
		bool L_29;
		L_29 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_26, L_28, NULL);
		if (L_29)
		{
			goto IL_009d;
		}
	}
	{
		Type_t* L_30 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_31 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int64_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_32;
		L_32 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_31, NULL);
		bool L_33;
		L_33 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_30, L_32, NULL);
		if (!L_33)
		{
			goto IL_00a3;
		}
	}

IL_009d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1958>
		return _stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9;
	}

IL_00a3:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1959>
		Type_t* L_34 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_35 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.single_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_36;
		L_36 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_35, NULL);
		bool L_37;
		L_37 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_34, L_36, NULL);
		if (L_37)
		{
			goto IL_00d9;
		}
	}
	{
		Type_t* L_38 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_39 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.double_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_40;
		L_40 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_39, NULL);
		bool L_41;
		L_41 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_38, L_40, NULL);
		if (L_41)
		{
			goto IL_00d9;
		}
	}
	{
		Type_t* L_42 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_43 = { reinterpret_cast<intptr_t> (Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_44;
		L_44 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_43, NULL);
		bool L_45;
		L_45 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_42, L_44, NULL);
		if (!L_45)
		{
			goto IL_00df;
		}
	}

IL_00d9:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1960>
		return _stringLiteralE3DFC065B6A6D9931B797808DD066491AAB82B29;
	}

IL_00df:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1961>
		Type_t* L_46 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_47 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.string_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_48;
		L_48 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_47, NULL);
		bool L_49;
		L_49 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_46, L_48, NULL);
		if (!L_49)
		{
			goto IL_0126;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1962>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_50 = ___0_p;
		NullCheck(L_50);
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_51;
		L_51 = Column_get_MaxStringLength_mAAA93C02B5F68450E5EC2E9106BF6EDBEE367FD1_inline(L_50, NULL);
		V_1 = L_51;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1964>
		bool L_52;
		L_52 = Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_inline((&V_1), Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_RuntimeMethod_var);
		if (!L_52)
		{
			goto IL_0120;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1965>
		int32_t L_53;
		L_53 = Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA((&V_1), Nullable_1_get_Value_m0DF3B826A745419D26A168689AEB4BE6F8698ECA_RuntimeMethod_var);
		V_2 = L_53;
		String_t* L_54;
		L_54 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_2), NULL);
		String_t* L_55;
		L_55 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(_stringLiteral3A0F6D9DBC0488BBFF8777F70B454F11D38CAC5F, L_54, _stringLiteralB3F14BF976EFD974E34846B742502C802FABAE9D, NULL);
		return L_55;
	}

IL_0120:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1967>
		return _stringLiteralDBB6EBD9AA582506BA733281AF7A5F5E65A624F1;
	}

IL_0126:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1968>
		Type_t* L_56 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_57 = { reinterpret_cast<intptr_t> (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_58;
		L_58 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_57, NULL);
		bool L_59;
		L_59 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_56, L_58, NULL);
		if (!L_59)
		{
			goto IL_013e;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1969>
		return _stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9;
	}

IL_013e:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1970>
		Type_t* L_60 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_61 = { reinterpret_cast<intptr_t> (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_62;
		L_62 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_61, NULL);
		bool L_63;
		L_63 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_60, L_62, NULL);
		if (!L_63)
		{
			goto IL_015f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1971>
		bool L_64 = ___1_storeDateTimeAsTicks;
		if (L_64)
		{
			goto IL_0159;
		}
	}
	{
		return _stringLiteralE7650EB4C8EF6F4B045B8E8747677ECDDEF6AA10;
	}

IL_0159:
	{
		return _stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9;
	}

IL_015f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1972>
		Type_t* L_65 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_66 = { reinterpret_cast<intptr_t> (DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_67;
		L_67 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_66, NULL);
		bool L_68;
		L_68 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_65, L_67, NULL);
		if (!L_68)
		{
			goto IL_0177;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1973>
		return _stringLiteralAB9DEBF202DC049083374F77D2854679064EF4A9;
	}

IL_0177:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1975>
		Type_t* L_69 = V_0;
		NullCheck(L_69);
		bool L_70;
		L_70 = VirtualFuncInvoker0< bool >::Invoke(70, L_69);
		if (!L_70)
		{
			goto IL_0185;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1979>
		return _stringLiteralB0A1C47352664275E2D7F477FA4C62FC016B575F;
	}

IL_0185:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1980>
		Type_t* L_71 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_72 = { reinterpret_cast<intptr_t> (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_73;
		L_73 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_72, NULL);
		bool L_74;
		L_74 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_71, L_73, NULL);
		if (!L_74)
		{
			goto IL_019d;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1981>
		return _stringLiteralD7764DAE340A30DF12CAC1D83DBBA792E904A118;
	}

IL_019d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1982>
		Type_t* L_75 = V_0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_76 = { reinterpret_cast<intptr_t> (Guid_t_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_77;
		L_77 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_76, NULL);
		bool L_78;
		L_78 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_75, L_77, NULL);
		if (!L_78)
		{
			goto IL_01b5;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1983>
		return _stringLiteral2BE7531317059E346E68D5E40F607A6DDDB9FA57;
	}

IL_01b5:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1985>
		Type_t* L_79 = V_0;
		Type_t* L_80 = L_79;
		if (L_80)
		{
			G_B34_0 = L_80;
			G_B34_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6791FD228A8829A89802587131C38934CF0E3A9D));
			goto IL_01c2;
		}
		G_B33_0 = L_80;
		G_B33_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6791FD228A8829A89802587131C38934CF0E3A9D));
	}
	{
		G_B35_0 = ((String_t*)(NULL));
		G_B35_1 = G_B33_1;
		goto IL_01c7;
	}

IL_01c2:
	{
		NullCheck(G_B34_0);
		String_t* L_81;
		L_81 = VirtualFuncInvoker0< String_t* >::Invoke(3, G_B34_0);
		G_B35_0 = L_81;
		G_B35_1 = G_B34_1;
	}

IL_01c7:
	{
		String_t* L_82;
		L_82 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B35_1, G_B35_0, NULL);
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_83 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_83, L_82, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_83, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Orm_SqlType_mDCE7980C3A660660D6700F7A4413F090E19959AE_RuntimeMethod_var)));
	}
}
// Method Definition Index: 88039
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsPK_mBF1730A4E7ED323706C717DFBC85CE53C37275AC (MemberInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1991>
		MemberInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (PrimaryKeyAttribute_tF4FB3F5CF631D71780EBC70306F86FAAEC9757C1_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1993>
		NullCheck(L_3);
		return (bool)((!(((uint32_t)(((RuntimeArray*)L_3)->max_length)) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 88040
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Orm_Collation_mDB9DE76216C8D86506F69A62B055D575FA8AC1B6 (MemberInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2001>
		MemberInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		V_0 = L_3;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2003>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if (!(((RuntimeArray*)L_4)->max_length))
		{
			goto IL_0024;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2004>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6 = 0;
		RuntimeObject* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(((CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C*)CastclassClass((RuntimeObject*)L_7, CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_il2cpp_TypeInfo_var)));
		String_t* L_8;
		L_8 = CollationAttribute_get_Value_m8BBDF28DFA2375F6E36CD0CA758954F6E261DC4D_inline(((CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C*)CastclassClass((RuntimeObject*)L_7, CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C_il2cpp_TypeInfo_var)), NULL);
		return L_8;
	}

IL_0024:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2010>
		String_t* L_9 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_defaults.string_class))->___Empty;
		return L_9;
	}
}
// Method Definition Index: 88041
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsAutoInc_m126F84B8548B4EFF57C48A1C31AC1E17748F3185 (MemberInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2016>
		MemberInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (AutoIncrementAttribute_t2D7AA9C540978AB8836CFE73E38C3AE28F72E59F_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2018>
		NullCheck(L_3);
		return (bool)((!(((uint32_t)(((RuntimeArray*)L_3)->max_length)) <= ((uint32_t)0)))? 1 : 0);
	}
}
// Method Definition Index: 88042
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Orm_GetIndices_m4296DBD5B13F476E7DB224DFB73E510E0DD9D750 (MemberInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerable_Cast_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_mC71EC946C5A6FCA3956E91CEFEA6AC53497D8F39_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2026>
		MemberInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2027>
		RuntimeObject* L_4;
		L_4 = Enumerable_Cast_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_mC71EC946C5A6FCA3956E91CEFEA6AC53497D8F39((RuntimeObject*)L_3, Enumerable_Cast_TisIndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F_mC71EC946C5A6FCA3956E91CEFEA6AC53497D8F39_RuntimeMethod_var);
		return L_4;
	}
}
// Method Definition Index: 88043
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 Orm_MaxStringLength_m6EB8E9A029C0454AA62C8B9FA1B61022A9CDC698 (PropertyInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2032>
		PropertyInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		V_0 = L_3;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2034>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if (!(((RuntimeArray*)L_4)->max_length))
		{
			goto IL_0029;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2035>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_5 = V_0;
		NullCheck(L_5);
		int32_t L_6 = 0;
		RuntimeObject* L_7 = (L_5)->GetAt(static_cast<il2cpp_array_size_t>(L_6));
		NullCheck(((MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0*)CastclassClass((RuntimeObject*)L_7, MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_il2cpp_TypeInfo_var)));
		int32_t L_8;
		L_8 = MaxLengthAttribute_get_Value_m41D0EE4D437B205AAAA56902DB7EFC0176397851_inline(((MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0*)CastclassClass((RuntimeObject*)L_7, MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0_il2cpp_TypeInfo_var)), NULL);
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_9;
		memset((&L_9), 0, sizeof(L_9));
		Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703((&L_9), L_8, Nullable_1__ctor_m141FA88563AC0B5179132FB929EABD02C47FF703_RuntimeMethod_var);
		return L_9;
	}

IL_0029:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2041>
		il2cpp_codegen_initobj((&V_1), sizeof(Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28));
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_10 = V_1;
		return L_10;
	}
}
// Method Definition Index: 88044
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Orm_IsMarkedNotNull_m2555E838D4C3CB82B522556F01B44449E6368CF0 (MemberInfo_t* ___0_p, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2046>
		MemberInfo_t* L_0 = ___0_p;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_1 = { reinterpret_cast<intptr_t> (NotNullAttribute_t38D2E134AB642408531BA39184945039941CCFF5_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_2;
		L_2 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_1, NULL);
		NullCheck(L_0);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3;
		L_3 = VirtualFuncInvoker2< ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, Type_t*, bool >::Invoke(14, L_0, L_2, (bool)1);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2048>
		NullCheck(L_3);
		return (bool)((!(((uint32_t)(((RuntimeArray*)L_3)->max_length)) <= ((uint32_t)0)))? 1 : 0);
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
// Method Definition Index: 88045
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLiteCommand_get_CommandText_mC5B929462D924D4197466FFF1EFBA48B06A6EE12 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2060>
		String_t* L_0 = __this->___U3CCommandTextU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88046
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_set_CommandText_mE6FE06C0BEFC9971431441AB6A99E7DDFD0F5203 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2060>
		String_t* L_0 = ___0_value;
		__this->___U3CCommandTextU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCommandTextU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88047
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand__ctor_m858549E5C58B4AF2515BA1C5B6BBE33AE1B82DBF (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mA5F09B5DB35D0EDC340F75E2C9CFB2AE65C81F0F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tC97D118E4BF4DED562658508050671CE052C65B9_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2062>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2064>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = ___0_conn;
		__this->____conn = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____conn), (void*)L_0);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2065>
		List_1_tC97D118E4BF4DED562658508050671CE052C65B9* L_1 = (List_1_tC97D118E4BF4DED562658508050671CE052C65B9*)il2cpp_codegen_object_new(List_1_tC97D118E4BF4DED562658508050671CE052C65B9_il2cpp_TypeInfo_var);
		List_1__ctor_mA5F09B5DB35D0EDC340F75E2C9CFB2AE65C81F0F(L_1, List_1__ctor_mA5F09B5DB35D0EDC340F75E2C9CFB2AE65C81F0F_RuntimeMethod_var);
		__this->____bindings = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____bindings), (void*)L_1);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2066>
		SQLiteCommand_set_CommandText_mE6FE06C0BEFC9971431441AB6A99E7DDFD0F5203_inline(__this, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2067>
		return;
	}
}
// Method Definition Index: 88048
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLiteCommand_ExecuteNonQuery_m9E1C1980946214E8C0CB50EC26828EC428435F5B (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	RuntimeObject* V_1 = NULL;
	bool V_2 = false;
	intptr_t V_3;
	memset((&V_3), 0, sizeof(V_3));
	String_t* V_4 = NULL;
	SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* G_B3_0 = NULL;
	String_t* G_B3_1 = NULL;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* G_B3_2 = NULL;
	SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* G_B2_0 = NULL;
	String_t* G_B2_1 = NULL;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* G_B2_2 = NULL;
	String_t* G_B4_0 = NULL;
	String_t* G_B4_1 = NULL;
	SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* G_B4_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2071>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = __this->____conn;
		NullCheck(L_0);
		bool L_1;
		L_1 = SQLiteConnection_get_Trace_mFF9F2DB848A04CF036DD487904E7DF71837855E2_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_002f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2072>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_2 = __this->____conn;
		if (__this)
		{
			G_B3_0 = __this;
			G_B3_1 = _stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C;
			G_B3_2 = L_2;
			goto IL_0020;
		}
		G_B2_0 = __this;
		G_B2_1 = _stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C;
		G_B2_2 = L_2;
	}
	{
		G_B4_0 = ((String_t*)(NULL));
		G_B4_1 = G_B2_1;
		G_B4_2 = G_B2_2;
		goto IL_0025;
	}

IL_0020:
	{
		NullCheck(G_B3_0);
		String_t* L_3;
		L_3 = VirtualFuncInvoker0< String_t* >::Invoke(3, G_B3_0);
		G_B4_0 = L_3;
		G_B4_1 = G_B3_1;
		G_B4_2 = G_B3_2;
	}

IL_0025:
	{
		String_t* L_4;
		L_4 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B4_1, G_B4_0, NULL);
		NullCheck(G_B4_2);
		SQLiteConnection_InvokeTrace_mC117DE5AF32471170B169B09E3D991B952427E49(G_B4_2, L_4, NULL);
	}

IL_002f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2075>
		V_0 = 0;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2076>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_5 = __this->____conn;
		NullCheck(L_5);
		RuntimeObject* L_6;
		L_6 = SQLiteConnection_get_SyncObject_mE82D7F8069DEC72A0CDC7119C14222C6D665FED5(L_5, NULL);
		V_1 = L_6;
		V_2 = (bool)0;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_005e:
			{
				{
					bool L_7 = V_2;
					if (!L_7)
					{
						goto IL_0067;
					}
				}
				{
					RuntimeObject* L_8 = V_1;
					Monitor_Exit_m05B2CF037E2214B3208198C282490A2A475653FA(L_8, NULL);
				}

IL_0067:
				{
					return;
				}
			}
		});
		try
		{
			RuntimeObject* L_9 = V_1;
			Monitor_Enter_m3CDB589DA1300B513D55FDCFB52B63E879794149(L_9, (&V_2), NULL);
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2077>
			intptr_t L_10;
			L_10 = SQLiteCommand_Prepare_mA2043FB66DB03F52E32B297539A6CE6B11896015(__this, NULL);
			V_3 = L_10;
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2078>
			intptr_t L_11 = V_3;
			int32_t L_12;
			L_12 = SQLite3_Step_m47764101C949500F2E1E61DDAF4BCC215C342950(L_11, NULL);
			V_0 = L_12;
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2079>
			intptr_t L_13 = V_3;
			SQLiteCommand_Finalize_mBB9D4342B1DBFB4D31F6840B8CC48EC596343900(__this, L_13, NULL);
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2080>
			goto IL_0068;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0068:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2081>
		int32_t L_14 = V_0;
		if ((!(((uint32_t)L_14) == ((uint32_t)((int32_t)101)))))
		{
			goto IL_007e;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2082>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_15 = __this->____conn;
		NullCheck(L_15);
		intptr_t L_16;
		L_16 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_15, NULL);
		int32_t L_17;
		L_17 = SQLite3_Changes_m0CA6C84B391B75B9B89D5115175F51D4B81BCEAC(L_16, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2083>
		return L_17;
	}

IL_007e:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2084>
		int32_t L_18 = V_0;
		if ((!(((uint32_t)L_18) == ((uint32_t)1))))
		{
			goto IL_009d;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2085>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_19 = __this->____conn;
		NullCheck(L_19);
		intptr_t L_20;
		L_20 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_19, NULL);
		String_t* L_21;
		L_21 = SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5(L_20, NULL);
		V_4 = L_21;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2086>
		int32_t L_22 = V_0;
		String_t* L_23 = V_4;
		SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* L_24;
		L_24 = SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920(L_22, L_23, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_24, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLiteCommand_ExecuteNonQuery_m9E1C1980946214E8C0CB50EC26828EC428435F5B_RuntimeMethod_var)));
	}

IL_009d:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2088>
		int32_t L_25 = V_0;
		if ((!(((uint32_t)L_25) == ((uint32_t)((int32_t)19)))))
		{
			goto IL_00d0;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2089>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_26 = __this->____conn;
		NullCheck(L_26);
		intptr_t L_27;
		L_27 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_26, NULL);
		int32_t L_28;
		L_28 = SQLite3_ExtendedErrCode_mE53EAE79412B17719370EA83EF845896409E4E68(L_27, NULL);
		if ((!(((uint32_t)L_28) == ((uint32_t)((int32_t)1299)))))
		{
			goto IL_00d0;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2090>
		int32_t L_29 = V_0;
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_30 = __this->____conn;
		NullCheck(L_30);
		intptr_t L_31;
		L_31 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_30, NULL);
		String_t* L_32;
		L_32 = SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5(L_31, NULL);
		NotNullConstraintViolationException_t879E7832BFBEBCFCE0B1902526231D755FA83456* L_33;
		L_33 = NotNullConstraintViolationException_New_mCBE6743A22BAE37F13BC97069BD90D5A197E9128(L_29, L_32, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_33, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLiteCommand_ExecuteNonQuery_m9E1C1980946214E8C0CB50EC26828EC428435F5B_RuntimeMethod_var)));
	}

IL_00d0:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2094>
		int32_t L_34 = V_0;
		Il2CppFakeBox<int32_t> L_35(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Result_tBCF6FD0B3965B1AB3130BD1B60A6B937FCD8EED4_il2cpp_TypeInfo_var)), (&V_0));
		String_t* L_36;
		L_36 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_35), NULL);
		SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* L_37;
		L_37 = SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920(L_34, L_36, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_37, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLiteCommand_ExecuteNonQuery_m9E1C1980946214E8C0CB50EC26828EC428435F5B_RuntimeMethod_var)));
	}
}
// Method Definition Index: 88052
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_OnInstanceCreated_m997D7BF1C22243343758FDDDCB7C225B9B0E8F8B (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2127>
		return;
	}
}
// Method Definition Index: 88055
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_Bind_mCA6324D7AC057A0934CB8FFA830AD6946E08456E (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, String_t* ___0_name, RuntimeObject* ___1_val, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Binding_t846C16F3FF76025D82F878E8E00A5894741580FD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m51B7F6D3686AE2542AB3B31697069DA12D259BA4_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2196>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2197>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2198>
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2199>
		List_1_tC97D118E4BF4DED562658508050671CE052C65B9* L_0 = __this->____bindings;
		Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_1 = (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD*)il2cpp_codegen_object_new(Binding_t846C16F3FF76025D82F878E8E00A5894741580FD_il2cpp_TypeInfo_var);
		Binding__ctor_m13CB4B80C3F97D812D6E871A671E2EADC50DDEDB(L_1, NULL);
		Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_2 = L_1;
		String_t* L_3 = ___0_name;
		NullCheck(L_2);
		Binding_set_Name_m6605B567612DDFD3FA9FC4557DD0F03ABE7698F8_inline(L_2, L_3, NULL);
		Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_4 = L_2;
		RuntimeObject* L_5 = ___1_val;
		NullCheck(L_4);
		Binding_set_Value_m63DB4E8880807D0480D3ED195430FE33717FBAD0_inline(L_4, L_5, NULL);
		NullCheck(L_0);
		List_1_Add_m51B7F6D3686AE2542AB3B31697069DA12D259BA4_inline(L_0, L_4, List_1_Add_m51B7F6D3686AE2542AB3B31697069DA12D259BA4_RuntimeMethod_var);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2200>
		return;
	}
}
// Method Definition Index: 88056
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_Bind_mBB710DAA5C5A4204949977D982E8FDC4BC7922ED (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, RuntimeObject* ___0_val, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2204>
		RuntimeObject* L_0 = ___0_val;
		SQLiteCommand_Bind_mCA6324D7AC057A0934CB8FFA830AD6946E08456E(__this, (String_t*)NULL, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2205>
		return;
	}
}
// Method Definition Index: 88057
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLiteCommand_ToString_mE12357628AC0B63EE531FF0CCE50EDE804E5C90B (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_mEFA76239AAE09EB0C4E66AB1ED13E2A8C60EAFC2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralA1604BA2DF7A8D273C546D03C05252552111513B);
		s_Il2CppMethodInitialized = true;
	}
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* V_0 = NULL;
	int32_t V_1 = 0;
	Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 V_2;
	memset((&V_2), 0, sizeof(V_2));
	Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* V_3 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2209>
		List_1_tC97D118E4BF4DED562658508050671CE052C65B9* L_0 = __this->____bindings;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_mEFA76239AAE09EB0C4E66AB1ED13E2A8C60EAFC2_inline(L_0, List_1_get_Count_mEFA76239AAE09EB0C4E66AB1ED13E2A8C60EAFC2_RuntimeMethod_var);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(1, L_1)));
		V_0 = L_2;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2210>
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = V_0;
		String_t* L_4;
		L_4 = SQLiteCommand_get_CommandText_mC5B929462D924D4197466FFF1EFBA48B06A6EE12_inline(__this, NULL);
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)L_4);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2211>
		V_1 = 1;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2212>
		List_1_tC97D118E4BF4DED562658508050671CE052C65B9* L_5 = __this->____bindings;
		NullCheck(L_5);
		Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 L_6;
		L_6 = List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F(L_5, List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F_RuntimeMethod_var);
		V_2 = L_6;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_005e:
			{
				Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD((&V_2), Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0053_1;
			}

IL_002c_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2212>
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_7;
				L_7 = Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_inline((&V_2), Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_RuntimeMethod_var);
				V_3 = L_7;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2213>
				StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = V_0;
				int32_t L_9 = V_1;
				int32_t L_10 = V_1;
				int32_t L_11 = ((int32_t)il2cpp_codegen_subtract(L_10, 1));
				RuntimeObject* L_12 = Box(il2cpp_defaults.int32_class, &L_11);
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_13 = V_3;
				NullCheck(L_13);
				RuntimeObject* L_14;
				L_14 = Binding_get_Value_mC2E67931562F6A62D66038EBEA50BA9395C77785_inline(L_13, NULL);
				String_t* L_15;
				L_15 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteralA1604BA2DF7A8D273C546D03C05252552111513B, L_12, L_14, NULL);
				NullCheck(L_8);
				(L_8)->SetAt(static_cast<il2cpp_array_size_t>(L_9), (String_t*)L_15);
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2214>
				int32_t L_16 = V_1;
				V_1 = ((int32_t)il2cpp_codegen_add(L_16, 1));
			}

IL_0053_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2212>
				bool L_17;
				L_17 = Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344((&V_2), Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344_RuntimeMethod_var);
				if (L_17)
				{
					goto IL_002c_1;
				}
			}
			{
				goto IL_006c;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2216>
		String_t* L_18;
		L_18 = Environment_get_NewLine_m8BF68A4EFDAFFB66500984CE779629811BA98FFF(NULL);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_19 = V_0;
		String_t* L_20;
		L_20 = String_Join_m557B6B554B87C1742FA0B128500073B421ED0BFD(L_18, L_19, NULL);
		return L_20;
	}
}
// Method Definition Index: 88058
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLiteCommand_Prepare_mA2043FB66DB03F52E32B297539A6CE6B11896015 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) 
{
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2221>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = __this->____conn;
		NullCheck(L_0);
		intptr_t L_1;
		L_1 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_0, NULL);
		String_t* L_2;
		L_2 = SQLiteCommand_get_CommandText_mC5B929462D924D4197466FFF1EFBA48B06A6EE12_inline(__this, NULL);
		intptr_t L_3;
		L_3 = SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2(L_1, L_2, NULL);
		V_0 = L_3;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2222>
		intptr_t L_4 = V_0;
		SQLiteCommand_BindAll_m611A3B2A51B3D4F0FC695575AC92570671DCE270(__this, L_4, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2223>
		intptr_t L_5 = V_0;
		return L_5;
	}
}
// Method Definition Index: 88059
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_Finalize_mBB9D4342B1DBFB4D31F6840B8CC48EC596343900 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2228>
		intptr_t L_0 = ___0_stmt;
		int32_t L_1;
		L_1 = SQLite3_Finalize_m109856BC23FA51D5AE62948F98C9381A9EA08CAC(L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2229>
		return;
	}
}
// Method Definition Index: 88060
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_BindAll_m611A3B2A51B3D4F0FC695575AC92570671DCE270 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 V_1;
	memset((&V_1), 0, sizeof(V_1));
	Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2233>
		V_0 = 1;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2234>
		List_1_tC97D118E4BF4DED562658508050671CE052C65B9* L_0 = __this->____bindings;
		NullCheck(L_0);
		Enumerator_t3BBF49A3816C05E1521FC8EF37E78A2F3BCD0702 L_1;
		L_1 = List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F(L_0, List_1_GetEnumerator_m0F356F282C77367D18E9BDCC9CB9D62220101A1F_RuntimeMethod_var);
		V_1 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0067:
			{
				Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD((&V_1), Enumerator_Dispose_mDC29B22F2ED60EAC3F59166FF626FFF1318341AD_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_005c_1;
			}

IL_0010_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2234>
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_2;
				L_2 = Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_inline((&V_1), Enumerator_get_Current_m344E87A561BE8216DB114365861DC31DD5028241_RuntimeMethod_var);
				V_2 = L_2;
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2235>
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_3 = V_2;
				NullCheck(L_3);
				String_t* L_4;
				L_4 = Binding_get_Name_m36460244708DECF7462EC96985049395A01BEE4F_inline(L_3, NULL);
				if (!L_4)
				{
					goto IL_0034_1;
				}
			}
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2236>
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_5 = V_2;
				intptr_t L_6 = ___0_stmt;
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_7 = V_2;
				NullCheck(L_7);
				String_t* L_8;
				L_8 = Binding_get_Name_m36460244708DECF7462EC96985049395A01BEE4F_inline(L_7, NULL);
				int32_t L_9;
				L_9 = SQLite3_BindParameterIndex_m7E9EAA9E6291ADD9991140E8B9DD82A3AEBCA572(L_6, L_8, NULL);
				NullCheck(L_5);
				Binding_set_Index_mD5F67E97A91ED368AF1055F65734E8FA474C3AB1_inline(L_5, L_9, NULL);
				goto IL_003f_1;
			}

IL_0034_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2238>
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_10 = V_2;
				int32_t L_11 = V_0;
				int32_t L_12 = L_11;
				V_0 = ((int32_t)il2cpp_codegen_add(L_12, 1));
				NullCheck(L_10);
				Binding_set_Index_mD5F67E97A91ED368AF1055F65734E8FA474C3AB1_inline(L_10, L_12, NULL);
			}

IL_003f_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2241>
				intptr_t L_13 = ___0_stmt;
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_14 = V_2;
				NullCheck(L_14);
				int32_t L_15;
				L_15 = Binding_get_Index_m5456E8E974EFC63C021CCF2AD8FC8036E8AA2C91_inline(L_14, NULL);
				Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* L_16 = V_2;
				NullCheck(L_16);
				RuntimeObject* L_17;
				L_17 = Binding_get_Value_mC2E67931562F6A62D66038EBEA50BA9395C77785_inline(L_16, NULL);
				SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_18 = __this->____conn;
				NullCheck(L_18);
				bool L_19;
				L_19 = SQLiteConnection_get_StoreDateTimeAsTicks_m4F0D2FE9AD61981FA554273C956E335B1C1F9929_inline(L_18, NULL);
				il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
				SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB(L_13, L_15, L_17, L_19, NULL);
			}

IL_005c_1:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2234>
				bool L_20;
				L_20 = Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344((&V_1), Enumerator_MoveNext_m453CB9C9E8A7EBFA5A4521BBA5D01957A8E48344_RuntimeMethod_var);
				if (L_20)
				{
					goto IL_0010_1;
				}
			}
			{
				goto IL_0075;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0075:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2243>
		return;
	}
}
// Method Definition Index: 88061
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB (intptr_t ___0_stmt, int32_t ___1_index, RuntimeObject* ___2_value, bool ___3_storeDateTimeAsTicks, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Guid_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralED45F4AF48C69346087C97D466BF405E270AABE2);
		s_Il2CppMethodInitialized = true;
	}
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A V_0;
	memset((&V_0), 0, sizeof(V_0));
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D V_1;
	memset((&V_1), 0, sizeof(V_1));
	DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 V_2;
	memset((&V_2), 0, sizeof(V_2));
	Guid_t V_3;
	memset((&V_3), 0, sizeof(V_3));
	int32_t G_B14_0 = 0;
	intptr_t G_B14_1;
	memset((&G_B14_1), 0, sizeof(G_B14_1));
	int32_t G_B13_0 = 0;
	intptr_t G_B13_1;
	memset((&G_B13_1), 0, sizeof(G_B13_1));
	int32_t G_B15_0 = 0;
	int32_t G_B15_1 = 0;
	intptr_t G_B15_2;
	memset((&G_B15_2), 0, sizeof(G_B15_2));
	Type_t* G_B39_0 = NULL;
	String_t* G_B39_1 = NULL;
	Type_t* G_B38_0 = NULL;
	String_t* G_B38_1 = NULL;
	String_t* G_B40_0 = NULL;
	String_t* G_B40_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2249>
		RuntimeObject* L_0 = ___2_value;
		if (L_0)
		{
			goto IL_000c;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2250>
		intptr_t L_1 = ___0_stmt;
		int32_t L_2 = ___1_index;
		int32_t L_3;
		L_3 = SQLite3_BindNull_m9C7AB23E02A0AF38C0ECEE46561509A7BD54862F(L_1, L_2, NULL);
		return;
	}

IL_000c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2252>
		RuntimeObject* L_4 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_4, il2cpp_defaults.int32_class)))
		{
			goto IL_0023;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2253>
		intptr_t L_5 = ___0_stmt;
		int32_t L_6 = ___1_index;
		RuntimeObject* L_7 = ___2_value;
		int32_t L_8;
		L_8 = SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3(L_5, L_6, ((*(int32_t*)UnBox(L_7, il2cpp_defaults.int32_class))), NULL);
		return;
	}

IL_0023:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2254>
		RuntimeObject* L_9 = ___2_value;
		if (!((String_t*)IsInstSealed((RuntimeObject*)L_9, il2cpp_defaults.string_class)))
		{
			goto IL_0040;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2255>
		intptr_t L_10 = ___0_stmt;
		int32_t L_11 = ___1_index;
		RuntimeObject* L_12 = ___2_value;
		il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		intptr_t L_13 = ((SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields*)il2cpp_codegen_static_fields_for(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var))->___NegativePointer;
		int32_t L_14;
		L_14 = SQLite3_BindText_mEDC93F5CA420D62CE61DC2624453A3C76670056A(L_10, L_11, ((String_t*)CastclassSealed((RuntimeObject*)L_12, il2cpp_defaults.string_class)), (-1), L_13, NULL);
		return;
	}

IL_0040:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2256>
		RuntimeObject* L_15 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_15, il2cpp_defaults.byte_class)))
		{
			goto IL_0060;
		}
	}
	{
		RuntimeObject* L_16 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_16, il2cpp_defaults.uint16_class)))
		{
			goto IL_0060;
		}
	}
	{
		RuntimeObject* L_17 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_17, il2cpp_defaults.sbyte_class)))
		{
			goto IL_0060;
		}
	}
	{
		RuntimeObject* L_18 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_18, il2cpp_defaults.int16_class)))
		{
			goto IL_006f;
		}
	}

IL_0060:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2257>
		intptr_t L_19 = ___0_stmt;
		int32_t L_20 = ___1_index;
		RuntimeObject* L_21 = ___2_value;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		int32_t L_22;
		L_22 = Convert_ToInt32_m9FEA65DB96264479B5268014F10754787382D297(L_21, NULL);
		int32_t L_23;
		L_23 = SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3(L_19, L_20, L_22, NULL);
		return;
	}

IL_006f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2258>
		RuntimeObject* L_24 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_24, il2cpp_defaults.boolean_class)))
		{
			goto IL_008c;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2259>
		intptr_t L_25 = ___0_stmt;
		int32_t L_26 = ___1_index;
		RuntimeObject* L_27 = ___2_value;
		if (((*(bool*)UnBox(L_27, il2cpp_defaults.boolean_class))))
		{
			G_B14_0 = L_26;
			G_B14_1 = L_25;
			goto IL_0084;
		}
		G_B13_0 = L_26;
		G_B13_1 = L_25;
	}
	{
		G_B15_0 = 0;
		G_B15_1 = G_B13_0;
		G_B15_2 = G_B13_1;
		goto IL_0085;
	}

IL_0084:
	{
		G_B15_0 = 1;
		G_B15_1 = G_B14_0;
		G_B15_2 = G_B14_1;
	}

IL_0085:
	{
		int32_t L_28;
		L_28 = SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3(G_B15_2, G_B15_1, G_B15_0, NULL);
		return;
	}

IL_008c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2260>
		RuntimeObject* L_29 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_29, il2cpp_defaults.uint32_class)))
		{
			goto IL_009c;
		}
	}
	{
		RuntimeObject* L_30 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_30, il2cpp_defaults.int64_class)))
		{
			goto IL_00ab;
		}
	}

IL_009c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2261>
		intptr_t L_31 = ___0_stmt;
		int32_t L_32 = ___1_index;
		RuntimeObject* L_33 = ___2_value;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		int64_t L_34;
		L_34 = Convert_ToInt64_mB980D7B1AB7B7071D416EE892C2B736D712BE1B5(L_33, NULL);
		int32_t L_35;
		L_35 = SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E(L_31, L_32, L_34, NULL);
		return;
	}

IL_00ab:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2262>
		RuntimeObject* L_36 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_36, il2cpp_defaults.single_class)))
		{
			goto IL_00c3;
		}
	}
	{
		RuntimeObject* L_37 = ___2_value;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_37, il2cpp_defaults.double_class)))
		{
			goto IL_00c3;
		}
	}
	{
		RuntimeObject* L_38 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_38, Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var)))
		{
			goto IL_00d2;
		}
	}

IL_00c3:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2263>
		intptr_t L_39 = ___0_stmt;
		int32_t L_40 = ___1_index;
		RuntimeObject* L_41 = ___2_value;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		double L_42;
		L_42 = Convert_ToDouble_m86FF4F837721833186E883102C056A35F0860EB0(L_41, NULL);
		int32_t L_43;
		L_43 = SQLite3_BindDouble_mEDD937BE65B3E374F9AFCDA8D482F9F1292C4290(L_39, L_40, L_42, NULL);
		return;
	}

IL_00d2:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2264>
		RuntimeObject* L_44 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_44, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var)))
		{
			goto IL_00f1;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2265>
		intptr_t L_45 = ___0_stmt;
		int32_t L_46 = ___1_index;
		RuntimeObject* L_47 = ___2_value;
		V_0 = ((*(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A*)UnBox(L_47, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		int64_t L_48;
		L_48 = TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline((&V_0), NULL);
		int32_t L_49;
		L_49 = SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E(L_45, L_46, L_48, NULL);
		return;
	}

IL_00f1:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2266>
		RuntimeObject* L_50 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_50, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var)))
		{
			goto IL_0135;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2267>
		bool L_51 = ___3_storeDateTimeAsTicks;
		if (!L_51)
		{
			goto IL_0113;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2268>
		intptr_t L_52 = ___0_stmt;
		int32_t L_53 = ___1_index;
		RuntimeObject* L_54 = ___2_value;
		V_1 = ((*(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D*)UnBox(L_54, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		int64_t L_55;
		L_55 = DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6((&V_1), NULL);
		int32_t L_56;
		L_56 = SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E(L_52, L_53, L_55, NULL);
		return;
	}

IL_0113:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2271>
		intptr_t L_57 = ___0_stmt;
		int32_t L_58 = ___1_index;
		RuntimeObject* L_59 = ___2_value;
		V_1 = ((*(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D*)UnBox(L_59, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		String_t* L_60;
		L_60 = DateTime_ToString_m6963A84785C320DA776C9FCFFEDAF26C8F1A8D78((&V_1), _stringLiteralED45F4AF48C69346087C97D466BF405E270AABE2, NULL);
		il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		intptr_t L_61 = ((SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields*)il2cpp_codegen_static_fields_for(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var))->___NegativePointer;
		int32_t L_62;
		L_62 = SQLite3_BindText_mEDC93F5CA420D62CE61DC2624453A3C76670056A(L_57, L_58, L_60, (-1), L_61, NULL);
		return;
	}

IL_0135:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2273>
		RuntimeObject* L_63 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_63, DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var)))
		{
			goto IL_0154;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2274>
		intptr_t L_64 = ___0_stmt;
		int32_t L_65 = ___1_index;
		RuntimeObject* L_66 = ___2_value;
		V_2 = ((*(DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4*)UnBox(L_66, DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var);
		int64_t L_67;
		L_67 = DateTimeOffset_get_UtcTicks_mADA0A7B073B9AD2DC81ABC3343382567119D4705((&V_2), NULL);
		int32_t L_68;
		L_68 = SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E(L_64, L_65, L_67, NULL);
		return;
	}

IL_0154:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2276>
		RuntimeObject* L_69 = ___2_value;
		NullCheck(L_69);
		Type_t* L_70;
		L_70 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_69, NULL);
		NullCheck(L_70);
		bool L_71;
		L_71 = VirtualFuncInvoker0< bool >::Invoke(70, L_70);
		if (!L_71)
		{
			goto IL_0170;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2280>
		intptr_t L_72 = ___0_stmt;
		int32_t L_73 = ___1_index;
		RuntimeObject* L_74 = ___2_value;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		int32_t L_75;
		L_75 = Convert_ToInt32_m9FEA65DB96264479B5268014F10754787382D297(L_74, NULL);
		int32_t L_76;
		L_76 = SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3(L_72, L_73, L_75, NULL);
		return;
	}

IL_0170:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2281>
		RuntimeObject* L_77 = ___2_value;
		if (!((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)IsInst((RuntimeObject*)L_77, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var)))
		{
			goto IL_0194;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2282>
		intptr_t L_78 = ___0_stmt;
		int32_t L_79 = ___1_index;
		RuntimeObject* L_80 = ___2_value;
		RuntimeObject* L_81 = ___2_value;
		NullCheck(((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_81, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var)));
		il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		intptr_t L_82 = ((SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields*)il2cpp_codegen_static_fields_for(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var))->___NegativePointer;
		int32_t L_83;
		L_83 = SQLite3_BindBlob_mECFD37EFD7AE1CE6A7B5A63D630CC1E15CF1206A(L_78, L_79, ((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_80, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var)), ((int32_t)(((RuntimeArray*)((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)Castclass((RuntimeObject*)L_81, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var)))->max_length)), L_82, NULL);
		return;
	}

IL_0194:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2283>
		RuntimeObject* L_84 = ___2_value;
		if (!((RuntimeObject*)IsInstSealed((RuntimeObject*)L_84, Guid_t_il2cpp_TypeInfo_var)))
		{
			goto IL_01c0;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2284>
		intptr_t L_85 = ___0_stmt;
		int32_t L_86 = ___1_index;
		RuntimeObject* L_87 = ___2_value;
		V_3 = ((*(Guid_t*)UnBox(L_87, Guid_t_il2cpp_TypeInfo_var)));
		String_t* L_88;
		L_88 = Guid_ToString_m2BFFD5FA726E03FA707AAFCCF065896C46D5290C((&V_3), NULL);
		il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		intptr_t L_89 = ((SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields*)il2cpp_codegen_static_fields_for(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var))->___NegativePointer;
		int32_t L_90;
		L_90 = SQLite3_BindText_mEDC93F5CA420D62CE61DC2624453A3C76670056A(L_85, L_86, L_88, ((int32_t)72), L_89, NULL);
		return;
	}

IL_01c0:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2286>
		RuntimeObject* L_91 = ___2_value;
		NullCheck(L_91);
		Type_t* L_92;
		L_92 = Object_GetType_mE10A8FC1E57F3DF29972CCBC026C2DC3942263B3(L_91, NULL);
		Type_t* L_93 = L_92;
		if (L_93)
		{
			G_B39_0 = L_93;
			G_B39_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE237EC436581AFB5F89F4E57554E10B20D85C41D));
			goto IL_01d2;
		}
		G_B38_0 = L_93;
		G_B38_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE237EC436581AFB5F89F4E57554E10B20D85C41D));
	}
	{
		G_B40_0 = ((String_t*)(NULL));
		G_B40_1 = G_B38_1;
		goto IL_01d7;
	}

IL_01d2:
	{
		NullCheck(G_B39_0);
		String_t* L_94;
		L_94 = VirtualFuncInvoker0< String_t* >::Invoke(3, G_B39_0);
		G_B40_0 = L_94;
		G_B40_1 = G_B39_1;
	}

IL_01d7:
	{
		String_t* L_95;
		L_95 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B40_1, G_B40_0, NULL);
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_96 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_96, L_95, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_96, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB_RuntimeMethod_var)));
	}
}
// Method Definition Index: 88062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SQLiteCommand_ReadCol_mC92CB5B68FD045C70567CB31BA216D163E211E03 (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, intptr_t ___0_stmt, int32_t ___1_index, int32_t ___2_type, Type_t* ___3_clrType, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Guid_t_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Guid_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Type_t* G_B42_0 = NULL;
	String_t* G_B42_1 = NULL;
	Type_t* G_B41_0 = NULL;
	String_t* G_B41_1 = NULL;
	String_t* G_B43_0 = NULL;
	String_t* G_B43_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2302>
		int32_t L_0 = ___2_type;
		if ((!(((uint32_t)L_0) == ((uint32_t)5))))
		{
			goto IL_0006;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2303>
		return NULL;
	}

IL_0006:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2305>
		Type_t* L_1 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.string_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		bool L_4;
		L_4 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_1, L_3, NULL);
		if (!L_4)
		{
			goto IL_0021;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2306>
		intptr_t L_5 = ___0_stmt;
		int32_t L_6 = ___1_index;
		String_t* L_7;
		L_7 = SQLite3_ColumnString_mC7495ED684AF170F31724D26EF5BB4EBA78E0E94(L_5, L_6, NULL);
		return L_7;
	}

IL_0021:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2307>
		Type_t* L_8 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_9 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int32_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_10;
		L_10 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_9, NULL);
		bool L_11;
		L_11 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_8, L_10, NULL);
		if (!L_11)
		{
			goto IL_0041;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2308>
		intptr_t L_12 = ___0_stmt;
		int32_t L_13 = ___1_index;
		int32_t L_14;
		L_14 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_12, L_13, NULL);
		int32_t L_15 = L_14;
		RuntimeObject* L_16 = Box(il2cpp_defaults.int32_class, &L_15);
		return L_16;
	}

IL_0041:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2309>
		Type_t* L_17 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_18 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.boolean_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_19;
		L_19 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_18, NULL);
		bool L_20;
		L_20 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_17, L_19, NULL);
		if (!L_20)
		{
			goto IL_0064;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2310>
		intptr_t L_21 = ___0_stmt;
		int32_t L_22 = ___1_index;
		int32_t L_23;
		L_23 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_21, L_22, NULL);
		bool L_24 = ((bool)((((int32_t)L_23) == ((int32_t)1))? 1 : 0));
		RuntimeObject* L_25 = Box(il2cpp_defaults.boolean_class, &L_24);
		return L_25;
	}

IL_0064:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2311>
		Type_t* L_26 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_27 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.double_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_28;
		L_28 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_27, NULL);
		bool L_29;
		L_29 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_26, L_28, NULL);
		if (!L_29)
		{
			goto IL_0084;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2312>
		intptr_t L_30 = ___0_stmt;
		int32_t L_31 = ___1_index;
		double L_32;
		L_32 = SQLite3_ColumnDouble_mE4F9CDF44BEF62E61DB8EDB332865923E7B17A7B(L_30, L_31, NULL);
		double L_33 = L_32;
		RuntimeObject* L_34 = Box(il2cpp_defaults.double_class, &L_33);
		return L_34;
	}

IL_0084:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2313>
		Type_t* L_35 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_36 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.single_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_37;
		L_37 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_36, NULL);
		bool L_38;
		L_38 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_35, L_37, NULL);
		if (!L_38)
		{
			goto IL_00a5;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2314>
		intptr_t L_39 = ___0_stmt;
		int32_t L_40 = ___1_index;
		double L_41;
		L_41 = SQLite3_ColumnDouble_mE4F9CDF44BEF62E61DB8EDB332865923E7B17A7B(L_39, L_40, NULL);
		float L_42 = ((float)L_41);
		RuntimeObject* L_43 = Box(il2cpp_defaults.single_class, &L_42);
		return L_43;
	}

IL_00a5:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2315>
		Type_t* L_44 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_45 = { reinterpret_cast<intptr_t> (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_46;
		L_46 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_45, NULL);
		bool L_47;
		L_47 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_44, L_46, NULL);
		if (!L_47)
		{
			goto IL_00ca;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2316>
		intptr_t L_48 = ___0_stmt;
		int32_t L_49 = ___1_index;
		int64_t L_50;
		L_50 = SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08(L_48, L_49, NULL);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_51;
		memset((&L_51), 0, sizeof(L_51));
		TimeSpan__ctor_m061B122FA11D2063FE751C1F1D019DF1C8B10B1F_inline((&L_51), L_50, NULL);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_52 = L_51;
		RuntimeObject* L_53 = Box(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var, &L_52);
		return L_53;
	}

IL_00ca:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2317>
		Type_t* L_54 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_55 = { reinterpret_cast<intptr_t> (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_56;
		L_56 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_55, NULL);
		bool L_57;
		L_57 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_54, L_56, NULL);
		if (!L_57)
		{
			goto IL_010e;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2318>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_58 = __this->____conn;
		NullCheck(L_58);
		bool L_59;
		L_59 = SQLiteConnection_get_StoreDateTimeAsTicks_m4F0D2FE9AD61981FA554273C956E335B1C1F9929_inline(L_58, NULL);
		if (!L_59)
		{
			goto IL_00fc;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2319>
		intptr_t L_60 = ___0_stmt;
		int32_t L_61 = ___1_index;
		int64_t L_62;
		L_62 = SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08(L_60, L_61, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_63;
		memset((&L_63), 0, sizeof(L_63));
		DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441((&L_63), L_62, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_64 = L_63;
		RuntimeObject* L_65 = Box(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var, &L_64);
		return L_65;
	}

IL_00fc:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2322>
		intptr_t L_66 = ___0_stmt;
		int32_t L_67 = ___1_index;
		String_t* L_68;
		L_68 = SQLite3_ColumnString_mC7495ED684AF170F31724D26EF5BB4EBA78E0E94(L_66, L_67, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2323>
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_69;
		L_69 = DateTime_Parse_m2DE2BF8FC3E6A6FB695ACE7A2D39A812D1D806DB(L_68, NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_70 = L_69;
		RuntimeObject* L_71 = Box(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var, &L_70);
		return L_71;
	}

IL_010e:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2325>
		Type_t* L_72 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_73 = { reinterpret_cast<intptr_t> (DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_74;
		L_74 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_73, NULL);
		bool L_75;
		L_75 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_72, L_74, NULL);
		if (!L_75)
		{
			goto IL_0138;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2326>
		intptr_t L_76 = ___0_stmt;
		int32_t L_77 = ___1_index;
		int64_t L_78;
		L_78 = SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08(L_76, L_77, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_79 = ((TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_StaticFields*)il2cpp_codegen_static_fields_for(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var))->___Zero;
		DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 L_80;
		memset((&L_80), 0, sizeof(L_80));
		DateTimeOffset__ctor_m81DCBFF0B9D7029AD6B8B80EA4CB8846387DFB9A((&L_80), L_78, L_79, NULL);
		DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4 L_81 = L_80;
		RuntimeObject* L_82 = Box(DateTimeOffset_t4EE701FE2F386D6F932FAC9B11E4B74A5B30F0A4_il2cpp_TypeInfo_var, &L_81);
		return L_82;
	}

IL_0138:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2328>
		Type_t* L_83 = ___3_clrType;
		NullCheck(L_83);
		bool L_84;
		L_84 = VirtualFuncInvoker0< bool >::Invoke(70, L_83);
		if (!L_84)
		{
			goto IL_014e;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2332>
		intptr_t L_85 = ___0_stmt;
		int32_t L_86 = ___1_index;
		int32_t L_87;
		L_87 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_85, L_86, NULL);
		int32_t L_88 = L_87;
		RuntimeObject* L_89 = Box(il2cpp_defaults.int32_class, &L_88);
		return L_89;
	}

IL_014e:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2333>
		Type_t* L_90 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_91 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int64_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_92;
		L_92 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_91, NULL);
		bool L_93;
		L_93 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_90, L_92, NULL);
		if (!L_93)
		{
			goto IL_016e;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2334>
		intptr_t L_94 = ___0_stmt;
		int32_t L_95 = ___1_index;
		int64_t L_96;
		L_96 = SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08(L_94, L_95, NULL);
		int64_t L_97 = L_96;
		RuntimeObject* L_98 = Box(il2cpp_defaults.int64_class, &L_97);
		return L_98;
	}

IL_016e:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2335>
		Type_t* L_99 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_100 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.uint32_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_101;
		L_101 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_100, NULL);
		bool L_102;
		L_102 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_99, L_101, NULL);
		if (!L_102)
		{
			goto IL_018f;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2336>
		intptr_t L_103 = ___0_stmt;
		int32_t L_104 = ___1_index;
		int64_t L_105;
		L_105 = SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08(L_103, L_104, NULL);
		uint32_t L_106 = ((uint32_t)((int32_t)(uint32_t)L_105));
		RuntimeObject* L_107 = Box(il2cpp_defaults.uint32_class, &L_106);
		return L_107;
	}

IL_018f:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2337>
		Type_t* L_108 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_109 = { reinterpret_cast<intptr_t> (Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_110;
		L_110 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_109, NULL);
		bool L_111;
		L_111 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_108, L_110, NULL);
		if (!L_111)
		{
			goto IL_01b4;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2338>
		intptr_t L_112 = ___0_stmt;
		int32_t L_113 = ___1_index;
		double L_114;
		L_114 = SQLite3_ColumnDouble_mE4F9CDF44BEF62E61DB8EDB332865923E7B17A7B(L_112, L_113, NULL);
		il2cpp_codegen_runtime_class_init_inline(Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var);
		Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F L_115;
		L_115 = Decimal_op_Explicit_mC97457D67812EF62FBEC4E9C07E5DCFACAA1FE66(L_114, NULL);
		Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F L_116 = L_115;
		RuntimeObject* L_117 = Box(Decimal_tDA6C877282B2D789CF97C0949661CC11D643969F_il2cpp_TypeInfo_var, &L_116);
		return L_117;
	}

IL_01b4:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2339>
		Type_t* L_118 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_119 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.byte_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_120;
		L_120 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_119, NULL);
		bool L_121;
		L_121 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_118, L_120, NULL);
		if (!L_121)
		{
			goto IL_01d5;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2340>
		intptr_t L_122 = ___0_stmt;
		int32_t L_123 = ___1_index;
		int32_t L_124;
		L_124 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_122, L_123, NULL);
		uint8_t L_125 = ((uint8_t)((int32_t)(uint8_t)L_124));
		RuntimeObject* L_126 = Box(il2cpp_defaults.byte_class, &L_125);
		return L_126;
	}

IL_01d5:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2341>
		Type_t* L_127 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_128 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.uint16_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_129;
		L_129 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_128, NULL);
		bool L_130;
		L_130 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_127, L_129, NULL);
		if (!L_130)
		{
			goto IL_01f6;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2342>
		intptr_t L_131 = ___0_stmt;
		int32_t L_132 = ___1_index;
		int32_t L_133;
		L_133 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_131, L_132, NULL);
		uint16_t L_134 = ((uint16_t)((int32_t)(uint16_t)L_133));
		RuntimeObject* L_135 = Box(il2cpp_defaults.uint16_class, &L_134);
		return L_135;
	}

IL_01f6:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2343>
		Type_t* L_136 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_137 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.int16_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_138;
		L_138 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_137, NULL);
		bool L_139;
		L_139 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_136, L_138, NULL);
		if (!L_139)
		{
			goto IL_0217;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2344>
		intptr_t L_140 = ___0_stmt;
		int32_t L_141 = ___1_index;
		int32_t L_142;
		L_142 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_140, L_141, NULL);
		int16_t L_143 = ((int16_t)L_142);
		RuntimeObject* L_144 = Box(il2cpp_defaults.int16_class, &L_143);
		return L_144;
	}

IL_0217:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2345>
		Type_t* L_145 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_146 = { reinterpret_cast<intptr_t> (&il2cpp_defaults.sbyte_class->byval_arg) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_147;
		L_147 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_146, NULL);
		bool L_148;
		L_148 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_145, L_147, NULL);
		if (!L_148)
		{
			goto IL_0238;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2346>
		intptr_t L_149 = ___0_stmt;
		int32_t L_150 = ___1_index;
		int32_t L_151;
		L_151 = SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF(L_149, L_150, NULL);
		int8_t L_152 = ((int8_t)L_151);
		RuntimeObject* L_153 = Box(il2cpp_defaults.sbyte_class, &L_152);
		return L_153;
	}

IL_0238:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2347>
		Type_t* L_154 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_155 = { reinterpret_cast<intptr_t> (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_156;
		L_156 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_155, NULL);
		bool L_157;
		L_157 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_154, L_156, NULL);
		if (!L_157)
		{
			goto IL_0253;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2348>
		intptr_t L_158 = ___0_stmt;
		int32_t L_159 = ___1_index;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_160;
		L_160 = SQLite3_ColumnByteArray_m09025DD6AB983E61366EFCB4F1500F7EA24CEC5E(L_158, L_159, NULL);
		return (RuntimeObject*)L_160;
	}

IL_0253:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2349>
		Type_t* L_161 = ___3_clrType;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_162 = { reinterpret_cast<intptr_t> (Guid_t_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_163;
		L_163 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_162, NULL);
		bool L_164;
		L_164 = Type_op_Equality_m99930A0E44E420A685FABA60E60BA1CC5FA0EBDC(L_161, L_163, NULL);
		if (!L_164)
		{
			goto IL_0278;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2350>
		intptr_t L_165 = ___0_stmt;
		int32_t L_166 = ___1_index;
		String_t* L_167;
		L_167 = SQLite3_ColumnString_mC7495ED684AF170F31724D26EF5BB4EBA78E0E94(L_165, L_166, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2351>
		Guid_t L_168;
		memset((&L_168), 0, sizeof(L_168));
		Guid__ctor_mAE66BA1C43B4194F4F7991E2E30370E36CBBF830((&L_168), L_167, NULL);
		Guid_t L_169 = L_168;
		RuntimeObject* L_170 = Box(Guid_t_il2cpp_TypeInfo_var, &L_169);
		return L_170;
	}

IL_0278:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2353>
		Type_t* L_171 = ___3_clrType;
		Type_t* L_172 = L_171;
		if (L_172)
		{
			G_B42_0 = L_172;
			G_B42_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralD635CA0E4F85CB7F26A62468F86B37AEADB9D184));
			goto IL_0286;
		}
		G_B41_0 = L_172;
		G_B41_1 = ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralD635CA0E4F85CB7F26A62468F86B37AEADB9D184));
	}
	{
		G_B43_0 = ((String_t*)(NULL));
		G_B43_1 = G_B41_1;
		goto IL_028b;
	}

IL_0286:
	{
		NullCheck(G_B42_0);
		String_t* L_173;
		L_173 = VirtualFuncInvoker0< String_t* >::Invoke(3, G_B42_0);
		G_B43_0 = L_173;
		G_B43_1 = G_B42_1;
	}

IL_028b:
	{
		String_t* L_174;
		L_174 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(G_B43_1, G_B43_0, NULL);
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_175 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_175, L_174, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_175, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLiteCommand_ReadCol_mC92CB5B68FD045C70567CB31BA216D163E211E03_RuntimeMethod_var)));
	}
}
// Method Definition Index: 88063
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SQLiteCommand__cctor_m01D3275406153635494959164180D16C0A3F3E6A (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2245>
		intptr_t L_0;
		memset((&L_0), 0, sizeof(L_0));
		IntPtr__ctor_m20A566609A091311C734617C699E61F545250AC7((&L_0), (-1), NULL);
		((SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_StaticFields*)il2cpp_codegen_static_fields_for(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var))->___NegativePointer = L_0;
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
// Method Definition Index: 88064
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Binding_get_Name_m36460244708DECF7462EC96985049395A01BEE4F (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2293>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Binding_set_Name_m6605B567612DDFD3FA9FC4557DD0F03ABE7698F8 (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2293>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88066
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Binding_get_Value_mC2E67931562F6A62D66038EBEA50BA9395C77785 (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2295>
		RuntimeObject* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88067
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Binding_set_Value_m63DB4E8880807D0480D3ED195430FE33717FBAD0 (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2295>
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CValueU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88068
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Binding_get_Index_m5456E8E974EFC63C021CCF2AD8FC8036E8AA2C91 (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2297>
		int32_t L_0 = __this->___U3CIndexU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88069
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Binding_set_Index_mD5F67E97A91ED368AF1055F65734E8FA474C3AB1 (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2297>
		int32_t L_0 = ___0_value;
		__this->___U3CIndexU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88070
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Binding__ctor_m13CB4B80C3F97D812D6E871A671E2EADC50DDEDB (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 88081
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool PreparedSqlLiteInsertCommand_get_Initialized_mCA24A887ADAD977158DC4E161DC05D6A0041703B (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2364>
		bool L_0 = __this->___U3CInitializedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88082
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Initialized_mEE003DDBDE4E99119A83428683D170BBB556ADAB (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2364>
		bool L_0 = ___0_value;
		__this->___U3CInitializedU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88083
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2366>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = __this->___U3CConnectionU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88084
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Connection_mCCBE4206E6F940C3762DDF7EC4E7C75174145E23 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2366>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = ___0_value;
		__this->___U3CConnectionU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CConnectionU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88085
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* PreparedSqlLiteInsertCommand_get_CommandText_m1774FAC339AF3EE7649470C4F02912EFED8E9214 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2368>
		String_t* L_0 = __this->___U3CCommandTextU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88086
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_CommandText_mF815B54C9CC7655C4EFD985B018A7F2BCB801D25 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2368>
		String_t* L_0 = ___0_value;
		__this->___U3CCommandTextU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCommandTextU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88087
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2370>
		intptr_t L_0 = __this->___U3CStatementU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88088
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Statement_mC87A23AD8B6856E34DC7B2020EA0188AFA737D07 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, intptr_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2370>
		intptr_t L_0 = ___0_value;
		__this->___U3CStatementU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88089
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand__ctor_mAC78E6F9CAB8A87FD6340F01B89E74B2303A439D (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_conn, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2373>
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2375>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = ___0_conn;
		PreparedSqlLiteInsertCommand_set_Connection_mCCBE4206E6F940C3762DDF7EC4E7C75174145E23_inline(__this, L_0, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2376>
		return;
	}
}
// Method Definition Index: 88090
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PreparedSqlLiteInsertCommand_ExecuteNonQuery_mB3C230E1C516704102397C40F4755B5B814C621E (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___0_source, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	String_t* V_2 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2380>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0;
		L_0 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_0);
		bool L_1;
		L_1 = SQLiteConnection_get_Trace_mFF9F2DB848A04CF036DD487904E7DF71837855E2_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0028;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2381>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_2;
		L_2 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		String_t* L_3;
		L_3 = PreparedSqlLiteInsertCommand_get_CommandText_m1774FAC339AF3EE7649470C4F02912EFED8E9214_inline(__this, NULL);
		String_t* L_4;
		L_4 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral5854D35F2CC7D025195818ABD6D4D237EBA08C9C, L_3, NULL);
		NullCheck(L_2);
		SQLiteConnection_InvokeTrace_mC117DE5AF32471170B169B09E3D991B952427E49(L_2, L_4, NULL);
	}

IL_0028:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2384>
		V_0 = 0;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2386>
		bool L_5;
		L_5 = PreparedSqlLiteInsertCommand_get_Initialized_mCA24A887ADAD977158DC4E161DC05D6A0041703B_inline(__this, NULL);
		if (L_5)
		{
			goto IL_0045;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2387>
		intptr_t L_6;
		L_6 = VirtualFuncInvoker0< intptr_t >::Invoke(5, __this);
		PreparedSqlLiteInsertCommand_set_Statement_mC87A23AD8B6856E34DC7B2020EA0188AFA737D07_inline(__this, L_6, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2388>
		PreparedSqlLiteInsertCommand_set_Initialized_mEE003DDBDE4E99119A83428683D170BBB556ADAB_inline(__this, (bool)1, NULL);
	}

IL_0045:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2392>
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_7 = ___0_source;
		if (!L_7)
		{
			goto IL_0072;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2393>
		V_1 = 0;
		goto IL_006c;
	}

IL_004c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2394>
		intptr_t L_8;
		L_8 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_9 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = ___0_source;
		int32_t L_11 = V_1;
		NullCheck(L_10);
		int32_t L_12 = L_11;
		RuntimeObject* L_13 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_14;
		L_14 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_14);
		bool L_15;
		L_15 = SQLiteConnection_get_StoreDateTimeAsTicks_m4F0D2FE9AD61981FA554273C956E335B1C1F9929_inline(L_14, NULL);
		il2cpp_codegen_runtime_class_init_inline(SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF_il2cpp_TypeInfo_var);
		SQLiteCommand_BindParameter_m629274A079AC37470336026EC2718803CDF47EBB(L_8, ((int32_t)il2cpp_codegen_add(L_9, 1)), L_13, L_15, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2393>
		int32_t L_16 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_16, 1));
	}

IL_006c:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2393>
		int32_t L_17 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_18 = ___0_source;
		NullCheck(L_18);
		if ((((int32_t)L_17) < ((int32_t)((int32_t)(((RuntimeArray*)L_18)->max_length)))))
		{
			goto IL_004c;
		}
	}

IL_0072:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2397>
		intptr_t L_19;
		L_19 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_20;
		L_20 = SQLite3_Step_m47764101C949500F2E1E61DDAF4BCC215C342950(L_19, NULL);
		V_0 = L_20;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2399>
		int32_t L_21 = V_0;
		if ((!(((uint32_t)L_21) == ((uint32_t)((int32_t)101)))))
		{
			goto IL_00a0;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2400>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_22;
		L_22 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_22);
		intptr_t L_23;
		L_23 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_22, NULL);
		int32_t L_24;
		L_24 = SQLite3_Changes_m0CA6C84B391B75B9B89D5115175F51D4B81BCEAC(L_23, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2401>
		intptr_t L_25;
		L_25 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_26;
		L_26 = SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E(L_25, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2402>
		return L_24;
	}

IL_00a0:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2403>
		int32_t L_27 = V_0;
		if ((!(((uint32_t)L_27) == ((uint32_t)1))))
		{
			goto IL_00c9;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2404>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_28;
		L_28 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_28);
		intptr_t L_29;
		L_29 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_28, NULL);
		String_t* L_30;
		L_30 = SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5(L_29, NULL);
		V_2 = L_30;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2405>
		intptr_t L_31;
		L_31 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_32;
		L_32 = SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E(L_31, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2406>
		int32_t L_33 = V_0;
		String_t* L_34 = V_2;
		SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* L_35;
		L_35 = SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920(L_33, L_34, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_35, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&PreparedSqlLiteInsertCommand_ExecuteNonQuery_mB3C230E1C516704102397C40F4755B5B814C621E_RuntimeMethod_var)));
	}

IL_00c9:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2407>
		int32_t L_36 = V_0;
		if ((!(((uint32_t)L_36) == ((uint32_t)((int32_t)19)))))
		{
			goto IL_0108;
		}
	}
	{
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_37;
		L_37 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_37);
		intptr_t L_38;
		L_38 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_37, NULL);
		int32_t L_39;
		L_39 = SQLite3_ExtendedErrCode_mE53EAE79412B17719370EA83EF845896409E4E68(L_38, NULL);
		if ((!(((uint32_t)L_39) == ((uint32_t)((int32_t)1299)))))
		{
			goto IL_0108;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2408>
		intptr_t L_40;
		L_40 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_41;
		L_41 = SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E(L_40, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2409>
		int32_t L_42 = V_0;
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_43;
		L_43 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_43);
		intptr_t L_44;
		L_44 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_43, NULL);
		String_t* L_45;
		L_45 = SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5(L_44, NULL);
		NotNullConstraintViolationException_t879E7832BFBEBCFCE0B1902526231D755FA83456* L_46;
		L_46 = NotNullConstraintViolationException_New_mCBE6743A22BAE37F13BC97069BD90D5A197E9128(L_42, L_45, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_46, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&PreparedSqlLiteInsertCommand_ExecuteNonQuery_mB3C230E1C516704102397C40F4755B5B814C621E_RuntimeMethod_var)));
	}

IL_0108:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2411>
		intptr_t L_47;
		L_47 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		int32_t L_48;
		L_48 = SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E(L_47, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2412>
		int32_t L_49 = V_0;
		Il2CppFakeBox<int32_t> L_50(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Result_tBCF6FD0B3965B1AB3130BD1B60A6B937FCD8EED4_il2cpp_TypeInfo_var)), (&V_0));
		String_t* L_51;
		L_51 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_50), NULL);
		SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* L_52;
		L_52 = SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920(L_49, L_51, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_52, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&PreparedSqlLiteInsertCommand_ExecuteNonQuery_mB3C230E1C516704102397C40F4755B5B814C621E_RuntimeMethod_var)));
	}
}
// Method Definition Index: 88091
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t PreparedSqlLiteInsertCommand_Prepare_m6E268A673856876CD0CA204DE8259957F8B02451 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2418>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0;
		L_0 = PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline(__this, NULL);
		NullCheck(L_0);
		intptr_t L_1;
		L_1 = SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline(L_0, NULL);
		String_t* L_2;
		L_2 = PreparedSqlLiteInsertCommand_get_CommandText_m1774FAC339AF3EE7649470C4F02912EFED8E9214_inline(__this, NULL);
		intptr_t L_3;
		L_3 = SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2(L_1, L_2, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2419>
		return L_3;
	}
}
// Method Definition Index: 88092
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_Dispose_mCA54621740609D3A5DC1952524DFCB280474E8C7 (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2424>
		PreparedSqlLiteInsertCommand_Dispose_m520FE32389F4CCEFB755F387EEDD744E73B3CC6D(__this, (bool)1, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2425>
		il2cpp_codegen_runtime_class_init_inline(GC_t920F9CF6EBB7C787E5010A4352E1B587F356DC58_il2cpp_TypeInfo_var);
		GC_SuppressFinalize_m71815DBD5A0CD2EA1BE43317B08B7A14949EDC65(__this, NULL);
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2426>
		return;
	}
}
// Method Definition Index: 88093
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_Dispose_m520FE32389F4CCEFB755F387EEDD744E73B3CC6D (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2430>
		intptr_t L_0;
		L_0 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
		intptr_t L_1 = ((PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_StaticFields*)il2cpp_codegen_static_fields_for(PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var))->___NullStatement;
		bool L_2;
		L_2 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline(L_0, L_1, NULL);
		if (!L_2)
		{
			goto IL_0033;
		}
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0020:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2434>
				intptr_t L_3 = ((PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_StaticFields*)il2cpp_codegen_static_fields_for(PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6_il2cpp_TypeInfo_var))->___NullStatement;
				PreparedSqlLiteInsertCommand_set_Statement_mC87A23AD8B6856E34DC7B2020EA0188AFA737D07_inline(__this, L_3, NULL);
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2435>
				PreparedSqlLiteInsertCommand_set_Connection_mCCBE4206E6F940C3762DDF7EC4E7C75174145E23_inline(__this, (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4*)NULL, NULL);
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2436>
				return;
			}
		});
		try
		{
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2432>
			intptr_t L_4;
			L_4 = PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline(__this, NULL);
			int32_t L_5;
			L_5 = SQLite3_Finalize_m109856BC23FA51D5AE62948F98C9381A9EA08CAC(L_4, NULL);
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2433>
			goto IL_0033;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0033:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2438>
		return;
	}
}
// Method Definition Index: 88094
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_Finalize_mFFAC493B286CD66A02BB8F9ACA85A0597B2E7D3A (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0009:
			{
				//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2443>
				Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
				return;
			}
		});
		try
		{
			//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2442>
			PreparedSqlLiteInsertCommand_Dispose_m520FE32389F4CCEFB755F387EEDD744E73B3CC6D(__this, (bool)0, NULL);
			goto IL_0010;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0010:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2443>
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
// Method Definition Index: 88095
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseTableQuery__ctor_m1E504A1BD11D864668DCEC1731386EC3AF1E6196 (BaseTableQuery_t28D9E3082475EF8E0FC7E8F87FA0174C247BED7D* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 88096
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Ordering_get_ColumnName_mC65267E5811EE3F8CE0CAD868BFBCCD226385E95 (Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2450>
		String_t* L_0 = __this->___U3CColumnNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88097
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Ordering_set_ColumnName_m66126D3284499DA6728C00293B9FB4A7F8C04671 (Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2450>
		String_t* L_0 = ___0_value;
		__this->___U3CColumnNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CColumnNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88098
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Ordering_get_Ascending_mF30E94AF04081D605BCFEC595157DF5FAB62E1AF (Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2451>
		bool L_0 = __this->___U3CAscendingU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88099
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Ordering_set_Ascending_m6270DD4601CFE7194398EAE9556B39F55FBA418D (Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2451>
		bool L_0 = ___0_value;
		__this->___U3CAscendingU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88100
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Ordering__ctor_mA2CD0E3D3D8AEF7298884B644C1FE3D89CA7B308 (Ordering_t8D3129D3E036EA513954A3A76CC9E1B92E633826* __this, const RuntimeMethod* method) 
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
// Method Definition Index: 88141
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Open_m80808E4C10BC275172A8A7D7FD25787117AB60EF (String_t* ___0_filename, intptr_t* ___1_db, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (char*, intptr_t*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(char*) + sizeof(intptr_t*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_open", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	char* ____0_filename_marshaled = NULL;
	____0_filename_marshaled = il2cpp_codegen_marshal_string(___0_filename);

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_open)(____0_filename_marshaled, ___1_db);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_filename_marshaled, ___1_db);
	#endif

	il2cpp_codegen_marshal_free(____0_filename_marshaled);
	____0_filename_marshaled = NULL;

	return returnValue;
}
// Method Definition Index: 88142
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Open_m3B612E922040951B5531825004CC8749B619EC17 (String_t* ___0_filename, intptr_t* ___1_db, int32_t ___2_flags, intptr_t ___3_zvfs, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (char*, intptr_t*, int32_t, intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(char*) + sizeof(intptr_t*) + sizeof(int32_t) + sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_open_v2", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	char* ____0_filename_marshaled = NULL;
	____0_filename_marshaled = il2cpp_codegen_marshal_string(___0_filename);

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_open_v2)(____0_filename_marshaled, ___1_db, ___2_flags, ___3_zvfs);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_filename_marshaled, ___1_db, ___2_flags, ___3_zvfs);
	#endif

	il2cpp_codegen_marshal_free(____0_filename_marshaled);
	____0_filename_marshaled = NULL;

	return returnValue;
}
// Method Definition Index: 88143
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Open_m6CDE6E15A1A94A043FF483B84715932A526DFDD7 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_filename, intptr_t* ___1_db, int32_t ___2_flags, intptr_t ___3_zvfs, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (uint8_t*, intptr_t*, int32_t, intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(void*) + sizeof(intptr_t*) + sizeof(int32_t) + sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_open_v2", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	uint8_t* ____0_filename_marshaled = NULL;
	if (___0_filename != NULL)
	{
		____0_filename_marshaled = reinterpret_cast<uint8_t*>((___0_filename)->GetAddressAtUnchecked(0));
	}

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_open_v2)(____0_filename_marshaled, ___1_db, ___2_flags, ___3_zvfs);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_filename_marshaled, ___1_db, ___2_flags, ___3_zvfs);
	#endif

	return returnValue;
}
// Method Definition Index: 88144
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Open16_mC73D15AD3440EF2661F8EFC2A867EE31C9C93E3D (String_t* ___0_filename, intptr_t* ___1_db, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (Il2CppChar*, intptr_t*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(Il2CppChar*) + sizeof(intptr_t*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_open16", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	Il2CppChar* ____0_filename_marshaled = NULL;
	if (___0_filename != NULL)
	{
		____0_filename_marshaled = &___0_filename->____firstChar;
	}

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_open16)(____0_filename_marshaled, ___1_db);
	#else
	int32_t returnValue = il2cppPInvokeFunc(____0_filename_marshaled, ___1_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88145
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_EnableLoadExtension_mAFFAC5F15C09EDBB8C427BBDD27B7252BC672037 (intptr_t ___0_db, int32_t ___1_onoff, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_enable_load_extension", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_enable_load_extension)(___0_db, ___1_onoff);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db, ___1_onoff);
	#endif

	return returnValue;
}
// Method Definition Index: 88146
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Close_mAAF5375BAD5920E5280ACC6423C639415E7EFA78 (intptr_t ___0_db, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_close", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_close)(___0_db);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88147
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Initialize_m304F435124113B0A8178ABDC44AFD44FACF463D6 (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_initialize", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_initialize)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// Method Definition Index: 88148
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Shutdown_m3FD675F1451569EDB62639896490F10C75FABA3C (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_shutdown", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_shutdown)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
}
// Method Definition Index: 88149
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Config_mCAB0267D34E08352FD7C4A4CB222DFD3ABCC5E62 (int32_t ___0_option, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_config", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_config)(___0_option);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_option);
	#endif

	return returnValue;
}
// Method Definition Index: 88150
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_SetDirectory_m3B30799E1F40465A1676B6A05C9972313DC768D3 (uint32_t ___0_directoryType, String_t* ___1_directoryPath, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (uint32_t, Il2CppChar*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(uint32_t) + sizeof(Il2CppChar*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_win32_set_directory", IL2CPP_CALL_C, CHARSET_UNICODE, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	Il2CppChar* ____1_directoryPath_marshaled = NULL;
	if (___1_directoryPath != NULL)
	{
		____1_directoryPath_marshaled = &___1_directoryPath->____firstChar;
	}

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_win32_set_directory)(___0_directoryType, ____1_directoryPath_marshaled);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_directoryType, ____1_directoryPath_marshaled);
	#endif

	return returnValue;
}
// Method Definition Index: 88151
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BusyTimeout_m66EA8D13E5A32D6BCA1E16FE7D8AAED356CE2FF5 (intptr_t ___0_db, int32_t ___1_milliseconds, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_busy_timeout", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_busy_timeout)(___0_db, ___1_milliseconds);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db, ___1_milliseconds);
	#endif

	return returnValue;
}
// Method Definition Index: 88152
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Changes_m0CA6C84B391B75B9B89D5115175F51D4B81BCEAC (intptr_t ___0_db, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_changes", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_changes)(___0_db);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88153
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Prepare2_m5531D11AAAEFE4C51DB0CF750D4D073930A58019 (intptr_t ___0_db, String_t* ___1_sql, int32_t ___2_numBytes, intptr_t* ___3_stmt, intptr_t ___4_pzTail, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, char*, int32_t, intptr_t*, intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(char*) + sizeof(int32_t) + sizeof(intptr_t*) + sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_prepare_v2", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	char* ____1_sql_marshaled = NULL;
	____1_sql_marshaled = il2cpp_codegen_marshal_string(___1_sql);

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_prepare_v2)(___0_db, ____1_sql_marshaled, ___2_numBytes, ___3_stmt, ___4_pzTail);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db, ____1_sql_marshaled, ___2_numBytes, ___3_stmt, ___4_pzTail);
	#endif

	il2cpp_codegen_marshal_free(____1_sql_marshaled);
	____1_sql_marshaled = NULL;

	return returnValue;
}
// Method Definition Index: 88154
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2 (intptr_t ___0_db, String_t* ___1_query, const RuntimeMethod* method) 
{
	intptr_t V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t V_1 = 0;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3073>
		intptr_t L_0 = ___0_db;
		String_t* L_1 = ___1_query;
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_2;
		L_2 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		String_t* L_3 = ___1_query;
		NullCheck(L_2);
		int32_t L_4;
		L_4 = VirtualFuncInvoker1< int32_t, String_t* >::Invoke(11, L_2, L_3);
		int32_t L_5;
		L_5 = SQLite3_Prepare2_m5531D11AAAEFE4C51DB0CF750D4D073930A58019(L_0, L_1, L_4, (&V_0), 0, NULL);
		V_1 = L_5;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3075>
		int32_t L_6 = V_1;
		if (!L_6)
		{
			goto IL_002a;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3076>
		int32_t L_7 = V_1;
		intptr_t L_8 = ___0_db;
		String_t* L_9;
		L_9 = SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5(L_8, NULL);
		SQLiteException_t7104409E8ADAC97D5B8DD8998E7C10A0DA4437DE* L_10;
		L_10 = SQLiteException_New_mBAA35B1ABD7422D5D62C6C9DE9D8BD61CB5C2920(L_7, L_9, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&SQLite3_Prepare2_mBC0448C52B777A3323376C9B59F4903D11B0D9D2_RuntimeMethod_var)));
	}

IL_002a:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3078>
		intptr_t L_11 = V_0;
		return L_11;
	}
}
// Method Definition Index: 88155
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Step_m47764101C949500F2E1E61DDAF4BCC215C342950 (intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_step", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_step)(___0_stmt);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt);
	#endif

	return returnValue;
}
// Method Definition Index: 88156
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Reset_mCCF573AD24F220FBAEA8E6C154B7737E9B45AD4E (intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_reset", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_reset)(___0_stmt);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt);
	#endif

	return returnValue;
}
// Method Definition Index: 88157
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_Finalize_m109856BC23FA51D5AE62948F98C9381A9EA08CAC (intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_finalize", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_finalize)(___0_stmt);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt);
	#endif

	return returnValue;
}
// Method Definition Index: 88158
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t SQLite3_LastInsertRowid_mDD625CFDF511A0167D291F719DB860ED845B82D1 (intptr_t ___0_db, const RuntimeMethod* method) 
{
	typedef int64_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_last_insert_rowid", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int64_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_last_insert_rowid)(___0_db);
	#else
	int64_t returnValue = il2cppPInvokeFunc(___0_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88159
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_Errmsg_m6FE2B877839224BC999C20A5D835A6B1103EBD2A (intptr_t ___0_db, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_errmsg16", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_errmsg16)(___0_db);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88160
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLite3_GetErrmsg_mB88E872BC14EC299C209139E3567210B559F51F5 (intptr_t ___0_db, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3098>
		intptr_t L_0 = ___0_db;
		intptr_t L_1;
		L_1 = SQLite3_Errmsg_m6FE2B877839224BC999C20A5D835A6B1103EBD2A(L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		String_t* L_2;
		L_2 = Marshal_PtrToStringUni_mA30F3D8587F2E51F70DF5F30A3C2910CBDAB6F20(L_1, NULL);
		return L_2;
	}
}
// Method Definition Index: 88161
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindParameterIndex_m7E9EAA9E6291ADD9991140E8B9DD82A3AEBCA572 (intptr_t ___0_stmt, String_t* ___1_name, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, char*);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(char*);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_parameter_index", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	char* ____1_name_marshaled = NULL;
	____1_name_marshaled = il2cpp_codegen_marshal_string(___1_name);

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_parameter_index)(___0_stmt, ____1_name_marshaled);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ____1_name_marshaled);
	#endif

	il2cpp_codegen_marshal_free(____1_name_marshaled);
	____1_name_marshaled = NULL;

	return returnValue;
}
// Method Definition Index: 88162
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindNull_m9C7AB23E02A0AF38C0ECEE46561509A7BD54862F (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_null", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_null)(___0_stmt, ___1_index);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88163
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindInt_m1F381D218E2410E2CA18A516F1B80CB001226BE3 (intptr_t ___0_stmt, int32_t ___1_index, int32_t ___2_val, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_int", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_int)(___0_stmt, ___1_index, ___2_val);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index, ___2_val);
	#endif

	return returnValue;
}
// Method Definition Index: 88164
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindInt64_mE1BEDBBE8D71846441873D76975FDF084497283E (intptr_t ___0_stmt, int32_t ___1_index, int64_t ___2_val, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t, int64_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t) + sizeof(int64_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_int64", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_int64)(___0_stmt, ___1_index, ___2_val);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index, ___2_val);
	#endif

	return returnValue;
}
// Method Definition Index: 88165
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindDouble_mEDD937BE65B3E374F9AFCDA8D482F9F1292C4290 (intptr_t ___0_stmt, int32_t ___1_index, double ___2_val, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t, double);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t) + sizeof(double);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_double", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_double)(___0_stmt, ___1_index, ___2_val);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index, ___2_val);
	#endif

	return returnValue;
}
// Method Definition Index: 88166
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindText_mEDC93F5CA420D62CE61DC2624453A3C76670056A (intptr_t ___0_stmt, int32_t ___1_index, String_t* ___2_val, int32_t ___3_n, intptr_t ___4_free, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t, Il2CppChar*, int32_t, intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t) + sizeof(Il2CppChar*) + sizeof(int32_t) + sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_text16", IL2CPP_CALL_C, CHARSET_UNICODE, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	Il2CppChar* ____2_val_marshaled = NULL;
	if (___2_val != NULL)
	{
		____2_val_marshaled = &___2_val->____firstChar;
	}

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_text16)(___0_stmt, ___1_index, ____2_val_marshaled, ___3_n, ___4_free);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index, ____2_val_marshaled, ___3_n, ___4_free);
	#endif

	return returnValue;
}
// Method Definition Index: 88167
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_BindBlob_mECFD37EFD7AE1CE6A7B5A63D630CC1E15CF1206A (intptr_t ___0_stmt, int32_t ___1_index, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___2_val, int32_t ___3_n, intptr_t ___4_free, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t, uint8_t*, int32_t, intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t) + sizeof(void*) + sizeof(int32_t) + sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_bind_blob", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	uint8_t* ____2_val_marshaled = NULL;
	if (___2_val != NULL)
	{
		____2_val_marshaled = reinterpret_cast<uint8_t*>((___2_val)->GetAddressAtUnchecked(0));
	}

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_bind_blob)(___0_stmt, ___1_index, ____2_val_marshaled, ___3_n, ___4_free);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index, ____2_val_marshaled, ___3_n, ___4_free);
	#endif

	return returnValue;
}
// Method Definition Index: 88168
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnCount_m1A6B1056CFC8E099C137988758E46FAF32DBCAE9 (intptr_t ___0_stmt, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_count", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_count)(___0_stmt);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt);
	#endif

	return returnValue;
}
// Method Definition Index: 88169
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnName_mE48860BBB774B8D30E0B8F628D05DDC85C914F34 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_name", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_name)(___0_stmt, ___1_index);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88170
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnName16Internal_m296D10EEB4C133C71292AD9AD27E6032C9E5D760 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_name16", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_name16)(___0_stmt, ___1_index);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88171
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLite3_ColumnName16_mFF172F2610B235D30624EEFC6A10BA7AE6B69844 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3132>
		intptr_t L_0 = ___0_stmt;
		int32_t L_1 = ___1_index;
		intptr_t L_2;
		L_2 = SQLite3_ColumnName16Internal_m296D10EEB4C133C71292AD9AD27E6032C9E5D760(L_0, L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		String_t* L_3;
		L_3 = Marshal_PtrToStringUni_mA30F3D8587F2E51F70DF5F30A3C2910CBDAB6F20(L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 88172
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnType_m4449C0C57377694A1CA0C50EC93C67D5BB2D65BC (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_type", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_type)(___0_stmt, ___1_index);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88173
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnInt_m3674CF3E07B2D0127DDA59AE7C154E402A5160EF (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_int", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_int)(___0_stmt, ___1_index);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88174
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t SQLite3_ColumnInt64_m72215BA39F473B24D8442AAA50A12D37024C7A08 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef int64_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_int64", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int64_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_int64)(___0_stmt, ___1_index);
	#else
	int64_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88175
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double SQLite3_ColumnDouble_mE4F9CDF44BEF62E61DB8EDB332865923E7B17A7B (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef double (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_double", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	double returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_double)(___0_stmt, ___1_index);
	#else
	double returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88176
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnText_m2DD2B44A67887C7864DE4A87EB464D618DD962FB (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_text", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_text)(___0_stmt, ___1_index);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88177
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnText16_m17C0B6B852576E3369DBF3C8C8F1BA3D7C002254 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_text16", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_text16)(___0_stmt, ___1_index);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88178
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t SQLite3_ColumnBlob_mB0E992DF4C8C119993796A69B160153D91688D35 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef intptr_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_blob", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	intptr_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_blob)(___0_stmt, ___1_index);
	#else
	intptr_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88179
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ColumnBytes_m79D6917064332E241C14666AC5E17E07782A554B (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t, int32_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t) + sizeof(int32_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_column_bytes", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_column_bytes)(___0_stmt, ___1_index);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_stmt, ___1_index);
	#endif

	return returnValue;
}
// Method Definition Index: 88180
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SQLite3_ColumnString_mC7495ED684AF170F31724D26EF5BB4EBA78E0E94 (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3161>
		intptr_t L_0 = ___0_stmt;
		int32_t L_1 = ___1_index;
		intptr_t L_2;
		L_2 = SQLite3_ColumnText16_m17C0B6B852576E3369DBF3C8C8F1BA3D7C002254(L_0, L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		String_t* L_3;
		L_3 = Marshal_PtrToStringUni_mA30F3D8587F2E51F70DF5F30A3C2910CBDAB6F20(L_2, NULL);
		return L_3;
	}
}
// Method Definition Index: 88181
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* SQLite3_ColumnByteArray_m09025DD6AB983E61366EFCB4F1500F7EA24CEC5E (intptr_t ___0_stmt, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3166>
		intptr_t L_0 = ___0_stmt;
		int32_t L_1 = ___1_index;
		int32_t L_2;
		L_2 = SQLite3_ColumnBytes_m79D6917064332E241C14666AC5E17E07782A554B(L_0, L_1, NULL);
		V_0 = L_2;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3167>
		int32_t L_3 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_3);
		V_1 = L_4;
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3168>
		int32_t L_5 = V_0;
		if ((((int32_t)L_5) <= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3169>
		intptr_t L_6 = ___0_stmt;
		int32_t L_7 = ___1_index;
		intptr_t L_8;
		L_8 = SQLite3_ColumnBlob_mB0E992DF4C8C119993796A69B160153D91688D35(L_6, L_7, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_1;
		int32_t L_10 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var);
		Marshal_Copy_mF7402FFDB520EA1B8D1C32B368DBEE4B13F1BE77(L_8, L_9, 0, L_10, NULL);
	}

IL_0022:
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:3170>
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = V_1;
		return L_11;
	}
}
// Method Definition Index: 88182
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_ExtendedErrCode_mE53EAE79412B17719370EA83EF845896409E4E68 (intptr_t ___0_db, const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) (intptr_t);
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = sizeof(intptr_t);
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_extended_errcode", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_extended_errcode)(___0_db);
	#else
	int32_t returnValue = il2cppPInvokeFunc(___0_db);
	#endif

	return returnValue;
}
// Method Definition Index: 88183
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SQLite3_LibVersionNumber_m2C388472E0DC6C13BA5F5A2DD8BB226EA30D52C5 (const RuntimeMethod* method) 
{
	typedef int32_t (CDECL *PInvokeFunc) ();
	#if !FORCE_PINVOKE_INTERNAL && !FORCE_PINVOKE_sqlite3_INTERNAL
	static PInvokeFunc il2cppPInvokeFunc;
	if (il2cppPInvokeFunc == NULL)
	{
		int parameterSize = 0;
		il2cppPInvokeFunc = il2cpp_codegen_resolve_pinvoke<PInvokeFunc>(IL2CPP_NATIVE_STRING("sqlite3"), "sqlite3_libversion_number", IL2CPP_CALL_C, CHARSET_NOT_SPECIFIED, parameterSize, false);
		IL2CPP_ASSERT(il2cppPInvokeFunc != NULL);
	}
	#endif

	#if FORCE_PINVOKE_INTERNAL || FORCE_PINVOKE_sqlite3_INTERNAL
	int32_t returnValue = reinterpret_cast<PInvokeFunc>(sqlite3_libversion_number)();
	#else
	int32_t returnValue = il2cppPInvokeFunc();
	#endif

	return returnValue;
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
// Method Definition Index: 88184
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t U3CPrivateImplementationDetailsU3E_ComputeStringHash_m6EA1F233618497AEFF8902A5EDFA24C74E2F2876 (String_t* ___0_s, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		String_t* L_0 = ___0_s;
		if (!L_0)
		{
			goto IL_002a;
		}
	}
	{
		V_0 = ((int32_t)-2128831035);
		V_1 = 0;
		goto IL_0021;
	}

IL_000d:
	{
		String_t* L_1 = ___0_s;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		Il2CppChar L_3;
		L_3 = String_get_Chars_mC49DF0CD2D3BE7BE97B3AD9C995BE3094F8E36D3(L_1, L_2, NULL);
		uint32_t L_4 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_multiply(((int32_t)((int32_t)L_3^(int32_t)L_4)), ((int32_t)16777619)));
		int32_t L_5 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
	}

IL_0021:
	{
		int32_t L_6 = V_1;
		String_t* L_7 = ___0_s;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_7, NULL);
		if ((((int32_t)L_6) < ((int32_t)L_8)))
		{
			goto IL_000d;
		}
	}

IL_002a:
	{
		uint32_t L_9 = V_0;
		return L_9;
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
// Method Definition Index: 87929
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* ColumnInfo_get_Name_m58406BCC746124ACF825EC2F71A33EC51EA787E2_inline (ColumnInfo_tADDAD99ABAC001A3A2EADFD5DBF7DAB0BA99A4B2* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:563>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88006
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Column_get_Name_mCD04FF5441F38141B4208B04398DA68BB9FBD959_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1864>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87951
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_ConnectionString_m86572BCB05C4F3AB9ADB3847FAECFB4B55A97876_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1579>
		String_t* L_0 = ___0_value;
		__this->___U3CConnectionStringU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CConnectionStringU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87955
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_StoreDateTimeAsTicks_mE61C0DD29C9985A25FBCDEBF7BF43389C5E69C23_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1581>
		bool L_0 = ___0_value;
		__this->___U3CStoreDateTimeAsTicksU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87953
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteConnectionString_set_DatabasePath_mE625A3627858ECFC73B7F530C066CE3C83716BC0_inline (SQLiteConnectionString_tAB6A6F83E42333E01C348CBA36550FDCE1460664* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1580>
		String_t* L_0 = ___0_value;
		__this->___U3CDatabasePathU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CDatabasePathU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87958
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableAttribute_set_Name_m1BE9470AE2BA2E3BAD9694E4E1B78E19E8212984_inline (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1603>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87961
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ColumnAttribute_set_Name_mE3122C2539DE916052E72CC9E7971B96234FE023_inline (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1614>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87966
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IndexedAttribute_set_Name_mC9D9DA8C0FD3BD0CFC098D113AD0C38863EAC898_inline (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1635>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87968
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void IndexedAttribute_set_Order_mBB0C74DD1D10DBBBA79A98C9798E3000312E3C57_inline (IndexedAttribute_t70A306085BCBFF1F5D7B0FCED8232D45378E863F* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1636>
		int32_t L_0 = ___0_value;
		__this->___U3COrderU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87979
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void MaxLengthAttribute_set_Value_m769CB0382163AFC0547A8237C646995EFA1EBC29_inline (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1675>
		int32_t L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87982
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void CollationAttribute_set_Value_m879958EE7A8C28BEE1D60FF7F57DF65736377F0A_inline (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1686>
		String_t* L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CValueU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87986
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_MappedType_mD0220B466756EA9D6E96E80B7DABDC5136638832_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1701>
		Type_t* L_0 = ___0_value;
		__this->___U3CMappedTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CMappedTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87985
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* TableMapping_get_MappedType_mEFC30D7C1A5CA7FE335BD3EA01B759170A16B6FA_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1701>
		Type_t* L_0 = __this->___U3CMappedTypeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87957
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* TableAttribute_get_Name_m28941E0E3D074B4D9AC32C13886B62B9678EB7C1_inline (TableAttribute_tC017BC787AD8FFE91E277918E16897BCBEE8A534* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1603>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87988
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_TableName_m74BB32CC2B1F03EB818461E7B8B7608E443D05A5_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1703>
		String_t* L_0 = ___0_value;
		__this->___U3CTableNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CTableNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87990
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_Columns_mB809C3C4C606ABECA6A7C39817E85C49E0580871_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1705>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = ___0_value;
		__this->___U3CColumnsU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CColumnsU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87989
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* TableMapping_get_Columns_m154A3DA448447050159EFFE005D97A4FB0B6C579_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1705>
		ColumnU5BU5D_t13AFD0F4FD82CE35383F87FEE2A9207E5D975960* L_0 = __this->___U3CColumnsU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88013
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsAutoInc_m0450ED22AB791989655C7FD559763909340463A9_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1872>
		bool L_0 = __this->___U3CIsAutoIncU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88017
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsPK_m93BA49BEDF4C9040B9D88F13F2FFEE11D4FD97C7_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1875>
		bool L_0 = __this->___U3CIsPKU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87992
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_PK_m65E0749BAD788A1FE4087774C2EB2DE22E2DD6F7_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1707>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = ___0_value;
		__this->___U3CPKU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CPKU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87997
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_HasAutoIncPK_m11254701AD04373CFD39137AB076C7735E6F1FF0_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1767>
		bool L_0 = ___0_value;
		__this->___U3CHasAutoIncPKU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 87991
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* TableMapping_get_PK_m60262F211F1A2F9C31183BBD63849106D0D2A76E_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1707>
		Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* L_0 = __this->___U3CPKU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87987
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* TableMapping_get_TableName_m8CA81DD62C564FC45C20182A70BE57CBAD16356C_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1703>
		String_t* L_0 = __this->___U3CTableNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87994
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TableMapping_set_GetByPrimaryKeySql_m2E681BF7B6CC67FDF742C2F8FC721A23C28A8215_inline (TableMapping_t5D7779FD498D51EA158D4530D6DE7F3306346966* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1709>
		String_t* L_0 = ___0_value;
		__this->___U3CGetByPrimaryKeySqlU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CGetByPrimaryKeySqlU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88009
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Column_get_ColumnType_mE2D5ABA4816C0824DA401FB17C8C7C262CD94A39_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1868>
		Type_t* L_0 = __this->___U3CColumnTypeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88086
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_CommandText_mF815B54C9CC7655C4EFD985B018A7F2BCB801D25_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2368>
		String_t* L_0 = ___0_value;
		__this->___U3CCommandTextU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCommandTextU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87960
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* ColumnAttribute_get_Name_m77A6DCA8A8508839AAF308D8A8FAFB0AE02E56B6_inline (ColumnAttribute_t77511FC8753FBCFC199416A63847764E327C45A4* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1614>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88007
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Name_mD882DC58740CE81E425CB2A31F3DCA0F0E50894D_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1864>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88010
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_ColumnType_m7CC823907CE0417707286D87E8B09356F56B3684_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1868>
		Type_t* L_0 = ___0_value;
		__this->___U3CColumnTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CColumnTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88012
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Collation_m38950A7B621B26E1445DD71BA8EB25310A9625E2_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1870>
		String_t* L_0 = ___0_value;
		__this->___U3CCollationU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCollationU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88018
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsPK_mF1E6B6A586CB5A6C00E2AC6E9BB2C6B431F1BC2C_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1875>
		bool L_0 = ___0_value;
		__this->___U3CIsPKU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88016
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsAutoGuid_mCC042141DA8E2AC6540F48E80C5A56F8E4A9BD3A_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1873>
		bool L_0 = ___0_value;
		__this->___U3CIsAutoGuidU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88015
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsAutoGuid_m57F6E41749A0EA41B0045EAAEA737420D91BFDD6_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1873>
		bool L_0 = __this->___U3CIsAutoGuidU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88014
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsAutoInc_mB5E9C07D162A67B47AA22CAD5377FA88FB539957_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1872>
		bool L_0 = ___0_value;
		__this->___U3CIsAutoIncU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88020
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_Indices_m3CE76E6C2C8921D734C9A02DEBE747C2F46675A7_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1877>
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CIndicesU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CIndicesU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88019
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Column_get_Indices_m7031A7B3593A288E9B314065A906D1358FF0580E_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1877>
		RuntimeObject* L_0 = __this->___U3CIndicesU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88022
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_IsNullable_mFFD923C501D7848B8DC14A9B40FB52D729DF8305_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1879>
		bool L_0 = ___0_value;
		__this->___U3CIsNullableU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88024
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Column_set_MaxStringLength_mDFCF47180CF9CB10CFEF5532AF58957C487C4FA1_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1881>
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_0 = ___0_value;
		__this->___U3CMaxStringLengthU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88021
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Column_get_IsNullable_mBA3EFE8EE8CEB4F11EA0AE63AE30E8E27BF3DF7F_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1879>
		bool L_0 = __this->___U3CIsNullableU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88011
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Column_get_Collation_mFCB25D7DEC4A917028AD1119B960797354754FE4_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1870>
		String_t* L_0 = __this->___U3CCollationU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88023
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 Column_get_MaxStringLength_mAAA93C02B5F68450E5EC2E9106BF6EDBEE367FD1_inline (Column_t564DF88EC1682FE8BFF942CEA00230032EF3D671* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1881>
		Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28 L_0 = __this->___U3CMaxStringLengthU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87981
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* CollationAttribute_get_Value_m8BBDF28DFA2375F6E36CD0CA758954F6E261DC4D_inline (CollationAttribute_tD5A6B879E824B221C55E1526C2EB88FF45F26F4C* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1686>
		String_t* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87978
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t MaxLengthAttribute_get_Value_m41D0EE4D437B205AAAA56902DB7EFC0176397851_inline (MaxLengthAttribute_t9B1ED8C4B24B0AF07C272CCF039E425B6C8B68E0* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:1675>
		int32_t L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88046
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SQLiteCommand_set_CommandText_mE6FE06C0BEFC9971431441AB6A99E7DDFD0F5203_inline (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2060>
		String_t* L_0 = ___0_value;
		__this->___U3CCommandTextU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CCommandTextU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 87842
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool SQLiteConnection_get_Trace_mFF9F2DB848A04CF036DD487904E7DF71837855E2_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:160>
		bool L_0 = __this->___U3CTraceU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87838
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t SQLiteConnection_get_Handle_m5199E6BE8B689983C361CF5766A9E54B867EB1BD_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:138>
		intptr_t L_0 = __this->___U3CHandleU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88065
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Name_m6605B567612DDFD3FA9FC4557DD0F03ABE7698F8_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2293>
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88067
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Value_m63DB4E8880807D0480D3ED195430FE33717FBAD0_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2295>
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CValueU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CValueU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88045
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* SQLiteCommand_get_CommandText_mC5B929462D924D4197466FFF1EFBA48B06A6EE12_inline (SQLiteCommand_tE4EAE2C5540D8A3E978930F43369250F5063E8BF* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2060>
		String_t* L_0 = __this->___U3CCommandTextU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88066
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Binding_get_Value_mC2E67931562F6A62D66038EBEA50BA9395C77785_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2295>
		RuntimeObject* L_0 = __this->___U3CValueU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88064
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Binding_get_Name_m36460244708DECF7462EC96985049395A01BEE4F_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2293>
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88069
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Binding_set_Index_mD5F67E97A91ED368AF1055F65734E8FA474C3AB1_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2297>
		int32_t L_0 = ___0_value;
		__this->___U3CIndexU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88068
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Binding_get_Index_m5456E8E974EFC63C021CCF2AD8FC8036E8AA2C91_inline (Binding_t846C16F3FF76025D82F878E8E00A5894741580FD* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2297>
		int32_t L_0 = __this->___U3CIndexU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 87852
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool SQLiteConnection_get_StoreDateTimeAsTicks_m4F0D2FE9AD61981FA554273C956E335B1C1F9929_inline (SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:185>
		bool L_0 = __this->___U3CStoreDateTimeAsTicksU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 2560
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) 
{
	{
		int64_t L_0 = __this->____ticks;
		return L_0;
	}
}
// Method Definition Index: 2557
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TimeSpan__ctor_m061B122FA11D2063FE751C1F1D019DF1C8B10B1F_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, int64_t ___0_ticks, const RuntimeMethod* method) 
{
	{
		int64_t L_0 = ___0_ticks;
		__this->____ticks = L_0;
		return;
	}
}
// Method Definition Index: 88084
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Connection_mCCBE4206E6F940C3762DDF7EC4E7C75174145E23_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2366>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = ___0_value;
		__this->___U3CConnectionU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CConnectionU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 88083
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* PreparedSqlLiteInsertCommand_get_Connection_mBB8F6B07CDA2CF1A8386A0FBE5C3FD61E15E74CA_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2366>
		SQLiteConnection_t7E2BA1E4CC3809FD458BFD2813B706A91189DCC4* L_0 = __this->___U3CConnectionU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88085
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* PreparedSqlLiteInsertCommand_get_CommandText_m1774FAC339AF3EE7649470C4F02912EFED8E9214_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2368>
		String_t* L_0 = __this->___U3CCommandTextU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88081
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PreparedSqlLiteInsertCommand_get_Initialized_mCA24A887ADAD977158DC4E161DC05D6A0041703B_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2364>
		bool L_0 = __this->___U3CInitializedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 88088
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Statement_mC87A23AD8B6856E34DC7B2020EA0188AFA737D07_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, intptr_t ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2370>
		intptr_t L_0 = ___0_value;
		__this->___U3CStatementU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88082
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PreparedSqlLiteInsertCommand_set_Initialized_mEE003DDBDE4E99119A83428683D170BBB556ADAB_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2364>
		bool L_0 = ___0_value;
		__this->___U3CInitializedU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 88087
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR intptr_t PreparedSqlLiteInsertCommand_get_Statement_m29BC704221EF28CEECA30BFE4E52217430CC719D_inline (PreparedSqlLiteInsertCommand_t2E0FDB355A754A9BB3DCC8163BA880F5B8161CC6* __this, const RuntimeMethod* method) 
{
	{
		//<source_info:C:/Users/USER/Desktop/RA-education-main/RA-Education-main/Assets/SQLite4Unity3d/SQLite.cs:2370>
		intptr_t L_0 = __this->___U3CStatementU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 3924
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B_inline (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) 
{
	{
		intptr_t L_0 = ___0_value1;
		intptr_t L_1 = ___1_value2;
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 705
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength;
		return L_0;
	}
}
// Method Definition Index: 11334
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
// Method Definition Index: 2193
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_mCF2FD8B3055FA87FC9C504F2122B3B0FAEDE3EC9_gshared_inline (Nullable_1_tCF32C56A2641879C053C86F273C0C6EC1B40BC28* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
// Method Definition Index: 11323
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
// Method Definition Index: 11384
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
