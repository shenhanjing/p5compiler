root@deployment-swx1416332-zngg-20260420153838-79b858bdff-znkj2:/usr1/p4c# ./build/p5c /usr1/iMA0/output/SD5993/SD5993_merged.p5 -o /usr1/iMA0/output/SD5993
Start P5 program parse.
P5 program parse success.
P5 AST written to /usr1/iMA0/output/SD5993/SD5993_mergedp5.ast.log
Open file: "/usr1/iMA0/output/SD5993/generated_enum.hpp"
Open file: "/usr1/iMA0/output/SD5993/generated_struct.hpp"
[--Werror=legacy] error: Cannot compute size for type bit<32>[7]
[--Werror=legacy] error: Cannot compute size for type bit<16>[7]
[--Werror=legacy] error: Cannot compute size for type bit<32>[7]
[--Werror=legacy] error: Cannot compute size for type bit<16>[7]
[--Werror=legacy] error: Cannot compute size for type bit<32>[7]
[--Werror=legacy] error: Cannot compute size for type bit<16>[7]
/usr1/iMA0/sources/dev/SD5993/headers_dev.p5(580): [--Werror=legacy] error: Cannot compute size for type t_porttype
    t_porttype PortType;
    ^^^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(340): [--Werror=legacy] error: Cannot compute size for type t_glport
  t_glport GLTP;
  ^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(347): [--Werror=legacy] error: Cannot compute size for type t_trunk
  t_trunk TrunkID;
  ^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(354): [--Werror=legacy] error: Cannot compute size for type t_ctccauseid
  t_ctccauseid CauseID;
  ^^^^^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(363): [--Werror=legacy] error: Cannot compute size for type t_dropcauseid
  t_dropcauseid CauseID;
  ^^^^^^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(370): [--Werror=legacy] error: Cannot compute size for type t_ecmpgroup
  t_ecmpgroup NstGroupIndex;
  ^^^^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(377): [--Werror=legacy] error: Cannot compute size for type t_vpidx
  t_vpidx DvpIndex;
  ^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(384): [--Werror=legacy] error: Cannot compute size for type t_mgid
  t_mgid Mgid;
  ^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(391): [--Werror=legacy] error: Cannot compute size for type t_nhp
  t_nhp NhpIndex;
  ^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(473): [--Werror=legacy] error: Cannot compute size for type t_glport
    t_glport GLSP;
    ^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(479): [--Werror=legacy] error: Cannot compute size for type t_glport
    t_glport SrcTrunkID;
    ^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(499): [--Werror=legacy] error: Cannot compute size for type t_llport
            t_llport Lltp;
            ^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(501): [--Werror=legacy] error: Cannot compute size for type t_trunk
        t_trunk Trunk;
        ^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(517): [--Werror=legacy] error: Cannot compute size for type t_sampleid
  t_sampleid SampleID;
  ^^^^^^^^^^
/usr1/iMA0/sources/common/fv_structs.p5(523): [--Werror=legacy] error: Cannot compute size for type t_mirrorid
  t_mirrorid MirrorID;
  ^^^^^^^^^^
terminate called after throwing an instance of 'P4::Util::CompilationError'
  what():  Number of errors exceeded set maximum of 20
