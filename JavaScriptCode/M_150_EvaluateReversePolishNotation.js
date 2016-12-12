/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const opDic = new Set(["+", "-", "*", "/"]);
    const stack = [];
    for (let token of tokens) {
        if (opDic.has(token)) {
            getOp(stack, token);
        } else {
            stack.push(parseInt(token));
        }
    }
    return stack[0];
};

var getOp = function(stack, token) {
    let r = stack.pop(), l = stack.pop();
    switch (token) {
        case "+": stack.push(l + r); return;
        case "-": stack.push(l - r); return;
        case "*": stack.push(l * r); return;
        case "/": stack.push((l / r) >> 0); return;
        default: return;
    }
};
