import { Token } from './lexer'

export class NumberNode {
    _value: string;
    _type: string;

    constructor(token: Token) {
        this._value = token.value;
        this._type = token.type;
    }

    get value(): string {
        return this._value;
    }

    setValue(newValue: string): void {
        this._value = newValue;
    }

    get type(): string {
        return this._type;
    }

    setType(newType: string): void {
        this._type = newType;
    }
}

export class BinOpNode {
    private _value: string;
    private _type: string;
    private _left;
    private _right;

    constructor(token: Token, left, right) {
        this._value = token.value;
        this._type = token.type;
        this._left = left;
        this._right = right;
    }

    get value(): string {
        return this._value;
    }

    setValue(newValue: string): void {
        this._value = newValue;
    }

    get type(): string {
        return this._type;
    }

    setType(newType: string): void {
        this._type = newType;
    }

    get left() {
        return this._left;
    }

    setLeft(node): void {
        this._left = node;
    }

    get right() {
        return this._right;
    }

    setRight(node): void {
        this._right = node;
    }
}

export class Parser {
    public tokens: Token[];
    public tokenIdx: number = -1;
    public currentTok: Token;

    // constructor
    constructor(tokens: Token[]) {
        this.tokens = tokens;
        this.advance();
    }

    // advance
    advance(): Token {
        this.tokenIdx += 1;
        if (this.tokenIdx < this.tokens.length) {
            this.currentTok = this.tokens[this.tokenIdx];
        }
        return this.currentTok;
    }

    // factor
    factor() {
        let token: Token = this.currentTok;

        if (token.type == "integer" || token.type == "float") {
            this.advance();
            return new NumberNode(token);
        }
    }

    // term
    term() {
        let left: any = this.factor();

        while (this.currentTok.type == "multiply" || this.currentTok.type == "divide") {
            let OperatorToken: Token = this.currentTok;
            this.advance();
            let right = this.factor();
            left = new BinOpNode(OperatorToken, left, right);
        }

        return left;
    }

    // expression
    expression() {
        let left: any = this.term();
        
        while (this.currentTok.type == "add" || this.currentTok.type == "subtract") {
            let OperatorToken: Token = this.currentTok;
            this.advance();
            let right = this.term();
            left = new BinOpNode(OperatorToken, left, right);
        }
        return left;
    }

    // Parse
    Parse() {
        let result: BinOpNode = this.expression();
        return result;
    }
}