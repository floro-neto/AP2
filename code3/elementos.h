void elementos(int *v) {
    for (int i = 0; i < 8; i++) {
        if (v[i] >= 15 && v[i] <= 20) {
            v[i] = 0;
        }
    }
}
