int checkNoCyCle(int val, int k){
    for(int i = 1; i<=N; i++){
        makeSet(i);
    }
    for(int j = 1; j<k; j++){
        int u = b[X[j]];
        int v = e[X[j]];
        int ru = findSet(u);
        int rv = findSet(v);
        if(ru == rv) return 0;
        link(ru, rv);
    }

    if(findSet(b[val]) == findSet(e[val])) return 0;
    return 1;
}

