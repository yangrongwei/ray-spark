This page book some **anti-intuitive** behaviors in Eclipse.

Specifically, this edition on SUSE 10 64-bit

    Eclipse IDE for C/C++ Developers
    Version: Indigo Service Release 1
    Build id: 20110916-0149

FIRST OF ALL, we should ALWAYS KEEP IN MIND _Eclipse CDT_ is **NOT** a commercial quality product, and maybe never. I watched the project several years, the improvement progress is very slow. Anyway, it is free, and has a stable base, Eclipse for Java. Another thing I want to share with you -- Eclipse is a really nice development tool to temper your willpower. Yes, that's it!

## Anti-intuitive Behavior (Git)
### You can always find **"Paste Repository Path or URI"** item in context (popup) menu within _Git Repositories_ view

This is an extremely torturing behavior for git beginner, like me. From time to time, I want to add a remote repository for my existing local repository, it helps me clone the remote repository again and again. At last, I realize it is a global behavior which SHOULD NOT show on any specific item!!! Damn!!! The property time to show it is when user popup the context menu on any blank space in _Git Repositories_ view. 

## Hard-to-use behaviors (Git)
### It is hard for user to add a **Remote** repository for local repository

Comparing this behavior with _Clone a repository_ , which is fluent and straightforward, in _Git Repositories_ view, ...