Generated C++ files will be saved to: /usr1/iMA0/output/SD5993/generated_output

[ RUN      ] Testing SD5993_merged.p5 ...
[  FAILED  ] g++ compilation failed for /usr1/iMA0/output/SD5993/SD5993_merged.p5:
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:3:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp: In member function ‘void p5Sim::GtvContext::pack_gtv_pgtv_to_bytes(uint8_t (&)[177], uint8_t (&)[24])’:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:1232:60: error: no matching function for call to ‘p5Sim::GtvContext::pack_to_buffers(p5Sim::MPLS_S [8], p5Sim::GtvPackedBuffer, p5Sim::PgtvPackedBuffer, std::size_t&)’
 1232 |         pack_to_buffers(MPLS, gtv_out, pgtv_out, bit_cursor);
      |                                                            ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:3:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3172:17: note: candidate: ‘static void p5Sim::GtvContext::pack_to_buffers(const p5Sim::Uint&, uint8_t (&)[177], uint8_t (&)[24], std::size_t&)’
 3172 |     static void pack_to_buffers(
      |                 ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3173:21: note:   no known conversion for argument 1 from ‘p5Sim::MPLS_S [8]’ to ‘const p5Sim::Uint&’
 3173 |         const Uint &value,
      |         ~~~~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3232:17: note: candidate: ‘template<class T> static void p5Sim::GtvContext::pack_to_buffers(const std::vector<T>&, uint8_t (&)[177], uint8_t (&)[24], std::size_t&)’
 3232 |     static void pack_to_buffers(
      |                 ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3232:17: note:   template argument deduction/substitution failed:
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:3:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:1232:60: note:   mismatched types ‘const std::vector<T>’ and ‘p5Sim::MPLS_S [8]’
 1232 |         pack_to_buffers(MPLS, gtv_out, pgtv_out, bit_cursor);
      |                                                            ^
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp: In member function ‘void p5Sim::GtvContext::unpack_gtv_pgtv_from_bytes(const uint8_t (&)[177], const uint8_t (&)[24])’:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:2177:62: error: no matching function for call to ‘p5Sim::GtvContext::unpack_from_buffers(p5Sim::MPLS_S [8], GtvPackedBuffer, PgtvPackedBuffer, std::size_t&)’
 2177 |         unpack_from_buffers(MPLS, gtv_in, pgtv_in, bit_cursor);
      |                                                              ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:3:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3189:17: note: candidate: ‘static void p5Sim::GtvContext::unpack_from_buffers(p5Sim::Uint&, const uint8_t (&)[177], const uint8_t (&)[24], std::size_t&)’
 3189 |     static void unpack_from_buffers(
      |                 ^~~~~~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3190:15: note:   no known conversion for argument 1 from ‘p5Sim::MPLS_S [8]’ to ‘p5Sim::Uint&’
 3190 |         Uint &value,
      |         ~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3244:17: note: candidate: ‘template<class T> static void p5Sim::GtvContext::unpack_from_buffers(std::vector<T>&, const uint8_t (&)[177], const uint8_t (&)[24], std::size_t&)’
 3244 |     static void unpack_from_buffers(
      |                 ^~~~~~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:3244:17: note:   template argument deduction/substitution failed:
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:3:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_gtv.hpp:2177:62: note:   mismatched types ‘std::vector<T>’ and ‘p5Sim::MPLS_S [8]’
 2177 |         unpack_from_buffers(MPLS, gtv_in, pgtv_in, bit_cursor);
      |                                                              ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp: At global scope:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:593:9: error: ‘bit’ does not name a type
  593 |         bit<8> &VaclNextHeader;
      |         ^~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:596:50: error: ‘bit’ has not been declared
  596 |         explicit VACLMYDIP_TBL(Pipeline &ctx_in, bit<8> &VaclNextHeader_in, OPAQUE_CAQM_CC_FULL_S &OpaqueCCMSICFeild_in) : ctx(ctx_in), VaclNextHeader(VaclNextHeader_in), OpaqueCCMSICFeild(OpaqueCCMSICFeild_in) {}
      |                                                  ^~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:596:53: error: expected ‘,’ or ‘...’ before ‘<’ token
  596 |         explicit VACLMYDIP_TBL(Pipeline &ctx_in, bit<8> &VaclNextHeader_in, OPAQUE_CAQM_CC_FULL_S &OpaqueCCMSICFeild_in) : ctx(ctx_in), VaclNextHeader(VaclNextHeader_in), OpaqueCCMSICFeild(OpaqueCCMSICFeild_in) {}
      |                                                     ^
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:1100:54: error: no matching function for call to ‘p5Sim::Pipeline::VACLMYDIP_TBL::VACLMYDIP_TBL(p5Sim::Pipeline&)’
 1100 |         VACLMYDIP_TBL tbVACLMYDIP = VACLMYDIP_TBL(ctx);
      |                                                      ^
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:596:18: note: candidate: ‘p5Sim::Pipeline::VACLMYDIP_TBL::VACLMYDIP_TBL(p5Sim::Pipeline&, int)’
  596 |         explicit VACLMYDIP_TBL(Pipeline &ctx_in, bit<8> &VaclNextHeader_in, OPAQUE_CAQM_CC_FULL_S &OpaqueCCMSICFeild_in) : ctx(ctx_in), VaclNextHeader(VaclNextHeader_in), OpaqueCCMSICFeild(OpaqueCCMSICFeild_in) {}
      |                  ^~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:596:18: note:   candidate expects 2 arguments, 1 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:590:11: note: candidate: ‘p5Sim::Pipeline::VACLMYDIP_TBL::VACLMYDIP_TBL(const p5Sim::Pipeline::VACLMYDIP_TBL&)’
  590 |     class VACLMYDIP_TBL {
      |           ^~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:590:11: note:   no known conversion for argument 1 from ‘p5Sim::Pipeline’ to ‘const p5Sim::Pipeline::VACLMYDIP_TBL&’
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:590:11: note: candidate: ‘p5Sim::Pipeline::VACLMYDIP_TBL::VACLMYDIP_TBL(p5Sim::Pipeline::VACLMYDIP_TBL&&)’
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:590:11: note:   no known conversion for argument 1 from ‘p5Sim::Pipeline’ to ‘p5Sim::Pipeline::VACLMYDIP_TBL&&’
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp: In member function ‘void p5Sim::Pipeline::NEXT_HEADER_OUTER_TBL::apply()’:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:118: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                      ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17552:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17552 |     IpInfo_S(
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17552:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17547:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t, p5Sim::ConstEnumTag)’
17547 |     IpInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17547:43: note:   no known conversion for argument 2 from ‘p5Sim::L4_PROTOCOL_E’ to ‘p5Sim::ConstEnumTag’
17547 |     IpInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |                              ~~~~~~~~~~~~~^~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17542:14: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t)’
17542 |     explicit IpInfo_S(uint64_t value)
      |              ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17542:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17537:14: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(p5Sim::NullTag)’
17537 |     explicit IpInfo_S(NullTag)
      |              ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17537:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17532:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S()’
17532 |     IpInfo_S()
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17532:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17519:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IpInfo_S>::value)), int>::type <anonymous> > p5Sim::IpInfo_S::IpInfo_S(const U&)’
17519 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IpInfo_S)
      |                                          ^~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17519:42: note:   template argument deduction/substitution failed:
17519 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IpInfo_S)
      |                                          ^~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:118: note:   candidate expects 1 argument, 2 provided
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                      ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17518:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(p5Sim::IpInfo_S&&)’
17518 |     IpInfo_S(IpInfo_S&&) noexcept = default;
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17518:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17517:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(const p5Sim::IpInfo_S&)’
17517 |     IpInfo_S(const IpInfo_S&) = default;
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17517:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:119: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                       ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20081:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20081 |     Part2or4_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20081:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20076:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t, p5Sim::ConstEnumTag)’
20076 |     Part2or4_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20076:5: note:   conversion of argument 2 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20071:14: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t)’
20071 |     explicit Part2or4_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20071:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20062:14: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(p5Sim::NullTag)’
20062 |     explicit Part2or4_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20062:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20053:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S()’
20053 |     Part2or4_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20053:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20036:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part2or4_S>::value)), int>::type <anonymous> > p5Sim::Part2or4_S::Part2or4_S(const U&)’
20036 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part2or4_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20036:42: note:   template argument deduction/substitution failed:
20036 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part2or4_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:119: note:   candidate expects 1 argument, 2 provided
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                       ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20035:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(p5Sim::Part2or4_S&&)’
20035 |     Part2or4_S(Part2or4_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20035:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20034:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(const p5Sim::Part2or4_S&)’
20034 |     Part2or4_S(const Part2or4_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20034:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:175: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                                                                               ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17552:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17552 |     IpInfo_S(
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17552:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17547:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t, p5Sim::ConstEnumTag)’
17547 |     IpInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17547:43: note:   no known conversion for argument 2 from ‘p5Sim::L4_PROTOCOL_E’ to ‘p5Sim::ConstEnumTag’
17547 |     IpInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |                              ~~~~~~~~~~~~~^~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17542:14: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(uint64_t)’
17542 |     explicit IpInfo_S(uint64_t value)
      |              ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17542:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17537:14: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(p5Sim::NullTag)’
17537 |     explicit IpInfo_S(NullTag)
      |              ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17537:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17532:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S()’
17532 |     IpInfo_S()
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17532:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17519:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IpInfo_S>::value)), int>::type <anonymous> > p5Sim::IpInfo_S::IpInfo_S(const U&)’
17519 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IpInfo_S)
      |                                          ^~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17519:42: note:   template argument deduction/substitution failed:
17519 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IpInfo_S)
      |                                          ^~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:175: note:   candidate expects 1 argument, 2 provided
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                                                                               ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17518:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(p5Sim::IpInfo_S&&)’
17518 |     IpInfo_S(IpInfo_S&&) noexcept = default;
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17518:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17517:5: note: candidate: ‘p5Sim::IpInfo_S::IpInfo_S(const p5Sim::IpInfo_S&)’
17517 |     IpInfo_S(const IpInfo_S&) = default;
      |     ^~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17517:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:176: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                                                                                ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20081:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20081 |     Part2or4_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20081:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20076:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t, p5Sim::ConstEnumTag)’
20076 |     Part2or4_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20076:5: note:   conversion of argument 2 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20071:14: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(uint64_t)’
20071 |     explicit Part2or4_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20071:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20062:14: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(p5Sim::NullTag)’
20062 |     explicit Part2or4_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20062:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20053:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S()’
20053 |     Part2or4_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20053:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20036:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part2or4_S>::value)), int>::type <anonymous> > p5Sim::Part2or4_S::Part2or4_S(const U&)’
20036 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part2or4_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20036:42: note:   template argument deduction/substitution failed:
20036 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part2or4_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:176: note:   candidate expects 1 argument, 2 provided
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                                                                                ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20035:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(p5Sim::Part2or4_S&&)’
20035 |     Part2or4_S(Part2or4_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20035:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20034:5: note: candidate: ‘p5Sim::Part2or4_S::Part2or4_S(const p5Sim::Part2or4_S&)’
20034 |     Part2or4_S(const Part2or4_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20034:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:288:277: error: no matching function for call to ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(<brace-enclosed initializer list>)’
  288 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=1
      |                                                                                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19710:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
19710 |     TelemetryInfo_S(
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19710:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19705:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(uint64_t, p5Sim::ConstEnumTag)’
19705 |     TelemetryInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19705:50: note:   no known conversion for argument 2 from ‘p5Sim::Ifa2Info_S’ to ‘p5Sim::ConstEnumTag’
19705 |     TelemetryInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |                                     ~~~~~~~~~~~~~^~~~~~~~~~~~~
