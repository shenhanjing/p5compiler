      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20164:42: note:   template argument deduction/substitution failed:
20164 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part6_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20163:5: note: candidate: ‘p5Sim::Part6_S::Part6_S(p5Sim::Part6_S&&)’
20163 |     Part6_S(Part6_S&&) noexcept = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20163:5: note:   conversion of argument 1 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20162:5: note: candidate: ‘p5Sim::Part6_S::Part6_S(const p5Sim::Part6_S&)’
20162 |     Part6_S(const Part6_S&) = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20162:5: note:   conversion of argument 1 would be ill-formed:
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:289:353: error: no matching function for call to ‘p5Sim::IfitInfo_S::IfitInfo_S(<brace-enclosed initializer list>)’
  289 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFIT_DT, IfitInfo_S{0, 0}}}, Part6_S{TelemetryInfo_S{(TELEMETRY_TYPE_MASK - 1), IfitInfo_S{0, 4}}})),  // tag=2
      |                                                                                                                                                                                                                                                                                                                                                                 ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19545:5: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
19545 |     IfitInfo_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19545:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19540:5: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(uint64_t, p5Sim::ConstEnumTag)’
19540 |     IfitInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19540:45: note:   no known conversion for argument 2 from ‘int’ to ‘p5Sim::ConstEnumTag’
19540 |     IfitInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |                                ~~~~~~~~~~~~~^~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19535:14: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(uint64_t)’
19535 |     explicit IfitInfo_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19535:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19530:14: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(p5Sim::NullTag)’
19530 |     explicit IfitInfo_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19530:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19525:5: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S()’
19525 |     IfitInfo_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19525:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19512:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IfitInfo_S>::value)), int>::type <anonymous> > p5Sim::IfitInfo_S::IfitInfo_S(const U&)’
19512 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IfitInfo_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
