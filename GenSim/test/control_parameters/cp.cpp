class TBL : public Table {
private:
    Switch &ctx;
public:
    explicit TBL(Switch &ctx_in) : ctx(ctx_in) {}

    p5::uint<8> cmd;
    p5::uint<5> tid;
    p5::uint<3> pid;
    CtrlInfo_S CtrlInfo;

    void apply() override {
        auto _KeyBuilder = ctx.keyBuilder();
        bool _BuiltKey = true;
        switch (A.to_ullong())
        {
            case 1:
            {
                _KeyBuilder.append(ctx.PART0);
                ctx.table_id = 0;
                ctx.command = 0;
                ctx.ma_id = 0;
                ctx._header_access = 0;
                ctx.decomp_profile = 0;
                ctx.control_info = (CtrlInfo_S){1};
                break;
            }
            default:
            {
                _BuiltKey = false;
                break;
            }
        }
        switch (B.to_ullong())
        {
            case 1:
            {
                _KeyBuilder.append(ctx.PART1);
                ctx.table_id = 1;
                ctx.command = 1;
                ctx.ma_id = 1;
                ctx._header_access = 1;
                ctx.decomp_profile = 1;
                ctx.control_info = (CtrlInfo_S){2};
                break;
            }
            default:
            {
                _BuiltKey = false;
                break;
            }
        }
        if (_BuiltKey) {
            _KeyBuilder.commit();
        }

        cmd = ctx._command();
        tid = ctx._table_id();
        pid = ctx._profile_id();
        CtrlInfo = ctx._control_info();
    }
};