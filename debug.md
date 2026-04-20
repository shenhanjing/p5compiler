
typedef uint<4> t_porttype;

struct Part1or3_S
{
  union
  {
    t_porttype PortType;
  };
};

root@deployment-swx1416332-zngg-20260420153838-79b858bdff-znkj2:/usr1/p4c# ./build/p5c /usr1/iMA0/output/SD5993/SD5993_merged.p5 -o /usr1/iMA0/output/SD5993
Start P5 program parse.
P5 program parse success.
P5 AST written to /usr1/iMA0/output/SD5993/SD5993_mergedp5.ast.log
Open file: "/usr1/iMA0/output/SD5993/generated_enum.hpp"
Open file: "/usr1/iMA0/output/SD5993/generated_struct.hpp"
/usr1/iMA0/output/SD5993/SD5993_merged.p5(8): [--Werror=legacy] error: Cannot compute size for type t_porttype
    t_porttype PortType;
    ^^^^^^^^^^
Open file: "/usr1/iMA0/output/SD5993/generated_gtv.hpp"
Open file: "/usr1/iMA0/output/SD5993/generated_pipeline.hpp"
Open file: "/usr1/iMA0/output/SD5993/generated_pipeline.cpp"
