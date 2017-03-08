# **Algorithm:**
```
1.	Push a left parenthesis ‘(‘ onto the stack;
2.	Append a right parenthesis ‘)’ to the end of infix.
3.	While the stack is not empty, read infix from left to right and do the following:
    a. If the current character in infix is a white space, simply ignore it.
    b. If the current character in infix is a digit, copy it to the next element of postfix.
    c. If the current character in infix is a left parenthesis, push it onto the stack.
    d. If the current character in infix is an operator,
        • Pop operators (if there are any) at the top of the stack while they have equal or higher
    precedence than the current operator, and insert the popped operators in postfix.
        • Push the current character in infix onto the stack.
    e. If the current character in infix is a right parenthesis,
        • Pop operators from the top of the stack and insert them in postfix until a left parenthesis
    is at the top of the stack.
        • Pop (and discard) the left parenthesis from the stack.
```
