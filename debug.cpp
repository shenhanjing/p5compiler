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
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19512:42: note:   template argument deduction/substitution failed:
19512 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IfitInfo_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:289:353: note:   candidate expects 1 argument, 2 provided
  289 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFIT_DT, IfitInfo_S{0, 0}}}, Part6_S{TelemetryInfo_S{(TELEMETRY_TYPE_MASK - 1), IfitInfo_S{0, 4}}})),  // tag=2
      |                                                                                                                                                                                                                                                                                                                                                                 ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19511:5: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(p5Sim::IfitInfo_S&&)’
19511 |     IfitInfo_S(IfitInfo_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19511:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19510:5: note: candidate: ‘p5Sim::IfitInfo_S::IfitInfo_S(const p5Sim::IfitInfo_S&)’
19510 |     IfitInfo_S(const IfitInfo_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19510:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:289:354: error: no matching function for call to ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(<brace-enclosed initializer list>)’
  289 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFIT_DT, IfitInfo_S{0, 0}}}, Part6_S{TelemetryInfo_S{(TELEMETRY_TYPE_MASK - 1), IfitInfo_S{0, 4}}})),  // tag=2
      |                                                                                                                                                                                                                                                                                                                                                                  ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19710:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
19710 |     TelemetryInfo_S(
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19710:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19705:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(uint64_t, p5Sim::ConstEnumTag)’
19705 |     TelemetryInfo_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19705:5: note:   conversion of argument 2 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19700:14: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(uint64_t)’
19700 |     explicit TelemetryInfo_S(uint64_t value)
      |              ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19700:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19692:14: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(p5Sim::NullTag)’
19692 |     explicit TelemetryInfo_S(NullTag)
      |              ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19692:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19684:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S()’
19684 |     TelemetryInfo_S()
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19684:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19668:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::TelemetryInfo_S>::value)), int>::type <anonymous> > p5Sim::TelemetryInfo_S::TelemetryInfo_S(const U&)’
19668 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(TelemetryInfo_S)
      |                                          ^~~~~~~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19668:42: note:   template argument deduction/substitution failed:
19668 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(TelemetryInfo_S)
      |                                          ^~~~~~~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:289:354: note:   candidate expects 1 argument, 2 provided
  289 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFIT_DT, IfitInfo_S{0, 0}}}, Part6_S{TelemetryInfo_S{(TELEMETRY_TYPE_MASK - 1), IfitInfo_S{0, 4}}})),  // tag=2
      |                                                                                                                                                                                                                                                                                                                                                                  ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19667:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(p5Sim::TelemetryInfo_S&&)’
19667 |     TelemetryInfo_S(TelemetryInfo_S&&) noexcept = default;
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19667:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19666:5: note: candidate: ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(const p5Sim::TelemetryInfo_S&)’
19666 |     TelemetryInfo_S(const TelemetryInfo_S&) = default;
      |     ^~~~~~~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:19666:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:289:355: error: no matching function for call to ‘p5Sim::Part6_S::Part6_S(<brace-enclosed initializer list>)’
  289 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFIT_DT, IfitInfo_S{0, 0}}}, Part6_S{TelemetryInfo_S{(TELEMETRY_TYPE_MASK - 1), IfitInfo_S{0, 4}}})),  // tag=2
      |                                                                                                                                                                                                                                                                                                                                                                   ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20194:5: note: candidate: ‘p5Sim::Part6_S::Part6_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20194 |     Part6_S(
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20194:5: note:   candidate expects 5 arguments, 1 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20189:5: note: candidate: ‘p5Sim::Part6_S::Part6_S(uint64_t, p5Sim::ConstEnumTag)’
20189 |     Part6_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20189:5: note:   candidate expects 2 arguments, 1 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20184:14: note: candidate: ‘p5Sim::Part6_S::Part6_S(uint64_t)’
20184 |     explicit Part6_S(uint64_t value)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20184:14: note:   conversion of argument 1 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20180:14: note: candidate: ‘p5Sim::Part6_S::Part6_S(p5Sim::NullTag)’
20180 |     explicit Part6_S(NullTag)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20180:14: note:   conversion of argument 1 would be ill-formed:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20176:5: note: candidate: ‘p5Sim::Part6_S::Part6_S()’
20176 |     Part6_S()
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20176:5: note:   candidate expects 0 arguments, 1 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20164:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part6_S>::value)), int>::type <anonymous> > p5Sim::Part6_S::Part6_S(const U&)’
20164 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part6_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:137: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:137: note:   candidate expects 1 argument, 5 provided
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:138: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:138: note:   candidate expects 1 argument, 2 provided
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:213: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:213: note:   candidate expects 1 argument, 5 provided
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:214: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:290:214: note:   candidate expects 1 argument, 2 provided
  290 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 0, 1}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=3
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:137: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:137: note:   candidate expects 1 argument, 5 provided
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:138: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:138: note:   candidate expects 1 argument, 2 provided
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:213: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:213: note:   candidate expects 1 argument, 5 provided
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:214: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:291:214: note:   candidate expects 1 argument, 2 provided
  291 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{0, 1, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=4
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:137: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:137: note:   candidate expects 1 argument, 5 provided
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                         ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:138: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:138: note:   candidate expects 1 argument, 2 provided
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                          ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:213: error: no matching function for call to ‘p5Sim::IPv4Info_S::IPv4Info_S(<brace-enclosed initializer list>)’
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17673:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17673 |     IPv4Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17674:18: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17674 |         uint64_t width,
      |         ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t, p5Sim::ConstEnumTag)’
17668 |     IPv4Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17668:5: note:   candidate expects 2 arguments, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(uint64_t)’
17663 |     explicit IPv4Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17663:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::NullTag)’
17655 |     explicit IPv4Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17655:14: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S()’
17647 |     IPv4Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17647:5: note:   candidate expects 0 arguments, 5 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv4Info_S>::value)), int>::type <anonymous> > p5Sim::IPv4Info_S::IPv4Info_S(const U&)’
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17631:42: note:   template argument deduction/substitution failed:
17631 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv4Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:213: note:   candidate expects 1 argument, 5 provided
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                                                                                                     ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(p5Sim::IPv4Info_S&&)’
17630 |     IPv4Info_S(IPv4Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17630:5: note:   candidate expects 1 argument, 5 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note: candidate: ‘p5Sim::IPv4Info_S::IPv4Info_S(const p5Sim::IPv4Info_S&)’
17629 |     IPv4Info_S(const IPv4Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17629:5: note:   candidate expects 1 argument, 5 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:214: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:292:214: note:   candidate expects 1 argument, 2 provided
  292 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv4Info_S{{1, 0, 0}, 0, 0, 0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=5
      |                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:118: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
