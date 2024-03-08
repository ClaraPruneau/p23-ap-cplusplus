struct Stack {
    friend Stack operator= (Stack &s1 , const Stack &s2);
};
inline Stack operator= (Stack &s1 , Stack &s2 ) {
    nb = s1.nb
    if (nb != s2.nb){
        throw "impossible"
    }
    for (int i = 0; i<nb ; i++){
        s1.tab[i]=s2.tab[i]
    }
return s1;};

