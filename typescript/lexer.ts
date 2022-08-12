export class Token {
    type: string;
    value: string;

    constructor(_type:string, _value:string) {
        this.type = _type;
        this.value = _value;
    }
}

const keywords: string[] = [
    "if",
    "else",
    "elsif",
    "while",
    "for",
    "string",
    "int",
    "float"
];

const operators: string[] = [
    '+',
    '-',
    '/',
    '*',
    '<',
    '>',
    '=',
    '!',
    '(',
    ')'
];

const operatorNames: string[] = [
    "add",
    "subtract",
    "divide",
    "multiply",
    "greater than",
    "less than",
    "assignment",
    "logical not",
    "left bracket",
    "right bracket"
];

export const lex = (text: string): Token => {
    for (let i = 0; i < keywords.length; i++) {
        if (text == keywords[i]) {
            return new Token("keyword", text);
        }
    }

    if (text.length > 1) {
        let twoCharOp: string = "";
        let twoCharName: string = "";
        for (let i = 0; i < operators.length; i++) {
            for (let j = 0; j < operators.length; j++) {
                if(text.charAt(0) == operators[i] && text.charAt(1) == operators[j]) {
                    twoCharOp = operators[i] + operators[j];
                    switch (twoCharOp) {
                        case '<=':
                            twoCharName = "less than or equal to";
                            break;
                        case '>=':
                            twoCharName = "greater than or equal to";
                            break;
                        case '+=':
                            twoCharName = "addition assignment";
                            break;
                        case '-=':
                            twoCharName = "subtraction assignment";
                            break;
                        case '*=':
                            twoCharName = "multiplication assignment";
                            break;
                        case '/=':
                            twoCharName = "division assignment";
                            break;
                        case '==':
                            twoCharName = "equal-to";
                            break;
                        case '!=':
                            twoCharName = "not equal-to";
                    }
                    return new Token(twoCharName, text);
                }
            }
        }
    } else {
        for (let i = 0; i < operators.length; i++) {
            if (text == operators[i]) {
                return new Token(operatorNames[i], text);
            }
        }
    }

    const identifier: RegExp = /^[_a-zA-Z]\w*$/g;
    if (text.match(identifier)) {
        return new Token("identifier", text);
    }

    const integer: RegExp = /^[0-9]+$/g;
    if (integer.test(text)) {
        return new Token("integer", text);
    }

    const decimal: RegExp = /^[0-9]+\.[0-9]+$/g;
    if (decimal.test(text)) {
        return new Token("decimal", text);
    }
};