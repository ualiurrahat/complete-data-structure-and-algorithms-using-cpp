Stack<char> s;
    s.push('r');
    s.push('a');
    s.push('h');
    s.push('a');
    s.push('t');
    cout << s.getSize() << endl; // 5

    cout << s.top() << endl;     // t
    cout << s.pop() << endl;     // t
    cout << s.pop() << endl;     // a
    cout << s.pop() << endl;     // h
    cout << s.getSize() << endl; // 2

    cout << s.isEmpty() << endl; // 0
    cout << s.pop() << endl;     // a
    cout << s.pop() << endl;     // r
    cout << s.top() << endl;     // stack is empty!
    cout << s.pop() << endl;     // stack is empty!
    cout << s.isEmpty() << endl; // true->1
