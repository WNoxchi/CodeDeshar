bool newRoadSystem(std::vector<std::vector<bool>> roadRegister) {
    int outroads = 0 inroads = 0;
    // on each iteration check the # trues in cols = # in rows
    for (int i = 0; i < roadRegister.size(); i++) {
        // check trues in row
        for (int col = 0; col < roadRegister.size(); col++) {
            if (roadRegister[i][col]) {
                outroads++;
            }
        }
        // check trues in col
        for (int row = 0; row < roadRegister.size(); row++) {
            if (roadRegister[row][i]) {
                inroads++;
            }
        }
        // if trues dont match return false
        if (outroads != inroads) {
            return false;
        }
    }
    return true;
}
