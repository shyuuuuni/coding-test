const OPER = {
    MULT: 0,
    PLUS: 1,
    MINUS: 2
};
const CALC = {
    0: (a, b) => a*b,
    1: (a, b) => a+b,
    2: (a, b) => a-b
};
const orders = [
    [OPER.MULT, OPER.PLUS, OPER.MINUS],
    [OPER.MULT, OPER.MINUS, OPER.PLUS],
    [OPER.PLUS, OPER.MULT, OPER.MINUS],
    [OPER.PLUS, OPER.MINUS, OPER.MULT],
    [OPER.MINUS, OPER.MULT, OPER.PLUS],
    [OPER.MINUS, OPER.PLUS, OPER.MULT],
];

class Node {
    constructor(value) {
        this.next = null;
        this.prev = null;
        this.value = value;
    }
}

class Expr {
    constructor(operand, operator) {
        this.first = new Node();
        this.last = new Node();
        this.init(operand, operator);
    }
    init(operand, operator) {
        this.first.next = this.last;
        this.last.prev = this.first;
        
        for (let i=0; i< operand.length; i++) {
            if (i < operand.length - 1) {
                const value = Number(operand[i]);
                const oper = this.getOPER(operator[i]);
                this.pushBack({ value, oper });
            } else {
                const value = Number(operand[i]);
                this.pushBack({ value });
            }
        }
    }
    getOPER(operand) {
        switch(operand) {
            case '*':
                return OPER.MULT;
            case '+':
                return OPER.PLUS;
            case '-':
                return OPER.MINUS;
        }
        return undefined;
    }
    pushBack(value) {
        const node = new Node(value);
        const p = this.last.prev,
              n = this.last;
        
        p.next = node;
        node.prev = p;
        
        n.prev = node;
        node.next = n;
        
        return node.value;
    }
    remove(node) {
        const p = node.prev,
              n = node.next;
        
        p.next = n;
        n.prev = p;
        
        return node.value;
    }
}

function solution(expression) {
    let answer = 0;
    
    const operand = expression.split(/[-*+]/g);
    const operator = expression.match(/[-*+]{1}/g);
    
    orders.forEach((order) => {
        const expr = new Expr(operand, operator);
        
        order.forEach((o) => {
            let ptr = expr.first.next;
            while (ptr !== expr.last) {
                const { value: v1, oper: o1 } = ptr.value;
                
                if (o1 === undefined) {
                    break;
                }
                if (o1 === o) {
                    const { value: v2, oper: o2 } = ptr.next.value;
                    const newValue = CALC[o1](v1, v2);
                    ptr.value = {
                        value: newValue,
                        oper: o2
                    };
                    expr.remove(ptr.next);
                } else {
                    ptr = ptr.next;
                }
            }
        });
        
        
        const result = expr.first.next.value.value;
        answer = Math.max(answer, Math.abs(result));
    })
    
    return answer;
}