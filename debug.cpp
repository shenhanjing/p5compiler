  296 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 0, 1}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 0, 1}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=9
      |                                                                                                                                                                                                                                                                                   ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20143:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20143 |     Part5_S(
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20146:52: note:   no known conversion for argument 3 from ‘<brace-enclosed initializer list>’ to ‘std::shared_ptr<std::vector<unsigned char> >’
20146 |         std::shared_ptr<std::vector<UINT_CHUNK_T>> data,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, p5Sim::ConstEnumTag)’
20138 |     Part5_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note:   candidate expects 2 arguments, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t)’
20133 |     explicit Part5_S(uint64_t value)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::NullTag)’
20126 |     explicit Part5_S(NullTag)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note: candidate: ‘p5Sim::Part5_S::Part5_S()’
20119 |     Part5_S()
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note:   candidate expects 0 arguments, 4 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part5_S>::value)), int>::type <anonymous> > p5Sim::Part5_S::Part5_S(const U&)’
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note:   template argument deduction/substitution failed:
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:296:275: note:   candidate expects 1 argument, 4 provided
  296 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 0, 1}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 0, 1}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=9
      |                                                                                                                                                                                                                                                                                   ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::Part5_S&&)’
20103 |     Part5_S(Part5_S&&) noexcept = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(const p5Sim::Part5_S&)’
20102 |     Part5_S(const Part5_S&) = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note:   candidate expects 1 argument, 4 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:118: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:118: note:   candidate expects 1 argument, 2 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:119: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:119: note:   candidate expects 1 argument, 2 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:175: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:175: note:   candidate expects 1 argument, 2 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:176: error: no matching function for call to ‘p5Sim::Part2or4_S::Part2or4_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:176: note:   candidate expects 1 argument, 2 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
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
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:234: error: no matching function for call to ‘p5Sim::Part5_S::Part5_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
      |                                                                                                                                                                                                                                          ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20143:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20143 |     Part5_S(
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20146:52: note:   no known conversion for argument 3 from ‘<brace-enclosed initializer list>’ to ‘std::shared_ptr<std::vector<unsigned char> >’
20146 |         std::shared_ptr<std::vector<UINT_CHUNK_T>> data,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, p5Sim::ConstEnumTag)’
20138 |     Part5_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note:   candidate expects 2 arguments, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t)’
20133 |     explicit Part5_S(uint64_t value)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::NullTag)’
20126 |     explicit Part5_S(NullTag)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note: candidate: ‘p5Sim::Part5_S::Part5_S()’
20119 |     Part5_S()
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note:   candidate expects 0 arguments, 4 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part5_S>::value)), int>::type <anonymous> > p5Sim::Part5_S::Part5_S(const U&)’
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note:   template argument deduction/substitution failed:
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:234: note:   candidate expects 1 argument, 4 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
      |                                                                                                                                                                                                                                          ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::Part5_S&&)’
20103 |     Part5_S(Part5_S&&) noexcept = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(const p5Sim::Part5_S&)’
20102 |     Part5_S(const Part5_S&) = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note:   candidate expects 1 argument, 4 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:275: error: no matching function for call to ‘p5Sim::Part5_S::Part5_S(<brace-enclosed initializer list>)’
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
      |                                                                                                                                                                                                                                                                                   ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20143:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, uint64_t, std::shared_ptr<std::vector<unsigned char> >, std::shared_ptr<p5Sim::Uint>, bool)’
20143 |     Part5_S(
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20146:52: note:   no known conversion for argument 3 from ‘<brace-enclosed initializer list>’ to ‘std::shared_ptr<std::vector<unsigned char> >’
20146 |         std::shared_ptr<std::vector<UINT_CHUNK_T>> data,
      |         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t, p5Sim::ConstEnumTag)’
20138 |     Part5_S(uint64_t value, ConstEnumTag is_const_enum)
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20138:5: note:   candidate expects 2 arguments, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(uint64_t)’
20133 |     explicit Part5_S(uint64_t value)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20133:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::NullTag)’
20126 |     explicit Part5_S(NullTag)
      |              ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20126:14: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note: candidate: ‘p5Sim::Part5_S::Part5_S()’
20119 |     Part5_S()
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20119:5: note:   candidate expects 0 arguments, 4 provided
In file included from /usr1/p4c/GenSimv2/include/uint.hpp:14,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:4,
                 from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note: candidate: ‘template<class U, typename std::enable_if<(std::is_base_of<p5Sim::Uint, typename std::decay<_Tp>::type>::value && (! std::is_same<typename std::decay<_Tp>::type, p5Sim::Part5_S>::value)), int>::type <anonymous> > p5Sim::Part5_S::Part5_S(const U&)’
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20104:42: note:   template argument deduction/substitution failed:
20104 |     DECLARE_UINT_SHALLOW_CONVERTING_CTOR(Part5_S)
      |                                          ^~~~~~~
/usr1/p4c/GenSimv2/include/project_macros.hpp:164:14: note: in definition of macro ‘DECLARE_UINT_SHALLOW_CONVERTING_CTOR’
  164 |     explicit CLASS_NAME(const U& rhs)                                                               \
      |              ^~~~~~~~~~
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:297:275: note:   candidate expects 1 argument, 4 provided
  297 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{0, 1, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=10
      |                                                                                                                                                                                                                                                                                   ^
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:1:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(p5Sim::Part5_S&&)’
20103 |     Part5_S(Part5_S&&) noexcept = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20103:5: note:   candidate expects 1 argument, 4 provided
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note: candidate: ‘p5Sim::Part5_S::Part5_S(const p5Sim::Part5_S&)’
20102 |     Part5_S(const Part5_S&) = default;
      |     ^~~~~~~
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_struct.hpp:20102:5: note:   candidate expects 1 argument, 4 provided
In file included from /usr1/iMA0/output/SD5993/generated_output/SD5993_merged/test_wrapper.cpp:4:
/usr1/iMA0/output/SD5993/generated_output/SD5993_merged/generated_pipeline.hpp:298:118: error: no matching function for call to ‘p5Sim::IpInfo_S::IpInfo_S(<brace-enclosed initializer list>)’
  298 |                             mswitch::CaseClause(mswitch::masked(Part2or4_S{L3_TYPE_IPv6, IpInfo_S{0, L4_PROTOCOL_NONE}}, Part2or4_S{L3_TYPE_MASK, IpInfo_S{0, L4_PROTOCOL_NONE}}), mswitch::masked(Part5_S{0, 0, {{1, 0, 0}}, {{0, 0, 0}}}, Part5_S{0, 0, {{1, 0, 0}}, {{0, 0, 0}}}), mswitch::masked(0, 0)),  // tag=11
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
