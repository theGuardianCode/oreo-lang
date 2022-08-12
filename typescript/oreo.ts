import * as fs from 'fs';
import {Token, lex} from './lexer';
import { BinOpNode, NumberNode, Parser} from './parser';

let tokenValue: string = "";
let tokens: Token[] = [];

let file: string = process.argv[2];

const fileContent: string = fs.readFileSync(file, 'utf-8');

for (let i = 0; i <= fileContent.length; i++) {
    if(fileContent.charAt(i) == ' ' || fileContent.charAt(i) == fileContent.charAt(fileContent.length)) {
        tokens.push(lex(tokenValue));
        tokenValue = "";
    } else {
        tokenValue = tokenValue + fileContent.charAt(i);
    }
}

const parser: Parser = new Parser(tokens);
const ast: BinOpNode = parser.Parse();

console.log(ast);