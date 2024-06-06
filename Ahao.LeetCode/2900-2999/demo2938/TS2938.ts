function minimumStepsTS(s: string): number {
    let res: number = 0;
    let sum: number = 0;
    for (let i: number = 0; i < s.length; i++) {
        if (s[i] == '1') {
            sum++;
        } else {
            res += sum;
        }
    }
    return res;
}