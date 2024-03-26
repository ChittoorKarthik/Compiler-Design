#include "token.h"

TokenInfo createTokenInfo(int token, int line_num, int col_num) {
    TokenInfo info;
    info.token = token;
    info.line_num = line_num;
    info.col_num = col_num;
    return info;
}
