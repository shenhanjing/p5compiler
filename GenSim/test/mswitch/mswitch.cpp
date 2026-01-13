void func0()
{
    uint<8> A = 1;
    uint<8> B = 2;
    uint<8> C = 3;

    { //switch
        auto _msw = p5::mswitch::tie(A, B, C);
        int _tag = 0;
        if (p5::mswitch::match(_msw, 1, 2, 3)) _tag = 1;
        else if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 4)) _tag = 2;
        else if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 5)) _tag = 3;
        else if (p5::mswitch::match(_msw, p5::mswitch::_, 2, 1)) _tag = 4;

        switch (_tag) {
            case 1: return parse_IPv4();
            case 2:
            case 3:
            case 4: return parse_IPv6();
            default: return _parser_next(0, 0);
        }
    }
}

void func1()
{
    uint<8> A = 1;
    uint<8> B = 2;
    uint<8> C = 3;
    uint<8> Z;

    { //switch
        auto _msw = p5::mswitch::tie(A, B, C);
        int _tag = 0;
        if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 4)) _tag = 1;
        else if (p5::mswitch::match(_msw, p5::mswitch::_, 2, 1)) _tag = 2;
        else if (p5::mswitch::match(_msw, 1, 2, 3)) _tag = 3;
        else if (p5::mswitch::match(_msw, 1, 3, 3)) _tag = 4;
        else if (p5::mswitch::match(_msw, 1, 4, 3)) _tag = 5;

        switch (_tag) {
            case 1: {
                Z = 1;
                break;
            }
            case 2:
            case 3:
            case 4:
            case 5: {
                Z = 2;
                break;
            }
            default: {
                Z = 0;
                break;
            }
        }
    }
}

class TBL : public Table {
private:
    Switch &ctx;
public:
    explicit TBL(Switch &ctx_in) : ctx(ctx_in) {}

    p5::uint<8> A;
    p5::uint<8> B;
    p5::uint<8> C;
    p5::uint<8> Z;

    void apply() override {
        A = 1;
        B = 2;
        C = 3;
        { //switch
            auto _msw = p5::mswitch::tie(A, B, C);
            int _tag = 0;
            if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 4)) _tag = 1;
            else if (p5::mswitch::match(_msw, p5::mswitch::_, 2, 1)) _tag = 2;
            else if (p5::mswitch::match(_msw, 1, 2, 3)) _tag = 3;
            else if (p5::mswitch::match(_msw, 1, 3, 3)) _tag = 4;
            else if (p5::mswitch::match(_msw, 1, 4, 3)) _tag = 5;

            switch (_tag) {
                case 1: {
                    Z = 1;
                    break;
                }
                case 2:
                case 3:
                case 4:
                case 5: {
                    Z = 2;
                    break;
                }
                default: {
                    Z = 0;
                    break;
                }
            }
        }
    }
};

class TBL_key : public Table {
private:
    Switch &ctx;
public:
    explicit TBL_key(Switch &ctx_in) : ctx(ctx_in) {}

    p5::uint<8> A;
    p5::uint<8> B;
    p5::uint<8> C;
    p5::uint<8> Z;
    p5::uint<8> Y;

    void apply() override {
        A = 1;
        B = 2;
        C = 3;
        Z = 4;
        Y = 5;
        { //key
            auto _KeyBuilder = ctx.keyBuilder();
            bool _BuiltKey = true;
            { //switch
                auto _msw = p5::mswitch::tie(A, B, C);
                int _tag = 0;
                if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 4)) _tag = 1;
                else if (p5::mswitch::match(_msw, p5::mswitch::_, 2, 1)) _tag = 2;
                else if (p5::mswitch::match(_msw, 1, 2, 3)) _tag = 3;
                else if (p5::mswitch::match(_msw, 1, 3, 3)) _tag = 4;
                else if (p5::mswitch::match(_msw, 1, 4, 3)) _tag = 5;

                switch (_tag) {
                    case 1: {
                        _KeyBuilder.append(Z);
                        ctx.command = 0;
                        break;
                    }
                    case 2:{
                        _KeyBuilder.append(Z);
                        ctx.command = 1;
                        break;
                    }
                    case 3:{
                        _KeyBuilder.append(Z);
                        ctx.command = 2;
                        break;
                    }
                    case 4:
                    case 5: {
                        _KeyBuilder.append(Z);
                        ctx.command = 3;
                        break;
                    }
                    default: {
                        _BuiltKey = false;
                        break;
                    }
                }
            }
            { //switch
                auto _msw = p5::mswitch::tie(A, B, C);
                int _tag = 0;
                if (p5::mswitch::match(_msw, 1, p5::mswitch::_, 4)) _tag = 1;
                else if (p5::mswitch::match(_msw, p5::mswitch::_, 2, 1)) _tag = 2;
                else if (p5::mswitch::match(_msw, 1, 2, 3)) _tag = 3;
                else if (p5::mswitch::match(_msw, 1, 3, 3)) _tag = 4;
                else if (p5::mswitch::match(_msw, 1, 4, 3)) _tag = 5;

                switch (_tag) {
                    case 1: {
                        _KeyBuilder.append(Y);
                        ctx.command = 0;
                        break;
                    }
                    case 2:{
                        _KeyBuilder.append(Y);
                        ctx.command = 1;
                        break;
                    }
                    case 3:{
                        _KeyBuilder.append(Y);
                        ctx.command = 2;
                        break;
                    }
                    case 4:
                    case 5: {
                        _KeyBuilder.append(Y);
                        ctx.command = 3;
                        break;
                    }
                    default: {
                        _BuiltKey = false;
                        break;
                    }
                }
            }
            if (_BuiltKey) {
                _KeyBuilder.commit();
            }
        }
    }
};