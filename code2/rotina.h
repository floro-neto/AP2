void substitui(int (*matriz)[3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] % 2 == 0) {
                matriz[i][j] = 1000;
            }
        }
    }
}
