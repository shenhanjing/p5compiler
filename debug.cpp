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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:118: note:   candidate expects 1 argument, 2 provided
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:119: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:119: note:   candidate expects 1 argument, 2 provided
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:175: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:175: note:   candidate expects 1 argument, 2 provided
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:176: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:293:176: note:   candidate expects 1 argument, 2 provided
  293 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv4, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=6
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:118: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:118: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:119: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:119: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:175: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:175: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:176: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:176: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:277: error: no matching function for call to ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:277: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
      |                                                                                                                                                                                                                                                                                     ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:278: error: no matching function for call to ‘p5Sim::Part6_S::Part6_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
      |                                                                                                                                                                                                                                                                                      ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:339: error: no matching function for call to ‘p5Sim::TelemetryInfo_S::TelemetryInfo_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
      |                                                                                                                                                                                                                                                                                                                                                   ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:339: note:   candidate expects 1 argument, 2 provided
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
      |                                                                                                                                                                                                                                                                                                                                                   ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:294:340: error: no matching function for call to ‘p5Sim::Part6_S::Part6_S(<brace-enclosed initializer list>)’
  294 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_IFA2, Ifa2Info_S{0}}}, Part6_S{TelemetryInfo_S{TELEMETRY_TYPE_MASK, Ifa2Info_S{0}}})),  // tag=7
      |                                                                                                                                                                                                                                                                                                                                                    ^
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:295:134: error: no matching function for call to ‘p5Sim::IPv6Info_S::IPv6Info_S(<brace-enclosed initializer list>)’
  295 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=8
      |                                                                                                                                      ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17792:5: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
17792 |     IPv6Info_S(
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17792:5: note:   candidate expects 5 arguments, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17787:5: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(uint64_t, p5Sim::ConstEnumTag)’
17787 |     IPv6Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17787:25: note:   no known conversion for argument 1 from ‘<brace-enclosed initializer list>’ to ‘uint64_t’ {aka ‘long unsigned int’}
17787 |     IPv6Info_S(uint64_t value, ConstEnumTag is_const_enum)
      |                ~~~~~~~~~^~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17782:14: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(uint64_t)’
17782 |     explicit IPv6Info_S(uint64_t value)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17782:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17777:14: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(p5Sim::NullTag)’
17777 |     explicit IPv6Info_S(NullTag)
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17777:14: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17772:5: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S()’
17772 |     IPv6Info_S()
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17772:5: note:   candidate expects 0 arguments, 2 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17759:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::IPv6Info_S>::value)), int>::type <anonymous> > p5Sim::IPv6Info_S::IPv6Info_S(const U&)’
17759 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv6Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17759:42: note:   template argument deduction/substitution failed:
17759 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(IPv6Info_S)
      |                                          ^~~~~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:295:134: note:   candidate expects 1 argument, 2 provided
  295 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=8
      |                                                                                                                                      ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17758:5: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(p5Sim::IPv6Info_S&&)’
17758 |     IPv6Info_S(IPv6Info_S&&) noexcept = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17758:5: note:   candidate expects 1 argument, 2 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17757:5: note: candidate: ‘p5Sim::IPv6Info_S::IPv6Info_S(const p5Sim::IPv6Info_S&)’
17757 |     IPv6Info_S(const IPv6Info_S&) = default;
      |     ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:17757:5: note:   candidate expects 1 argument, 2 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:295:135: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  295 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IPv6Info_S{{0, 0, 0, 0, 1}, L4_PROTOCOL_NONE}}), mswitch::masked(0, 0), mswitch::masked(0, 0)),  // tag=8
      |                                                                                                                                       ^
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
