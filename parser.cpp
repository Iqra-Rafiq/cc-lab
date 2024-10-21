#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

enum TokenType {
    T_INT, T_FLOAT, T_DOUBLE, T_STRING, T_BOOL, T_CHAR,
    T_ID, T_NUM, T_IF, T_ELSE, T_RETURN,
    T_ASSIGN, T_PLUS, T_MINUS, T_MUL, T_DIV, 
    T_LPAREN, T_RPAREN, T_LBRACE, T_RBRACE,  
    T_SEMICOLON, T_GT, T_EOF,
};

struct Token {
    TokenType type;
    string value;
    size_t line; // Line number for error reporting
};

class Lexer {
private:
    string src;
    size_t pos;
    size_t line;
    unordered_map<string, TokenType> keywords;

public:
    Lexer(const string &src) : pos(0), line(1), keywords({
        {"int", T_INT}, {"float", T_FLOAT}, {"double", T_DOUBLE},
        {"string", T_STRING}, {"bool", T_BOOL}, {"char", T_CHAR},
        {"if", T_IF}, {"else", T_ELSE}, {"return", T_RETURN}
    }) {
        this->src = src;  
    }

    vector<Token> tokenize() {
        vector<Token> tokens;
        while (pos < src.size()) {
            char current = src[pos];
            if (isspace(current)) {
                if (current == '\n') line++;
                pos++;
                continue;
            }
            if (isdigit(current)) {
                tokens.push_back(Token{T_NUM, consumeNumber(), line});
                continue;
            }
            if (current == '"') {
                tokens.push_back(Token{T_STRING, consumeString(), line});
                continue;
            }
            if (current == '\'') {
                tokens.push_back(Token{T_CHAR, consumeChar(), line});
                continue;
            }
            if (isalpha(current)) {
                string word = consumeWord();
                auto it = keywords.find(word);
                if (it != keywords.end()) {
                    tokens.push_back(Token{it->second, word, line});
                } else {
                    tokens.push_back(Token{T_ID, word, line});
                }
                continue;
            }
            switch (current) {
                case '=': tokens.push_back(Token{T_ASSIGN, "=", line}); break;
                case '+': tokens.push_back(Token{T_PLUS, "+", line}); break;
                case '-': tokens.push_back(Token{T_MINUS, "-", line}); break;
                case '*': tokens.push_back(Token{T_MUL, "*", line}); break;
                case '/': tokens.push_back(Token{T_DIV, "/", line}); break;
                case '(': tokens.push_back(Token{T_LPAREN, "(", line}); break;
                case ')': tokens.push_back(Token{T_RPAREN, ")", line}); break;
                case '{': tokens.push_back(Token{T_LBRACE, "{", line}); break;  
                case '}': tokens.push_back(Token{T_RBRACE, "}", line}); break;  
                case ';': tokens.push_back(Token{T_SEMICOLON, ";", line}); break;
                case '>': tokens.push_back(Token{T_GT, ">", line}); break;
                default: cout << "Unexpected character: " << current << " at line " << line << endl; exit(1);
            }
            pos++;
        }
        tokens.push_back(Token{T_EOF, "", line});
        return tokens;
    }

    string consumeNumber() {
        size_t start = pos;
        while (pos < src.size() && (isdigit(src[pos]) || src[pos] == '.')) pos++;
        return src.substr(start, pos - start);
    }

    string consumeWord() {
        size_t start = pos;
        while (pos < src.size() && isalnum(src[pos])) pos++;
        return src.substr(start, pos - start);
    }

    string consumeString() {
        size_t start = pos; // Save the start position
        pos++; // Skip the opening quote
        while (pos < src.size() && src[pos] != '"') {
            if (src[pos] == '\n') {
                line++; // Increment line number if a newline is encountered
            }
            pos++;
        }
        if (pos < src.size()) {
            pos++; // Skip the closing quote
            return src.substr(start, pos - start); // Return the whole string including quotes
        } else {
            cout << "Unterminated string literal at line " << line << endl;
            exit(1);
        }
    }

    string consumeChar() {
        size_t start = pos; // Save the start position
        pos++; // Skip the opening quote
        if (pos < src.size() && src[pos] != '\'') {
            pos++; // Skip the character
        }
        if (pos < src.size() && src[pos] == '\'') {
            pos++; // Skip the closing quote
            return src.substr(start, pos - start); // Return the whole char literal including quotes
        } else {
            cout << "Unterminated character literal at line " << line << endl;
            exit(1);
        }
    }
};

class Parser {
public:
    Parser(const vector<Token> &tokens) : tokens(tokens), pos(0) {}

    void parseProgram() {
        while (tokens[pos].type != T_EOF) {
            parseStatement();
        }
        cout << "Parsing completed successfully! No Syntax Error" << endl;
    }

private:
    vector<Token> tokens;
    size_t pos;

    void parseStatement() {
        if (tokens[pos].type == T_INT || tokens[pos].type == T_FLOAT || 
            tokens[pos].type == T_DOUBLE || tokens[pos].type == T_STRING || 
            tokens[pos].type == T_BOOL || tokens[pos].type == T_CHAR) {
            parseDeclaration();
        } else if (tokens[pos].type == T_ID) {
            parseAssignment();
        } else if (tokens[pos].type == T_IF) {
            parseIfStatement();
        } else if (tokens[pos].type == T_RETURN) {
            parseReturnStatement();
        } else if (tokens[pos].type == T_LBRACE) {  
            parseBlock();
        } else {
            cout << "Syntax error: unexpected token '" << tokens[pos].value 
                 << "' at line " << tokens[pos].line << endl;
            exit(1);
        }
    }

    void parseBlock() {
        expect(T_LBRACE);  
        while (tokens[pos].type != T_RBRACE && tokens[pos].type != T_EOF) {
            parseStatement();
        }
        expect(T_RBRACE);  
    }

    void parseDeclaration() {
        if (tokens[pos].type == T_INT) {
            expect(T_INT);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else if (tokens[pos].type == T_FLOAT) {
            expect(T_FLOAT);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else if (tokens[pos].type == T_DOUBLE) {
            expect(T_DOUBLE);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else if (tokens[pos].type == T_STRING) {
            expect(T_STRING);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else if (tokens[pos].type == T_BOOL) {
            expect(T_BOOL);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else if (tokens[pos].type == T_CHAR) {
            expect(T_CHAR);
            expect(T_ID);
            expect(T_SEMICOLON);  
        } else {
            cout << "Syntax error: unexpected token '" << tokens[pos].value 
                 << "' at line " << tokens[pos].line << endl;
            exit(1);
        }
    }

    void parseAssignment() {
        expect(T_ID);
        expect(T_ASSIGN);
        parseExpression();
        expect(T_SEMICOLON);
    }

    void parseIfStatement() {
        expect(T_IF);
        expect(T_LPAREN);
        parseExpression();
        expect(T_RPAREN);
        parseStatement();  
        if (tokens[pos].type == T_ELSE) {
            expect(T_ELSE);
            parseStatement();  
        }
    }

    void parseReturnStatement() {
        expect(T_RETURN);
        parseExpression();
        expect(T_SEMICOLON);
    }

    void parseExpression() {
        parseTerm();
        while (tokens[pos].type == T_PLUS || tokens[pos].type == T_MINUS) {
            pos++;
            parseTerm();
        }
        if (tokens[pos].type == T_GT) {
            pos++;
            parseExpression();  
        }
    }

    void parseTerm() {
        parseFactor();
        while (tokens[pos].type == T_MUL || tokens[pos].type == T_DIV) {
            pos++;
            parseFactor();
        }
    }

    void parseFactor() {
        if (tokens[pos].type == T_NUM || tokens[pos].type == T_ID || 
            tokens[pos].type == T_STRING || tokens[pos].type == T_CHAR) {
            pos++;
        } else if (tokens[pos].type == T_LPAREN) {
            expect(T_LPAREN);
            parseExpression();
            expect(T_RPAREN);
        } else {
            cout << "Syntax error: unexpected token '" << tokens[pos].value 
                 << "' at line " << tokens[pos].line << endl;
            exit(1);
        }
    }

    void expect(TokenType type) {
        if (tokens[pos].type == type) {
            pos++;
        } else {
            cout << "Syntax error: expected token type " << type 
                 << " but found '" << tokens[pos].value 
                 << "' at line " << tokens[pos].line << endl;
            exit(1);
        }
    }
};

int main() {
    string input = R"(
        int a;
        float b;
        double c;
        string name;
        bool flag;
        char letter;

        a = 5;
        b = 3.14;
        c = a + b;
        name = "Hello, World!";
        flag = true;
        letter = 'A';

        if (a > 10) {
            return c;
        } else {
            return 0;
        }
    )";

    Lexer lexer(input);
    vector<Token> tokens = lexer.tokenize();
    
    Parser parser(tokens);
    parser.parseProgram();

    return 0;
}
