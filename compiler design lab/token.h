// token.h
#ifndef TOKEN_H
#define TOKEN_H

typedef struct {
    int token;
    int line_num;
    int col_num;
} TokenInfo;

TokenInfo createTokenInfo(int token, int line_num, int col_num);

#endif /* TOKEN_H */
